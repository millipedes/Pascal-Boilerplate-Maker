#include "include/lang_type.h"

lang_type * init_lang_type(char * literal, type t) {
  size_t len = 0;
  lang_type * lt = calloc(1, sizeof(struct LANG_TYPE_T));
  if(literal) {
    len = strnlen(literal, MAX_TYPE) + 1;
    lt->literal = calloc(len, sizeof(char));
    strncpy(lt->literal, literal, len);
  } else
    lt->literal = NULL;

  lt->itself = t;
  return lt;
}

void debug(lang_type * lt) {
  printf("Lang Type:\n");
  if(lt->literal)
    printf("Literal: %s, Type: %s\n", lt->literal, type_to_string(lt->itself));
  else
    printf("Type: %s\n", type_to_string(lt->itself));
}

void free_lang_type(lang_type * lt) {
  if(lt) {
    if(lt->literal)
      free(lt->literal);
    free(lt);
  }
}
