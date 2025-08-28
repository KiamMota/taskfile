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
    printf("taskfile created.\n");
    if (arg_n == 4 && !strcmp(arg_vector[3], "--force")) {
      create_context();
      const char *json = configure_context();
      ovwrite_fie(".tfile_context.json", json);
      return;
    }
    atten("A configuration file already exists. If you want to overwrite it, "
          "use: task init <name> --force");
    return;
  }
}
