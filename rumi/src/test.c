#include <string.h>
#include "tools.h"
#include "types.h"
#include "test.h"

void run_all_tests()
{
  with_open_file("/rumi/tests/type_predicates.scm", test_types);
}

void test_types(FILE* fp)
{
  char line[256];
  char *token;
  int type_id;
  int guess;
  const char *delimiters = " \t\n,."; // Common delimiters
  while (fgets(line, sizeof(line), fp) != NULL) {
    token = strtok(line, delimiters);
    type_id = atoi(strtok(NULL, delimiters));
    guess = token_to_type(token);
    if(guess == type_id)
      {
	printf("PASS ");
      }
    else
      {
	printf("FAIL ");
      }
    printf("Value: %s Expected: %s Actual: %s\n",
	   token,
	   type_to_string(type_id),
	   type_to_string(token_to_type(token)));
  }
}

