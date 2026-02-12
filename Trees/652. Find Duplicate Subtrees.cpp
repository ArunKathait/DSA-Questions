************************************************APPROACH 1st**********************************************************

/**
 * Definition for a binary tree node.
 */

class Solution {// TC ---> O(N²)                              SC ---> O(N²)
public:
    // This function serializes each subtree and detects duplicates
    string solve(TreeNode *root, vector<TreeNode*>& ans, unordered_map<string,int>& ump)
    {
        // Base case: if node is NULL, represent it with '#'
        // This helps uniquely identify tree structure
        if(root == NULL)
        {
            return "#";
        }

        // Recursively serialize left subtree
        string left = solve(root->left, ans, ump);

        // Recursively serialize right subtree
        string right = solve(root->right, ans, ump);

        // Create serialization of current subtree
        // Format: root_value,left_subtree,right_subtree
        string str = to_string(root->val) + "," + left + "," + right;

        // If this serialization is seen exactly once before,
        // then this is the second time → duplicate subtree found
        if(ump[str] == 1)
        {
            ans.push_back(root); // store root of duplicate subtree
        }

        // Increase frequency of this subtree serialization
        ump[str]++;

        // Return serialization to parent call
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;               // stores duplicate subtree roots
        unordered_map<string,int> ump;       // maps subtree serialization → count

        // Start DFS traversal and serialization
        solve(root, ans, ump);

        return ans; // return all duplicate subtree roots
    }
};

***********************************************APPROACH 2nd(SMALL CHANGES)**********************************************

  /**
 * Definition for a binary tree node.
 */

class Solution {// TC ---> O(N²)                                    SC ---> O(N²)
public:
    // This function serializes each subtree and detects duplicates
    string solve(TreeNode *root, vector<TreeNode*>& ans, unordered_map<string,int>& ump)
    {
        // Base case:
        // If current node is NULL, return a special marker
        // This is necessary to preserve tree structure
        if(root == NULL)
        {
            return "#";
        }

        // Serialize the current subtree in preorder format:
        // root_value,left_subtree,right_subtree
        string str = to_string(root->val) + "," + solve(root->left, ans, ump) + "," + solve(root->right, ans, ump);

        // If this subtree serialization has appeared exactly once before,
        // then this is the second occurrence → duplicate subtree
        if(ump[str] == 1)
        {
            ans.push_back(root);  // store root of duplicate subtree
        }

        // Increase count of this subtree serialization
        ump[str]++;

        // Return serialized subtree to parent
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;               // stores duplicate subtree roots
        unordered_map<string,int> ump;       // maps subtree serialization → frequency

        // Start DFS traversal from root
        solve(root, ans, ump);

        return ans;
    }
};
