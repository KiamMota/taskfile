import os

import cmd.create

def dispatch_table():
    umap: dict = {}
    
    umap["create"] = cmd.create.create()

