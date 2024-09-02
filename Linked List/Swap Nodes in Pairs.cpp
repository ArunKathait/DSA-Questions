**********************************************APPROACH 1st(SIMPLE APPROACH)**********************************************
// NOTE:Here we are modifying the linked list so it is not a good approach.

class Solution {// TC--->O(N)                       SC--->O(1)
public:
    ListNode* swapPairs(ListNode* head) {
        // Check for base cases
        // If the list is empty (head is NULL) or contains only one node (head->next is NULL),
        // return the head as there are no pairs to swap.
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        // Initialize a pointer to traverse the linked list starting from the head.
        ListNode *current = head;
        
        // Traverse the linked list in pairs
        // Continue while there are at least two nodes left to swap.
        while(current != NULL && current->next != NULL)
        {
            // Swap values of the current node and the next node.
            int val = current->val;                  // Store the value of the current node.
            current->val = current->next->val;       // Assign the value of the next node to the current node.
            current->next->val = val;                // Assign the stored value to the next node.
            
            // Move to the next pair
            // Advance the current pointer by two nodes to continue swapping pairs.
            current = current->next->next;
        }
        
        // Return the modified list
        // The head pointer still points to the beginning of the modified list.
        return head;
    }
};

************************************************APPROACH 2nd(BETTER APPROACH)*****************************************

class Solution {// TC--->O(N)                            SC--->O(1)
public:
    ListNode* swapPairs(ListNode* head) {
        // Check if the list is empty or has only one node.
        // If either condition is true, return the head as no swapping is needed.
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        // Create a dummy node to act as the previous node to the head.
        // This helps in handling the edge cases more easily.
        ListNode *dummy = new ListNode();
        
        // This node will always point to the node before the pair being swapped.
        ListNode *prevNode = dummy;
        
        // Initialize current node as the head of the list.
        ListNode *current = head;
        
        // Traverse the list while there are at least two nodes left to swap.
        while(current != NULL && current->next != NULL)
        {
            // Perform the swapping of the current node and the next node.
            // Point the previous node's next to the second node in the pair.
            prevNode->next = current->next;
            
            // Re-point the current node's next to the node after the next node.
            current->next = prevNode->next->next;
            
            // Connect the second node's next to the first node in the pair.
            prevNode->next->next = current;
            
            // Move the previous node pointer to the current node (which is now the second node in the swapped pair).
            prevNode = current;
            
            // Move the current pointer to the next pair (next node to be swapped).
            current = current->next;
        }
        
        // Return the new head of the list, which is the node after the dummy node.
        return dummy->next;
    }
};

******************************************************APPROACH 3rd(USING RECURSION)************************************

class Solution {// TC--->O(N)                         SC--->O(N)
public:
    ListNode* swapPairs(ListNode* head) {
        // Base cases
        // If the list is empty (head is NULL) or contains only one node (head->next is NULL),
        // there are no pairs to swap, so return the head as is.
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        // Identify the nodes to swap
        // `temp` points to the second node in the current pair.
        ListNode *temp = head->next;
        
        // Recursively call swapPairs for the rest of the list
        // The head's next pointer is set to the result of swapPairs starting from the third node.
        // This effectively swaps pairs in the remaining part of the list.
        head->next = swapPairs(head->next->next);
        
        // Complete the swap of the current pair
        // Point `temp`'s next to `head` to complete the swap of the current pair.
        temp->next = head;
        
        // Return the new head of the list
        // `temp` is now the new head of the current swapped pair, so return it.
        return temp;
    }
};
