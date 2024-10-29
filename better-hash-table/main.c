#include "hashtable.h"

typedef struct entry {
  char *key; // the key, like index in previous hash table
  void *object; // data
  struct entry *next; // for chaining
} entry;

typedef struct _hash_table {
  uint32_t size; // num of elements
  hash_function *hash;
  entry **elements; // arr of elements
} hash_table;

hash_table *hash_table_create(uint32_t size, hash_function *hf) {
  hash_table *ht = malloc(sizeof(*ht));
  ht->size = size;
  ht->hash = hf;
  // calloc zeros out the memory
  ht->elements = calloc(sizeof(entry*), ht->size);
  return ht;
};
void hash_table_destroy(hash_table *ht) {
  free(ht->elements);
  free(ht);
};

void hash_table_print(hash_table *ht) {
  printf("Start\n");
  for(uint32_t i = 0; i < ht->size; i++) {
    if(ht->elements[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else {
      printf("\t%i\t\n", i);
      entry *tmp = ht->elements[i];

      while(tmp != NULL) {
        printf("\"%s\"(%p) - ", tmp->key, tmp->object);
        tmp = tmp->next;
      };

      printf("\n"); 
    };

  };

  printf("End\n"); 
};

bool hash_table_insert(hash_table *ht, const char *key, void *obj);

void *hash_table_lookup(hash_table *ht, const char *key);

void *hash_table_delete(hash_table *ht, const char *key);

int main() {
  return 0;
}
