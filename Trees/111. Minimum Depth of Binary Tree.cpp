**************************************************APPROACH 1st(USING BFS)**********************************************

class Solution {// TC--->O(N)                                     SC--->O(N)
public:
    int minDepth(TreeNode* root) {
        // If tree is empty, its depth is 0
        if (root == NULL) 
        {
            return 0;
        }

        // 'depth' keeps track of the current level we are on
        int depth = 1;

        // Standard BFS queue to traverse level by level
        queue<TreeNode*> q;
        q.push(root);  // Start from the root node

        // Level-order traversal (BFS)
        while (!q.empty()) 
        {
            int size = q.size(); // Number of nodes in the current level

            // Traverse all nodes in the current level
            while (size--) 
            {
                TreeNode* node = q.front();
                q.pop();

                // If this node is a leaf (no children),
                // we’ve found the minimum depth, so return it immediately
                if (node->left == NULL && node->right == NULL) 
                {
                    return depth;
                }

                // Otherwise, push its children to the queue for next level
                if (node->left != NULL) 
                {
                    q.push(node->left);
                }

                if (node->right != NULL) 
                {
                    q.push(node->right);
                }
            }

            // After processing one full level, increase depth
            depth++;
        }

        // Should never reach here (since we return when we find a leaf)
        return -1;
    }
};

**************************************************APPROACH 2nd(USING DFS)********************************************


class Solution {// TC--->O(N)                          SC--->O(H)--->Height of Tree
public:
    int minDepth(TreeNode* root) {
        // Base case: If tree is empty, depth is 0
        if (root == NULL) 
        {
            return 0;
        }

        // Case 1: If left subtree is NULL, we must go down the right subtree.
        // We cannot take the min because left side doesn't exist.
        if (root->left == NULL) 
        {
            return 1 + minDepth(root->right);
        }

        // Case 2: If right subtree is NULL, we must go down the left subtree.
        // Again, we cannot take the min here.
        if (root->right == NULL) 
        {
            return 1 + minDepth(root->left);
        }

        // Case 3: If both left and right children exist,
        // take the minimum of their depths and add 1 for the current node.
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
