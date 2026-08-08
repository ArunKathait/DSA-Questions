****************************************************APPROACH 1st******************************************************

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

class Solution {// TC ---> O(n)                           SC ---> O(n + h) ~ O(n)
public:

    // This function performs inorder traversal of the BST
    // and stores the node values in the 'inorder' vector.
    void solve(TreeNode* root, vector<int>& inorder)
    {
        // If there is no node, simply return.
        if(root == NULL)
        {
            return;
        }

        // Step 1: Visit the left subtree
        solve(root->left, inorder);

        // Step 2: Visit the current node
        inorder.push_back(root->val);

        // Step 3: Visit the right subtree
        solve(root->right, inorder);
    }

    int getMinimumDifference(TreeNode* root)
    {
        // If tree is empty, there is no difference to calculate.
        if(root == NULL)
        {
            return 0;
        }

        // Vector to store the inorder traversal.
        vector<int> inorder;

        // Perform inorder traversal.
        solve(root, inorder);

        /*
            Important property of BST:

            Inorder traversal of a BST gives values
            in sorted/ascending order.

            Example:

                    4
                   / \
                  2   6
                 / \
                1   3

            Inorder = [1, 2, 3, 4, 6]
        */

        // Start with the largest possible value
        // because we are looking for a minimum.
        int ans = INT_MAX;

        /*
            Since the array is sorted, the minimum
            difference will always be between adjacent
            elements.

            Example:

            [1, 2, 3, 4, 6]

            Differences:

            2 - 1 = 1
            3 - 2 = 1
            4 - 3 = 1
            6 - 4 = 2

            Minimum = 1
        */
        for(int i = 1; i < inorder.size(); i++)
        {
            // Calculate difference between current
            // element and previous element.
            int difference = inorder[i] - inorder[i - 1];

            // Keep the smallest difference found so far.
            ans = min(ans, difference);
        }

        // Return the minimum absolute difference.
        return ans;
    }
};

**********************************************APPROACH 2nd************************************************************

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

class Solution {// TC ---> O(n)                           SC ---> O(h)
public:

    // prev = previous node visited during inorder traversal
    // ans  = minimum difference found so far
    void solve(TreeNode* root, int &ans, TreeNode* &prev)
    {
        // If there is no node, return.
        if(root == NULL)
        {
            return;
        }

        // 1. Visit the left subtree first.
        //
        // Since this is a BST, inorder traversal gives
        // the nodes in sorted order.
        solve(root->left, ans, prev);


        // 2. Process the current node.
        //
        // If prev is not NULL, it means we have already
        // visited a previous node in inorder traversal.
        if(prev != NULL)
        {
            // Since inorder traversal is sorted,
            // current value >= previous value.
            //
            // Calculate the difference between current
            // node and previous node.
            ans = min(ans, root->val - prev->val);
        }


        // Make the current node the previous node
        // for the next node we visit.
        prev = root;


        // 3. Visit the right subtree.
        solve(root->right, ans, prev);
    }


    int getMinimumDifference(TreeNode* root)
    {
        // Initially, there is no previous node.
        TreeNode* prev = NULL;

        // Start with the maximum possible integer
        // because we are looking for the minimum difference.
        int ans = INT_MAX;

        // Perform inorder traversal.
        solve(root, ans, prev);

        // Return the minimum difference found.
        return ans;
    }
};
