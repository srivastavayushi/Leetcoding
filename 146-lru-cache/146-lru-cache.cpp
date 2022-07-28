class LRUCache {
private:
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>mpp;
    int size;
public:
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        l.splice(l.begin(),l,mpp[key]);
        return mpp[key]->second;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            mpp[key]->second = value;
            l.splice(l.begin(),l,mpp[key]);
            return;
            
        }
        if(size == l.size()){
            auto d_node = l.back().first;
            l.pop_back();
            mpp.erase(d_node);
        }
        
        l.push_front({key,value});
        mpp[key] = l.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */