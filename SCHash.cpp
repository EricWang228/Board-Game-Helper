
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include "BoardGameOBJ/BoardGame.h"
using namespace std;


class SCHash{
    public:
        struct item{
            string key;
            BoardGame value;
        };
    private:
        item* create_item(string& key, BoardGame& value);
        unsigned long hash_function(string& key); 
        // Default map items
        list<item*> hash_table[16]; // SC collion resolution
        int cap;
        int b_size ;
        double l_factor;

    public:
        // Default Constructor
        SCHash();
        // Destructor
        ~SCHash();
        // Getters
        int capacity();
        int bucket_size();
        double load_factor();
        // Insertion and deletion 
        void insert(string key, BoardGame& value);
        void remove(string key);

}; 

typename SCHash::item* SCHash::create_item(string& key, BoardGame& value){
    item* new_item = new item;
    new_item->key = key;
    new_item->value = value;
    return new_item;
}

unsigned long SCHash::hash_function(string& key){
    // Converts key to char*
    char* temp = new char[key.length()-1];
    strcpy(temp, key.c_str());
    unsigned long hash = 0;
    for(int i = 0; temp[i]; i++){
        hash += temp[i];
    }
    // Deletes the allocated space
    hash = hash % cap;
    return hash;
}

SCHash::SCHash(){
    cap = 16;
    b_size = 0;
    l_factor = 0.75;
}

SCHash::~SCHash(){
    
}

// Getters
int SCHash::capacity(){
    return cap;
}

int SCHash::bucket_size(){
    return b_size;
}

double SCHash::load_factor(){
    return l_factor;
}

void SCHash::insert(string key, BoardGame& value){
    unsigned long index = hash_function(key);
    b_size++;
    auto& block = hash_table[index];
    bool keyExists = false;
    for(auto iter = block.begin(); iter != block.end(); iter++){
        if((*iter)->key == key){
            keyExists = true;
            (*iter)->value = value;
            break;
        }
    }
    if(!keyExists){
        block.emplace_back(create_item(key, value));
    }
}

void SCHash::remove(string key){
    unsigned long index = hash_function(key);
    b_size++;
    auto& block = hash_table[index];
    bool keyExists = false;
    for(auto iter = block.begin(); iter != block.end(); iter++){
        if((*iter)->key == key){
            keyExists = true;
            iter = block.erase(iter);
            break;
        }
    }
}