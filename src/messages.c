#include "messages.h"
#include "defines.h"
#include <stdio.h>

void help() {
  printf("welcome to taskfile.\n");
  printf("\tusage:\n");
  printf("task <command> <subcommand> <parameters>");
}

void version() { printf("taskfile version %s\n", task_version); }

void err(const char *log) {
  printf("error: %s\n", log);
  fflush(stdin);
}
