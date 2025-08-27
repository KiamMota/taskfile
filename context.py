import json
import utils.file

json_context: str = '{"config": {}}'

def create_context(taskfile: str, username: str):
    data = json.loads(json_context)
    data["config"]["username"] = username
    data["config"]["taskfile"] = taskfile
    utils.file.create_file(".mdo_context.json")
    utils.file.write_file(".mdo_context.json", json.dumps(data, indent=4)) 






