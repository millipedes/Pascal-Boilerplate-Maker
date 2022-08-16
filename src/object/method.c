#define _POSIX_C_SOURCE 200809L
#include "include/method.h"

method * init_method(char * name, lang_type * return_type,
    privacy_status status) {
  size_t len = 0;
  method * mth = calloc(1, sizeof(struct METHOD_T));
  len = strnlen(name, MAX_TYPE) + 1;
  mth->name = calloc(len, sizeof(char));
  strncpy(mth->name, name, len);
  mth->parameters = NULL;
  mth->return_type = init_lang_type(return_type->literal, return_type->itself);
  mth->qty_parameters = 0;
  mth->status = status;
  return mth;
}

void add_method_parameter(method * mth, attribute * attr,
    privacy_status status) {
  mth->qty_parameters++;
  if(mth->parameters)
    mth->parameters = realloc(mth->parameters, mth->qty_parameters
        * sizeof(struct ATTRIBUTE_T *));
  else
    mth->parameters = calloc(mth->qty_parameters, mth->qty_parameters
        * sizeof(struct ATTRIBUTE_T *));
  mth->parameters[mth->qty_parameters - 1]
    = init_attribute(attr->name, attr->attr_type, status);
}

void free_method(method * mth) {
  if(mth) {
    if(mth->name)
      free(mth->name);
    if(mth->parameters) {
      for(int i = 0; i < mth->qty_parameters; i++)
        if(mth->parameters[i])
          free_attribute(mth->parameters[i]);
      free(mth->parameters);
    }
    free(mth);
  }
}
