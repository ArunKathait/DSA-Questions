
class Solution {// TC--->O(N)                        SC--->O(K)
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // To store the total length of the linked list
        int length = 0;
        
        // Pointer to traverse the linked list
        ListNode *current = head;
        
        // First loop: Calculate the total length of the linked list
        while(current != NULL)
        {
            // Increment length for each node
            length++;
            
            // Move to the next node
            current = current->next;
        }
        
        // Determine how many nodes will be in each part and the remainder
        // Minimum nodes in each part
        int eachBucketNodes = length/k;
        
        // Extra nodes to distribute evenly
        int remainingNodes = length%k;
        
        // Index to keep track of the current part
        int i = 0;
        
        // Reset current to the head of the list for the second pass
        current = head;
        
        // To keep track of the previous node
        ListNode *prev = NULL;
        
         // Initialize a vector of size `k` to store the heads of the split parts, all initially set to NULL
        vector<ListNode*>ans(k,0);
        
        // Second loop: Split the list into k parts
        while(current != NULL && i < k)
        {
            // Set the start of the current part to the current node
            ans[i] = current;
            
            // Calculate how many nodes should be in the current part
            // Each part will have at least `eachBucketNodes` nodes, and if `remainingNodes > 0`, it gets 1 extra node
            for(int count=1;count<=eachBucketNodes + (remainingNodes > 0 ? 1 : 0);count++)
            {
                // Keep track of the last node in the current part
                prev = current;
                
                // Move to the next node
                current = current->next;
            }
            
            // Disconnect the current part from the rest of the list
            prev->next = NULL;
            
            // Move to the next part
            i++;
            
            // Decrease remainingNodes as one extra node has been assigned (if any)
            remainingNodes--;
        }
        
        // Return the vector containing the heads of the split parts
        return ans;
    }
};
