*****************************************************APPROACH 1st(WITHOUT REFERENCE)************************************************

class Solution {// TC--->O(N)                                SC--->O(H)--->Height of Tree
public:
    // Recursive helper function to explore all root-to-leaf paths
    void solve(TreeNode *root, int sum, int targetSum, vector<int> temp, vector<vector<int>>& ans)
    {
        // Base case: if the node is null, just return
        if (root == NULL) 
        {
            return;
        }

        // Add current node's value to the running sum
        sum += root->val;

        // Add current node's value to the current path
        temp.push_back(root->val);

        // If the node is a leaf (no children)
        if (root->left == NULL && root->right == NULL)
        {
            // Check if the running sum equals the target sum
            if (sum == targetSum)
            {
                // If so, add this path to the result list
                ans.push_back(temp);
            }

            // Since this is a leaf, return (no further recursion needed)
            return;
        }

        // Recurse on the left subtree
        solve(root->left, sum, targetSum, temp, ans);

        // Recurse on the right subtree
        solve(root->right, sum, targetSum, temp, ans);
    }

    // Main function to be called with the root and target sum
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         // Initialize running sum
        int sum = 0; 

        // To store all valid paths
        vector<vector<int>> ans;  

         // Temporary vector to store current path
        vector<int> temp; 

        // Start the recursive traversal
        solve(root, sum, targetSum, temp, ans);

        // Return all valid root-to-leaf paths that match targetSum
        return ans;
    }
};

***************************************************APPROACH 2nd(USING REFERENCE)***************************************************

class Solution {// TC--->O(N)                               SC--->O(H)--->Height of Tree
public:
    // Helper function for DFS traversal to find paths that sum up to targetSum
    void solve(TreeNode *root, int sum, int targetSum, vector<int>& temp, vector<vector<int>>& ans)
    {
        // Base case: If the node is NULL, just return
        if (root == NULL) 
        {
            return;
        }

        // Add the current node's value to the running sum
        sum += root->val;

        // Add the current node's value to the current path (temp)
        temp.push_back(root->val);

        // Check if the current node is a leaf (both left and right children are NULL)
        if (root->left == NULL && root->right == NULL)
        {
            // If the sum matches the target, add the current path (temp) to the result list
            if (sum == targetSum) 
            {
                ans.push_back(temp);
            }

            // After the leaf node, backtrack by popping the last element from the path
            temp.pop_back();

            // Since it's a leaf, no need to continue further down this path
            return;  
        }

        // Recurse on the left subtree
        solve(root->left, sum, targetSum, temp, ans);
        
        // Recurse on the right subtree
        solve(root->right, sum, targetSum, temp, ans);

        // Backtrack after exploring both left and right subtrees
        temp.pop_back();
    }

    // Main function to return all paths where the sum of node values equals targetSum
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // Initialize sum to 0
        int sum = 0;  

        // This will store the valid paths
        vector<vector<int>> ans;  

        // Temporary vector to store the current path
        vector<int> temp;  

        // Start the DFS traversal from the root
        solve(root, sum, targetSum, temp, ans);

        // Return all valid paths stored in ans
        return ans;
    }
};
