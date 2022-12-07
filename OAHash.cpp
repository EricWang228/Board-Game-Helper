#include <string>
#include <cstring>
#include <vector>
#include "BoardGameOBJ/BoardGame.h"
using namespace std;

class OAHash{
    private: 
        struct item{
            string key;
            BoardGame value;
        };
        // Variables and Parameters
        int cap = 16;
        int table_size = 0;
        double l_factor = 0.75;   
        // Container
        vector<item*> hash_table;
        BoardGame empty;

        item* create_item(string& key, BoardGame& value);
        unsigned long hash_function(string& key);
        void private_insert(vector<item*>& map, string key, BoardGame value);
        vector<item*> update_table(); 
    public:
        // Constructor and Destructor
        OAHash();
        ~OAHash();
        // Getters
        int capacity();
        int size();
        double load_factor();
        // Insertion and Deletion
        void insert(string key, BoardGame& value);
        void remove(string key);
        // Searches
        void find(string target);
        void find_all(string target);
        void find_all_year(string target);
        void find_all_minPlayers(string target);
        void find_all_maxPlayers(string target);
        void find_all_age(string target);
};

typename OAHash::item* OAHash::create_item(string& key, BoardGame& value){
    item* new_item = new item;
    new_item->key = key;
    new_item->value = value;
    return new_item;
}

unsigned long OAHash::hash_function(string& key){
    // Follows Sum of ACII * 2137 % Capacity 
    unsigned long hash = 0;
    for(int i = 0; i < key.length(); i++){
        char a = key[i];
        hash += a;
    }
    hash = (hash*2137) % cap;
    return hash;
}

void OAHash::private_insert(vector<item*>& map, string key, BoardGame value){
    // Gets hashed index
    unsigned long index = hash_function(key);
    table_size++;
    for(int i = index; i < cap; i++){
        // Bucket is empty
        if(map[i] == nullptr){
            map[i] = create_item(key, value);
            // break when inserted
            break;
        }
        // Bucket is not empty, check for same key
        if(map[i]->key == key){
            delete map[i];
            map[i] = create_item(key, value);
            break;
        }
        // reset to front 
        if(i == 15){
            i = 0;
        }
    }    
}

vector<OAHash::item*> OAHash::update_table(){
    cap = 2*cap;
    // make new table with double the size
    vector<item*> new_table;
    for(int i = 0; i < cap; i++){
        item* temp = nullptr;
        new_table.push_back(temp);
    }
    // Rehashes and inserts all values inside new table
    for(int j = 0; j < hash_table.size(); j++){
        if(hash_table[j] != nullptr){
            private_insert(new_table, hash_table[j]->key, hash_table[j]->value);
            table_size--;
            // Free memeory
            delete hash_table[j];
        }
    }
    return new_table;
}

OAHash::OAHash(){
    for(int i = 0; i < cap; i++){
        item* temp = nullptr;
        hash_table.push_back(temp);
    }
}

OAHash::~OAHash(){
    for(int i = 0; i < cap; i++){
        delete hash_table[i];
    }
}

int OAHash::capacity(){
    return cap;
}

int OAHash::size(){
    return table_size;
}

double OAHash::load_factor(){
    return l_factor;
}

void OAHash::insert(string key, BoardGame& value){
    // Determines if table needs to be refactored to new size
    if(((double)table_size/cap) >= l_factor){ 
        hash_table = update_table();
        private_insert(hash_table, key, value);
    }
    else{
        private_insert(hash_table, key, value);
    }
}

void OAHash::remove(string key){
    unsigned long index = hash_function(key);
    for(int i = index; i < cap; i++){
        if(hash_table[index] == nullptr){
            // break when vals is not inside map
            break;
        }
        // Bucket is not empty, check for same key
        if(hash_table[index]->key == key){
            delete hash_table[index];
            break;
        }
        // reset to front 
        if(i == 15){
            i = 0;
        }
    }
}

void OAHash::find(string target){
    // Go to potential index first and continue from there
    unsigned long index = hash_function(target);
    for(int i = index; i < cap; i++){
        // Target not found
        if(hash_table[index] == nullptr){
            break;
        }
        // Bucket is filled, check if target is the right one
        if(hash_table[index]->key.find(target) != string::npos){
            hash_table[index]->value.print_details();
        }
        // reset to front 
        if(i == 15){
            i = 0;
        }
    }
}

void OAHash::find_all(string target){
    for(int i = 0; i < cap; i++){
        if(hash_table[i] != nullptr){
            if(hash_table[i]->key.find(target) != string::npos){
                hash_table[i]->value.print_details();
            }
        }
    }
}

void OAHash::find_all_year(string target){
    for(int i = 0; i < cap; i++){
        if(hash_table[i] != nullptr){
            if(hash_table[i]->value.get_year() == target){
                hash_table[i]->value.print_details();
            }
        }
    }
}

void OAHash::find_all_minPlayers(string target){
    int max = stoi(target);
    for(int i = 0; i < cap; i++){
        if(hash_table[i] != nullptr){
            if(max == 10){
                if(hash_table[i]->value.get_min_player() >= max){
                    hash_table[i]->value.print_details();
                }
            }
            else if(hash_table[i]->value.get_min_player() == max){
                hash_table[i]->value.print_details();
            }
        }
    }
}

void OAHash::find_all_maxPlayers(string target){
    int max = stoi(target);
    for(int i = 0; i < cap; i++){
        if(hash_table[i] != nullptr){
            if(max == 10){
                if(hash_table[i]->value.get_max_players() >= max){
                    hash_table[i]->value.print_details();
                }
            }
            else if(hash_table[i]->value.get_max_players() == max){
                hash_table[i]->value.print_details();
            }
        }
    }
}

void OAHash::find_all_age(string target){
    int max = stoi(target);
    for(int i = 0; i < cap; i++){
        if(hash_table[i] != nullptr){
            if(max == 10){
                if(hash_table[i]->value.get_age() >= max){
                    hash_table[i]->value.print_details();
                }
            }
            else if(hash_table[i]->value.get_age() == max){
                hash_table[i]->value.print_details();
            }
        }
    }
}
