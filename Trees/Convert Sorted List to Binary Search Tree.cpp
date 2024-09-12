
class Solution {// TC--->O(NlogN)                       SC--->O(logN)
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Base case 1: If the head is NULL, the linked list is empty, return NULL.
        if(head == NULL)
        {
            return NULL;
        }
        
        // Base case 2: If there's only one node in the list, create a TreeNode with that value and return it.
        if(head->next == NULL)
        {
            return new TreeNode(head->val);
        }
        
        // Initialize pointers to find the middle of the list.
        ListNode *slow = head;            // Slow pointer (moves one step at a time).
        
        ListNode *fast = head;            // Fast pointer (moves two steps at a time).
        
        ListNode *slowPrev = NULL;        // Pointer to keep track of the node before the slow pointer.
        
        // Move slow pointer to the middle of the list and fast pointer to the end.
        while(fast != NULL && fast->next != NULL)
        {
            // Keep track of the node before slow.
            slowPrev = slow;
            
            // Move slow by one step.
            slow = slow->next;
            
            // Move fast by two steps.
            fast = fast->next->next;
        }
        
        // Slow pointer is now at the middle node. This will be the root of the BST.
        TreeNode *root = new TreeNode(slow->val);// Create a new TreeNode with the value at the slow pointer.
        
        // Disconnect the left half of the list from the middle node.
        slowPrev->next = NULL;// Break the list into two halves by setting the node before slow to NULL.
        
        // Recursive call: Build the left subtree using the left half of the list.
        root->left = sortedListToBST(head); // Recursively convert the left part of the list to a BST.
        
        // Recursive call: Build the right subtree using the right half of the list.
        root->right = sortedListToBST(slow->next);// Recursively convert the right part of the list to a BST.
        
        // Return the root node of the BST.
        return root;
    }
};
