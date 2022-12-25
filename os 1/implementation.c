#include "header.h"
// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



const int BUCKET_COUNT = 1024;

struct Binding{

    const char* key;
    int value;
    struct Binding* next;
};

 struct HashTable{

    struct Binding *buckets[1024];

};

struct HashTable* create(){

    struct HashTable *hashtable;

    hashtable = (struct HashTable*) malloc(sizeof(struct HashTable));

    for(int i = 0; i< BUCKET_COUNT;i++){
        hashtable->buckets[i] = (struct Binding*) malloc(sizeof(struct Binding));
        hashtable->buckets[i]->next= NULL;
    
    }

    if(hashtable == NULL){
        // printf("not created");
        return NULL;
    }

  
        // printf("hashTable created \n");
         
    

   
    

    return hashtable;
}


bool add (struct HashTable *table, const char *key, int value){
    
    unsigned int x = hash(key);
    struct Binding *bind ,*new_bind,*prev,*tmp2,*tmp;
    new_bind = intialize(key,value);
    tmp2 = find(table,key);

    if(tmp2 == NULL){
        prev = table->buckets[x]->next;
        table->buckets[x]->next = new_bind;
        new_bind->next = prev;
        // printf("intialized\n");
        return true;
    }
    
   else{
       bind = table->buckets[x];
       while(bind != NULL){
           if(bind->key == key){
               if(bind->value = value){
                   return false;
               }
               else{
                    bind->value = value;
            //    printf("linked ");
               return true;
               }
              

           }
           else{
               prev = bind;
               bind = bind->next;
           }
       }
    
   }

    return false;
    
}


struct Binding* intialize(const char *key,int value){
    struct Binding *nbind;
    nbind = (struct Binding*)malloc(sizeof(struct Binding));
    nbind->key = key;
    nbind->value = value;
    nbind->next = NULL;
    return nbind;

}

struct Binding* find(struct HashTable* table, const char* key){
     struct Binding *bind ,*prev;
     unsigned int d = hash(key);
     bind = table->buckets[d]->next;
     

    while(bind != NULL){

           if(bind->key == key){
               return bind;
           }

           else{
               prev = bind;
               bind = bind->next;
           }
}  
    
    return NULL;
} 


bool remove(struct HashTable* table, const char* key){
   unsigned int x = hash(key);
    struct Binding *bind ,*prev;
   
    bind = table->buckets[x]->next;
    prev = table->buckets[x];
    
       while(bind != NULL){
           if(bind->key == key){
            if(bind->next != NULL){
                 prev->next = bind->next;
                 bind = NULL;
                 free(bind);

                 return true;
            }
            if(bind->next == NULL){
                prev->next = NULL;
                free(bind);
                // printf("worked");
                return true;
            }
               return true;

           }
           else{
               prev = bind;
               bind = bind->next;
           }
       }
    
   

    return false;
}

  
void delete_table(struct HashTable* table){
   
struct Binding *bucket,*next_bucket;

for(int i = 0;i < BUCKET_COUNT; i++){

    bucket = table->buckets[i];
    next_bucket = table->buckets[i]->next;

    while(next_bucket != NULL){
        bucket->next = next_bucket->next;
        next_bucket = bucket->next;
        
    }
    
    free(next_bucket);
    table->buckets[i] = NULL;
    free(table->buckets[i]);

    
    
}
    free(table);
}

unsigned int hash(char const *key) {
    const int p = 31 ;
    
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (int i = 0; i< strlen(key);i++) {
            hash_value = (hash_value + (key[i] + 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
       
    }
    return hash_value % BUCKET_COUNT;
}





