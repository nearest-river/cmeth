
const LIB_NAME="cmeth";
const ROOT=new URL("../",import.meta.url);
const INCLUDE_DIR=new URL("./include/",ROOT);

async function main() {
  const call_stack=new Array<Promise<void>>();
  Deno.chdir(ROOT);
  await Promise.allSettled([ensure_dir("include"),ensure_dir("bin")]);

  async function walk_dir(path: URL|string) {
    const cwd=Deno.cwd();
    Deno.chdir(path);
    for await(const file of Deno.readDir(".")) {
      const real_path=await Deno.realPath(file.name);
      if(file.isDirectory) {
        await walk_dir(real_path);
        continue;
      }
      if(!file.name.endsWith(".c")) continue;

      const obj_name=real_path.replace(ROOT.pathname,"").replaceAll("/","_");
      call_stack.push(run(`gcc -Wall -g -c ${real_path} -o ${INCLUDE_DIR.pathname}/${obj_name}.o`));
    }
    Deno.chdir(cwd);
  }

    

  await walk_dir("src");
  await Promise.allSettled(call_stack);

  Deno.chdir(INCLUDE_DIR);

  const objects=new Array<string>();
  for await(const file of Deno.readDir(".")) {
    if(!file.isFile || !file.name.endsWith(".o")) continue;
    objects.push(file.name);
  }

  const object_paths=objects.join(" ");
  await run(`ar -rc ./lib${LIB_NAME}.a ${object_paths}`);
  await run(`rm -f ${object_paths}`);
}


//gcc -Wall -g -c ../lib/*.c;
//ar -rc "./lib$1.a" *.o


async function ensure_dir(path: URL|string) {
  await Deno.mkdir(path,{ recursive: true }).catch(_=> {});
}

async function run(cmd: string) {
  const [command,...args]=cmd.split(" ");
  const process=new Deno.Command(command,{ args }).spawn();
  await process.status;
}



if(import.meta.main) await main();
