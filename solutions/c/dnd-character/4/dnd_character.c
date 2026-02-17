#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int ability() {
  srand(time(NULL));
  int sum = 0;
  int lowest = 7;
  for (int i = 0; i < 4; i++) {
    int roll = (rand() % 6) + 1;
    sum += roll;
    if (roll < lowest) {
      roll = lowest;
    }
  }
  return sum - lowest;
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
