#include "high_scores.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
  return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  int32_t best = 0;
  for (unsigned int i = 0; i < scores_len - 1; i++) {
    if (scores[i] > best) {
      best = scores[i];
    }
  }
  return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  int top_len;
  if (scores_len < 3)
    top_len = scores_len;
  else
    top_len = 3;

  for (unsigned int i = 0; i < scores_len; i++) {
    int j = 0;
    while (scores[i] <= output[j] && j < top_len - 1) {
      j++;
    }
    if (scores[i] > output[j]) {
      for (int k = top_len - 1; k > j; k--) {
        output[k] = output[k - 1];
      }
      output[j] = scores[i];
    }
  }
  return top_len;
}
