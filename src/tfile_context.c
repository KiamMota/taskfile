#include "tfile_context.h"
#include "cjson/cJSON.h"
#include "stdio.h"
#include "utils-file.h"
#include <stdlib.h>

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
void create_context() {
  if (!file_exists(".tfile_context.json"))
    create_file(".tfile_context.json");
  write_file(".tfile_context.json", configure_context());
}
