#include <stdio.h>
#include <stdlib.h>

void load_file(char* f_name)
{
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
  fp = fopen(f_name, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }
  
  while ((read = getline(&line, &len, fp)) != -1) {
    printf("%s", line);
  }
  
  fclose(fp);
  if (line) {
    free(line);
  }
}

int main()
{
  printf("Hello Rumi!\n");
  load_file("/sample.scm");
  return 0;
}
