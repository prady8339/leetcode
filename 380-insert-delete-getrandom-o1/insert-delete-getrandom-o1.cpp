class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> un;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!un.count(val)){
            v.push_back(val);
            un[val] = v.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = un.find(val);
        if(it != un.end()){
            v[it->second] = v.back();
            v.pop_back();
            un[v[it->second]] = it->second;
            un.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */