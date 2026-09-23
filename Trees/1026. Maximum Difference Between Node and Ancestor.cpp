*************************************************APPROACH 1st(BRUTE FORCE)******************************************

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

class Solution {// Time Complexity: O(N²) worst case            Space Complexity: O(H)
public:

    // root = fixed ancestor
    // child = current descendant
    // maxDiff = stores the maximum difference found so far
    int findMaxDiff(TreeNode *root, TreeNode *child, int &maxDiff)
    {
        // If there is no ancestor or no descendant,
        // there is nothing to compare
        if(root == NULL || child == NULL)
        {
            return 0;
        }

        // Compare the fixed ancestor with the current descendant
        // Example: ancestor = 8, child = 1
        // difference = |8 - 1| = 7
        maxDiff = max(maxDiff, abs(root->val - child->val));

        // Keep the same ancestor and move to the left descendant
        findMaxDiff(root, child->left, maxDiff);

        // Keep the same ancestor and move to the right descendant
        findMaxDiff(root, child->right, maxDiff);

        // Return the maximum difference found so far
        return maxDiff;
    }


    // This function makes every node a possible ancestor
    void solve(TreeNode *root, int &maxDiff)
    {
        // No node → nothing to process
        if(root == NULL)
        {
            return;
        }

        // Treat the current node as an ancestor
        // and compare it with all nodes in its left subtree
        findMaxDiff(root, root->left, maxDiff);

        // Treat the current node as an ancestor
        // and compare it with all nodes in its right subtree
        findMaxDiff(root, root->right, maxDiff);


        // Now move to the left subtree.
        // Nodes there will become ancestors in later calls.
        solve(root->left, maxDiff);

        // Now move to the right subtree.
        // Nodes there will become ancestors in later calls.
        solve(root->right, maxDiff);
    }


    int maxAncestorDiff(TreeNode* root)
    {
        // Empty tree → no ancestor-descendant pair
        if(root == NULL)
        {
            return 0;
        }

        // Stores the maximum difference found in the entire tree
        int maxDiff = 0;

        // Start from the root.
        // solve() will consider every node as an ancestor.
        solve(root, maxDiff);

        // Return the maximum ancestor-descendant difference
        return maxDiff;
    }
};

/*

┌──────────────────────────────────────┐
│   Maximum Ancestor Difference        │
│          BRUTE FORCE                 │
├──────────────────────────────────────┤
│ IDEA:                                │
│ For every node, treat it as an       │
│ ancestor and check all descendants.  │
│                                      │
│ solve():                             │
│ 1. Pick current node as ancestor.    │
│ 2. findMaxDiff() visits descendants. │
│ 3. Compare ancestor & descendant.    │
│ 4. Update maxDiff.                   │
│                                      │
│ Difference:                          │
│ abs(ancestor->val - child->val)      │
│                                      │
│ Time  : O(N²) worst case             │
│ Space : O(H)                         │
│                                      │
│ Balanced Tree → lower practical work │
│ Skewed Tree   → O(N²)                │
└──────────────────────────────────────┘

*/

**********************************************APPROACH 2nd(OPTIMAL)*************************************************

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {// Time Complexity: O(N)                      Space Complexity: O(H)
public:

    // maxVal = maximum value seen from root to current node
    // minVal = minimum value seen from root to current node
    int solve(TreeNode *root, int maxVal, int minVal)
    {
        // If we reach NULL, the current root-to-leaf path is completed.
        // maxVal and minVal contain the maximum and minimum values
        // from that path.
        //
        // Their difference is the maximum possible difference
        // between an ancestor and a descendant on this path.
        if (root == NULL)
        {
            return abs(maxVal - minVal);
        }

        // Include the current node's value in the maximum value
        // seen on the current path.
        maxVal = max(maxVal, root->val);

        // Include the current node's value in the minimum value
        // seen on the current path.
        minVal = min(minVal, root->val);

        // Recursively find the maximum difference in the left subtree.
        //
        // We pass the updated maxVal and minVal because they represent
        // all the ancestor values seen on the path to the left child.
        int ls = solve(root->left, maxVal, minVal);

        // Recursively find the maximum difference in the right subtree.
        //
        // Again, we pass the updated maxVal and minVal so the right
        // subtree also knows the ancestor information.
        int rs = solve(root->right, maxVal, minVal);

        // The answer can be present in either the left subtree
        // or the right subtree, so return the larger one.
        return max(ls, rs);
    }

    int maxAncestorDiff(TreeNode* root)
    {
        // If the tree is empty, there is no ancestor-descendant pair.
        if (root == NULL)
        {
            return 0;
        }

        // Initially, the root is the only value we have seen.
        // Therefore, both maximum and minimum are root->val.
        //
        // solve() will update them as it moves down the tree.
        return solve(root, root->val, root->val);
    }
};

/*

┌──────────────────────────────────────┐
│   Maximum Ancestor Difference        │
├──────────────────────────────────────┤
│ IDEA:                                │
│ Carry minVal & maxVal on each path.  │
│                                      │
│ At NULL:                             │
│ abs(maxVal - minVal)                 │
│                                      │
│ Update:                              │
│ maxVal = max(maxVal, root->val)      │
│ minVal = min(minVal, root->val)      │
│                                      │
│ Left  → solve(root->left, ...)       │
│ Right → solve(root->right, ...)      │
│                                      │
│ Time  : O(N)                         │
│ Space : O(H)                         │
│                                      │
│ Balanced Tree → O(log N)             │
│ Skewed Tree   → O(N)                 │
└──────────────────────────────────────┘

*/
