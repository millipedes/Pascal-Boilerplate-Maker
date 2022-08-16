#include <stdio.h>
#include "../type/include/lang_type.h"
#include "../io/include/fileio.h"

int main (void) {
  lang_type * lt = init_lang_type("CustomType", CUSTOM);
  read_file("src/main/main.c");
  debug(lt);
  free_lang_type(lt);
  return 0;
}
