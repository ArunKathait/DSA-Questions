*********************************************APPROACH 1st*********************************************************

class Solution {// TC--->O(N*K)                          SC--->O(K)
public:
    int minimumRecolors(string blocks, int k) {
        // Get the length of the string 'blocks'
        int  n = blocks.size();
        
        // Initialize 'ans' to a very large value (to find the minimum)
        int ans = INT_MAX;

        // Iterate through all possible substrings of length 'k'
        for(int i=0;i<=n-k;i++)
        {
            // Extract a substring of length 'k' starting from index 'i'
            string str = blocks.substr(i,k);

            // Variable to count 'W' (white) blocks in the substring
            int white = 0;

            // Count the number of 'W' (white) blocks in the current substring
            for(auto &ch:str)
            {
                if(ch == 'W')
                {
                    white++;
                }
            }

            // Update 'ans' with the minimum number of recolors required
            ans = min(ans,white);
        }

        // Return the minimum recolors required to get 'k' consecutive 'B'
        return ans;
    }
};

**********************************************APPROACH 2nd(2 POINTERS)**********************************************

class Solution {// TC--->O(N)            SC--->O(1)
public:
    int minimumRecolors(string blocks, int k) {
        // Get the size of the string
        int n = blocks.size();
        
        // Left pointer of the sliding window
        int i = 0;

        // Right pointer of the sliding window
        int j = 0;
        
        // Store the minimum number of white ('W') blocks to recolor
        int ans = INT_MAX;

        // Count of white ('W') blocks in the current window
        int white = 0;

        // Traverse the string using a sliding window approach
        while(j < n)
        {
            // If the current character is 'W', increase the white count
            if(blocks[j] == 'W')
            {
                white++;
            }

            // When the window size reaches 'k'
            if(j - i + 1 == k)
            {
                // Update the minimum number of white blocks found in a k-length window
                ans = min(ans,white);
                
                // Before sliding the window forward, check if the leftmost character is 'W'
                // If it is, decrement the white count as it is being removed from the window
                if(blocks[i] == 'W')
                {
                    white--;
                }

                // Slide the window to the right
                i++;
            }

            // Expand the window by moving the right pointer
            j++;
        }

        // Return the minimum number of recolors required
        return ans;
    }
};
