#include <unordered_map>
using namespace std;

struct LinkNode {
    int key;
    int value;
    LinkNode* prev;
    LinkNode* succ;
    LinkNode(int k, int v)
        : key(k)
        , value(v)
        , prev(nullptr)
        , succ(nullptr) {};
    LinkNode()
        : key(-1)
        , value(-1)
        , prev(nullptr)
        , succ(nullptr) {};
};

class LRUCache {
public:
    LRUCache(int capacity)
        : capacity_(capacity)
        , size_(0)
    {
        head = new LinkNode();
        tail = new LinkNode();
        head->succ = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        auto iter = cache.find(key);
        if (iter == cache.end()) {
            return -1;
        } else {
            LinkNode* node = iter->second;
            move2head(node);
            return node->value;
        }
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end()) {
            LinkNode* node = cache[key];
            node->value = value;
            move2head(node);
        } else {
            if (size_ == capacity_) {
                LinkNode* removed = removeTail();
                cache.erase(removed->key);
                size_ -= 1;
                delete removed;
            }
            size_ += 1;
            LinkNode* node = new LinkNode(key, value);
            cache[key] = node;
            add2head(node);
        }
    }

private:
    void add2head(LinkNode* node)
    {
        node->prev = head;
        node->succ = head->succ;
        head->succ->prev = node;
        head->succ = node;
    }

    LinkNode* removeTail()
    {
        LinkNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    void removeNode(LinkNode* node)
    {
        node->prev->succ = node->succ;
        node->succ->prev = node->prev;
    }

    void move2head(LinkNode* node)
    {
        removeNode(node);
        add2head(node);
    }

private:
    //O(1)的复杂度，需要哈希表的辅助
    unordered_map<int, LinkNode*> cache;
    //需要伪头部和伪尾部
    LinkNode* head;
    LinkNode* tail;
    //需要一个值记录最大容量
    int capacity_;
    //需要一个值记录元素个数
    int size_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */