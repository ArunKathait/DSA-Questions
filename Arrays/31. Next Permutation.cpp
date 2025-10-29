
class Solution {// TC ---> O(N)                                 SC ---> O(1)
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); // Size of the input array

        int targetIndex = -1; 
        // Step 1️⃣: Find the first index from the end where nums[i-1] < nums[i]
        // This identifies the point (pivot) where the increasing order breaks from the right.
        for (int i = n - 1; i > 0; i--) 
        {
            if (nums[i - 1] < nums[i]) 
            {
                targetIndex = i - 1;  // Found the pivot index
                break;
            }
        }

        int swapIndex = -1; 
        // Step 2️⃣: If such a pivot exists, find the smallest number greater than nums[targetIndex]
        // to the right of it, to swap and make the permutation just larger.
        if (targetIndex != -1) 
        {
            for (int i = n - 1; i >= targetIndex + 1; i--) 
            {
                if (nums[i] > nums[targetIndex]) 
                {
                    swapIndex = i;
                    break;
                }
            }

            // Step 3️⃣: Swap the pivot element with the found element.
            swap(nums[targetIndex], nums[swapIndex]);
        }

        // Step 4️⃣: Reverse the elements to the right of the pivot
        // (or reverse the entire array if no pivot was found).
        // This gives the next lexicographically smallest sequence.
        reverse(nums.begin() + targetIndex + 1, nums.end());
    }
};
