class Solution {// TC--->O(1)             SC--->O(1)
public:
    void deleteNode(ListNode* node) {
        
        // Create a pointer to the node that needs to be deleted
        ListNode *DeleteNode = node->next;
        
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        
        // Point the current node's next pointer to the node after the next node
        node->next = node->next->next;
        
        // Delete the node that was originally after the current node
        delete DeleteNode;
    }
};
