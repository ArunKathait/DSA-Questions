**********************************************APPROACH 1st***************************************************

class Solution {// TC--->O(N)           SC--->O(N)
public:
    ListNode* reverseList(ListNode* head) {
        // Create a stack to store the values of the linked list nodes
        stack<int>st;
        
        // Temporary pointer to traverse the linked list starting from the head
        ListNode *temp = head;
        
        // Traverse the linked list and push the values onto the stack
        while(temp != NULL)
        {
            // Push the value of the current node onto the stack
            st.push(temp->val);
            
            // Move to the next node
            temp = temp->next;
        }
        
        // Reset the temporary pointer to the head of the list
        temp = head;
        
        // Traverse the linked list again
        while(temp != NULL)
        {
            // Update the value of the current node with the top value from the stack
            temp->val = st.top();
            
            // Remove the top value from the stack
            st.pop();
            
            /// Move to the next node
            temp = temp->next;
        }
        
        // Return the head of the reversed linked list
        return head;
    }
};

******************************************APPROACH 2nd*******************************************************

class Solution {// TC--->O(N)            SC--->O(1)
public:
    ListNode* reverseList(ListNode* head) {
      
        // Initialize two pointers: prev to keep track of the previous node and current to traverse the list
        // Initially, prev is NULL as there is no previous node before the head
        ListNode *prev = NULL;
        
        // Start traversing the list from the head
        ListNode *current = head;
        
        // Iterate through the list until we reach the end
        while(current != NULL)
        {
            // Store the next node in a temporary variable
            ListNode *nextNode = current->next;
            
            // Reverse the pointer of the current node to point back to the previous node
            current->next = prev;
            
            // Move prev to the current node and current to the next node for the next iteration
            prev = current;
            current = nextNode;
        }
        
        // After the loop, prev will point to the new head of the reversed list
        return prev;
    }
};
