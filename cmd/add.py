import sys
from datetime import date, datetime

import utils.file
import context

def have_executor() -> bool:
    if len(sys.argv) != 5:
        return False
    return True

def have_context() -> bool:
    if context.context_exists() == 0:
        return False
    return True

def cmd_add():
    task_content: str = sys.argv[2]
 
    if not have_executor():
        print("error: the task needs an executor.")
        print("usage: task add \"<task>\" to \"<name>\" ")
        print("(if the task is for yourself, use '-')")
        exit(1)

    if not have_context():
        print("error: context not found. (use --context to use your taskfile)")
        exit(1)

    task_date = datetime.now().strftime("%H:%M:%S - %Y/%m/%d") 
    task_sender: str = context.get_sender_context()
    
    if sys.argv[4] == '-':
        task_executor = "yourself"
    else:
        task_executor = sys.argv[4]
    
    task_all_string: str = "[" + task_date + "]" + task_sender
    task_all_string += "Task: " + task_content
    utils.file.write_file(context.get_taskfile_context(), task_all_string)

    print("done.")
    print("task date: " + task_date)
    print("task sender: " + task_sender)
    print("task executor: " + task_executor)
    print("task content: ")
    print("    \"" + task_content + "\"")



