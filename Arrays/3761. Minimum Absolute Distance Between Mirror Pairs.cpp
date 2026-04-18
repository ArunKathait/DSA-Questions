
class Solution {// TC ---> O(n * d)                               SC ---> O(N)
public:

    // Function to reverse a number
    int getReverse(int num)
    {
        int rev = 0;

        // Loop until number becomes 0
        while(num)
        {
            int rem = num % 10;          // get last digit
            rev = (rev * 10) + rem;      // build reversed number
            num /= 10;                   // remove last digit
        }
        return rev;                      // return reversed number
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        // Map to store: reversed number -> its index
        unordered_map<int,int> ump;

        int ans = INT_MAX; // initialize answer with maximum value

        for(int i = 0; i < n; i++)
        {
            // Check if current number already exists as a reversed value
            // means we previously saw its mirror pair
            if(ump.count(nums[i]))
            {
                // update minimum distance between indices
                ans = min(ans, abs(i - ump[nums[i]]));
            }

            // Store reverse of current number with its index
            // so future elements can match with it
            ump[getReverse(nums[i])] = i;
        }

        // If no mirror pair found, return -1
        return ans == INT_MAX ? -1 : ans;
    }
};
