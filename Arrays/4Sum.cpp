class Solution {// TC--->O(N^3) + O(NlogN)                          SC--->O(1)
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Get the size of the input array
        int n = nums.size();
        
        // Sort the array to make duplicate removal easier and apply two-pointer approach
        sort(nums.begin(),nums.end());
        
        // Store the final quadruples
        vector<vector<int>>ans;
        
        // Outer loop: Pick the first element
        for(int i=0;i<n;i++)
        {
             // Skip duplicate elements for 'i' to avoid duplicate quadruples
             if(i>0 && nums[i] == nums[i-1])
             {
                continue;
             }

             // Second loop: Pick the second element
            for(int j=i+1;j<n;j++)
            {
                // Skip duplicate elements for 'j' to avoid duplicate quadruples
                if(j>i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }

                // Two-pointer approach to find the remaining two numbers
                int k = j+1;  // Left pointer
                int l = n-1;  // Right pointer
                
                // Condition to ensure valid pairs
                while(k<l)
                {
                    // Use long long to prevent integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    // If the sum matches the target, store the quadruple
                    if(sum == target)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;  // Move left pointer forward
                        l--;  // Move right pointer backward
                        
                        // Skip duplicate elements for 'k'
                        while(k<l && nums[k] == nums[k-1])
                        {
                            k++;
                        }

                        // Skip duplicate elements for 'l'
                        while(k<l && nums[l] == nums[l+1])
                        {
                            l--;
                        }
                    }

                    // If the sum is too small, move the left pointer right
                    else if(sum < target)
                    {
                        k++;
                    }
                    // If the sum is too large, move the right pointer left
                    else 
                    {
                        l--;
                    }
                }
            }
        }

        // Return the list of unique quadruples
        return ans;
    }
};
