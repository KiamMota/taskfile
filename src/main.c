#include "defines.h"
#include "messages.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arg_n = 0;
char **arg_vector = NULL;

int main(int argc, char *argv[]) {

  arg_n = argc;
  arg_vector = (char **)malloc(sizeof(arg_n));
  for (int i = 0; i < arg_n; i++) {
    arg_vector[i] = (char *)malloc(sizeof(strlen(arg_vector[i])));
    strcpy(arg_vector[i], argv[i]);
  }

  if (argc < 2) {
    help();
    exit(1);
  }

  if (!strcmp(argv[1], "--version")) {
    version();
    exit(1);
  }
  if (!strcmp(argv[1], "-v")) {
    version();
    exit(1);
  }

  for (short i = 0; i < argc; i++) {
    *arg_vector = argv[i];
  }

  printf("argc : %d\n", arg_n);

  return 0;
}
