#include "types.h"

char* type_to_string(enum Types t)
{
  switch (t) {
  case boolean: {
    return "boolean";
  }
  case integer: {
    return "integer";
  }
  case symbol: {
    return "symbol";
  }
  case string: {
    return "string";
  }
  }
}

int is_number(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; // False
        }
    }
    return 1; // True
}

int is_boolean(const char *str)
{
  if(strcmp(str, "#t") == 0 || strcmp(str, "#f") == 0)
    {
      return 1;      
    }
  return 0;
}

int is_string(const char *str)
{
  if(str[0] == '"' &&  str[strlen(str) - 1] == '"')
    {
      return 1;
    }
  return 0;
}


enum Types token_to_type(char* token)
{
  if(is_boolean(token))
    {
      return boolean;      
    }
  else if(is_number(token))
    {
      return integer;      
    }
  else if(is_string(token))
    {
      return string;      
    }
  return symbol;      
}
