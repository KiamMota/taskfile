#include "tfile_context.h"
#include "cjson/cJSON.h"
#include "messages.h"
#include "utils-file.h"
#include <string.h>

static char *configure_context() {
  cJSON *main_obj = cJSON_CreateObject();
  cJSON *config_obj = cJSON_CreateObject();
  cJSON_AddStringToObject(config_obj, MAIN_CTXF_USER, "none");
  cJSON_AddStringToObject(config_obj, MAIN_CTXF_TFILE, "Taskfile");
  cJSON_AddStringToObject(config_obj, MAIN_CTXF_TICKETTYPE, "normal");
  cJSON_AddItemToObject(main_obj, "config", config_obj);
  char *json_ret = cJSON_Print(main_obj);
  cJSON_Delete(main_obj);
  return json_ret;
}

static cJSON *start_parsing() {
  char *file = get_file_content(".tfile_context.json");
  if (!file_exists(".tfile_context.json")) {
    err("context file not exists.");
    return NULL;
  }
  cJSON *parse_root = cJSON_Parse(file);
  cJSON *config = cJSON_GetObjectItem(parse_root, "config");
  return config;
}

char *get_context_user() {
  cJSON *config = start_parsing();
  cJSON *user = cJSON_GetObjectItem(config, MAIN_CTXF_USER);
  return user->valuestring;
}

char *get_context_taskfile() {
  cJSON *config = start_parsing();
  cJSON *taskname = cJSON_GetObjectItem(config, MAIN_CTXF_TFILE);
  return taskname->valuestring;
}

char *get_context_ticket_type() {
  cJSON *config = start_parsing();
  cJSON *ticket_type = cJSON_GetObjectItem(config, MAIN_CTXF_TICKETTYPE);
  return ticket_type->valuestring;
}

void create_context() {
  if (!file_exists(".tfile_context.json")) {
    create_file(".tfile_context.json");
  }
  write_file(".tfile_context.json", configure_context());
}
