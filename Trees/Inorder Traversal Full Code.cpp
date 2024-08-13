
#include<iostream>
using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode *left, *right;
    
    TreeNode(int new_data)
    {
        data = new_data;
        left = NULL;
        right = NULL;
        // Removed `next` as it is not necessary for a binary tree node.
    }
};

void inorder(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    
    // Traverse the left subtree
    inorder(root->left);
    
    // Visit the root node
    cout << root->data << " ";
    
    // Traverse the right subtree
    inorder(root->right);
}

int main()
{
    // Creating the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    cout << "Inorder Traversal: ";
    
    // Performing inorder traversal
    inorder(root);
    
    cout << endl;  // Add a new line after the traversal output
    
    return 0;
}
