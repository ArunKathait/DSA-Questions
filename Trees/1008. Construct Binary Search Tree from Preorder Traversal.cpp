
class Solution {// TC ---> O(N)                                SC ---> O(h) ---> height of the BST
public:

    // index -> current position in preorder array (passed by reference)
    // bound -> maximum value allowed in the current subtree
    TreeNode* buildBST(int &index, vector<int>& preorder, int bound)
    {
        // Base Case:
        // 1. If we have processed all elements, return NULL.
        // 2. If current value is greater than the allowed bound,
        //    it cannot belong to this subtree.
        if (index >= preorder.size() || preorder[index] > bound)
        {
            return NULL;
        }

        // Create the root node using the current preorder element.
        TreeNode *root = new TreeNode(preorder[index]);

        // Move to the next element in preorder.
        // Since preorder is Root -> Left -> Right,
        // the next element will either belong to the left subtree
        // or, if larger than root->val, the recursive call will return NULL.
        index++;

        // Construct the left subtree.
        // Every node in the left subtree must be smaller than root->val,
        // so the new upper bound becomes root->val.
        root->left = buildBST(index, preorder, root->val);

        // Construct the right subtree.
        // Right subtree values must be:
        //  > root->val (implicitly ensured because left subtree has already
        //    consumed all smaller values)
        //  <= current bound inherited from the parent.
        root->right = buildBST(index, preorder, bound);

        // Return the constructed subtree.
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        // Start processing from the first preorder element.
        int index = 0;

        // Initially there is no upper limit,
        // so use INT_MAX as the bound.
        return buildBST(index, preorder, INT_MAX);
    }
};
