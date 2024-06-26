class LRUCache {
public:
    class Node{
        public:
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int key,int val)
        {
            this->val=val;
            this->key=key;
        }
        
    };
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node *>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node *newNode)
    {
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node *delNode)
    {
        Node *delNext=delNode->next;
        Node *delPrev=delNode->prev;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node *resNode=mp[key];
            int res=resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node *existingNode=mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */