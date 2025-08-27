import os

def create_file(file_name: str):
    with open(file_name, "w") as fl:
        fl.write("")

def write_file(filename: str, what: str):
    with open(filename, "w") as fl:
        fl.write(what)
