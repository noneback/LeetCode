/**
	难点在于设计数据结构，使用了hashMap和双向链表，把最近操作的节点放在一端，最不常用的放在另一端
	
**/


struct MListNode {
    int key;
    int val;   
    MListNode* pre;
    MListNode* next;
};

class LRUCache {

private:
        unordered_map<int,MListNode*> m;
        MListNode* head;
        MListNode* tail;
        int size = 0;
        int capacity;
        void changeToTail(MListNode* node) {
            
            MListNode* pre = node -> pre;
            MListNode* next = node -> next;
            pre -> next = next;
            next -> pre = pre;    
            
            tail -> pre -> next = node;
            node -> pre = tail -> pre;
            node -> next = tail;
            tail -> pre = node;
        }
public:
        LRUCache(int capacity) {
            this -> capacity = capacity;
            this -> head = new MListNode{};
            this -> tail = new MListNode{};
            head -> next = tail;
            tail -> pre = head;
        }
        
        int get(int key) {
            if (!m.count(key)) return -1;
            auto node = m[key];
            // put to tail
            changeToTail(node);
            return node -> val;
        }
        
        void put(int key, int value) {
            if (m.count(key)) {
                auto node = m[key];
                node -> val = value;
                changeToTail(node);
            } else {
                MListNode* node;
                if (size < capacity) {
                    size++;
                    // add a new node to tail
                    node = new MListNode{};
                    node -> val = value;
                    node -> key = key;
                } else {
                    // move head to tail
                    node = head -> next;
                    head -> next = node -> next;
                    node -> next -> pre = head;
                    auto it = m.find(node -> key);
                    m.erase(it);
                    node -> val = value;
                    node -> key = key;

                }
                
                tail -> pre -> next = node;
                node -> pre = tail -> pre;
                node -> next = tail;
                tail -> pre = node;

                m[key] = node;
            }

        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
