******************************************************APPROACH 1st***************************************************

class Solution {// TC--->O(N^2 * log(K))                        SC--->O(K)
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        // Declare a max-heap (priority queue) to store the k smallest distances
        priority_queue<int>pq;
        
        // Get the size of the input array
        int n = nums.size();
        
        // Traverse each pair of elements in the array
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // Calculate the absolute difference between the two elements
                int val = abs(nums[i] - nums[j]);
                
                // Add the difference to the max-heap
                pq.push(val);
                
                // If the heap size exceeds k, remove the largest element
                // This ensures that the heap only contains the k smallest distances
                if(pq.size() > k)
                {
                    // Remove the largest element (root of the max-heap)
                    pq.pop();
                }
            }
        }
        
        // The top of the max-heap now contains the k-th smallest distance
        return pq.top();

    }
};

*********************************************APPROACH 2nd***********************************************************

class Solution {// TC--->O(N^2)                        SC--->O(maxElement)
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Get the size of the input array
        int n = nums.size();
        
        // Find the maximum element in the array to determine the possible range of differences
        int maxElement = *max_element(nums.begin(),nums.end());
        
        // Create a vector to store the frequency of each possible difference
        // The size of this vector is maxElement + 1, as the maximum difference possible is maxElement - 0
        vector<int>vec(maxElement + 1,0);
        
        // Traverse each pair of elements in the array
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // Calculate the absolute difference between the two elements
                int diff = abs(nums[i] - nums[j]);
                
                // Increment the count of this difference in the frequency vector
                vec[diff]++;
            }
        }
        
        // Traverse the frequency vector to find the k-th smallest distance
        for(int i=0;i<vec.size();i++)
        {
            // Subtract the frequency of the current difference from k
            k -= vec[i];
            
            // If k is less than or equal to 0, it means we've found the k-th smallest distance
            if(k <= 0)
            {
                // Return the current index, which represents the k-th smallest distance
                return i;
            }
        }
        
        // In case something goes wrong, though it shouldn't, return -1
        return -1;
    }
};

*********************************************APPROACH 3rd(BINARY SEARCH)**********************************************

class Solution {// TC--->O(NlogN + NlogM)                     SC--->O(1)
public:
    // Function to count the number of pairs with a distance less than or equal to 'distance'
    int sliding(vector<int>&nums,int distance)
    {
        // Start of the sliding window
        int i = 0;
        
        // End of the sliding window
        int j = 1;
        
        // To count the number of valid pairs
        int count = 0;
        
        // Traverse through the array using the sliding window
        while(j < nums.size())
        {
            // Adjust the start of the window until the pair (i, j) satisfies the distance condition
            while(abs(nums[j] - nums[i]) > distance)
            {
                i++;
            }
            
            // The number of pairs ending at index j and starting from any index between i and j is (j - i)
            count += j - i;
            
            // Move the end of the window to the next element
            j++;
        }
        return count;
    }
    
    // Function to find the k-th smallest distance pair
    int smallestDistancePair(vector<int>& nums, int k) {
        // Get the size of the array
        int n = nums.size();
        
        // Sort the array to allow binary searching for distances
        sort(nums.begin(),nums.end());
        
        // Initialize the search range for the distance
        int low = 0;
        
        // Maximum possible distance in the sorted array
        int high = nums[n-1] - nums[0];
        
        // Variable to store the final answer
        int ans = 0;
        while(low <= high)
        {
            // Find the mid-point of the current range
            int mid = low + (high - low)/2;
            
            // Count the number of pairs with distance less than or equal to 'mid'
            int count = sliding(nums,mid);
            
            // If the count of such pairs is less than k, search in the higher half
            if(count < k)
            {
                low = mid + 1;
            }
            // Otherwise, search in the lower half (including the current mid as a candidate)
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        
        // Return the k-th smallest distance
        return ans;
    }
};
