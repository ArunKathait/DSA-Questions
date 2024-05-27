***********************************************APPROACH 1st(BRUTE FORCE)*********************************************

class Solution {// TC--->O(N^2)                SC--->O(1)
public:
    // Function to count how many numbers in the array are greater than or equal to 'val'
    int findGreaterEqual(vector<int>&nums,int val)
    {
        // Initialize the counter to zero
        int ans = 0;
        
        // Loop through each element in the array
        for(int i=0;i<nums.size();i++)
        {
            // If the current element is greater than or equal to 'val'
            if(val <= nums[i])
            {
                // Increment the counter
                ans++;
            }
        }
        // Return the final count
        return ans;
    }
    
    // Function to find the special number in the array
    int specialArray(vector<int>& nums) {
        // Get the size of the array
        int n = nums.size();
        
        // Iterate over the possible values from 0 to n (inclusive)
        for(int i=0;i<=n;i++)
        {
            // Count how many numbers in the array are greater than or equal to the current value 'i'
            int count = findGreaterEqual(nums,i);
            
            // If the count is equal to the current value 'i', we found our special number
            if(count == i)
            {
                // Return the special number
                return i;
            }
        }
        // If no special number is found, return -1
        return -1;
    }
};


********************************************APPROACH 2nd(USING BINARY SEARCH)****************************************

class Solution { // TC--->O(NlogN)             SC--->O(1)
public:
    // Function to perform binary search and find the position where 'val' should be inserted
    // in a sorted array 'nums' to maintain the sorted order
    int binarySearch(vector<int>&nums,int val)
    {
        
        int low=0,high = nums.size() - 1;
        
        // Perform binary search
        while(low <= high)
        {
            // Calculate mid-point to avoid overflow
            int mid = low + (high - low)/2;
            
            // If the mid element is greater than or equal to 'val',
            // move the high pointer to mid - 1 to search in the left half
            if(nums[mid] >= val)
            {
                high = mid - 1;
            }
            // If the mid element is less than 'val',
            // move the low pointer to mid + 1 to search in the right half
            else
            {
                low = mid + 1;
            }
        }
        // Return the position where 'val' should be inserted
        return low;
    }
    
    // Function to find the special value 'x' such that there are exactly 'x' numbers in the array
    // that are greater than or equal to 'x'
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        // Sort the array to apply binary search
        sort(nums.begin(),nums.end());
        
        // Iterate through all possible values of 'x' from 0 to the size of the array
        for(int i=0;i<=n;i++)
        {
            // Find the index where 'i' should be inserted in the sorted array
            int index = binarySearch(nums,i);
            
            // Calculate the count of elements that are greater than or equal to 'i'
            int count = n - index;
            
            // If the count of elements is equal to 'i', then 'i' is the special value
            if(count == i)
            {
                return i;
            }
        }
        
        // If no special value is found, return -1
        return -1;
    }
};


*********************************************APPROACH 3rd(BETTER APPROACH)**************************************

class Solution {// TC--->O(NlogN)             SC--->O(1)
public:
    // Function to find a special number x where exactly x elements in the array are >= x
    int specialArray(vector<int>& nums) {
        
         // Sort the array in non-decreasing order
        sort(nums.begin(),nums.end());
        
        // Get the size of the array
        int n = nums.size();
        
        // Initialize binary search bounds
        int low = 0,high = n;
        
        // Binary search to find the special number x
        while(low <= high)
        {
            // Calculate the middle point
            int mid = low + (high - low)/2;
            
            // Find the first index where the element is >= mid using lower_bound
            int index = lower_bound(nums.begin(),nums.end(),mid) - nums.begin();
            
            // Calculate the count of elements >= mid
            int count = n - index;
            
            // Check if the count of elements >= mid is exactly mid
            if(count == mid)
            {
                // Found the special number, return it
                return mid;
            }
            
            // If the count of elements >= mid is greater than mid, search in the higher half
            else if(count > mid)
            {
                low = mid + 1;
            }
            // If the count of elements >= mid is less than mid, search in the lower half
            else
            {
                high = mid - 1;
            }
        }
        
        // If no such special number is found, return -1
        return -1;
    }
};


****************************************APPROACH 4th(OPTIMAL APPROACH)******************************************

class Solution {// TC--->O(N)             SC--->O(N)
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize a frequency array of size n+1 to count occurrences
        vector<int>freq(n+1);
        
        // Count occurrences of each number in nums, but cap the count at n
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            
            // If num >= n, increment freq[n]
            freq[min(n,num)]++;
        }
        
        int cumulativeSum = 0;
        
        // Traverse the frequency array from the end to the beginning
        for(int x=n;x>=0;x--)
        {
            // Add current frequency to cumulative sum
            cumulativeSum += freq[x];
            
            // Check if x equals the cumulative sum of frequencies
            if(x == cumulativeSum)
            {
                // Found the special value x
                return x;
            }
        }
        // If no special value is found, return -1
        return -1;
    }
};
