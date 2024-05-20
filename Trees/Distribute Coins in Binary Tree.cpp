class Solution {// TC--->O(N)                SC--->O(N)
public:
    // Helper function to calculate the number of moves required to balance the coins
    int solve(TreeNode *root,int &moves)
    {
        // Base case: if the current node is NULL, return 0 coins
        if(root == NULL)
        {
            return 0;
        }
        
        // Recursively solve for the left subtree
        int leftCoins = solve(root->left,moves);
        
        // Recursively solve for the right subtree
        int rightCoins = solve(root->right,moves);
        
        // Calculate the number of moves required for the current node
        // abs(leftCoins) + abs(rightCoins) is the total number of moves needed to balance coins from/to left and right children
        moves += abs(leftCoins) + abs(rightCoins);
            
        // Return the net balance of coins after distributing coins to the left and right subtrees
        // (root->val + leftCoins + rightCoins) - 1
        // root->val: number of coins at the current node
        // leftCoins: net balance of coins from the left subtree
        // rightCoins: net balance of coins from the right subtree
        // -1: since each node should ideally have 1 coin, we subtract 1
        return (root->val + leftCoins + rightCoins) - 1;
    }
    
    // Main function to calculate the number of moves required to balance the coins in the binary tree
    int distributeCoins(TreeNode* root) {
        
        // Initialize the number of moves to 0
        int moves = 0;
        
        // Call the helper function with the root node
        solve(root,moves);
        
        // Return the total number of moves
        return moves;
    }
};
