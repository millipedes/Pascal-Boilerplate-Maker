#include "include/fileio.h"

void read_file(char * name) {
  FILE * fp = fopen(name, "r");
  char buf[MAX_TYPE];
  while(fgets(buf, MAX_TYPE, fp)) {
  }
  fclose(fp);
}
