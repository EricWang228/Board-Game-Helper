
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
        vector<list<item*>> hash_table; // SC collion resolution
        int cap;
        int b_size ;
        double l_factor;
        void private_insert(vector<list<item*>>& map, string key, BoardGame& value);
        vector<list<item*>> update_table();
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
    /*
    // Converts key to char*
    char* temp = new char[key.length()-1];
    strcpy(temp, key.c_str());
    unsigned long hash = 0;
    for(int i = 0; temp[i]; i++){
        hash += temp[i];
    }
    // Deletes the allocated space
    delete[] temp;
    hash = hash % cap;
    return hash;
    */
    unsigned long hash = 0;
    for(int i = 0; i < key.length(); i++){
        char a = key[i];
        int temp = (int)a;
        hash += temp;
    }
    hash = hash % cap;
    return hash;
}

SCHash::SCHash(){
    cap = 4;
    b_size = 0;
    l_factor = 0.75;
    for(int i = 0; i < cap; i++){
        list<item*> temp;
        hash_table.push_back(temp);
    }
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

void SCHash::private_insert(vector<list<item*>>& map, string key, BoardGame& value){
    unsigned long index = hash_function(key);
    b_size++;
    auto& block = map[index];
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

vector<list<SCHash::item*>> SCHash::update_table(){
    // Double capacity
    cap = 2*cap;
    // Make new table with double the size
    vector<list<item*>> new_table;
    for(int i = 0; i < cap; i++){
        list<item*> temp;
        new_table.push_back(temp);
    }
    for(int j = 0; j < hash_table.size(); j++){
        auto& block = hash_table[j];
        for(auto iter = block.begin(); iter != block.end(); iter++){
            private_insert(new_table, (*iter)->key, (*iter)->value);
            b_size--;
            delete (*iter);
            iter = --block.erase(iter);
        }
    }
    return new_table;
}

void SCHash::insert(string key, BoardGame& value){
    if(((double)b_size/cap) >= l_factor){ // Load Factor reached double size of hashmap
        hash_table = update_table();
        private_insert(hash_table, key, value);
    }
    else{
        private_insert(hash_table, key, value);
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