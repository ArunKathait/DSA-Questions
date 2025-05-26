*********************************************APPROACH 1st(USING DFS)*********************************************

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    // Default constructor
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    // Constructor with value only
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    // Constructor with value and neighbor list
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {// TC--->O(N+E)                     SC--->O(N)
public:

    // Helper function to perform DFS and clone nodes
    Node* dfs(Node* node, unordered_map<Node*, Node*>& ump) {
        // Step 1: Clone the current node
        Node* cloneNode = new Node(node->val);

        // Step 2: Store this clone in the map
        ump[node] = cloneNode;

        // Step 3: Recurse for all neighbors
        for (auto& neighbor : node->neighbors) 
        {
            // If neighbor is already cloned, just link it
            if (ump.find(neighbor) != ump.end()) 
            {
                cloneNode->neighbors.push_back(ump[neighbor]);
            } 
            else 
            {
                // Else, recursively clone it and link the result
                cloneNode->neighbors.push_back(dfs(neighbor, ump));
            }
        }

        // Step 4: Return the cloned node
        return cloneNode;
    }

    // Main function to clone the graph
    Node* cloneGraph(Node* node) {
        // Base case: if the input graph is empty
        if (node == NULL) 
        {
            return NULL;
        }

        // Map to store already cloned nodes to avoid cycles
        unordered_map<Node*, Node*> ump;

        // Call DFS helper to start cloning from the given node
        return dfs(node, ump);
    }
};


************************************************APPROACH 2nd(USING BFS)*******************************************

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    // Default constructor
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    // Constructor with node value
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    // Constructor with node value and neighbor list
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {// TC--->O(N + E)                           SC--->O(N)
public:
    Node* cloneGraph(Node* node) {
        // Base case: if input node is NULL, return NULL
        if (node == NULL) 
        {
            return NULL;
        }

        // Hash map to store original node -> cloned node mapping
        unordered_map<Node*, Node*> ump;

        // Queue for BFS traversal
        queue<Node*> q;

        // Step 1: Create clone for the starting node and push it to queue
        Node* cloneNode = new Node(node->val);
        ump[node] = cloneNode;
        q.push(node);

        // Step 2: BFS traversal of the graph
        while (!q.empty()) 
        {
            // Get the front node
            Node* current = q.front(); 
            q.pop();

            // Traverse all neighbors of current node
            for (auto& neighbor : current->neighbors) 
            {
                // If this neighbor is not yet cloned
                if (ump.find(neighbor) == ump.end()) 
                {
                    // Create a clone and map it
                    Node* clonedNeighbor = new Node(neighbor->val);
                    ump[neighbor] = clonedNeighbor;

                    // Push the original neighbor to the queue for BFS
                    q.push(neighbor);
                }

                // Link the cloned neighbor to the cloned current node
                ump[current]->neighbors.push_back(ump[neighbor]);
            }
        }

        // Step 3: Return the clone of the original input node
        return cloneNode;
    }
};
