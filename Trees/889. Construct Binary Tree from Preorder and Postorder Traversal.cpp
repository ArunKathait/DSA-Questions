
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

class Solution {// TC: O(n) average                            SC: O(n) 
public:

    // preStart and preEnd represent the current subtree in preorder.
    // postStart represents where this subtree starts in postorder.
    //
    // We don't need postEnd because the position of the left subtree
    // root in postorder is enough to calculate the left subtree size.
    TreeNode* solve(int preStart, int preEnd, int postStart,vector<int>& preorder,unordered_map<int, int>& ump) {

        // If there are no elements in this subtree,
        // there is nothing to construct.
        if (preStart > preEnd) 
        {
            return NULL;
        }

        // In preorder:
        // Root -> Left -> Right
        //
        // Therefore, the first element of the current preorder range
        // is always the root of the current subtree.
        TreeNode* root = new TreeNode(preorder[preStart]);

        // If the current subtree contains only one node,
        // we have already created the node.
        if (preStart == preEnd) 
        {
            return root;
        }

        // The element immediately after the root in preorder
        // is the root of the left subtree.
        //
        // Example:
        // Preorder = [1, 2, 4, 5, 3, 6, 7]
        //            ↑  ↑
        //          root leftRoot
        int leftRootValue = preorder[preStart + 1];

        // Find the position of the left subtree root in postorder.
        //
        // Postorder:
        // Left -> Right -> Root
        //
        // The position tells us where the left subtree ends
        // in the postorder traversal.
        int index = ump[leftRootValue];

        // Calculate the number of nodes in the left subtree.
        //
        // Example:
        // postStart = 0
        // index = 2
        //
        // Left subtree occupies:
        // postorder[0 ... 2]
        //
        // Number of nodes = 2 - 0 + 1 = 3
        int leftSize = index - postStart + 1;

        // Construct the left subtree.
        //
        // In preorder, the left subtree starts immediately
        // after the root.
        //
        // Its range is:
        // preStart + 1
        //       to
        // preStart + leftSize
        //
        // Its postorder range starts at postStart.
        root->left = solve(preStart + 1,preStart + leftSize,postStart,preorder,ump);

        // Construct the right subtree.
        //
        // In preorder:
        // Root -> Left -> Right
        //
        // So the right subtree starts after:
        // root + leftSize nodes.
        //
        // Therefore:
        // right subtree starts at preStart + leftSize + 1
        //
        // In postorder, the left subtree ends at index,
        // so the right subtree starts at index + 1.
        root->right = solve(preStart + leftSize + 1,preEnd,index + 1,preorder,ump);

        // Return the root of the current subtree.
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,vector<int>& postorder) {

        int n = preorder.size();

        // Store the index of every value in postorder.
        //
        // This allows us to find the left subtree root
        // in O(1) average time.
        unordered_map<int, int> ump;

        for (int i = 0; i < n; i++) 
        {
            ump[postorder[i]] = i;
        }

        // Initially, the entire preorder array represents
        // the complete tree.
        //
        // preStart = 0
        // preEnd = n - 1
        // postStart = 0
        return solve(0,n - 1,0,preorder,ump);
    }
};

/*

┌─────────────────────────────────────┐
│   LeetCode 889 — Binary Tree        │
│   Construct from Pre + Post         │
├─────────────────────────────────────┤
│ Preorder → Root + Left Root         │
│ Postorder → Left subtree boundary   │
│                                     │
│ root = preorder[preStart]           │
│ leftRoot = preorder[preStart + 1]   │
│ index = position[leftRoot]          │
│ leftSize = index - postStart + 1    │
│                                     │
│ Left:  preStart+1 → preStart+size   │
│ Right: preStart+size+1 → preEnd     │
│                                     │
│ Base: preStart > preEnd → NULL      │
│       preStart == preEnd → root     │
│                                     │
│ TC: O(n) average                    │
│ SC: O(n)                            │
└─────────────────────────────────────┘

*/
