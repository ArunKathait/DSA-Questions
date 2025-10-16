**************************************************APPROACH 1st(USING BRUTE FORCE)*******************************************

class Solution {// TC--->O(N) + O(NlogN) + O(N) ~ O(NlogN)                                   SC--->O(N) + O(N) + O(H) ~ O(N)
public:
    // Function to perform inorder traversal and collect node values
    void inorderTraversal(TreeNode *node, vector<int> &inorderValues) {
        if (node == NULL) 
        {
            return; // Base case: stop when reaching a null node
        }

        // Visit left subtree
        inorderTraversal(node->left, inorderValues);

        // Store the current node's value
        inorderValues.push_back(node->val);

        // Visit right subtree
        inorderTraversal(node->right, inorderValues);
    }

    // Function to rebuild the tree by assigning sorted values back
    void rebuildBST(TreeNode *node, vector<int> &sortedValues, int &currentIndex) {
        if (node == NULL) 
        {
            return; // Base case: stop when reaching a null node
        }

        // Rebuild left subtree first (inorder order)
        rebuildBST(node->left, sortedValues, currentIndex);

        // Assign the correct (sorted) value to current node
        node->val = sortedValues[currentIndex++];

        // Rebuild right subtree
        rebuildBST(node->right, sortedValues, currentIndex);
    }

    // Main function to recover a BST where two nodes were swapped
    void recoverTree(TreeNode* root) {
        // Step 1: Store the inorder traversal of the BST
        vector<int> inorderValues;
        inorderTraversal(root, inorderValues);

        // Step 2: Create a sorted version of inorderValues
        vector<int> sortedValues = inorderValues;
        sort(sortedValues.begin(), sortedValues.end());

        // Step 3: Replace the incorrect node values with sorted ones
        int currentIndex = 0;
        rebuildBST(root, sortedValues, currentIndex);
    }
};

***********************************************APPROACH 2nd(USING BETTER APPROACH)***************************************

class Solution {// TC--->O(N)                              SC--->O(N)--->Recursion Stack Space
public:
    // Recursive function to perform inorder traversal and find the two swapped nodes
    void inorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second)
    {
        // Base case: if node is null, return
        if (root == NULL) 
        {
            return;
        }

        // Traverse the left subtree (inorder traversal: Left → Root → Right)
        inorder(root->left, prev, first, second);

        // Check if the current node violates the BST property
        // In a BST's inorder traversal, the sequence should be strictly increasing.
        // So, if we find a node with a value smaller than the previous node's value,
        // it means a swap has occurred.
        if (prev != NULL && prev->val > root->val)
        {
            // If this is the first violation, mark 'first' as the previous node
            // because it's larger than it should be.
            if (first == NULL)
            {
                first = prev;
            }

            // The current node ('root') is smaller than previous,
            // so it could be the second swapped node.
            second = root;
        }

        // Move 'prev' pointer to the current node before moving to the right subtree.
        // This ensures we always compare consecutive nodes in inorder traversal.
        prev = root;

        // Continue traversal in the right subtree
        inorder(root->right, prev, first, second);
    }

    // Main function to recover the BST
    void recoverTree(TreeNode* root)
    {
        TreeNode *prev = NULL;   // Keeps track of the previous node in inorder traversal
        TreeNode *first = NULL;  // Will point to the first wrongly placed node
        TreeNode *second = NULL; // Will point to the second wrongly placed node

        // Step 1: Find the two nodes that are swapped by mistake
        inorder(root, prev, first, second);

        // Step 2: Swap their values to restore the BST property
        swap(first->val, second->val);
    }
};
