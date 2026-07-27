#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
};

class LRUCache: public Cache{
    protected:
        void moveToHead(Node* node)
        {
            if (node == head)
                return;
            if (node->prev != NULL)
                node->prev->next = node->next;
            if (node->next != NULL)
                node->next->prev = node->prev;
            if (node == tail)
                tail = node->prev;
            node->prev = NULL;
            node->next = head;
            head->prev = node;
            head = node;
        }

    public:
        LRUCache(int capacity)
        {
            cp = capacity;
            head = NULL;
            tail = NULL;
        }

        int get(int key) override
        {
            auto find = mp.find(key);
            if (find != mp.end())
            {
                Node* node = find->second;
                moveToHead(node);
                return find->second->value;
            }
            return -1;
        }

        void set(int key, int value) override
        {
            auto find = mp.find(key);
            if (find != mp.end())
            {
                Node* node = find->second;
                node->value = value;
                moveToHead(node);
            }
            else
            {
                if (mp.size() == cp && tail != NULL)
                {
                    mp.erase(tail->key);
                    Node* temp = tail;
                    if (tail->prev != NULL)
                    {
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                    else
                    {
                        head = tail = NULL;
                    }                    
                    delete temp;
                }
                Node* newNode = new Node(key, value);
                if (head == NULL)
                {
                    head = tail = newNode;
                }
                else
                {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                mp[key] = newNode;
            }
        }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}