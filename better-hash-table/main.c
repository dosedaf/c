#include "hashtable.h"

typedef struct entry {
  char *key;
  size_t keylen;
  void *object;
  struct entry *next;
} entry;

typedef struct _hash_table {
  uint32_t size;
  hash_function *hash;
  entry **elements;
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

void hash_table_print(hash_table *hf);
bool hash_table_insert(hash_table *ht, const char *key, size_t keylen,
                       void *obj);
void *hash_table_lookup(hash_table *ht, const char *key, size_t keylen);
void *hash_table_delete(hash_table *ht, const char *key, size_t keylen);

int main() {
  return 0;
}
