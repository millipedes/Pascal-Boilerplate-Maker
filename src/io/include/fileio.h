#ifndef FIO_H
#define FIO_H

#include "../../object/include/object.h"
#include "../../main/include/constants.h"

void read_file(char * name);
object * read_object(FILE * fp);
attribute * read_attribute(char buf[]);
method * read_method(char buf[]);

#endif
