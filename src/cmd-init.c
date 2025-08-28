#include "cmd-init.h"
#include "args.h"
#include "messages.h"
#include "tfile_context.h"
#include "utils-file.h"
#include <stdio.h>
#include <string.h>

static bool taskfile_exists() {
  if (file_exists("Taskfile")) {
    return true;
  }
  return false;
}

static void create_files() {
  if (!create_file("Taskfile")) {
    err("cannot create file");
    return;
  }
  printf("created taskfile.\n");
  create_context();
  printf("created context.\n");
  char *config = configure_context();
  ovwrite_fie("tfile_context.json", config);
}

void cmd_init() {
  if (arg_n == 1)
    return;
  if (arg_n == 2) {
    if (taskfile_exists()) {
      atten("taskfile already exists.");
      printf("to override, use --force.\n");
      return;
    }
    create_files();
  }
  if (arg_n == 3 && !strcmp(arg_vector[2], "--force")) {
    printf("overriding files...\n");
    create_files();
    return;
  }
}
