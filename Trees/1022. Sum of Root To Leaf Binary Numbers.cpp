
class Solution {// TC ---> O(N)                              SC ---> O(N)
public:

    // Recursive function to calculate sum of all root-to-leaf binary numbers
    int solve(TreeNode *root, int val)
    {
        // Base case:
        // If node is NULL, it contributes 0 to the sum
        if(root == NULL)
        {
            return 0;
        }

        // Build the current binary number:
        // Multiply previous value by 2 (left shift in binary)
        // Add current node's value (0 or 1)
        val = (2 * val) + root->val;

        // If this is a leaf node (no left and right child)
        // That means we have formed a complete root-to-leaf binary number
        if(root->left == NULL && root->right == NULL)
        {
            return val;   // Return the formed number
        }

        // Recursively compute sum of left subtree
        int leftSum = solve(root->left, val);

        // Recursively compute sum of right subtree
        int rightSum = solve(root->right, val);

        // Total sum from both sides
        return leftSum + rightSum;
    }

    int sumRootToLeaf(TreeNode* root) {
        // Start recursion with initial binary value = 0
        return solve(root, 0);
    }
};
