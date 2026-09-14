
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {// TC ---> O(N)                           SC ---> O(N)
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        // If the tree is empty, there are no levels.
        // So return an empty 2D vector.
        if (root == NULL) 
        {
            return {};
        }

        // This will store all levels from TOP to BOTTOM.
        //
        // For example:
        //
        //        3
        //       / \
        //      9  20
        //         / \
        //        15  7
        //
        // ans will initially become:
        // [[3], [9,20], [15,7]]
        vector<vector<int>> ans;

        // Queue is used for BFS (level-order traversal).
        // It stores the nodes that we need to process.
        queue<TreeNode*> q;

        // Start BFS by putting the root into the queue.
        q.push(root);

        // Continue until there are no nodes left to process.
        while (!q.empty()) 
        {
            // q.size() tells us how many nodes belong
            // to the CURRENT level.
            //
            // This is important because after processing
            // these nodes, their children belong to the next level.
            int size = q.size();

            // Store all node values of the current level.
            vector<int> level;

            // Process exactly 'size' nodes.
            //
            // We use size-- so that only nodes belonging
            // to the current level are processed here.
            while (size--) 
            {
                // Take the first node from the queue.
                TreeNode* node = q.front();

                // Remove that node from the queue.
                q.pop();

                // Store the current node's value
                // in the current level.
                level.push_back(node->val);

                // If the current node has a left child,
                // add it to the queue.
                //
                // It will be processed in the NEXT level.
                if (node->left) 
                {
                    q.push(node->left);
                }

                // If the current node has a right child,
                // add it to the queue.
                //
                // It will also be processed in the NEXT level.
                if (node->right) 
                {
                    q.push(node->right);
                }
            }

            // We have finished processing one complete level.
            // Add that level to ans.
            ans.push_back(level);
        }

        // Currently ans is from TOP to BOTTOM:
        //
        // [[3], [9,20], [15,7]]
        //
        // But the question asks for BOTTOM to TOP.
        // So reverse the order of the levels.
        reverse(ans.begin(), ans.end());

        // Now:
        //
        // [[15,7], [9,20], [3]]
        //
        // Return the bottom-up level order.
        return ans;
    }
};

/*

╔══════════════════════════════════════════╗
║      LEVEL ORDER BOTTOM — CHEAT BOX      ║
╠══════════════════════════════════════════╣
║ Pattern: BFS + Queue                     ║
║                                          ║
║ 1. Push root into queue                  ║
║ 2. q.size() = current level size         ║
║ 3. Process exactly `size` nodes          ║
║ 4. Push left & right children            ║
║ 5. ans.push_back(level)                  ║
║ 6. reverse(ans.begin(), ans.end())       ║
║                                          ║
║ Flow:                                    ║
║ Top → Bottom → Reverse → Bottom → Top    ║
║                                          ║
║ Key: queue + q.size()                    ║
║                                          ║
║ TC: O(N)                                 ║
║ SC: O(N)                                 ║
╚══════════════════════════════════════════╝

*/
