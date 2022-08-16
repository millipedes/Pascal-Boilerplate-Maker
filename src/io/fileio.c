#include "include/fileio.h"

void read_file(char * name) {
  FILE * fp = fopen(name, "r");
  object ** obj_list = NULL;
  int qty_objs = 0;
  char buf[MAX_TYPE];
  while(fgets(buf, MAX_TYPE, fp)) {
    if(!strncmp(buf, "Object:", MAX_TYPE)) {
      qty_objs++;
      if(obj_list)
        obj_list = calloc(1, sizeof(struct OBJECT_T *));
      else
        obj_list = realloc(obj_list, qty_objs * sizeof(struct OBJECT_T *));
      obj_list[qty_objs - 1] = read_object(fp);
    } else
      break;
  }
  fclose(fp);
}

object * read_object(FILE * fp) {
  object * obj = NULL;
  attribute * tmp_attr = NULL;
  method * tmp_method = NULL;
  char buf[MAX_TYPE];
  while(fgets(buf, MAX_TYPE, fp)) {
    if(!strncmp(buf, "Attributes:", MAX_TYPE))
      while(strncmp(buf, "End", MAX_TYPE)) {
        tmp_attr = read_attribute(buf);
        add_attribute(obj, tmp_attr);
        free_attribute(tmp_attr);
        tmp_attr = NULL;
        fgets(buf, MAX_TYPE, fp);
      }
    if(!strncmp(buf, "Methods:", MAX_TYPE))
      while(strncmp(buf, "End", MAX_TYPE)) {
        tmp_method = read_method(buf);
        add_method(obj, tmp_method);
        free_attribute(tmp_attr);
        tmp_attr = NULL;
        fgets(buf, MAX_TYPE, fp);
      }
  }
  return obj;
}

attribute * read_attribute(char buf[]) {
}

method * read_method(char buf[]) {
}
