#include "implementation.c"
#include <assert.h>

int main(){

    unsigned int index = hash("a");
    struct HashTable *hashed =  create();
    

    add(hashed,"u",100);
    add(hashed,"a",31);



    struct HashTable* table = create();

    assert( find(table, "Test Key") == NULL);

    assert( add(table, "Test Key", 11) == true);

    assert( add(table, "Test Key", 11) == false);

    struct Binding* binding =  find(table, "Test Key");

    assert( binding != NULL &&  binding->value == 11);
    
    
   
    return 0;
}




  
    



