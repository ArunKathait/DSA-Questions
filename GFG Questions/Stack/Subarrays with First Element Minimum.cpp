
class Solution {// TC ---> O(N)                       SC ---> O(N)
  public:

    // Function to compute Next Smaller Element to the Right (NSR)
    vector<int> getNSR(int n, vector<int>& arr)
    {
        // NSR[i] will store the index of the next element
        // to the right of i that is strictly smaller than arr[i]
        vector<int> NSR(n);

        // Stack will store indices of array elements
        stack<int> st;

        // Traverse from right to left because we want
        // the next smaller element on the right side
        for(int i = n - 1; i >= 0; i--)
        {
            // Maintain a monotonic increasing stack
            // Remove elements greater than or equal to arr[i]
            // because they cannot be the "next smaller"
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            // If stack becomes empty
            // there is no smaller element to the right
            // so we store n (out of bounds index)
            NSR[i] = st.empty() ? n : st.top();

            // Push current index to stack
            st.push(i);
        }

        // Return the NSR array
        return NSR;
    }

    
    int countSubarrays(vector<int> &arr) {

        // Size of array
        int n = arr.size();

        // Get the next smaller element indices
        vector<int> NSR = getNSR(n, arr);

        // This will store the total number of valid subarrays
        int ans = 0;

        // For each element, count subarrays where
        // this element is the first element and minimum
        for(int i = 0; i < n; i++)
        {
            // Number of valid subarrays starting at index i
            // We can extend until the next smaller element
            int right = NSR[i] - i;

            // Add to answer
            ans += right;
        }

        return ans;
    }
};
