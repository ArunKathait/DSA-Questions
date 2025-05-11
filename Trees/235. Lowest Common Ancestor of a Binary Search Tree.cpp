
class Solution {// TC--->O(H)--->(i.e height of BST)                       SC--->O(H)--->Recursion Stack
public:
    // Function to find the Lowest Common Ancestor (LCA) of two nodes p and q in a Binary Search Tree (BST)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case: If the root is NULL, return NULL
        // This means we've reached the end of a branch without finding p or q
        if(root == NULL)
        {
            return NULL;
        }

        // Get the value of the current node (root)
        int currentVal = root->val;

        // If both p and q are greater than the current node value,
        // then the LCA must be in the right subtree
        if(currentVal < p->val && currentVal < q->val)
        {
            // Recurse on the right subtree
            return lowestCommonAncestor(root->right, p, q);
        }
        // If both p and q are smaller than the current node value,
        // then the LCA must be in the left subtree
        else if(currentVal > p->val && currentVal > q->val)
        {
            // Recurse on the left subtree
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            // If neither of the above conditions are true, it means p and q are on different sides of the current node
            // or one of them is equal to the current node.
            // Hence, the current node is the LCA of p and q.
            return root;
        }
    }
};
