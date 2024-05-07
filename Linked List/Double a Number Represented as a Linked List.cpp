*****************************************APPROACH 1st************************************************************

class Solution {// TC--->O(N)           SC--->O(N)
public:
    ListNode* reverse(ListNode *head)
    {
        // Initialize current pointer to head of the list
        ListNode *current = head;
        
        // Initialize prev pointer to NULL, as it will be the last node in the reversed list
        ListNode *prev = NULL;
        
        // Iterate through the list
        while(current != NULL)
        {
            // Store the next node of the current node
            ListNode *next = current->next;
            
            // Reverse the link of the current node to point to the previous node
            current->next = prev;
            
            // Move prev pointer to the current node
            prev = current;
            
            // Move current pointer to the next node
            current = next;
        }
        // Return the new head of the reversed list (which is the last node of the original list)
        return prev;
    }
    
    
    ListNode* doubleIt(ListNode* head) {
        
        // Reverse the original list
        ListNode *reverseHead = reverse(head);
        
        // Initialize temp pointer to the head of the reversed list
        ListNode *temp = reverseHead;
        
        // Initialize prev pointer to temp, as it will be the last node in the list after doubling
        ListNode *prev = temp;
        
        // Initialize carry to 0
        int carry = 0;
        
        // Iterate through the list
        while(temp != NULL)
        {
            // Calculate the sum of the current node's value multiplied by 2 and carry
            int sum = carry + (temp->val*2);
            
            // Update carry for the next node
            carry = sum/10;
            
            // Update the current node's value with the remainder of sum divided by 10

            temp->val = sum%10;
            
            // Move prev pointer to the current node
            prev = temp;
            
            // Move temp pointer to the next node
            temp = temp->next;
        }
        
        // If there's a carry after iterating through the list, add a new node with the carry
        if(carry > 0)
        {
            // Create a new node with the carry value
            ListNode *newnode = new ListNode(carry);
            
            // Link the new node to the end of the list
            prev->next = newnode;
        }
        
        // Reverse the modified list and return it
        return reverse(reverseHead);
    }
};


********************************************APPROACH 2nd(RECURSION)**********************************************

class Solution {// TC--->O(N)              SC--->O(N)
public:
    
    int doubleUtil(ListNode *head)
    {
        // Base case: If the current node is NULL, return 0 (no carry)
        if(head == NULL)
        {
            return 0;
        }
        
        // Recursively call doubleUtil for the next node, to calculate carry for the next iteration
        int carry = doubleUtil(head->next);
        
        // Calculate the new value for the current node
        int newValue = (head->val)*2 + carry;
        
        // Update the value of the current node with the unit digit of newValue
        head->val = newValue%10;
        
        // Return the carry for the next iteration (tens digit of newValue)
        return newValue/10;
    }
    
    
    ListNode* doubleIt(ListNode* head) {
        
        // Call doubleUtil to double the values of nodes, starting from the head
        int lastCarry = doubleUtil(head);
        
        // If there's a carry after doubling the values of all nodes
        if(lastCarry > 0)
        {
            // Create a new node with the value of lastCarry
            ListNode *newHead = new ListNode(lastCarry);
            
            // Link the original list to the new node
            newHead->next = head;
            
            // Return the new head of the list
            return newHead;
        }
        
        // If there's no carry after doubling, return the original head of the list
        return head;
    }
};


*******************************************APPROACH 3rd(BETTER APPROACH)******************************************

class Solution {// TC--->O(N)              SC--->O(1)
public:
    ListNode* doubleIt(ListNode* head) {
        
        // Initialize a pointer to traverse the linked list
        ListNode *current = head;
        
        // If the value of the current node is greater than or equal to 5
        if(current->val >= 5)
        {
            // Create a new node with value 1 and make it the new head of the list
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            head = newHead;
        }
        
        // Iterate through the linked list
        while(current != NULL)
        {
            // Double the value of the current node and take the modulo 10
            current->val = (current->val*2)%10;
            
            // If the current node has a next node and the value of the next node is greater than or equal to 5
            if(current->next != NULL && current->next->val >= 5)
            {
                // Add 1 to the value of the current node (carry operation)
                current->val += 1;
            }
            
            // Move to the next node
            current = current->next;
        }
        
        // Return the head of the modified linked list
        return head;
    }
};
