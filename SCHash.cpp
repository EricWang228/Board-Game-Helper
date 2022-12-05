#include <string>
#include <vector>
#include "BoardGameOBJ/BoardGame.h"
using namespace std;


class SCHash{
    public:
    struct item{
        string key;
        BoardGame value;
    };
    private:
        BoardGame* hash_table;
        int capacity;
        int bucket_size;
        long load_factor;
        item* create_item(string key, BoardGame& value);
    public:
        
}; 

typename SCHash::item* SCHash::create_item(string key, BoardGame& value){
    item* new_item = new item;
    new_item->key = key;
    new_item->value = value;
    return new_item;
}