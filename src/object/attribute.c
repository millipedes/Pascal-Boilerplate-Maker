#define _POSIX_C_SOURCE 200809L
#include "include/attribute.h"

attribute * init_attribute(char * name, lang_type * attr_type,
    privacy_status status) {
  size_t len = 0;
  attribute * attr = calloc(1, sizeof(struct ATTRIBUTE_T));
  len = strnlen(name, MAX_TYPE) + 1;
  attr->name = calloc(len, sizeof(char));
  strncpy(attr->attr_type->literal, name, len);
  attr->attr_type = init_lang_type(attr_type->literal, attr_type->itself);
  attr->status = status;
  return attr;
}

void free_attribute(attribute * attr) {
  if(attr) {
    if(attr->name)
      free(attr->name);
    free(attr);
  }
}
