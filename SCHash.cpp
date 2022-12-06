#include <string>
#include <cstring>
#include <vector>
#include <list>
#include "BoardGameOBJ/BoardGame.h"
using namespace std;

class SCHash{
    private: 
        struct item{
            string key;
            BoardGame value;
        };
        item* create_item(string& key, BoardGame& value);
        unsigned long hash_function(string& key); 
        // Each index maps to a list for SC resolution
        vector<list<item*>> hash_table; 
        int cap = 16;
        int b_size = 0;
        double l_factor = 0.75;
        // For both updated_table inserts and current hash_table inserts
        void private_insert(vector<list<item*>>& map, string key, BoardGame& value); 
        // Resize table for Load Factor
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
        // Search
        vector<BoardGame> find_all(string target);
}; 

typename SCHash::item* SCHash::create_item(string& key, BoardGame& value){
    item* new_item = new item;
    new_item->key = key;
    new_item->value = value;
    return new_item;
}

unsigned long SCHash::hash_function(string& key){
    // Follows Sum of ACII * 2137 % Capacity 
    unsigned long hash = 0;
    for(int i = 0; i < key.length(); i++){
        char a = key[i];
        hash += a;
    }
    hash = (hash*2137) % cap;
    return hash;
}

SCHash::SCHash(){
    for(int i = 0; i < cap; i++){
        list<item*> temp;
        hash_table.push_back(temp);
    }
}

SCHash::~SCHash(){
    // Loops through all indicies and deletes all item* in the list structure
    for(int i = 0; i < cap; i++){
        auto& block = hash_table[i];
        for (auto iter = block.begin(); iter != block.end(); iter++){
            delete(*iter);
            iter = --block.erase(iter);
        }
    }
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
            b_size--;
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
    auto& block = hash_table[index];
    for(auto iter = block.begin(); iter != block.end(); iter++){
        if((*iter)->key == key){
            b_size--;
            iter = block.erase(iter);
            break;
        }
    }
}

vector<BoardGame> SCHash::find_all(string target){
    vector<BoardGame> targets;
    for(int i = 0; i < hash_table.size(); i++){
        auto& block = hash_table[i];
        for(auto iter = block.begin(); iter != block.end(); iter++){
            if((*iter)->key.find(target) != string::npos){
                targets.push_back((*iter)->value);
            }
        }
    }
    return targets;
}
