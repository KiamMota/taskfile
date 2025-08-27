import sys
from cmd.add import cmd_add
import dispatch
import utils.messages

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
    dispatch.dispatch_table()

init()
