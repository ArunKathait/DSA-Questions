
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:
    /* TC ---> O(h)  -->Average/Balanced BST ---> O(log n), Worst case (skewed BST) → O(n)
       SC ---> O(h)  ->O(log n) for balanced BST, -> O(n) for skewed BST
    */

    // Function to find the minimum value in a BST
    // We always go to the left-most node
    int findMinimumValue(TreeNode* currentNode) {
        int minimumValue = currentNode->val;

        // Move left until no more left child exists
        while (currentNode->left != NULL) 
        {
            minimumValue = currentNode->left->val;
            currentNode = currentNode->left;
        }

        return minimumValue;
    }

    // Function to delete a node with given key from BST
    TreeNode* deleteNode(TreeNode* rootNode, int keyToDelete) {

        // Base case: tree is empty
        if (rootNode == NULL) 
        {
            return NULL;
        }

        // If key is smaller, search in left subtree
        if (keyToDelete < rootNode->val) 
        {
            rootNode->left = deleteNode(rootNode->left, keyToDelete);
        }

        // If key is larger, search in right subtree
        else if (keyToDelete > rootNode->val) 
        {
            rootNode->right = deleteNode(rootNode->right, keyToDelete);
        }
        // Key found → this is the node to delete
        else 
        {
            // Case 1: Node has no left child
            // Replace node with its right child
            if (rootNode->left == NULL) 
            {
                return rootNode->right;
            }

            // Case 2: Node has no right child
            // Replace node with its left child
            else if (rootNode->right == NULL) {
                return rootNode->left;
            }

            // Case 3: Node has two children
            // Find inorder successor (minimum in right subtree)
            int inorderSuccessorValue = findMinimumValue(rootNode->right);

            // Replace current node's value with successor's value
            rootNode->val = inorderSuccessorValue;

            // Delete the inorder successor from right subtree
            rootNode->right = deleteNode(rootNode->right, inorderSuccessorValue);
        }

        // Return updated root
        return rootNode;
    }
};
