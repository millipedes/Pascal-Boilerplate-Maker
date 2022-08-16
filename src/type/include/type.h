#ifndef TYP_H
#define TYP_H

#include <stdlib.h>

typedef enum {
  CUSTOM,
  VOID,
  INTEGER,
  STRING,
  TEXTFILE,
  REAL
} type;

const char * type_to_string(type t);

#endif
