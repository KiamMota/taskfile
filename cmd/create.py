import sys
import os
import utils.file
from context import create_context

MAIN_NAME = "Taskfile"

def cmd_create():
    file: str = sys.argv[2]
    abspath: str = os.getcwd()
    if sys.argv[2] == "": return

    if sys.argv[2] != '-':
        utils.file.create_file(file)
        print("file '" + file + "' created in " + abspath)
        create_context(file, "--")
        return
    if sys.argv[2] == '-':
        utils.file.create_file(MAIN_NAME)
        print("file named Taskfile created in " + abspath)
        create_context(MAIN_NAME, "--")
        return
