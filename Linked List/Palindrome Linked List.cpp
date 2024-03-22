****************************************APPROACH 1st(USING STACK)****************************************

class Solution {// TC--->O(N)           SC--->O(N)
public:
  
    bool isPalindrome(ListNode* head) {
    // Create a stack to store values of the linked list nodes
    stack<int> st;
    
    // Temporary pointer to traverse the linked list
    ListNode *temp = head;
    
    // Traverse the linked list and push the values onto the stack
    while (temp != NULL) 
    {
        st.push(temp->val); // Push the value of the current node onto the stack
        temp = temp->next; // Move to the next node
    }
    
    // Reset temp pointer to the head of the linked list
    temp = head;
    
    // Traverse the linked list again and compare values with the stack
    while (!st.empty()) 
    {
        // Check if the value at the top of the stack is not equal to the value of the current node
        if (st.top() != temp->val) 
        {
            return false; // If values don't match, it's not a palindrome
        }
        
        temp = temp->next; // Move to the next node
        st.pop(); // Pop the top element from the stack
    }
    
    return true; // If all corresponding nodes match, it's a palindrome
}
};

*********************************************APPROACH 2nd***************************************************
// Reverse 2nd Half Of Linked List
  
class Solution {// TC--->O(N)            SC--->O(1)
public:
    // Function to reverse a linked list
    ListNode *reverseList(ListNode *head)
    {
        // Initialize current pointer to the head of the list
        ListNode *current = head;
        
        // Initialize previous pointer to NULL
        ListNode *prev = NULL;
        
        // Traverse the list and reverse the pointers
        while(current != NULL)
        {
            // Store the next node
            ListNode *newnode = current->next;
            
            // Reverse the pointer to previous node
            current->next = prev;
            
            // Move previous pointer one step ahead
            prev = current;
            
            // Move current pointer one step ahead
            current = newnode;
        }
        
        // Return the new head of the reversed list
        return prev;
    }
    
    // Function to check if a linked list is palindrome
    bool isPalindrome(ListNode* head) {
        
        // Check if the linked list is empty (head is NULL) or has only one node (head->next is NULL)
        if(head == NULL || head->next == NULL)
        {
            // If either condition is true, return true because an empty list or a single-node list is              //  considered a palindrome
            return true;
        }
        
        // Initialize slow pointer to head of the list
        ListNode *slow = head;
        
        // Initialize fast pointer to head of the list
        ListNode *fast = head;
        
        // Initialize a pointer to keep track of the middle node
        ListNode *prev = NULL;
        
        // Move slow and fast pointers to find the middle of the list
        while(fast != NULL && fast->next != NULL)
        {
            // Update prev pointer
            prev = slow;
            
            // Move slow pointer one step ahead
            slow = slow->next;
            
            // Move fast pointer two steps ahead
            fast = fast->next->next;
        }
        
        // Break the list into two halves
        prev->next = NULL;
        
        // Reverse the second half of the list
        ListNode *reverseHead =  reverseList(slow);
        
        // Traverse both halves of the list and compare corresponding nodes
        while(head != NULL && reverseHead != NULL)
        {
            // If values don't match, it's not a palindrome
            if(head->val != reverseHead->val)
            {
                return false;
            }
            
            // Move head pointer of the first half forward
            head = head->next;
            
            // Move head pointer of the reversed half forward
            reverseHead = reverseHead->next;
        }
        
        // If all corresponding nodes match, it's a palindrome
        return true;
    }
};

********************************************3rd APPROACH(BETTER APPROACH)****************************************

class Solution {// TC--->O(N)          SC--->O(1)
public:
    bool isPalindrome(ListNode* head) {
        
        // Check if the linked list is empty or has only one node
        if(head == NULL || head->next == NULL)
        {
            // If true, it's considered a palindrome
            return true;
        }
        
        // Pointer for the slow traversal of the list
        ListNode *slow = head;
        
        // Pointer for the fast traversal of the list
        ListNode *fast = head;
        
        // Pointer to keep track of the previous node
        ListNode *prev = NULL;
        
        // Find the middle of the linked list using slow and fast pointers
        while(fast != NULL && fast->next != NULL)
        {
            // Move fast pointer two steps ahead
            fast = fast->next->next;
            
            // Store the next node
            ListNode *nextNode = slow->next;
            
            // Reverse the pointers
            slow->next = prev;
            
            // Move prev pointer one step ahead
            prev = slow;
            
            // Move slow pointer one step ahead
            slow = nextNode;
        }
        
        // If the number of nodes is odd, move slow pointer one step forward
        if(fast != NULL)
        {
            slow =slow->next;
        }
        
        // Compare values of the first half (prev) and second half (slow) of the list
        while(slow !=NULL && prev != NULL)
        {
            // If values don't match, it's not a palindrome
            if(slow->val != prev->val)
            {
                return false;
            }
            
            // Move prev pointer forward
            prev = prev->next;
            
            // Move slow pointer forward
            slow = slow->next;
        }
        
        // If all corresponding nodes match, it's a palindrome
        return true;
    }
};

***************************************APPROACH 4(RECURSION)***********************************************
class Solution {// TC--->O(N)             SC--->O(N)
public:
    
    // Global variable to keep track of the current node
    ListNode *current;
    
    // Recursive function to check if the linked list is palindrome
    bool recur(ListNode *head)
    {
        // Base case: If the head is NULL, we've reached the end of the list, so it's a palindrome
        if(head == NULL)
        {
            return true;
        }

        // Recursively call the function with the next node in the list
        bool ans = recur(head->next);
        
    // Check if the value of the current node matches the value of the corresponding node from the end
        if(current->val != head->val)
        {
            // If values don't match, it's not a palindrome
            return false;
        }
        
         // Move the current pointer to the next node
        current = current->next;
        
        // Return the result of the recursive call
        return ans;
    }
    
    // Main function to check if the linked list is palindrome
    bool isPalindrome(ListNode* head) {
        
        // Set the current pointer to the head of the list
        current = head;
        
        // Call the recursive function and return its result
        return recur(head);
    }
};
