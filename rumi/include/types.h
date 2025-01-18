#pragma once

enum Types {
  boolean = 0,
  integer,
  string,
  symbol
};

char* type_to_string(enum Types);
int is_number(const char *str);
int is_boolean(const char *str);
int is_string(const char *str);
enum Types token_to_type(char*);
