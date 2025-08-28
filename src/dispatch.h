#ifndef _DISPATCH_H_
#define _DISPATCH_H_

typedef struct {
  char *command;
  void (*f)();
} Dispatch;

void disptach(const char *key);

#endif
