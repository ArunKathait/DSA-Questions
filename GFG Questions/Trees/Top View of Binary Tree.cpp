
/*
class Node {
  public:
    int data;        // value stored in the node
    Node* left;      // pointer to left child
    Node* right;     // pointer to right child

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {// TC ---> O(N log N)                                   SC ---> O(N)
  public:
    vector<int> topView(Node *root) {

        // If the tree is empty, return an empty result
        if(root == NULL)
        {
            return {};
        }

        // map<HD , nodeValue>
        // HD = Horizontal Distance from root
        // map keeps keys sorted automatically
        map<int,int> ump;

        // Queue for BFS traversal
        // pair<Node*, HD>
        queue<pair<Node*,int>> q;

        // Push the root node with horizontal distance = 0
        q.push({root,0});

        // Start BFS traversal
        while(!q.empty())
        {
                // Get the front element from queue
                auto node = q.front().first;  // current node
                int level = q.front().second; // horizontal distance
                q.pop();

                // If this horizontal distance is seen for the first time
                // store this node value
                // because the first node encountered in BFS
                // will be the topmost node for that HD
                if(ump.find(level) == ump.end())
                {
                    ump[level] = node->data;
                }

                // If left child exists
                // push it with HD - 1
                if(node->left)
                {
                    q.push({node->left,level-1});
                }

                // If right child exists
                // push it with HD + 1
                if(node->right)
                {
                    q.push({node->right,level+1});
                }
        }

        // Vector to store the final top view
        vector<int> ans;

        // map stores keys in sorted order
        // so iteration will automatically give left → right view
        for(auto &it:ump)
        {
            ans.push_back(it.second);
        }

        // Return the top view
        return ans;
    }
};

/*
  
✅ Key idea

First node seen at each horizontal distance = Top View node

*/
