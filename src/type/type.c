#include "include/type.h"

const char * type_to_string(type t) {
  switch(t) {
    case CUSTOM:   return "Custom";
    case VOID:     return "Void";
    case INTEGER:  return "Integer";
    case STRING:   return "String";
    case TEXTFILE: return "Textfile";
    case REAL:     return "Real";
  }
  return NULL;
}
