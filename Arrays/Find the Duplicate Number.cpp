// Using Slow and Fast pointer

class Solution {//  TC--->O(N)       SC--->O(1)
public:
    int findDuplicate(vector<int>& nums) {
    // Initialize two pointers, 'slow' and 'fast', both initially pointing to the first element of the vector 'nums'.
        int slow = nums[0];
        int fast = nums[0];
        
        // Move 'slow' one step ahead and 'fast' two steps ahead initially.
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        // This loop finds the intersection point of 'slow' and 'fast' within a cycle.
        while(slow != fast)
        {
            // Move 'slow' one step ahead.
            slow = nums[slow];
            
            // Move 'fast' two steps ahead.
            fast = nums[nums[fast]];
        }
        
        //Again restart fast to nums[0]
        fast = nums[0];
        
         // At this point, we know there's a cycle, but we don't know where the cycle starts.
        // We reset one of the pointers to the beginning and move them at the same pace until they meet again.
        while(slow != fast)
        {
            // Move 'slow' one step ahead.
            slow = nums[slow];
            
            // Move 'fast' one step ahead.
            fast = nums[fast];
        }
        
 // 'fast' and 'slow' have met again, and this is the start of the cycle, which corresponds to the duplicate number.
        return fast;//We can also return slow here.
    }
};
