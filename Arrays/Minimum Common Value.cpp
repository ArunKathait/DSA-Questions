*********************************************************************1st APPROACH(USING SET)***********************************************************************

class Solution {//TC--->O(m+n)               SC--->O(m)
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        // Create a unordered set for nums2 to efficiently check for common elements
        unordered_set<int>set(nums2.begin(),nums2.end());
        
        // Iterate through each element in nums1
        for(auto x:nums1)
        {
            // Check if the current element from nums1 exists in the set
            if(set.find(x)!=set.end())
            {
                // If found, return the common element
                 return x;
            }
        }
        
        // If no common element found, return -1
        return -1;
    }
};

*********************************************************************2nd APPROACH(USING BINARY SEARCH)*******************************************************************************

class Solution { //TC--->O(m*logm)        SC--->O(1)
public:
    
    // Function to perform binary search in a sorted vector
    bool binarySearch(vector<int>&nums,int target)
    {
        // Initialize low index of the search range
        int low = 0;
        
        // Initialize high index of the search range
        int high = nums.size()-0;
        
        // Perform binary search until the search range is valid
        while(low<=high)
        {
            // Calculate the middle index
            int mid = low + (high - low)/2;
            
            // If target is found at middle index
            if(nums[mid] == target)
            {
                // Return true indicating target is found
                return true;
            }
            
            // If target is greater, search in the right half
            else if(nums[mid] < target)
            {
                // Update low index to search in the right half
                low = mid + 1;
            }
            else
            {
                // If target is smaller, search in the left half
                // Update high index to search in the left half
                high = mid - 1;
            }
        }
        
        // Return false indicating target is not found
        return false;
    }
    
    
    // Function to find the common element between two sorted vectors using binary search
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        // Iterate through each element in the second vector
        for(auto x:nums2)
        {
            // If the current element in the second vector is found in the first vector
            if(binarySearch(nums1,x))
            {
                // Return the common element
                return x;
            }
        }
        
        // Return -1 if no common element is found
        return -1;
    }
};

*********************************************************************3rd APPROACH(USING 2 POINTERS)************************************************************

class Solution {//TC--->O(M + N)        SC--->O(1)
public:
    
    // Function to find the common element between two sorted vectors
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Pointer for nums1
        int i = 0;
        
        // Pointer for nums2
        int j = 0;
        
        // Iterate until we reach the end of either vector
        while(i<nums1.size() && j<nums2.size())
        {
            // If the current elements are equal
            if(nums1[i] == nums2[j])
            {
                // Return the common element
                return nums1[i];
            }
            // If the element in nums1 is smaller
            else if(nums1[i] < nums2[j])
            {
                // Move to the next element in nums1
                i++;
            }
            // If the element in nums2 is smaller
            else if(nums1[i] > nums2[j])
            {
                // Move to the next element in nums2
                j++;
            }
        }
        
        // Return -1 if no common element is found
        return -1;
    }
};
