import os
import json
import utils.file

MAIN_CONTEXT_NAME = ".tfile_context.json"

json_context: str = '{"config": {}}'

def create_context(taskfile: str, username: str):
    data = json.loads(json_context)
    data["config"]["sender"] = username
    data["config"]["taskfile"] = taskfile
    utils.file.create_file(MAIN_CONTEXT_NAME)
    utils.file.write_file(MAIN_CONTEXT_NAME, json.dumps(data, indent=4)) 

def get_sender_context()-> str:
    file_content: str = utils.file.get_file_content(MAIN_CONTEXT_NAME)
    obj = json.loads(file_content)
    return obj["config"]["sender"]

def get_taskfile_context() -> str:
    file_content: str = utils.file.get_file_content(MAIN_CONTEXT_NAME)
    obj = json.loads(file_content)
    return obj["config"]["taskfile"]

def context_exists() -> bool:
    return os.path.exists(MAIN_CONTEXT_NAME)







