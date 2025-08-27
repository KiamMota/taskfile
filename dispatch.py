import sys

import cmd.init
import cmd.add
import cmd.list

def dispatch_table():
    arg: str = sys.argv[1]
    umap: dict = {} 
    umap["init"] = cmd.init.cmd_init
    umap["add"] = cmd.add.cmd_add
    umap["list"] = cmd.list.cmd_list

    if arg in umap:
        umap[arg]()
    else:
        print("error: '" + arg + "' is an invalid command.")

