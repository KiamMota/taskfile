# taskfile
taskfile is a system for managing, versioning and maintaining tasks in a structured way
It has a metadata system and was designed using the command line

### philosophy

The taskfile is completely task-oriented, where any task have:
- a sender (the person requesting the task)
- an executor (the person making the request)

basic syntax:

``` bash
task <command> <subcommand> <flags>
```

## essentials:

``` bash
task init "<name>"
```

this starts a taskfile in your current directory, it creates metadata written in a generated file called `.tfile_context.json`
where it has the name of the taskfile and the user (it is done through the system name)

``` bash
task add "<content>" to "<name>"
```

This creates a task within the file for the specific executor. It creates essential data:
- task status, whether it's on hold or not
- request date
- who sent it
- who executes it

If you're the executor, you can use a `-` instead of `<name>`.






