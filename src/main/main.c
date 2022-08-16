#include <stdio.h>
#include "../type/include/lang_type.h"

int main (void) {
  lang_type * lt = init_lang_type("CustomType", CUSTOM);
  debug(lt);
  free_lang_type(lt);
  return 0;
}
