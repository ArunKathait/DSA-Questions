

class Solution {// TC ---> O(N) – each node is processed once         SC ---> O(H) recursion stack height of the tree
public:
    
    // DFS function to calculate longest ZigZag path
    void dfs(TreeNode* node,int currentLength,bool lastMoveWasLeft, int &maxZigZagLength)
    {
        // Base case: if node is null, stop recursion
        if (node == NULL) 
        {
            return;
        }

        // Update the maximum ZigZag length found so far
        maxZigZagLength = max(maxZigZagLength, currentLength);

        // If last move was towards LEFT
        if (lastMoveWasLeft) 
        {
            // Move RIGHT to continue ZigZag → increase length
            dfs(node->right, currentLength + 1, false, maxZigZagLength);

            // Move LEFT again → ZigZag breaks, reset length to 1
            dfs(node->left, 1, true, maxZigZagLength);
        }
        else 
        {
            // Last move was RIGHT

            // Move LEFT to continue ZigZag → increase length
            dfs(node->left, currentLength + 1, true, maxZigZagLength);

            // Move RIGHT again → ZigZag breaks, reset length to 1
            dfs(node->right, 1, false, maxZigZagLength);
        }
    }

    int longestZigZag(TreeNode* root) {
        int maxZigZagLength = 0;

        // Start DFS assuming first move is LEFT
        dfs(root, 0, true, maxZigZagLength);

        // Start DFS assuming first move is RIGHT
        dfs(root, 0, false, maxZigZagLength);

        return maxZigZagLength;
    }
};
