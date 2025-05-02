

class Solution {// TC--->O(N)                         SC--->O(H)--->Height of Tree
public:
// Helper function to recursively check for a root-to-leaf path with a given sum
    bool solve(TreeNode *root,int sum,int targetSum)
    {
         // Base case: if node is null, no path exists
        if(root == NULL)
        {
            return false;
        }

        // Add current node's value to the current path sum
        sum += root->val;

        // If current node is a leaf (no left and right children)
        if(root->left == NULL && root->right == NULL)
        {
            // Check if the current path sum equals the target sum
            if(sum == targetSum)
            {
                // A valid path is found
                return true;
            }
            // It's a leaf, but path sum doesn't match
            return false;
        }

        // Recur for left and right subtree
        bool leftSide = solve(root->left,sum,targetSum);
        bool rightSide = solve(root->right,sum,targetSum);

        // If any of the two subtrees return true, we return true
        return leftSide || rightSide;
    }

    // Main function called by user to start recursion
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Initialize path sum to 0
        int sum = 0;

        // Start recursion from root
        return solve(root,sum,targetSum);
    }
};
