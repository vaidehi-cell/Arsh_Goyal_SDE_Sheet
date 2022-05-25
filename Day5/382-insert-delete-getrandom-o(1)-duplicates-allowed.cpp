class RandomizedCollection {
public:
    vector<int> list;
    unordered_map<int, set<int>> mp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        mp[val].insert(list.size());
        list.push_back(val);
        if(mp[val].size() == 1)
            return true;
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end() && mp[val].size())
        {
            int x = *mp[val].begin();
            mp[val].erase(x);
            if(mp[val].size() == 0)
                mp.erase(val);
            if(mp.size() > 0)
            {
                mp[list[list.size()-1]].insert(x);
                mp[list[list.size()-1]].erase(list.size()-1);
                swap(list[x], list[list.size()-1]);   
            }
            list.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = list.size();
        int r = rand();
        if(n > 0)
            return list[r % n];
        else 
            return -1;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
