#include "dispatch.h"
#include "cmd-create.h"
#include <stdio.h>
#include <string.h>

Dispatch disp[] = {
    {"create", cmd_create},
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
  printf("(task -h or task --help to see commands)\n");
}
