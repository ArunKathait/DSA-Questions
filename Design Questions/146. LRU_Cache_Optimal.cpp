
class LRUCache {// TC ---> O(1)                                   SC ---> O(1)
public:
    
    // Node structure for Doubly Linked List
    class Node
    {
    public:
        int key, val;          // store key and value
        Node *prev;            // pointer to previous node
        Node *next;            // pointer to next node

        // Constructor to initialize node
        Node(int k,int v)
        {
            key = k;
            val = v;
            prev = next = NULL; // initially no connections
        }
    };

    // Dummy head and tail nodes (to simplify operations)
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    // HashMap to store key -> node address
    unordered_map<int,Node*> ump;

    int limit; // capacity of cache

    // Function to insert node right after head (Most Recently Used)
    void addNode(Node *newNode)
    {
        Node *oldNext = head->next; // store current first node

        head->next = newNode;       // connect head -> newNode
        newNode->next = oldNext;    // connect newNode -> oldNext

        newNode->prev = head;       // connect newNode <- head
        oldNext->prev = newNode;    // connect oldNext <- newNode
    }

    // Function to delete a node from list
    void deleteNode(Node *oldNode)
    {
        Node *oldPrev = oldNode->prev; // get previous node
        Node *oldNext = oldNode->next; // get next node

        oldPrev->next = oldNext;       // bypass oldNode (prev -> next)
        oldNext->prev = oldPrev;       // fix backward link
    }

    // Constructor
    LRUCache(int capacity) {
        limit = capacity;              // set capacity

        head->next = tail;             // initially head -> tail
        tail->prev = head;             // and tail <- head
    }
    
    // Get value for a key
    int get(int key) {
        // If key not present → return -1
        if(ump.find(key) == ump.end())
        {
            return -1;
        }

        Node *ansNode = ump[key];   // get node from map
        int ans = ansNode->val;     // store value

        // Move this node to front (MRU)
        ump.erase(key);             // remove from map (optional)
        deleteNode(ansNode);        // remove from current position
        addNode(ansNode);           // insert at front
        ump[key] = ansNode;         // reinsert in map

        return ans;                 // return value
    }
    
    // Insert or update key-value
    void put(int key, int value) {

        // If key already exists
        if(ump.find(key) != ump.end())
        {
            Node *oldNode = ump[key]; // get existing node
            ump.erase(key);           // remove from map
            deleteNode(oldNode);      // remove from list
        }

        // If cache is full → remove LRU node
        if(ump.size() == limit)
        {
            Node *lru = tail->prev;   // last node = least recently used
            ump.erase(lru->key);      // remove from map
            deleteNode(lru);          // remove from list
        }

        // Create new node
        Node *newNode = new Node(key,value);

        ump[key] = newNode;   // insert in map
        addNode(newNode);     // insert at front (MRU)
    }
};

/*         
         LRU Cache uses a HashMap for constant-time lookup and a Doubly Linked List to maintain usage order. 
         The most recently used element is kept at the front, and the least recently used at the back. On every access,
         we move the node to the front, and when capacity is exceeded, we remove the node from the back. This ensures O(1)
         time complexity for both get and put operations.

         🧠 🔹 Mental Picture : 

                head <-> MRU <-> ... <-> LRU <-> tail

         🎯 🔹 Final Quick Recall
               ---> HashMap = fast access
               ---> DLL = order maintain
               ---> Head = MRU
               ---> Tail = LRU
               ---> Remove from tail
               ---> Insert at head
*/
