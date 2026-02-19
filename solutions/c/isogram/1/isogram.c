#include "isogram.h"
#include <ctype.h>
#include <stdlib.h>

bool is_isogram(const char phrase[]) {

  if (phrase == NULL)
    return NULL;
  int c, flag = 0;
  while ((c = *phrase++) != '\0') {
    c = tolower(c);
    if ('a' <= c && c <= 'z') {
      if (flag & (1 << (c - 'a'))) {
        return false;
      } else
        flag |= 1 << (c - 'a');
    }
  }
  return true;
}
