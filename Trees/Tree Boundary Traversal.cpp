

class Solution {// TC--->O(N)                      SC--->O(H)
  public:
    // Utility function to check if a node is a leaf node
    bool isLeaf(Node *node)
    {
        // A node is leaf if both left and right are NULL
        if(node->left == NULL && node->right == NULL)
        {
            return true;
        }
        return false;
    }
    
    // Function to traverse the left boundary (excluding leaf nodes)
    void leftTraversal(Node *root, vector<int>& ans)
    {
        Node *current = root->left; // start from the left child
        
        // Move down the left boundary
        while(current)
        {
            // Add current node’s data if it’s not a leaf
            if(!isLeaf(current))
            {
                ans.push_back(current->data);
            }
            
            // Prefer moving left, if not possible move right
            if(current->left)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    
    // Function to traverse the right boundary (excluding leaf nodes)
    void rightTraversal(Node *root, vector<int>& ans)
    {
        Node *current = root->right; // start from the right child
        vector<int> temp; // temporary vector to reverse later
        
        while(current)
        {
            // Add to temp if not a leaf
            if(!isLeaf(current))
            {
                temp.push_back(current->data);
            }
            
            // Prefer moving right, if not possible move left
            if(current->right)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        
        // Reverse order of right boundary before adding to main ans
        for(int i = temp.size() - 1; i >= 0; i--)
        {
            ans.push_back(temp[i]);
        }
    }
    
    // Recursive function to add all leaf nodes
    void addLeaves(Node *root, vector<int>& ans)
    {
        // Base case: if leaf node, add it to ans
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        
        // Recur for left subtree
        if(root->left)
        {
            addLeaves(root->left, ans);
        }
        
        // Recur for right subtree
        if(root->right)
        {
            addLeaves(root->right, ans);
        }
    }
    
    // Main function to perform Boundary Traversal
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        // Empty tree case
        if(root == NULL)
        {
            return ans;
        }
        
        // Add root node only if it's not a leaf
        if(!isLeaf(root))
        {
            ans.push_back(root->data);
        }
        
        // Step 1: Add left boundary (top to bottom)
        leftTraversal(root, ans);
        
        // Step 2: Add all leaf nodes (left to right)
        addLeaves(root, ans);
        
        // Step 3: Add right boundary (bottom to top)
        rightTraversal(root, ans);
        
        // Return complete boundary traversal
        return ans;
    }
};

/* NOTE : 
          
🧠 Logic Summary

Boundary Traversal is done in three parts:

Left Boundary → All nodes on the left edge (excluding leaf nodes).

Leaf Nodes → All leaf nodes from left to right.

Right Boundary → All nodes on the right edge (excluding leaf nodes), but added in reverse order.

Final Output Order:
➡️ Root → Left Boundary → Leaf Nodes → Right Boundary (reversed)

*/
