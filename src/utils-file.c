#include "utils-file.h"
#include "messages.h"
#include <stdio.h>

void write_file(const char *name, const char *content) {
  FILE *f = fopen(name, "a");
  fprintf(f, content, "\n");
  fclose(f);
}

void create_file(const char *name) {
  FILE *f = fopen(name, "a");
  if (!f) {
    err("cannot create the file.");
    return;
  }
  fclose(f);
}

bool file_exists(const char *name) {
  FILE *f = fopen(name, "r");
  if (!f) {
    return true;
  }
  fclose(f);
  return false;
}
