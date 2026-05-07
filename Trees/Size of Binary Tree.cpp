
class Solution {// TC ---> O(N)                                       SC ---> O(H)
  public:

    // Function to count total nodes in the tree
    int count(Node *root)
    {
        // Base Case:
        // If node is NULL, no node exists
        if(root == NULL)
        {
            return 0;
        }
        
        // Recursively count nodes in left subtree
        int left = count(root->left);
        
        // Recursively count nodes in right subtree
        int right = count(root->right);
        
        // Total nodes =
        // 1 (current node)
        // + left subtree nodes
        // + right subtree nodes
        return 1 + (left + right);
    }
    
    // Function to return size of binary tree
    int getSize(Node* root) {
        
        // If tree is empty
        if(root == NULL)
        {
            return 0;
        }
        
        // Call recursive function to count nodes
        return count(root);
    }
};

/*    NOTE : 

Start from root
      ↓
Count left subtree nodes
      ↓
Count right subtree nodes
      ↓
Add:
1 (current node) + left + right
      ↓
Return total size

*/
