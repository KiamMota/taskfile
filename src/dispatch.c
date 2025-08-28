#include "dispatch.h"
#include "cmd-init.h"
#include <stdio.h>
#include <string.h>

Dispatch disp[] = {
    {"init", cmd_init},
};

int size_commands = sizeof(disp) / sizeof(disp[0]);

void disptach(const char *key) {
  for (short i = 0; i < size_commands; i++) {
    if (!strcmp(disp[i].command, key)) {
      disp[i].f();
      return;
    }
  }
  printf("error: '%s' is not a valid argument.\n", key);
  printf("(task -h or task --help to see commands)");
}

void show_commands() {
  printf("commands: \n");
  for (int i = 0; i < size_commands; i++) {
    printf("\t%s\n", disp[i].command);
  }
}
