***********************************APPROACH 1st(USING EXTRA SPACE)*******************************************************

class Solution {// TC--->O(N + M)                       SC--->O(N + M)
public:
    // Function to return a modified list by removing nodes whose values exist in the 'nums' vector
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create an unordered set from the vector 'nums' for quick lookup.
        unordered_set<int>ump(nums.begin(),nums.end());
        
        // Dummy node to act as the starting point of the new linked list
        ListNode *dummy = new ListNode();
        
        // 'temp' is used to build the new linked list.
        ListNode *temp = dummy;
        
        // 'current' is used to traverse the original linked list.
        ListNode *current = head;
        
         // Traverse the entire original linked list.
        while(current != NULL)
        {
            // Check if the current node's value is NOT in the unordered set 'ump'
            if(ump.find(current->val) == ump.end())
            {
                // Create a new node with the current node's value
                ListNode *newnode = new ListNode(current->val);
                
                // Append this new node to the result list
                temp->next = newnode;
                
                // Move the 'temp' pointer forward to the newly added node
                temp = temp->next;
            }
            
            // Move to the next node in the original list
            current = current->next;
        }
        
        // Return the new linked list starting from the node after the dummy node
        return dummy->next;
    }
};

**********************************************APPROACH 2nd**************************************************************

class Solution {// TC--->O(N + M)                          SC--->O(N)
public:
    // Function to modify the list by removing nodes whose values are in the vector 'nums'
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create an unordered set from the 'nums' vector for fast lookup
        unordered_set<int>set(nums.begin(),nums.end());
        
        // Handle the case where the head node itself has a value in the 'set'
        // Continue removing nodes from the beginning as long as the head's value is found in the set
        while(head != NULL && set.find(head->val) != set.end())
        {
            // Store the current head
            ListNode *temp = head;
            
            // Move head to the next node
            head = head->next;
            
            // Delete the current head node to free memory
            delete(temp);
        }
        
        // Now handle the rest of the list, starting from the updated head
        ListNode *current = head;
        
        // Traverse the list until the end
        while(current != NULL && current->next != NULL)
        {
            // Check if the next node's value exists in the set
            if(set.find(current->next->val) != set.end())
            {
                // If the value is found, we need to remove this node
                // Store the node to be deleted
                ListNode *temp = current->next;
                
                // Skip the node (bypass it)
                current->next = current->next->next;
                
                // Delete the skipped node
                delete(temp);
            }
            else
            {
                // If the next node's value is not in the set, move the 'current' pointer forward
                current = current->next;
            }
        }
        
        // Return the updated head of the list
        return head;
    }
};
