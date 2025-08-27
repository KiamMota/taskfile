import os

def create_file(file_name: str):
    with open(file_name, "w") as fl:
        fl.write("")

def write_file(filename: str, what: str):
    with open(filename, "a") as fl:
        append: str = what + "\n"
        fl.write(append)

def get_file_content(filename: str) -> str:
    with open(filename, "r") as fl:
        content: str = fl.read()
    return content
