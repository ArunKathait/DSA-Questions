
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

class Solution {// Time = O(N)                               SC ---> Space = O(H)
public:

    // solve(root) returns a pair:
    // first  -> maximum money if we TAKE/ROB this node
    // second -> maximum money if we SKIP this node
    pair<int,int> solve(TreeNode *root)
    {
        // Base case:
        // If there is no node, we cannot rob anything.
        // So both TAKE and SKIP values are 0.
        if(root == NULL)
        {
            return {0, 0};
        }

        // Recursively calculate the two DP states
        // for the left and right subtrees.
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        // TAKE current node:
        //
        // If we rob the current node, we CANNOT rob
        // either of its children because they are adjacent.
        //
        // Therefore, we take:
        // current node value
        // + left subtree's SKIP value
        // + right subtree's SKIP value
        int take = root->val + left.second + right.second;

        // SKIP current node:
        //
        // If we don't rob the current node, then for
        // each child we can either ROB or SKIP it.
        //
        // So we take the better option from each subtree.
        int skip = max(left.first, left.second)
                 + max(right.first, right.second);

        // Return both DP states to the parent.
        return {take, skip};
    }

    int rob(TreeNode* root)
    {
        // Calculate TAKE and SKIP values for the root.
        pair<int,int> p = solve(root);

        // We can either rob the root or skip it.
        // Choose whichever gives maximum money.
        return max(p.first, p.second);
    }
};

/*    

┌──────────────────────────────────────────────┐
│           🏠 HOUSE ROBBER III               │
├──────────────────────────────────────────────┤
│                                              │
│ At every node, we have 2 choices:            │
│                                              │
│ 1️⃣ TAKE / ROB the current node               │
│    → Cannot rob its children                 │
│    → take = node->val                        │
│            + left.skip                       │
│            + right.skip                      │
│                                              │
│ 2️⃣ SKIP the current node                     │
│    → Children can be taken OR skipped        │
│    → skip = max(left.take, left.skip)        │
│           + max(right.take, right.skip)      │
│                                              │
│ Do this bottom-up using Postorder DFS.       │
│                                              │
│ Each node returns:                           │
│    {take, skip}                              │
│                                              │
│ Finally:                                     │
│    answer = max(root.take, root.skip)        │
│                                              │
│ 🔑 Pattern: Tree DP + Take/Skip              │
└──────────────────────────────────────────────┘

  */
