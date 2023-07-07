class Node{
    public:
    int key, val;
    Node* prev = NULL, *next = NULL;
    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};

class LRUCache {
public:
    int size;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        //delete node;
    }
    
    void insert(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            int ans = node->val;
            remove(m[key]);
            m.erase(key);
            insert(new Node(key, ans));
            m[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            remove(m[key]);
            m.erase(key);
        }
        else if(m.size() == size){
            m.erase(tail->prev->key);
            remove(tail->prev);
        }
        insert(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */