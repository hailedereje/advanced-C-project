#include <stdbool.h>
struct HashTable* create();
struct Binding* intialize(const char *key,int value);
unsigned int hash(const char* key);
bool add(struct HashTable* table, const char* key, int value);
struct Binding* find(struct HashTable* table, const char* key);
bool remove(struct HashTable* table, const char* key);
void delete_table(struct HashTable* table);


