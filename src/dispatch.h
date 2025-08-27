#ifndef _DISPATCH_H_
#define _DISPATCH_H_

typedef struct {
  char *command;
  void (*f)(char **argv);
} Dispatch;

void disptach(char **argv);

#endif
