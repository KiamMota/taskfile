#include "cmd-create.h"
#include "args.h"
#include "messages.h"
#include "utils-file.h"
#include <stdio.h>
#include <string.h>

// task create -

void cmd_create() {
  if (arg_n < 3) {
    err("insufficient arguments");
    return;
  }

  if (!strcmp(arg_vector[2], "-")) {
    create_file("Taskfile");
    printf("taskfile created.\n");
  }
}
