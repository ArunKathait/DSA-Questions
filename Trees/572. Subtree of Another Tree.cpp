
class Solution {// TC ---> O(N * M)                           SC ---> O(H)
public:
    // Function to check whether two trees are identical
    bool isSame(TreeNode* p, TreeNode* q)
    {
        // Base Case:
        // If both nodes are NULL,
        // trees are identical till this path
        if(p == NULL && q == NULL)
        {
            return true;
        }

        // If one node is NULL
        // and the other is not,
        // trees are not identical
        if(p == NULL || q == NULL)
        {
            return false;
        }

        // If values of current nodes do not match
        if(p->val != q->val)
        {
            return false;
        }

        // Recursively check:
        // 1. Left subtree
        // 2. Right subtree
        // Both must be true
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }

    // Function to check whether subRoot
    // exists inside root tree
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If main tree becomes NULL,
        // subtree cannot exist
        if(root == NULL)
        {
            return false;
        }

        // Check if current subtree
        // is identical to subRoot
        if(isSame(root, subRoot))
        {
            return true;
        }

        // Otherwise search in:
        // 1. Left subtree
        // 2. Right subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

/* NOTE :

Start from root
      ↓
Compare current subtree with subRoot
      ↓
If identical → return true
      ↓
Else search left subtree
      ↓
Else search right subtree

*/
