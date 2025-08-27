import context
import utils.file
import context

def cmd_list():
    str_list: str = utils.file.get_file_content(context.get_taskfile_context())
    print("tasks: ")
    print(str_list)