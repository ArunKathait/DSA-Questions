**********************************************(HERE WE ARE CALCULATING MAXSUM)*******************************************
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
// TC ---> O(n)                       SC ---> O(h), where h is the height of the tree.
// This class stores information about a subtree.
class Node
{
public:

    // Minimum value present in this subtree.
    int minNode;

    // Maximum value present in this subtree.
    int maxNode;

    // Sum of the current BST subtree.
    int maxSum;

    Node(int minNode, int maxNode, int maxSum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution
{
public:

    // Returns information about the BST formed by the current subtree.
    //
    // It returns:
    // 1. Minimum value of the subtree
    // 2. Maximum value of the subtree
    // 3. Sum of the subtree if it is a valid BST
    //
    // ans stores the maximum BST sum found anywhere in the tree.
    Node findLargestBSTSum(TreeNode *root, int &ans)
    {
        // Base case:
        // An empty tree is considered a valid BST.
        //
        // min = INT_MAX
        // max = INT_MIN
        // sum = 0
        //
        // Why these values?
        // They make the BST condition work correctly for leaf nodes.
        if(root == NULL)
        {
            return Node{INT_MAX, INT_MIN, 0};
        }

        // First solve the left subtree.
        //
        // We need its maximum value to check:
        //      left.maxNode < root->val
        Node left = findLargestBSTSum(root->left, ans);

        // Then solve the right subtree.
        //
        // We need its minimum value to check:
        //      root->val < right.minNode
        Node right = findLargestBSTSum(root->right, ans);


        // Check whether the current subtree is a BST.
        //
        // For a BST:
        //
        //     maximum value in left subtree
        //                 <
        //              root value
        //                 <
        //     minimum value in right subtree
        //
        if(left.maxNode < root->val && root->val < right.minNode)
        {
            // Current subtree is a valid BST.

            // Minimum value of the complete BST.
            //
            // It can come from:
            // - current root
            // - left subtree
            int currentMin = min(root->val, left.minNode);

            // Maximum value of the complete BST.
            //
            // It can come from:
            // - current root
            // - right subtree
            int currentMax = max(root->val, right.maxNode);

            // Calculate sum of the current BST.
            //
            //     left subtree sum
            //   + right subtree sum
            //   + current root value
            //
            int currentSum = root->val + left.maxSum + right.maxSum;

            // Update the global maximum answer.
            //
            // We update this at every valid BST because
            // the entire tree itself may not be a BST,
            // but some smaller subtree can have the maximum sum.
            ans = max(ans, currentSum);

            // Return information about this valid BST
            // to its parent.
            return Node{currentMin, currentMax, currentSum};
        }


        // If we reach here, the current subtree is NOT a BST.
        //
        // We cannot combine this entire subtree with its parent.
        //
        // INT_MIN and INT_MAX are used deliberately:
        //
        // Parent checks:
        //     left.maxNode < parent->val
        //
        // Since maxNode = INT_MAX, this will fail.
        //
        // OR:
        //
        //     parent->val < right.minNode
        //
        // Since minNode = INT_MIN, this will fail.
        //
        // Therefore, the parent will also know that
        // this subtree cannot be part of a valid BST.
        //
        // Sum = 0 because this invalid subtree should
        // not contribute to a valid BST sum.
        return Node{INT_MIN, INT_MAX, 0};
    }


    int maxSumBST(TreeNode* root)
    {
        // Initially, maximum BST sum is 0.
        // so 0 is a valid initial answer.
        int ans = 0;

        // Process the complete tree.
        //
        // ans is passed by reference so every recursive call
        // can update the same answer.
        findLargestBSTSum(root, ans);

        // Return the maximum BST sum found anywhere.
        return ans;
    }
};

/*

┌──────────────────────────────────────┐
│       MAXIMUM SUM BST — CHEAT        │
├──────────────────────────────────────┤
│ State:                               │
│ {minNode, maxNode, maxSum}           │
│                                      │
│ NULL:                                │
│ {INT_MAX, INT_MIN, 0}                │
│                                      │
│ BST:                                 │
│ left.maxNode < root < right.minNode  │
│                                      │
│ If BST:                              │
│ min = min(root, left.minNode)        │
│ max = max(root, right.maxNode)       │
│ sum = left.sum + right.sum + root    │
│                                      │
│ ans = max(ans, currentSum)           │
│                                      │
│ If NOT BST:                          │
│ {INT_MIN, INT_MAX, 0}                │
│                                      │
│ Traversal: Postorder                 │
│ LEFT → RIGHT → ROOT                  │
│                                      │
│ Time  : O(n)                         │
│ Space : O(h)                         │
│                                      │
│ Balanced → O(log n)                  │
│ Skewed   → O(n)                      │
└──────────────────────────────────────┘

*/

**********************************************(HERE WE ARE CALCULATING MAXSIZE)******************************************


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

// Time  : O(n)                                          Space : O(h)
// This Node class stores information about a subtree.
//
// minNode -> minimum value present in the subtree
// maxNode -> maximum value present in the subtree
// maxSize -> number of nodes in the BST subtree
class Node {
public:

    int minNode;
    int maxNode;
    int maxSize = 0;

    Node(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};


class Solution {
public:

    // This function returns information about the subtree
    // rooted at 'root'.
    Node findLargestBST(TreeNode* root) {

        // Base case:
        // An empty tree is considered a valid BST.
        if (root == NULL) 
        {
            // minNode = INT_MAX
            // maxNode = INT_MIN
            // maxSize = 0
            //
            // Why?
            // There are no nodes, so its size is 0.
            return Node{INT_MAX, INT_MIN, 0};
        }


        // First process the left subtree.
        Node left = findLargestBST(root->left);

        // Then process the right subtree.
        Node right = findLargestBST(root->right);


        // Now check whether the subtree rooted at 'root'
        // is a valid BST.
        //
        // For a BST:
        //
        //          root
        //         /    \
        //       left   right
        //
        // Maximum value in left subtree
        // must be smaller than root.
        //
        // Minimum value in right subtree
        // must be greater than root.
        if (left.maxNode < root->val && root->val < right.minNode) 
            {
            // Current subtree is a valid BST.
            //
            // Find minimum value of this BST.
            //
            // Minimum can be:
            // 1. root->val
            // 2. minimum value from left subtree
            int currentMin = min(root->val, left.minNode);


            // Find maximum value of this BST.
            //
            // Maximum can be:
            // 1. root->val
            // 2. maximum value from right subtree
            int currentMax = max(root->val, right.maxNode);


            // Count nodes in the current BST.
            //
            // Number of nodes =
            // left subtree nodes
            // + right subtree nodes
            // + current root
            //
            // +1 because the current root is also a node.
            int currentSize = left.maxSize + right.maxSize + 1;


            // Return information about the current BST.
            return Node{currentMin,currentMax,currentSize};
        }


        // If we reach here, the current subtree
        // is NOT a BST.
        //
        // We cannot use the current root's subtree
        // as a BST.
        //
        // So we return:
        //
        // minNode = INT_MIN
        // maxNode = INT_MAX
        //
        // These values make sure that the parent
        // cannot consider this invalid subtree as a BST.
        //
        // max(left.maxSize, right.maxSize)
        // means:
        // "Even though the current subtree is invalid,
        //  one of its child subtrees may still be a valid BST."
        return Node{INT_MIN,INT_MAX,max(left.maxSize, right.maxSize)};
    }


    int maxBST(TreeNode* root) {

        // Start DFS from the root.
        //
        // findLargestBST() returns information about
        // the subtree rooted at root.
        Node result = findLargestBST(root);

        // Return the maximum BST size.
        return result.maxSize;
    }
};

/*

┌─────────────────────────────────────────────┐
│       LARGEST BST — MAXIMUM NODE COUNT      │
├─────────────────────────────────────────────┤
│ State:                                      │
│ Node → {minNode, maxNode, maxSize}          │
│                                             │
│ Base:                                       │
│ NULL → {INT_MAX, INT_MIN, 0}                │
│                                             │
│ Get children first:                         │
│ left  = solve(root->left)                   │
│ right = solve(root->right)                  │
│                                             │
│ BST Condition:                              │
│ left.maxNode < root->val                    │
│              < right.minNode                │
│                                             │
│ If BST:                                     │
│ min  = min(root->val, left.minNode)         │
│ max  = max(root->val, right.maxNode)        │
│ size = left.maxSize + right.maxSize + 1     │
│                                             │
│ If NOT BST:                                 │
│ min = INT_MIN                               │
│ max = INT_MAX                               │
│ size = max(left.maxSize, right.maxSize)     │
│                                             │
│ Traversal:                                  │
│ LEFT → RIGHT → ROOT                         │
│                                             │
│ TC: O(n)                                    │
│ SC: O(h)                                    │
└─────────────────────────────────────────────┘

🔑 Remember these 3 things
-> Valid BST → combine: left + root + right
-> Invalid BST → don't combine: take max(left, right)
-> Invalid boundaries: INT_MIN, INT_MAX → prevents parent from considering it a BST.

*/
