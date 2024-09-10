***********************************************APPROACH 1st(ITERATIVE APPROACH))******************************************

class Solution {// TC--->O(N)                          SC--->O(1)
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Initialize 'current' to point to the head of the linked list
        ListNode *current = head;
        
        // Traverse the linked list, stopping when 'current' or 'current->next' is NULL
        while(current != NULL && current->next != NULL)
        {
            // Get the values of the current node and the next node
            int a = current->val;
            
            // Pointer to the next node
            ListNode *nextNode = current->next;
            int b = nextNode->val;
            
            // Calculate the greatest common divisor (GCD) of 'a' and 'b'
            // Built-in function to compute GCD
            int gcd = __gcd(a,b);
            
            // Create a new node with the GCD value
            ListNode *newnode = new ListNode(gcd);
            
            // Insert the new node between 'current' and 'nextNode'
            current->next = newnode;
            newnode->next = nextNode;
            
            // Move the 'current' pointer forward to the next node in the original list
            // Move to the next original node
            current = nextNode;
        }
        
        // Return the modified linked list
        return head;
    }
};


************************************************APPROACH 2nd(USING RECURSION)*******************************************

class Solution {// TC--->O(N)                           SC--->O(N)
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Base case: if the list is empty or only contains one node, return the head as it is
        if(head == NULL || head->next == NULL)
        {
            // No need to insert a GCD node, just return the current node
            return head;
        }
        
        // Recursive call: process the rest of the list from the second node onward
        ListNode *temp = insertGreatestCommonDivisors(head->next);
        
        // Calculate the GCD of the current node's value and the next node's value
        ListNode *gcdNode = new ListNode(__gcd(head->val,head->next->val));
        
        // Insert the newly created GCD node between the current node and the rest of the list
        // Connect the GCD node to the rest of the processed list
        gcdNode->next = temp;
        
        // Connect the current node to the GCD node
        head->next = gcdNode;
        
        // Return the updated list starting from the current head
        return head;
    }
};
