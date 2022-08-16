#ifndef PRS_H
#define PRS_H

#include <stdlib.h>

typedef enum {
  PUBLIC,
  PROTECTED,
  PRIVATE
} privacy_status;

const char * privacy_status_to_string(privacy_status ps);

#endif

