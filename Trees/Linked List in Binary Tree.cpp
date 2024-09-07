class Solution {// TC--->O(N * M)                            SC--->O(N + M)
public:
    // This helper function checks if the linked list starting at 'head'
    // matches a path in the binary tree starting at 'root'.
    bool check(ListNode *head,TreeNode *root)
    {
        // Base case 1: If the linked list has been fully traversed,
        // it means we have found a matching path.
        if(head == NULL)
        {
            return true;
        }
        
        
        // Base case 2: If we reach a null node in the tree but the linked list
        // is not fully traversed, return false (no match).
        if(root == NULL)
        {
            return false;
        }
        
        // If the current node values in the linked list and tree do not match,
        // return false.
        if(head->val != root->val)
        {
            return false;
        }
        
        // Recurse by checking both left and right subtrees of the current tree node.
        // The linked list moves to its next node (head->next).
        // If any of these paths returns true, we have a match.
        return check(head->next,root->left) || check(head->next,root->right);
    }
    
    // This function checks if the linked list starting at 'head' is a subpath 
    // of the binary tree starting at 'root'.
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        // Base case: If the tree is empty (root is NULL), there can be no path, so return false.
        if(root == NULL)
        {
            return false;
        }
        
        // There are three possibilities to check:
        // 1. The current root node starts a valid subpath matching the linked list.
        // 2. The linked list could match starting in the left subtree of the current node.
        // 3. The linked list could match starting in the right subtree of the current node.
        return check(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};
