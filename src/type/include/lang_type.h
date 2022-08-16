#ifndef LTP_H
#define LTP_H

#include <stdio.h>
#include <string.h>
#include "type.h"
#include "../../main/include/constants.h"

typedef struct LANG_TYPE_T {
  char * literal;
  type itself;
} lang_type;

lang_type * init_lang_type(char * literal, type t);
void debug(lang_type * lt);
void free_lang_type(lang_type * lt);

#endif
