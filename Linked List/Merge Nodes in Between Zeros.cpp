
class Solution {// TC--->O(N)                SC--->O(1)
public:
    ListNode* mergeNodes(ListNode* head) {
        // Check if the list is empty or contains only one node
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        // Initialize pointers
        // Pointer to build the new list
        ListNode *temp = head;
        
        // Pointer to traverse the original list
        ListNode *forward = head->next;
        
        // Traverse the original list
        while(forward != NULL)
        {
            // Initialize sum to store values between zeros
            int sum = 0;
            
            // Sum up the values between zeros
            while(forward != NULL && forward->val != 0)
            {
                sum += forward->val;
                forward = forward->next;
            }
            
            // Create a new node with the sum
            ListNode *newnode = new ListNode(sum);
            
            // Attach the new node to the result list
            temp->next = newnode;
            
            // Move the temp pointer to the new node
            temp = temp->next;
            
            // Move the forward pointer to the next node (after zero)
            forward = forward->next;
        }
        
        // Return the head of the new list (excluding the initial zero)
        return head->next;
    }
};





