#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define Class struct

Class Person {
  char name[15];
  uint8_t age;
  uint8_t height;
  void(*show)(Class Person *);
};

void person_print(Class Person *this) {
  printf("name: %s, age: %d, height: %d \n", this->name, this->age, this->height);
}

Class Person *newPerson(char name[], uint8_t age, uint8_t height) {
  Class Person *this = (Class Person *) malloc(sizeof(Class Person));
  strcpy(this->name, name);
  this->age = age;
  this->height = height;

  this->show = &person_print;

  return this;
}


int main() {
  Class Person *person2 = (Class Person *) newPerson("Edmar Rafael", 40, 171);

  person2->show(person2);

  char e[] = "Edmar Rafael Henches";
  
  printf("%ld \n", sizeof(e));
  return 0;
}