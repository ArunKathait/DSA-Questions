class Solution {// TC--->O(N)       SC--->O(N)
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // Create two vectors to store the maximum and minimum values
        // that can be obtained from each position onward in the array
        vector<int>postMax(n,0);
        vector<int>postMin(n,0);
        
        // Initialize the last elements of both vectors with the last element of the input array
        postMax[n-1] = arr[n-1];
        postMin[n-1] = arr[n-1];
        
        // Iterate through the array in reverse order to calculate the maximum and minimum values
        // that can be obtained from each position onward
        for(int i=n-2;i>=0;i--)
        {
            postMax[i] = max(arr[i],postMax[i+1]);
            postMin[i] = min(arr[i],postMin[i+1]);
        }
        
        // Initialize variables for sliding window approach
        // Define two pointers i and j, where j is k-1 steps ahead of i
        int i = 0,j = k-1;
        
        // Initialize variables to store maximum, minimum, and final answer
        int maxi = INT_MIN,mini = INT_MAX,ans = INT_MAX;
        
        // Iterate through the array using the sliding window approach
        while(j<n)
        {
             // If i is not at the beginning of the array, update maxi and mini
            if(i!=0)
            {
                maxi = max(maxi,arr[i-1]);
                mini = min(mini,arr[i-1]);
            }
            
            // Store temporary maximum and minimum values
            int temp1 = maxi,temp2 = mini;
            
            // If j is not at the end of the array, update temp1 and temp2
            if(j!=n-1)
            {
                temp1 = max(temp1,postMax[j+1]);
                temp2 = min(temp2,postMin[j+1]);
            }
            
            // Update the answer by taking the minimum absolute difference between temp1 and temp2
            ans = min(ans,abs(temp1-temp2));
            
            // Move the window by incrementing i and j
            i++;
            j++;
        }
        
        // Return the final answer
        return ans;
    }
};
