

class Solution {// TC--->O(2N)                         SC--->O(1)
public:
    // Function to find the k-th node from the current node
    // Traverses k nodes starting from 'temp'. If k nodes are found, it returns the k-th node.
    // If there are fewer than k nodes left, it returns NULL.
    ListNode *findKthNode(ListNode *temp,int k)
    {
        while(temp != NULL && k > 1)
        {
            // Move to the next node
            temp = temp->next;
            
            // Decrease k with each iteration
            k--;
        }
        
         // Return the k-th node or NULL if the list is shorter than k
        return temp;
    }
    
    // Function to reverse a linked list from 'head' to NULL
    // It reverses the entire sublist starting from 'head'.
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = NULL;
        
        // Iterate through the list and reverse the pointers
        while(current != NULL)
        {
             // Store the next node
            ListNode *next = current->next;
            
            // Reverse the current node's next pointer
            current->next = prev;
            
            // Move 'prev' forward
            prev = current;
            
            // Move 'current' to the next node
            current = next;
        }
        
        // 'prev' becomes the new head of the reversed list
        return prev;
    }
    
     // Function to reverse nodes in groups of size k
    ListNode* reverseKGroup(ListNode* head, int k) {
         // Start from the head of the list
        ListNode *temp = head;
        
        // This will keep track of the last node of the previous reversed group
        ListNode *prevLast = NULL;
        
        // Traverse the list in chunks of k nodes
        while(temp != NULL)
        {
            // Find the k-th node from the current position
            ListNode *kthNode = findKthNode(temp,k);
            
            // If there are fewer than k nodes left
            if(kthNode == NULL)
            {
                if(prevLast)
                {
                    // Connect the remaining nodes without reversing
                    prevLast->next = temp;
                }
                
                // No more groups to reverse, so exit the loop
                break;
            }
            
            // Save the node after the k-th node (next group)
            ListNode *nextNode = kthNode->next;
            
            // Temporarily cut the connection to isolate the k nodes
            kthNode->next = NULL;
            
             // Reverse the current group of k nodes
            reverseList(temp);
            
            // If this is the first group, the new head of the list will be the k-th node
            if(head == temp)
            {
                head = kthNode;
            }
            // For subsequent groups, connect the last node of the previous group to the new head of the current reversed group
            else
            {
                prevLast->next = kthNode;
            }
            
            // The current 'temp' becomes the last node of the reversed group
            prevLast = temp;
            
            // Move to the next group of nodes
            temp = nextNode;
        }
        
        // Return the new head of the list
        return head;
    }
};
