#include "include/privacy_status.h"

const char * privacy_status_to_string(privacy_status ps) {
  switch(ps) {
    case PUBLIC:    return "Public";
    case PROTECTED: return "Protected";
    case PRIVATE:   return "Private";
  }
  return NULL;
}
