***********************************************APPROACH 1st(USING STACK)*******************************************

class Solution {// TC--->O(N)            SC--->O(N)
public:
    ListNode* removeNodes(ListNode* head) {
        
        // Create a stack to store nodes in decreasing order of values
        stack<ListNode*>st;
        
        // Temporary pointer to traverse the linked list
        ListNode *temp = head;
        
        // Traverse the linked list
        while(temp != NULL)
        {
            // While the stack is not empty and the value of current node is greater than the value of top node in stack
            while(!st.empty() && temp->val > st.top()->val)
            {
                // Pop nodes from the stack until the current node's value is less than or equal to the top node's value
                st.pop();
            }
            
            // Push the current node onto the stack
            st.push(temp);
            
            // Move to the next node in the linked list
            temp = temp->next;
        }
        
        // Variable to store the next node in the modified linked list
        ListNode *next = NULL;
        
        // Reconstruct the linked list using nodes from the stack
        while(!st.empty())
        {
            // Pop a node from the stack
            temp = st.top();
            st.pop();
            
            // Set the next pointer of the popped node to the previously processed node
            temp->next = next;
            
            // Update the next pointer to the popped node
            next = temp;
        }
        
        // Return the head of the modified linked list
        return temp;   
    }
};


*********************************************APPROACH 2nd(USING RECURSION)*****************************************

class Solution {// TC--->O(N)               SC--->O(N)
public:
    ListNode* removeNodes(ListNode* head) {
        
        // Base case: If the head is NULL or the head has no next node
        // In these cases, there are no nodes to remove, so simply return the head
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        // Recursively call removeNodes function on the next node
        ListNode *nextNode = removeNodes(head->next);
        
        
        // Check if the current node's value is less than the value of the next node
        // If true, delete the current node and return the next node
        if(head->val < nextNode->val)
        {
            delete head;
            return nextNode;
        }
        
        // If the current node's value is greater than or equal to the next node's value,
        // set the next pointer of the current node to the nextNode returned from recursive call
        head->next = nextNode;
        
        // Return the current node as it will be part of the modified list
        return head;
    }
};


******************************************APPROACH 3rd*************************************************************

class Solution {// TC--->O(N)                   SC--->O(1)
public:
    // Function to reverse a linked list
    ListNode *reverseList(ListNode *head)
    {
        // Pointer to traverse the list
        ListNode *current = head;
        
        // Pointer to keep track of the previous node
        ListNode *prev = NULL;
        
        // Iterate through the list
        while(current != NULL)
        {
            // Save the next node
            ListNode *nextNode = current->next;
            
            // Reverse the pointer to the previous node
            current->next = prev;
            
            // Move the prev pointer one step forward
            prev = current;
            
            // Move the current pointer one step forward
            current = nextNode;
        }
        
        // Return the new head of the reversed list
        return prev;
    }
    
    // Function to remove nodes whose value is less than the maximum value encountered so far
    ListNode* removeNodes(ListNode* head) {
        
        // Reverse the list to facilitate removal
        head = reverseList(head);
        
        // Variable to store the maximum value encountered
        int maxNode = -1;
        
        // Pointer to keep track of the previous node
        ListNode *prev = NULL;
        
        // Pointer to traverse the list
        ListNode *current = head;
        
        // Iterate through the list
        while(current != NULL)
        {
            // Update maxNode with the maximum value encountered so far
            maxNode = max(maxNode,current->val);
            
             // If the current node's value is less than maxNode, remove the node
            if(current->val < maxNode)
            {
                // Link the previous node to the next node
                prev->next = current->next;
                
                // Store the current node to be deleted
                ListNode *temp = current;
                
                // Move current pointer to the next node
                current = current->next;
                
                // Delete the node
                delete temp;
            }
            else
            {
                // Move prev pointer to the current node
                prev = current;
                
                // Move current pointer to the next node
                current = current->next;
            }
        }
        
        // Reverse the list back to its original order and return
        return reverseList(head);
    }
};
