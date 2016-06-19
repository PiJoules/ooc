#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/**
 * Macros
 */
#define CAST(cls, obj) ((cls*) obj)
#define CALL(cls, obj, method, ...) CAST(cls, obj)->method(obj, ##__VA_ARGS__)

#define CLASS_PROPERTIES \
    size_t size; \
    size_t ref_count;

//    void (*del)(hashtable_t* self);


/**
 * Declarations
 */
typedef void* Any;
typedef struct entry_s entry_t;
typedef struct hashtable_s hashtable_t;

void default_del(hashtable_t* self);

hashtable_t* ht_create(size_t size);
void ht_decref(hashtable_t* hashtable);
size_t hash(char* key);
size_t ht_hash(hashtable_t* hashtable, char* key);
entry_t* ht_pair(char* key, Any value);
void ht_set(hashtable_t* hashtable, char* key, Any value);
Any ht_get(hashtable_t* hashtable, char* key);

typedef struct {
    CLASS_PROPERTIES
} ClassProperties;


/**
 * Definitions
 */

struct entry_s {
    char* key;
    Any value;
    entry_t* next;
};

struct hashtable_s {
    CLASS_PROPERTIES
    entry_t** table;
};

void default_del(hashtable_t* self){}

hashtable_t* ht_create(size_t size){
    // Allocate for table
    hashtable_t* hashtable = (hashtable_t*)malloc(sizeof(hashtable_t));

#ifdef DEBUG
    assert(hashtable);
#endif

    // Allocate pointers to head nodes
    hashtable->table = (entry_t**)malloc(sizeof(entry_t*) * size);

#ifdef DEBUG
    assert(hashtable->table);
#endif

    // Set default values to null
    for (size_t i = 0; i < size; i++){
        hashtable->table[i] = NULL;
    }
    hashtable->size = size;
    hashtable->ref_count = 1;
    //hashtable->del = default_del;
    return hashtable;
}


/**
 *
 */
void ht_decref(hashtable_t* hashtable){
#ifdef DEBUG
    assert(hashtable->ref_count > 0);
#endif
    hashtable->ref_count--;

    if (!hashtable->ref_count){
        for (size_t i = 0; i < hashtable->size; i++){
            entry_t* entry = hashtable->table[i];
            if (entry){
                hashtable_t* value = CAST(hashtable_t, entry->value);
                if (value){
                    Any del_method = ht_get(value, "del");
                    if (del_method){
                        
                    }
                    ht_decref(value);

                    // Free entries
                    free(entry->key);
                    free(entry);
                }
            }
        }

        // Free head
        free(hashtable->table);

        // Free table
        free(hashtable);
    }
}

/**
 * Slight change from
 * http://stackoverflow.com/a/7666577/2775471
 * using size_t instead of unsigned long.
 */
size_t hash(char* key){
    size_t hashval = 5381;
    size_t c;
    while ((c = *(key++))){
        hashval = ((hashval << 5) + hashval ) + c;
    }
    return hashval;
}


size_t ht_hash(hashtable_t* hashtable, char* key){
    return hash(key) % hashtable->size;
}


entry_t* ht_pair(char* key, Any value){
    entry_t* pair = (entry_t*)malloc(sizeof(entry_t));

#ifdef DEBUG
    assert(pair);
#endif

    size_t key_len = strlen(key);
    pair->key = (char*)malloc(sizeof(char) * key_len + 1);
    pair->key[key_len] = '\0';

#ifdef DEBUG
    assert(pair->key);
#endif

    strncpy(pair->key, key, strlen(key));
    pair->value = value;
    pair->next = NULL;
    return pair;
}


void ht_set(hashtable_t* hashtable, char* key, Any value){
    size_t bin = ht_hash(hashtable, key);
    entry_t* next = hashtable->table[bin];
    entry_t* last = NULL;
    CAST(hashtable_t, value)->ref_count++;

    // Keep adjusting until the current or next key is empty
    while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0) {
        last = next;
        next = next->next;
    }

    if (next != NULL && next->key != NULL && strcmp( key, next->key ) == 0) {
        // Pair exists. Replace.
        ht_decref(next->value);
        next->value = value;
    }
    else {
        // Pair does not exist. Create new one.
        entry_t* pair = ht_pair(key, value);
        
        if (next == hashtable->table[bin]){
            // At the start of the linked list in this bin
            pair->next = next;
            hashtable->table[bin] = pair;
        }
        else if (next == NULL){
            // At the end of the linked list in this bin
            last->next = pair;
        }
        else {
            // In the middle of the list
            pair->next = next;
            last->next = pair;
        }
    }
}


Any ht_get(hashtable_t* hashtable, char* key){
    size_t bin = ht_hash(hashtable, key);
    entry_t* pair = hashtable->table[bin];
    // Step through the bin, looking for the value.
    while (pair != NULL && pair->key != NULL && strcmp(key, pair->key) > 0) {
        pair = pair->next;
    }

    // Did we actually find anything?
    if (pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0) {
        return NULL;
    }
    else {
        return pair->value;
    }
}


/**
 * Entry point.
 */
int main(int argc, char* argv[]){
#ifdef DEBUG
    printf("DEBUG flag set.\n");
#endif

    hashtable_t* ht = ht_create(100);
    hashtable_t* ht2 = ht_create(10);
    hashtable_t* ht3 = ht_create(11);
    hashtable_t* ht4 = ht_create(12);
    hashtable_t* ht5 = ht_create(13);

    /**
     * Test set
     */
    ht_set(ht, "some key", ht2);
    ht_set(ht, "some key2", ht3);
    ht_set(ht, "some key", ht4);
    ht_set(ht4, "nested", ht5);
    ht_set(ht5, "nested2", ht2);
    ht_set(ht4, "nested2", ht2);

    ht_decref(ht);
    ht_decref(ht2);
    ht_decref(ht5);
    ht_decref(ht3);
    ht_decref(ht4);


    return 0;
}

