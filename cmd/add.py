import sys
from datetime import datetime

import utils.file
import context

def cmd_add():
    task_date = datetime.now().strftime("%Y-%m-%d %H:%M:%S") 
    task_content: str = sys.argv[2]
    if context.context_exists() == 0:
        print("error: context doesnt exists")
        return
    task_get_sender: str = context.get_sender_context()
    task_all_string: str = "[" + task_date + "]" + task_get_sender
    task_all_string += "Task: " + task_content
    utils.file.write_file(context.get_taskfile_context(), task_all_string)

