import sys
import os
import utils.file
from context import create_context

def create():
    file: str = sys.argv[2]
    abspath: str = os.getcwd()
    if sys.argv[2] == "": return

    if sys.argv[1] == "create" and sys.argv[2] != '-':
        utils.file.create_file(file)
        print("file '" + file + "' created in " + abspath)
        create_context(file, "--")
        return
    if sys.argv[1] == "create" and sys.argv[2] == '-':
        utils.file.create_file("taskfile.txt")
        print("file named taskfile.txt created in " + abspath)
        create_context("taskfile.txt", "--")
        return
