#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFFFUL)

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
    } else if(hash_table[i] == DELETED_NODE) {
      printf("\t%i\t<deleted>\n", i);
    } else {
      printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
  }
  printf("\tEnd\n");
}

bool hash_table_insert(person *p) {
  if(p == NULL) return false;

  int index = hash(p->name);
  for(int i = 0; i < TABLE_SIZE; i++) {
    int try = (i + index) % TABLE_SIZE; // iterate from index % TABLE_SIZE until find null, time complexity kind of suck
    if(hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
      hash_table[try] = p;
      return true;
    };
  };

  return false;
}

person *hash_table_lookup(char *name) { // time complexity : O(1)
  int index = hash(name); // ambil index dgn cara hash nama
  for(int i = 0; i < TABLE_SIZE; i++) {
    int try = (i + index) % TABLE_SIZE; // iterate from index % TABLE_SIZE until find null, time complexity kind of suck
    if(hash_table[try] == NULL) { // if its null meaning theres no data that tried to populate this [try] index, meaning, no insert in this index, meaning no linaer probing
      return false;
    }
    if(hash_table[try] == DELETED_NODE) continue; // if its deleted then there's a chance that a data was there and it triggers the linear probing when another data w the same index is inputted
    if(strncmp(hash_table[try]->name, name, MAX_NAME)==0 ) {
      return hash_table[try];
    };
  };

  return NULL;
}

person *hash_table_delete(char *name) { // time complexity : O(1)
  int index = hash(name); // ambil index dgn cara hash nama
  for(int i = 0; i < TABLE_SIZE; i++) {
    int try = (i + index) % TABLE_SIZE; // iterate from index % TABLE_SIZE until find null, time complexity kind of suck
    if(hash_table[try] == NULL) {
      return NULL;
    }
    if(hash_table[try] == DELETED_NODE) continue;
    if(strncmp(hash_table[try]->name, name, MAX_NAME)==0 ) {
      person *tmp = hash_table[try];
      hash_table[try] = DELETED_NODE;
      return tmp;
    };
  };

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

  char *n1 = "Jacob";
  char *n2 = "Hiyori";
  char *n3 = "Mpho";

  printf("done inserting the data\n");

  printf("table before\n");
  print_table();
  hash_table_delete(n3);

  printf("table after\n");
  print_table();

  person *tmp = hash_table_lookup(n1);
  if(tmp) {
    printf("found em! : %s\n", tmp->name);
  } else {
    printf("user %s not found!\n", n1);
  }

  tmp = hash_table_lookup(n2);
  if(tmp) {
    printf("found em! : %s\n", tmp->name);
  } else {
    printf("user %s not found!\n", n2);
  }

  print_table();
  tmp = hash_table_lookup(n3);  
  printf("%s", tmp);
  if(tmp) {
    printf("found em! : %s\n", tmp->name);
  } else {
    printf("user %s not found!\n", n3);
  }

  print_table();

  return 0;
};
