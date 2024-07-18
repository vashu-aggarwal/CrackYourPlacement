class RandomizedCollection {
public:
    map<int,int> m;
    vector<int> v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        m[val]++;
        v.push_back(val);
        if(m[val]>1)
            return false;
        else
           return true;
    }
    
    bool remove(int val) {
        if(m[val]==0) 
           return false;
        else
        {
           m[val]--;
           for(auto it=v.begin();it!=v.end();it++)
           {
               if(*it==val)
               {
                   v.erase(it);
                   break;
               }
           }
           return true;
        }
    }
    
    int getRandom() {
        return *next(v.begin(),rand()%v.size());
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */