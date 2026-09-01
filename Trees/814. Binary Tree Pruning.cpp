
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {// Time  : O(n)                                 Space : O(h)
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        // If the current node is NULL,
        // there is nothing to prune.
        if(root == NULL)
        {
            return NULL;
        }

        // Recursively prune the left subtree.
        // The returned value can be NULL if the
        // entire left subtree needs to be removed.
        root->left = pruneTree(root->left);

        // Recursively prune the right subtree.
        // Similarly, the returned value can be NULL
        // if the entire right subtree needs to be removed.
        root->right = pruneTree(root->right);

        // If the current node is 0 and after pruning
        // it has no left or right child, then this node
        // does not contain any 1 in its subtree.
        // So remove this node by returning NULL.
        if(root->val == 0 && root->left == NULL && root->right == NULL)
        {
            return NULL;
        }

        // Otherwise, keep the current node.
        return root;
    }
};

/*  

┌──────────────────────────────────────────┐
│            PRUNE BINARY TREE             │
├──────────────────────────────────────────┤
│                                          │
│ Pattern: POSTORDER RECURSION             │
│                                          │
│ First prune LEFT subtree                 │
│ Then prune RIGHT subtree                 │
│ Then check CURRENT node                  │
│                                          │
│        LEFT → RIGHT → ROOT               │
│                                          │
│ For every node:                          │
│                                          │
│ 1. If root == NULL                       │
│       → return NULL                      │
│                                          │
│ 2. Prune left                            │
│       root->left = pruneTree(left)       │
│                                          │
│ 3. Prune right                           │
│       root->right = pruneTree(right)     │
│                                          │
│ 4. If root is 0 AND                      │
│    left == NULL AND right == NULL        │
│       → return NULL                      │
│                                          │
│ 5. Otherwise                             │
│       → return root                      │
│                                          │
│ KEY IDEA:                                │
│ First prune children, then decide        │
│ whether current node should stay.        │
│                                          │
│ Why assignment?                          │
│ Recursive call can return NULL.          │
│ So update parent's child pointer.        │
│                                          │
│ Complexity:                              │
│ Time  → O(n)                             │
│ Space → O(h)                             │
└──────────────────────────────────────────┘

🧠 Cheat Box

Whenever you see recursion on a tree, ask:

What does my function return?
          ↓
Can that returned value change the subtree?
          ↓
        YES
          ↓
root->left = solve(root->left);

        NO
          ↓
solve(root->left);

*/
