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
        // Variables
        int cap = 16;
        int table_size = 0;
        double l_factor = 0.75;
        // Container
        vector<list<item*>> hash_table; 
        item* create_item(string& key, BoardGame& value);
        unsigned long hash_function(string& key); 
        BoardGame empty;
        // Helper for insert, supports both regular and updated inserts
        void private_insert(vector<list<item*>>& map, string key, BoardGame& value); 
        // Resize table for Load Factor
        vector<list<item*>> update_table(); 
        // For default returns
    public:
        // Default Constructor
        SCHash();
        // Destructor
        ~SCHash();
        // Getters
        int capacity();
        int size();
        double load_factor();
        // Insertion and deletion 
        void insert(string key, BoardGame& value);
        void remove(string key);
        // Search
        void find_all(string target);
        BoardGame find(string target);
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

void SCHash::private_insert(vector<list<item*>>& map, string key, BoardGame& value){
    // Gets hashed index
    unsigned long index = hash_function(key);
    table_size++;
    // Finds the Linked list at the index
    auto& Bucket = map[index];
    bool keyExists = false;
    // Runs through the Linked List at the Bucket index, checking for existing keys
    for(auto iter = Bucket.begin(); iter != Bucket.end(); iter++){
        if((*iter)->key == key){
            keyExists = true;
            table_size--;
            (*iter)->value = value;
            break;
        }
    }
    // Otherwise append to end of Linked List (Seperate Chaining)
    if(!keyExists){
        Bucket.emplace_back(create_item(key, value));
    }
}

vector<list<SCHash::item*>> SCHash::update_table(){
    cap = 2*cap;
    // Make new table with double the size
    vector<list<item*>> new_table;
    for(int i = 0; i < cap; i++){
        list<item*> temp;
        new_table.push_back(temp);
    }
    // Rehashes all items in the old table into the new table
    for(int j = 0; j < hash_table.size(); j++){
        auto& Bucket = hash_table[j];
        for(auto iter = Bucket.begin(); iter != Bucket.end(); iter++){
            private_insert(new_table, (*iter)->key, (*iter)->value);
            table_size--;
            // Free memory
            delete (*iter);
            iter = --Bucket.erase(iter);
        }
    }
    return new_table;
}

SCHash::SCHash(){
    // Allocate space for Map
    for(int i = 0; i < cap; i++){
        list<item*> temp;
        hash_table.push_back(temp);
    }
}

SCHash::~SCHash(){
    // Loops through all indicies and deletes all item* in the list structure
    for(int i = 0; i < cap; i++){
        auto& Bucket = hash_table[i];
        for (auto iter = Bucket.begin(); iter != Bucket.end(); iter++){
            delete(*iter);
            iter = --Bucket.erase(iter);
        }
    }
}

int SCHash::capacity(){
    return cap;
}

int SCHash::size(){
    return table_size;
}

double SCHash::load_factor(){
    return l_factor;
}

void SCHash::insert(string key, BoardGame& value){
    // Determines if table needs to be refactored to new size
    if(((double)table_size/cap) >= l_factor){ 
        hash_table = update_table();
        private_insert(hash_table, key, value);
    }
    else{
        private_insert(hash_table, key, value);
    }
}

void SCHash::remove(string key){
    unsigned long index = hash_function(key);
    auto& Bucket = hash_table[index];
    for(auto iter = Bucket.begin(); iter != Bucket.end(); iter++){
        if((*iter)->key == key){
            table_size--;
            iter = Bucket.erase(iter);
            break;
        }
    }
}

void SCHash::find_all(string target){
    // vector<BoardGame> vals;
    // Loops though all 
    for(int i = 0; i < hash_table.size(); i++){
        auto& Bucket = hash_table[i];
        for(auto iter = Bucket.begin(); iter != Bucket.end(); iter++){
            if((*iter)->key.find(target) != string::npos){
                (*iter)->value.print_details();
            }
        }
    }
    // return vals;
}

BoardGame SCHash::find(string target){
    unsigned long index = hash_function(target);
    auto& Bucket = hash_table[index];
    // Searches in potential bucket for target first
    for(auto iter = Bucket.begin(); iter != Bucket.end(); iter++){
        if((*iter)->key.find(target) != string::npos){
                return (*iter)->value;
            } 
    }
    // Target is not in potential bucket
    for(int i = 0; i < hash_table.size(); i++){
        // Bucket is Searched already
        if(i = index)
            continue;
        Bucket = hash_table[i];
        for(auto iter = Bucket.begin(); iter != Bucket.end(); iter++){
            if((*iter)->key.find(target) != string::npos){
                return (*iter)->value;
            }
        }
    }
    // Nothing is found
    return empty;
}


