//146. LRU Cache
class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *prev;
        node *next;
        node(int key_, int val_)
        {
            key = key_;
            val = val_;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node *newnode)
    {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
    }
    void deletenode(node *delnode)
    {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
        //delete(delnode);
    }
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            node *resnode = mp[key];
            int res = resnode->val;
            deletenode(resnode);
            addnode(resnode);
            mp.erase(key);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            node *exnode = mp[key];
            mp.erase(key);
            deletenode(exnode);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */