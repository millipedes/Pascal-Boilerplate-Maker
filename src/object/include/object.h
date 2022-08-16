#ifndef OBJ_H
#define OBJ_H

#include "../../main/include/constants.h"
#include "attribute.h"
#include "method.h"

typedef struct OBJECT_T {
  attribute ** attrs;
  method ** methods;
  char * name;
  int qty_attrs;
  int qty_methods;
} object;

object * init_object(char * name);
void add_method(object * obj, method * new_method);
void add_attribute(object * obj, attribute * new_attr);
void free_object(object * obj);

#endif
