
class Solution {// TC--->O(N)                    SC--->O(1)
public:
    int getDecimalValue(ListNode* head) {
        // This will store the final decimal value of the binary number
        int ans = 0;  
        
        // Traverse the linked list until the end
        while(head) 
        {  
            // Shift the current value of 'ans' to the left by 1 bit (equivalent to multiplying by 2)
            // Then use bitwise OR '|' to add the current node's bit (0 or 1) to the rightmost position
            ans = (ans << 1) | head->val;

            // Move to the next node in the list
            head = head->next;
        }

        // After processing all bits, return the final decimal value
        return ans;
    }
};
