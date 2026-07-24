
class Solution {// TC ---> O(n × log(max(nums)))                      SC ---> O(1)
public:

    // This function calculates the total sum after dividing
    // every element by 'mid' and taking the ceiling value.
    long long isPossible(vector<int>& nums, int mid)
    {
        long long sum = 0;

        // Traverse every number in the array
        for(int i = 0; i < nums.size(); i++)
        {
            // Divide nums[i] by mid.
            // Since we need the ceiling value,
            // convert to double before division.
            //
            // Example:
            // nums[i] = 7, mid = 3
            // 7/3 = 2.333...
            // ceil(2.333) = 3
            //
            // nums[i] = 6, mid = 3
            // 6/3 = 2
            // ceil(2) = 2
            sum += ceil((double)nums[i] / mid);
        }

        // Return total divisions
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        // Lowest possible divisor
        int low = 1;

        // Highest possible divisor
        // Divisor cannot be greater than the maximum element.
        int high = *max_element(nums.begin(), nums.end());

        int ans = 0;

        // Binary Search
        while(low <= high)
        {
            // Middle divisor
            int mid = low + (high - low) / 2;

            // Calculate the total sum using this divisor
            if(isPossible(nums, mid) <= threshold)
            {
                // This divisor works.
                // Store it as a possible answer.
                ans = mid;

                // Try finding an even smaller divisor.
                high = mid - 1;
            }
            else
            {
                // Sum is greater than threshold.
                // We need a larger divisor so that
                // division results become smaller.
                low = mid + 1;
            }
        }

        return ans;
    }
};
