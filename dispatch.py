import sys

import cmd.init
import cmd.add

def dispatch_table():
    arg: str = sys.argv[1]
    umap: dict = {} 
    umap["init"] = cmd.init.cmd_init
    umap["add"] = cmd.add.cmd_add

    if arg in umap:
        umap[arg]()
    else:
        print("error:", arg, " is an invalid command.")

