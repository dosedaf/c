#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
  char name[MAX_NAME];
  int age;
} person;

person * hash_table[TABLE_SIZE];  

void init_hash_table() {
  // calloc aja ga sih?
  for(int i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] == NULL;
  }
}

unsigned int hash(char *name) {
  int length = strnlen(name, MAX_NAME);
  unsigned int hash_value = 0;
  for(int i = 0; i < length; i++) {
    hash_value += name[i];
    hash_value = hash_value * name[i] % TABLE_SIZE;
  }

  return hash_value;
}

void print_table() {
  printf("\tStart\n");
  for(int i = 0; i < TABLE_SIZE; i++) {
    if(hash_table[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else {
      printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
  }
  printf("\tEnd\n");
}

bool hash_table_insert(person *p) {
  if(p == NULL) return false;

  int index = hash(p->name);
  if(hash_table[index] != NULL) return false;
  
  hash_table[index] = p;
  return true;
}

person *hash_table_lookup(char *name) { // time complexity : O(1)
  int index = hash(name); // ambil index dgn cara hash nama
  if(hash_table[index] != NULL && strncmp(hash_table[index]->name, name, MAX_NAME) == 0) {
    return hash_table[index];
  }

  return NULL;
}

person *hash_table_delete(char *name) { // time complexity : O(1)
  int index = hash(name); // ambil index dgn cara hash nama
  if(hash_table[index] != NULL && strncmp(hash_table[index]->name, name, MAX_NAME) == 0) {
    person *tmp = hash_table[index];
    hash_table[index] = NULL;
    return tmp;
  }

  return NULL;
}

int main() {
  init_hash_table();

  person jacob = {.name="Jacob", .age=25};
  person kate = {.name="Kate", .age=27};
  person mpho = {.name="Mpho", .age=14};
  person sarah = {.name="Sarah", .age=25};
  person edna = {.name="Edna", .age=25};
  person maren = {.name="Maren", .age=27};
  person eliza = {.name="Eliza", .age=14};
  person robert = {.name="Robert", .age=27};
  person jane = {.name="Jane", .age=14};

  hash_table_insert(&jacob);
  hash_table_insert(&kate);
  hash_table_insert(&mpho);
  hash_table_insert(&sarah);
  hash_table_insert(&edna);
  hash_table_insert(&maren);
  hash_table_insert(&eliza);
  hash_table_insert(&robert);
  hash_table_insert(&jane);

  print_table();
  printf("\tPERTANYAAN\n");
  printf("\t<---kemana perginya robert dan jane?--->\n");

  return 0;
};

