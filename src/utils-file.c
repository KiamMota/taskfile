#include "utils-file.h"
#include "messages.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void write_file(const char *name, const char *content) {
  FILE *f = fopen(name, "a");
  if (!f)
    return;
  fprintf(f, "%s\n", content);
  fclose(f);
}

char *get_file_content(const char *name) {
  if (!file_exists(name))
    return NULL;

  FILE *f = fopen(name, "rb");

  fseek(f, 0, SEEK_END);
  long size = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *content = (char *)malloc(size);

  for (int i = 0; i < size; i++) {
    content[i] = fgetc(f);
  }
  return content;
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
