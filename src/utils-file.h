#ifndef _UTILS_FILE_H_
#define _UTILS_FILE_H_

#include "defines.h"

void write_file(const char *name, const char *content);
bool file_exists(const char *name);
bool create_file(const char *name);
char *get_file_content(const char *name);

#endif
