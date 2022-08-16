#ifndef MTH_H
#define MTH_H

#include "attribute.h"
#include "privacy_status.h"

typedef struct METHOD_T {
  char * name;
  attribute ** parameters;
  lang_type * return_type;
  privacy_status status;
  int qty_parameters;
} method;

method * init_method(char * name, lang_type * return_type,
    privacy_status status);
void add_method_parameter(method * mth, attribute * attr,
    privacy_status status);
void free_method(method * mth);

#endif

