#include "dnd_character.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ability() {
  int lowest = (rand() % 6) + 1;
  int values[3];
  for (long unsigned int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
    int new = (rand() % 6) + 1;
    values[i] = new;
    if (lowest > new) {
      values[i] = lowest;
    }
  }

  int sum = 0;
  for (long unsigned int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
    sum += values[i];
  }
  return sum;
}

int modifier(int score) { return floor((score - 10) / 2.0); }

dnd_character_t make_dnd_character() {
  dnd_character_t character;
  character.strength = ability();
  character.dexterity = ability();
  character.constitution = ability();
  character.intelligence = ability();
  character.wisdom = ability();
  character.charisma = ability();
  character.hitpoints = 10 + modifier(character.constitution);

  return character;
}
