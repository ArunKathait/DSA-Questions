*********************************************APPROACH 1st****************************************************

class Solution {// TC--->O(N) + O(N) + O(N) = O(N)                  SC--->O(N) + O(N) = O(N)
public:
    int candy(vector<int>& ratings) {
        // Get the number of children
        int n = ratings.size(); 

        // Step 1: Initialize a vector for left to right pass, assigning 1 candy to each child
        vector<int> leftToRight(n, 1);

        // Step 2: Left to right pass
        // If current child's rating is greater than previous child, give current child more candies
        for (int i = 1; i < n; i++) 
        {
            if (ratings[i] > ratings[i - 1]) 
            {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }

        // Step 3: Initialize a vector for right to left pass, assigning 1 candy to each child
        vector<int> rightToLeft(n, 1);

        // Step 4: Right to left pass
        // If current child's rating is greater than next child, give current child more candies
        for (int i = n - 2; i >= 0; i--) 
        {
            if (ratings[i] > ratings[i + 1]) 
            {
                rightToLeft[i] = rightToLeft[i + 1] + 1;
            }
        }

        // Step 5: Calculate the total candies
        // For each child, take the maximum candies needed from both directions
        int ans = 0;
        for (int i = 0; i < n; i++) 
        {
            ans += max(leftToRight[i], rightToLeft[i]);
        }

        // Return the total number of candies needed
        return ans; 
    }
};

*******************************************APPROACH 2nd(BETTER APPROACH)*****************************************

class Solution {// TC--->O(N)                                     SC--->O(1)
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        // Start by giving 1 candy to each child => total candies = n
        int candy = n;

        int i = 1;
        while (i < n) 
        {
            // If current child has the same rating as the previous one,
            // no need to give extra candies, move to next child
            if (ratings[i] == ratings[i - 1]) 
            {
                i++;
                continue;
            }

            // Count the length of strictly increasing sequence (ascending slope / peak)
            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) 
            {
                // We are moving up, so we give increasing number of candies
                peak++;
                // Add extra candies for current peak position             
                candy += peak;      
                i++;
                if (i == n) 
                {
                    // If we reach the end while climbing up, return total candies
                    return candy;
                }
            }

            // Count the length of strictly decreasing sequence (descending slope / dip)
            int dip = 0;
            while (i < n && ratings[i] < ratings[i - 1]) 
            {
                // Going down, give increasing number of candies from the dip
                dip++;  
                // Add extra candies for current dip position            
                candy += dip;       
                i++;
            }

            // The child at the peak gets counted twice — once in ascending and once in descending
            // So we subtract the minimum of (peak, dip) to avoid double-counting the peak child
            candy -= min(peak, dip);
        }
        // Return the total minimum candies required
        return candy; 
    }
};
