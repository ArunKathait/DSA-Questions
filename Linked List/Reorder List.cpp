*******************************************APPROACH 1st(USING STACK)****************************************

class Solution {// TC--->O(N)           SC--->O(N)
public:
    void reorderList(ListNode* head) {
        // Create a stack to store the nodes
        stack<ListNode*>st;
        
        // Traverse the linked list and push each node onto the stack
        ListNode *current = head;
        while(current != NULL)
        {
            st.push(current);
            
            // Move to the next node
            current = current->next;
        }
        
        // Reset current pointer to the head of the list
        current = head;
        
        // Calculate the number of nodes to process
        int k = st.size()/2;
        
        // Reorder the list by popping nodes from the stack and inserting them between nodes of                 // the original list
        while(k--)
        {
            // Pop a node from the stack
            ListNode *element = st.top();
            st.pop();
            
            // Save the next node in the original list
            ListNode *temp = current->next;
            
            // Update pointers to insert the popped node between current and temp
            // Make current point to the popped node
            current->next = element;
            
            // Make the popped node point to the next node in the original list
            element->next = temp;
            
            // Move current pointer to the next node in the original list (which is now temp)
            current = temp;
        }
        
        // Set the next pointer of the last node to NULL to terminate the list
        current->next = NULL;
        
    }
};

*******************************************APPROACH 2nd***********************************************

class Solution {// TC--->O(N)        SC--->O(1)
public:
    // Function to reverse a linked list
    ListNode *reverseList(ListNode *head)
    {
        // Initialize pointers for reversing the list
        // Pointer to the previous node, initially NULL
        ListNode *prev = NULL;
        
        // Pointer to the current node, initially at the head
        ListNode *current = head;
        
        // Traverse the list, reversing pointers along the way
        while(current != NULL)
        {
            // Store the next node
            ListNode *newnode = current->next;
            
            // Reverse the pointer to the previous node
            current->next = prev;
            
            // Move prev to current
            prev = current;
            
            // Move current to the next node
            current = newnode;
        }
        
        // Return the new head of the reversed list
        return prev;
    }
    
    // Function to reorder a linked list
    void reorderList(ListNode* head) {
        
        // Pointer to traverse the list one step at a time
        ListNode *slow = head;
        
        // Pointer to traverse the list two steps at a time
        ListNode *fast = head;
       
        // Find the middle of the list using the slow and fast pointers
        while(fast!=NULL && fast->next!=NULL)
        {
            // Move fast two steps ahead
            fast = fast->next->next;
            
        // Move slow one step ahead
            slow = slow->next;
        }
        
        // Pointer to traverse the first half of the list
        ListNode *current = head;
      
        // Reverse the second half of the list
        ListNode *reversehead = reverseList(slow);
    
        // Merge the two halves of the list alternately
        while(reversehead->next != NULL)
        {
            // Store the next node in the original list
            ListNode *headnext = current->next;
            
            // Store the next node in the reversed list
            ListNode *revnext = reversehead->next;
            
            // Update pointers to insert the reversed node
            // Insert the reversed node into the original list
            current->next = reversehead;
            
            // Point the reversed node to the next node in the original list
            reversehead->next = headnext;
              
             // Move to the next nodes
            // Move to the next node in the original list
            current = headnext;
            
            // Move to the next node in the reversed list
            reversehead = revnext;
        }     
    }
};
