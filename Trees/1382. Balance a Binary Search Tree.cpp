

class Solution {// TC ---> O(N)                                 SC ---> O(N)
public:

    // This function builds a balanced BST from a sorted array
    // left  -> starting index
    // right -> ending index
    // vec   -> sorted values (inorder of BST)
    TreeNode* constructBST(int left, int right, vector<int>& vec)
    {
        // Base case: no elements to form a tree
        if (left > right)
        {
            return NULL;
        }

        // Choose middle element to keep tree balanced
        int mid = left + (right - left) / 2;

        // Create root node with middle element
        TreeNode* root = new TreeNode(vec[mid]);

        // Recursively build left subtree from left half
        root->left = constructBST(left, mid - 1, vec);

        // Recursively build right subtree from right half
        root->right = constructBST(mid + 1, right, vec);

        // Return root of balanced subtree
        return root;
    }

    // Inorder traversal of BST
    // It stores values in sorted order into vector
    void inorder(TreeNode* root, vector<int>& vec)
    {
        // Base case
        if (root == NULL)
        {
            return;
        }

        // Visit left subtree
        inorder(root->left, vec);

        // Visit root node
        vec.push_back(root->val);

        // Visit right subtree
        inorder(root->right, vec);
    }

    // Main function to balance BST
    TreeNode* balanceBST(TreeNode* root) {

        // Step 1: Store inorder traversal of BST
        // Inorder of BST is always sorted
        vector<int> vec;
        inorder(root, vec);

        // Step 2: Build balanced BST from sorted array
        int left = 0;
        int right = vec.size() - 1;

        TreeNode* ans = constructBST(left, right, vec);

        // Return balanced BST root
        return ans;
    }
};
