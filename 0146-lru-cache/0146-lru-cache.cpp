class LRUCache {
public:
    class Node{
        public:
           int key;
           int val;
           Node* prev;
           Node* next;
           
           Node(int key,int val){
             this->key=key;
             this->val=val;
           }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insertNode(Node* temp){
      
       head->next->prev=temp;
        temp->next=head->next;
        temp->prev=head;
        head->next=temp;
    }

    void deleteNode(Node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode=mp[key];
            int ans=resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            insertNode(resNode);
           
            mp[key]= head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if(mp.size()==cap){
           
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        insertNode(new Node(key,value));
        
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */