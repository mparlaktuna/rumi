#include "tools.h"

void with_open_file(char* f_name, void (*f)(FILE*) )
{
  FILE *fp;
  
  fp = fopen(f_name, "r");
  if (fp == NULL) {
    perror("Error opening file");
  }
  
  f(fp);
  fclose(fp);
}

