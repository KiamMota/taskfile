#ifndef _CMD_CONFIG_H_
#define _CMD_CONFIG_H_

#include "args.h"
#include "messages.h"
#include "tfile_context.h"
#include "utils-file.h"
#include <stdio.h>
#include <string.h>

void cmd_config() {
  if (arg_n < 2) {
    err("no arguments");
    return;
  }
  if (!strcmp(arg_vector[2], "show")) {
    if (!file_exists(".tfile_context.json")) {
      err("no context file found.");
      return;
    }
    printf("username: %s\n", get_context_user());
    printf("taskfile: %s\n", get_context_taskfile());
    printf("ticket type: %s\n", get_context_ticket_type());
  }
}

#endif
