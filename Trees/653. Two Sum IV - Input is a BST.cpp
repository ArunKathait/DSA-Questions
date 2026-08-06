*********************************************APPROACH 1st**************************************************************

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *          : val(x), left(left), right(right) {}
 * };
 */

class Solution {// Tc ---> O(N)                                              SC ---> O(N)
public:

    // DFS traversal of the tree.
    // The unordered_map stores all values visited so far.
    bool solve(TreeNode *root, unordered_map<int, bool>& ump, int k)
    {
        // Base case:
        // If the current node is NULL,
        // no pair can be formed.
        if (root == NULL)
        {
            return false;
        }

        // Calculate the value required to make the target.
        int findVal = k - root->val;

        // If the required value has already been visited,
        // then we found two nodes whose sum is k.
        if (ump.find(findVal) != ump.end())
        {
            return true;
        }

        // Store the current node value in the hash map
        // so future nodes can use it as a complement.
        ump[root->val] = true;

        // Search in the left subtree.
        bool left = solve(root->left, ump, k);

        // Search in the right subtree.
        bool right = solve(root->right, ump, k);

        // Return true if either subtree found a valid pair.
        return left || right;
    }

    bool findTarget(TreeNode* root, int k) {

        // Hash map to store the values of
        // all previously visited nodes.
        unordered_map<int, bool> ump;

        // Start DFS traversal from the root.
        return solve(root, ump, k);
    }
};

*********************************************APPROACH 2nd**************************************************************

class Solution {// TC ---> O(N)                            SC ---> O(N)
public:

    // Perform inorder traversal of the BST.
    // Inorder traversal of a BST always produces
    // the node values in sorted (ascending) order.
    void solve(TreeNode *root, int k, vector<int>& inorder)
    {
        // Base case: if the node is NULL, return.
        if (root == NULL)
        {
            return;
        }

        // Traverse the left subtree.
        solve(root->left, k, inorder);

        // Visit the current node and store its value.
        inorder.push_back(root->val);

        // Traverse the right subtree.
        solve(root->right, k, inorder);
    }

    bool findTarget(TreeNode* root, int k) {

        // This vector will store the BST elements
        // in sorted order after inorder traversal.
        vector<int> inorder;

        // Fill the inorder vector.
        solve(root, k, inorder);

        // Two pointers:
        // left starts from the smallest element.
        int left = 0;

        // right starts from the largest element.
        int right = inorder.size() - 1;

        // Continue until the two pointers meet.
        while (left < right)
        {
            // Calculate the sum of the current pair.
            int sum = inorder[left] + inorder[right];

            // If the required target is found,
            // return true immediately.
            if (sum == k)
            {
                return true;
            }

            // If the sum is smaller than the target,
            // move the left pointer to increase the sum.
            else if (sum < k)
            {
                left++;
            }

            // If the sum is greater than the target,
            // move the right pointer to decrease the sum.
            else
            {
                right--;
            }
        }

        // No pair with sum = k exists.
        return false;
    }
};

**************************************************APPROACH 3rd******************************************************

