#include "pangram.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_pangram(const char *sentence) {

  char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  if (sentence == NULL)
    return false;

  int count = 0;
  if (strlen(sentence) < 26)
    return false;
  for (int i = 0; i < 25; i++) {
    int j = 0;
    while (sentence[j] != '\0') {
      if (alpha[i] == tolower(sentence[j])) {
        count++;
        break;
      }
      j++;
    }
  }
  printf("Count: %d\n", count);
  return count == 25;
}
