*********************************************APPROACH 1st********************************************************

class Solution {// TC--->O(N)                  SC--->O(1)
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Initialize pointers to traverse the linked list
        
        // current node is the second node initially
        ListNode *current = head->next;
        
        // prev node is the first node
        ListNode *prev = head;
        
        // position of the last critical point encountered
        int previousCriticalPos = 0;
        
        // position of the first critical point encountered
        int firstCriticalPos = 0;
        
        // current position in the list (1-based index)
        int currentPos = 1;
        
        // minimum distance between two critical points, initialized to maximum integer value
        int minDist = INT_MAX;
        
        // Traverse the linked list until the second last node
        while(current->next != NULL)
        {
            // Check if the current node is a critical point
            if((current->val > current->next->val && current->val > prev->val) ||
              (current->val < current->next->val && current->val < prev->val))
            {
                // If it's the first critical point encountered
                if(firstCriticalPos == 0)
                {
                    // set the position of the first critical point
                    firstCriticalPos = currentPos;
                    
                    // set the last critical point position to the current position
                    previousCriticalPos = currentPos;
                }
                else
                {
                    // Calculate the distance between the current and previous critical points
                    minDist = min(minDist,currentPos - previousCriticalPos);
                    
                    // update the last critical point position
                    previousCriticalPos = currentPos;
                }
            }
            
            // Move to the next node
            currentPos++;
            prev = current;
            current = current->next;
        }
        
        // If no critical points or only one critical point was found
        if(minDist == INT_MAX)
        {
            // return -1, -1 indicating no valid critical point distances
            return {-1,-1};
        }
        
        // Return the minimum distance and the distance between the first and last critical points
        return {minDist,previousCriticalPos - firstCriticalPos};
    }
};


**************************************************APPROACH 2nd**************************************************

class Solution {// TC--->O(N)                SC--->O(1)
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Initialize variables to store values of the previous, current, and next nodes
        int prevVal = 0;
        int currentVal = 0;
        int nextVal = 0;
        
        // Initialize positions for the first and previous critical points
        int firstCriticalPos = 0;
        int prevCriticalPos = 0;
        
        // Initialize the minimum distance to the maximum integer value
        int minDist = INT_MAX;
        
        // Initialize the current position in the list
        int currentPos = 1;
        
        // Initialize the answer vector with default values of -1, -1
        vector<int>ans = {-1,-1};
        
        // Traverse the linked list
        while(head != NULL)
        {
            // Update the values of the previous, current, and next nodes
            prevVal = currentVal;
            currentVal = nextVal;
            nextVal = head->val;
            
            // Check if the current node is a critical point
            if(prevVal != 0 && currentVal != 0 && nextVal != 0 && ((prevVal > currentVal && currentVal < nextVal) || (prevVal < currentVal && currentVal > nextVal)))
            {
                // If this is the first critical point encountered
                if(firstCriticalPos == 0)
                {
                    // set the position of the first critical point
                    firstCriticalPos = currentPos;
                }
                else
                {
                    // Calculate the minimum distance between critical points
                    minDist = min(minDist,currentPos - prevCriticalPos);
                    
                    // Update the answer vector with the minimum distance and the distance between first and last critical points
                    ans = {minDist,currentPos - firstCriticalPos};
                }
                
                // Update the position of the previous critical point
                prevCriticalPos = currentPos;
            }
            
            // Move to the next node in the list
            head = head->next;
            
            // Increment the current position
            currentPos++;
        }
        
        // Return the answer vector
        return ans;
    }
};
