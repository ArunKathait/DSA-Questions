
class Solution {// TC ---> O(N)                                  Sc ---> O(W) , W = maximum width of the binary tree
public:
    int maxLevelSum(TreeNode* root) {

        // If tree is empty, no level exists
        if (root == NULL) 
        {
            return 0;
        }

        // Queue is used for Level Order Traversal (BFS)
        queue<TreeNode*> q;

        // Start BFS from root
        q.push(root);

        // Stores the maximum sum found among all levels
        int maxSum = INT_MIN;

        // Stores the level number which has maximum sum
        int maxLevel = 0;

        // Keeps track of current level number (1-based index)
        int level = 0;

        // Traverse tree level by level
        while (!q.empty()) 
        {

            // Number of nodes present at current level
            int size = q.size();

            // Sum of values of nodes at current level
            int sum = 0;

            // Process all nodes of the current level
            while (size--) 
            {
                // Get the front node of the queue
                TreeNode* node = q.front();
                q.pop();

                // Add current node's value to level sum
                sum += node->val;

                // Push left child to queue if it exists
                if (node->left) 
                {
                    q.push(node->left);
                }

                // Push right child to queue if it exists
                if (node->right) 
                {
                    q.push(node->right);
                }
            }

            // Completed one level traversal
            level++;

            // Update maxSum and maxLevel if current level sum is greater
            if (sum > maxSum) 
            {
                maxSum = sum;
                maxLevel = level;
            }
        }

        // Return the level number having maximum sum
        return maxLevel;
    }
};
