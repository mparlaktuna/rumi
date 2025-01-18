#pragma once

#include <stdio.h>
#include <stdlib.h>

void with_open_file(char* f_name,  void (*f)(FILE*) );
