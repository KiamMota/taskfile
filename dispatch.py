import sys

import cmd.create
import cmd.add

def dispatch_table():
    arg: str = sys.argv[1]
    umap: dict = {} 
    umap["create"] = cmd.create.cmd_create
    umap["add"] = cmd.add.cmd_add

    if arg in umap:
        umap[arg]()
    else:
        print("error:", arg, " is an invalid command.")

