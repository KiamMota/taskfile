#include "cmd-init.h"
#include "args.h"
#include "messages.h"
#include "tfile_context.h"
#include "utils-file.h"
#include <stdio.h>
#include <string.h>

// task create -

void cmd_init() {
  if (arg_n < 3) {
    err("insufficient arguments");
    return;
  }

  if (!strcmp(arg_vector[2], "-")) {
    create_file("Taskfile");
    create_context();
    printf("taskfile created.\n");
  }
}
