import sys
import os
import utils.messages
import utils.file

def get_args():
    if sys.argv[1] == "create" and sys.argv[2] != "":
        file: str = sys.argv[2]
        abspath: str = os.getcwd()
        utils.file.create_file(file)
        print("file '" + file + "' created in " + abspath)

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
    get_args() 

init()
