#ifndef _UTILS_FILE_H_
#define _UTILS_FILE_H_

#include "defines.h"

void write_file(const char *name, const char *content);
bool file_exists(const char *name);
void create_file(const char *name);

#endif
