class Solution {//TC--->O(N)           SC--->O(N)
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a dummy node to handle cases where the entire list is removed
        ListNode *dummy = new ListNode(0);
        
        // Connect the dummy node to the head of the given linked list
        dummy->next = head;
        
        // Create an unordered map to store the prefix sum and its corresponding node
        unordered_map<int,ListNode*>ump;
        
        // Initialize with 0 sum and dummy node
        ump[0] = dummy;
        
        // Initialize prefix sum
        int prefix_sum = 0;
        
        // Traverse the linked list
        while(head!=NULL)
        {
            // Update prefix sum
            prefix_sum += head->val;
            
            // If the current prefix sum is found in the map, it means there is a sublist with sum 0
            if(ump.find(prefix_sum)!=ump.end())
            {
                // Get the node where the prefix sum was first encountered
                ListNode *start = ump[prefix_sum];
                
     //Create a temp pointer and assign start to it because we traverse it forward to erase the nodes
                ListNode *temp = start;
                
                //Assign prefix_sum to pSum
                int pSum = prefix_sum;
                
        // Traverse the sublist again to remove nodes and erase their corresponding sums from the map
                while(temp != head)
                {
                    temp = temp->next;
                    
                    // Update the pSum by adding temp->val to it
                    pSum += temp->val; 
                    
                    // Erase the prefix sums until we reach the current head
                    if(temp != head)
                    {
                        ump.erase(pSum);
                    } 
                }
                // Adjust the pointers to skip the sublist with sum 0
                start->next = head->next;
            }
            else
            {
                // If the current prefix sum is not found, store it in the map along with its node
                ump[prefix_sum] = head;
            }
            
            // Move to the next node in the linked list
            head = head->next;
        }
        
        // Return the modified linked list (excluding nodes with sum 0)
        return dummy->next;
    }
};
