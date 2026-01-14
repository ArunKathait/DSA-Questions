
class Solution {// TC ---> O(N)                            SC ---> O(1)
public:
    int jump(vector<int>& nums) {

        int n = nums.size();   // Total number of positions

        int farthest = 0;      // Farthest index reachable so far
        int jumps = 0;         // Number of jumps taken
        int current = 0;       // End of the range covered by current jump

        // We iterate only till n-1 because we don't need to jump from last index
        for(int i = 0; i < n - 1; i++) 
        {
            // From index i, update the farthest position we can reach
            farthest = max(farthest, i + nums[i]);

            // If we have reached the end of the current jump range
            if(i == current) 
            {
                // We must take a jump here
                jumps++;

                // Update the range end to the farthest we can reach
                current = farthest;
            }
        }

        // Total minimum jumps needed to reach last index
        return jumps;
    }
};
