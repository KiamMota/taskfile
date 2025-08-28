#ifndef _TFILE_CONTEXT_H_
#define _TFILE_CONTEXT_H_

#define MAIN_CTXF_NAME ".tfile_context.json"
#define MAIN_CTXF_TFILE "taskfile"
#define MAIN_CTXF_USER "username"
#define MAIN_CTXF_TICKETTYPE "ticket_type"

void create_context();
char *get_context_user();
char *get_context_taskfile();
char *get_context_ticket_type();

#endif
