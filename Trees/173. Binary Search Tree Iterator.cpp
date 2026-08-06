
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *          : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
public:

    // Stack stores the path from the root
    // to the current smallest unvisited node.
    stack<TreeNode*> st;

    // Push all left nodes starting from 'root'
    // onto the stack.
    //
    // Since inorder traversal visits:
    // Left -> Root -> Right,
    // the leftmost node will always be
    // the next smallest element.
    void storeLeftNodes(TreeNode *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }

    // Constructor:
    // Initially push the leftmost path
    // starting from the root.
    BSTIterator(TreeNode* root) // TC --> O(h)                      SC ---> O(h)
    {
        storeLeftNodes(root);
    }

    // Returns the next smallest element.
    int next() // TC ---> O(1)                          SC ---> O(h)
    {
        // The top of the stack is always
        // the next smallest node.
        TreeNode *current = st.top();
        st.pop();

        // After visiting the current node,
        // move to its right subtree.
        //
        // Again, push all the left nodes
        // of the right subtree because
        // inorder traversal visits the
        // leftmost node first.
        storeLeftNodes(current->right);

        // Return the current node value.
        return current->val;
    }

    // Returns true if there are still
    // unvisited nodes remaining.
    bool hasNext() // TC ---> O(1)                          SC ---> O(1)
    {
        return st.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 *
 * BSTIterator* obj = new BSTIterator(root);
 *
 * int value = obj->next();
 *
 * bool exists = obj->hasNext();
 */
