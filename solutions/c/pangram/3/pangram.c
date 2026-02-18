#include "pangram.h"
#include <ctype.h>
#include <string.h>

bool is_pangram(const char *sentence) {

  if (sentence == NULL)
    return NULL;

  int c, flags = 0;
  while ((c = *sentence++) != '\0') {
    int lower = tolower(c);
    if ('a' <= lower && lower <= 'z')
      flags |= 1 << (lower - 'a');
  }
  return flags == 0x3ffffff;
}
