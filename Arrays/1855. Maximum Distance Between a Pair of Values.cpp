
class Solution {// TC ---> O(n + m)                                        SC ---> O(1)
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        // n = size of nums1, m = size of nums2
        int n = nums1.size();
        int m = nums2.size();

        // Two pointers for both arrays
        int i = 0;  // pointer for nums1
        int j = 0;  // pointer for nums2

        int ans = 0; // to store maximum distance

        // Traverse both arrays
        while(i < n && j < m)
        {
            // If nums1[i] > nums2[j], condition is invalid
            // because we need nums1[i] <= nums2[j]
            // so move i forward to find a smaller value
            if(nums1[i] > nums2[j])
            {
                i++;
            }
            else
            {
                // Valid pair found: nums1[i] <= nums2[j]
                // Calculate distance (j - i)
                ans = max(ans, j - i);

                // Try to increase distance by moving j forward
                j++;
            }
        }

        // Return maximum distance found
        return ans;
    }
};
