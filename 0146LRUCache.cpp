// self defined double linked list
// Or you can use the built-in list, and push_front(), erase(), splice() function
struct Dlinks{
    int key, value;
    Dlinks *prev, *next;
    Dlinks():key(0),value(0),prev(nullptr),next(nullptr){}
    Dlinks(int k,int v): key(k),value(v),prev(nullptr),next(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        len = 0;
        head->next = end;
        end->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        auto found = cache.find(key);
        if(found==cache.end()) return -1;
        moveToHead(found->second);
        return found->second->value;
    }
    
    void put(int key, int value) {
        auto found = cache.find(key);
        if(found!=cache.end()){ // update it
            moveToHead(found->second);
            found->second->value = value;
            return ;
        }
        if(len>=cap){ //need to remove
            auto last = getLast();
            cache.erase(last->key);
            delete last;
            len --;
        }
        // add a new node
        Dlinks *node = new Dlinks(key, value);
        addNode(node);
        cache.insert({key, node});
        len ++;
    }
    
    void addNode(Dlinks *node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Dlinks *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveToHead(Dlinks *node){
        removeNode(node);
        addNode(node);
    }
    
    Dlinks* getLast(){
        auto last = end->prev;
        removeNode(last);
        return last;
    }
    
    
private:
    int len, cap;
    Dlinks dl;
    unordered_map<int, Dlinks*> cache;
    Dlinks *head = new Dlinks();
    Dlinks *end = new Dlinks();
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*
class LRUCache {
public:
    LRUCache(int capacity) {
        len = capacity;
        cache.clear();
        time_stamp.clear();
        cnt = 0;
    }
    
    int get(int key) {
        cnt ++;
        auto found = cache.find(key);
        if(found == cache.end()) return -1;
        else{
            auto result = std::find_if(
            time_stamp.begin(),
            time_stamp.end(),
            [key](const auto& mo) {return mo.second == key; });
            time_stamp.erase(result);
            time_stamp.insert({cnt, key});
            return found->second;
        }
    }
    
    void put(int key, int value) {
        cnt ++;
        auto found = cache.find(key);
        if(found != cache.end()) { // exist, update it
            found->second = value;
            
            auto result = std::find_if(
            time_stamp.begin(),
            time_stamp.end(),
            [key](const auto& mo) {return mo.second == key; });
            time_stamp.erase(result);
            time_stamp.insert({cnt, key});
            
            return;
        }
        if(cache.size() == len){ //buffer full ==> page fault, remove oldest one
            cache.erase(time_stamp.begin()->second);
            time_stamp.erase(time_stamp.begin());
        }
        // now, add new value
        time_stamp.insert({cnt, key});
        cache.insert({key, value});
    }
private:
    int len=0, cnt = 0;
    unordered_map<int, int> cache;
    map<int, int> time_stamp;   
};
*/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
