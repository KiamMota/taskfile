import sys
import os
import utils.messages
import utils.file

def create():
    file: str = sys.argv[2]
    abspath: str = os.getcwd()
    if sys.argv[2] == "": return

    if sys.argv[1] == "create" and sys.argv[2] != '-':
        utils.file.create_file(file)
        print("file '" + file + "' created in " + abspath)
        return
    if sys.argv[1] == "create" and sys.argv[2] == '-':
        utils.file.create_file("taskfile.txt")
        print("file named taskfile.txt created in " + abspath)
        return

def init():
    if len(sys.argv) < 2:
        print(utils.messages.help_message())
        exit(0)
    if sys.argv[1] == "--help" or sys.argv[1] == "-h":
        print(utils.messages.help_message())
        exit(0)
    if sys.argv[1] == "--version" or sys.argv[1] == "-v" :
        print(utils.messages.version_message())
        exit(0)
    create() 

init()
