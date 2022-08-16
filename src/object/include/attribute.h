#ifndef ATT_H
#define ATT_H

#include "../../type/include/lang_type.h"
#include "privacy_status.h"

typedef struct ATTRIBUTE_T {
  char * name;
  lang_type * attr_type;
  privacy_status status;
} attribute;

attribute * init_attribute(char * name, lang_type * attr_type,
    privacy_status status);
void free_attribute(attribute * attr);

#endif
