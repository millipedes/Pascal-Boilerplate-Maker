#define _POSIX_C_SOURCE 200809L
#include "include/object.h"

object * init_object(char * name) {
  size_t len = 0;
  object * obj = calloc(1, sizeof(struct OBJECT_T));
  len = strnlen(name, MAX_TYPE) + 1;
  obj->name = calloc(len, sizeof(char));
  strncpy(obj->name, name, len);
  obj->attrs = NULL;
  obj->methods = NULL;
  obj->qty_attrs = 0;
  obj->qty_methods = 0;
  return obj;
}

void add_method(object * obj, method * new_method) {
  obj->qty_methods++;
  if(obj->methods)
    obj->methods = realloc(obj->methods, obj->qty_methods
        * sizeof(struct METHOD_T *));
  else
    obj->methods = calloc(obj->qty_methods, obj->qty_methods
        * sizeof(struct METHOD_T *));
  obj->methods[obj->qty_methods - 1] =
    init_method(new_method->name, new_method->return_type, new_method->status);
}

void add_attribute(object * obj, attribute * new_attr) {
  obj->qty_attrs++;
  if(obj->attrs)
    obj->attrs = realloc(obj->attrs, obj->qty_attrs
        * sizeof(struct ATTRIBUTE_T *));
  else
    obj->attrs = calloc(obj->qty_attrs, obj->qty_attrs
        * sizeof(struct ATTRIBUTE_T *));
  obj->attrs[obj->qty_attrs - 1] =
    init_attribute(new_attr->name, new_attr->attr_type, new_attr->status);
}

void free_object(object * obj) {
  if(obj) {
    if(obj->attrs) {
      for(int i = 0; i < obj->qty_attrs; i++)
        if(obj->attrs[i])
          free(obj->attrs[i]);
      free(obj->attrs);
    }
    free(obj);
  }
}
