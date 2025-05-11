
class Solution {// TC--->O(N)                             SC--->O(h)--->Height of Tree
public:
    // Function to find the Lowest Common Ancestor (LCA) of two nodes p and q in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case: If the root is NULL or if the root is either p or q, return root
        // This means we have reached a leaf node, or we've found either p or q
        if(root == NULL || root == p || root == q)
        {
            return root;
        }

        // Recursively search for p and q in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If the left subtree returns NULL, it means neither p nor q was found on the left side
        // Hence, return the result from the right subtree
        if(left == NULL)
        {
            return right;
        }
        // If the right subtree returns NULL, it means neither p nor q was found on the right side
        // Hence, return the result from the left subtree
        else if(right == NULL)
        {
            return left;
        }
        else
        {
            // If both left and right return non-NULL, it means p and q were found in different subtrees
            // So, the current node (root) is the LCA (Lowest Common Ancestor) of p and q
            return root;
        }
    }
};
