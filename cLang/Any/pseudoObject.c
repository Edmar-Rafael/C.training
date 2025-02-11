#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define Class struct

Class Person {
  char name[25];
  uint8_t age;
  uint8_t height;
  void(*show)(Class Person *);
};

void printPerson(Class Person *this) {
  printf("Name: %s, Age: %d, Height: %d \n", this->name, this->age, this->height);
}

Class Person* newPerson(char name[], uint8_t age, uint8_t height) {
  Class Person *this = (Class Person *) malloc(sizeof(Class Person));
  strcpy(this->name, name);
  this->age = age;
  this->height = height;

  this->show = &printPerson;

  return this;
}


int main() {
  Class Person *person2 = (Class Person *) newPerson("Edmar Rafael Henches", 41, 171);

  person2->show(person2);

  return 0;
}