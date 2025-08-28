#include "utils-file.h"
#include "messages.h"
#include <stdio.h>

void write_file(const char *name, const char *content) {
  FILE *f = fopen(name, "a");
  if (!f)
    return;
  fprintf(f, "%s\n", content);
  fclose(f);
}

bool create_file(const char *name) {
  FILE *f = fopen(name, "r");
  if (!f) {
    return false;
  }
  fclose(f);
  return true;
}

bool file_exists(const char *name) {
  FILE *f = fopen(name, "r");
  if (!f) {
    return false;
  }
  fclose(f);
  return true;
}
