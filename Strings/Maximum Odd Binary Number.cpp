************************************************************* 1st APPROACH **************************************************************************************************

class Solution {//TC--->O(N)      SC--->O(N)
public:
    string maximumOddBinaryNumber(string s) {
        // Initialize two counters to keep track of the number of 0s and 1s in the input string.
        int count0 = 0,count1 = 0;
        
        // Iterate through each character in the input string.
        for(int i=0;i<s.size();i++)
        {
            // If the current character is '1', increment the count of 1s.
            if(s[i] == '1')
            {
                count1++;
            }
            // If the current character is '0', increment the count of 0s.
            else
            {
                count0++;
            }
        }
        
        // Create an empty string to store the result.
        string ans;
        
        // Add '1' characters to the result until there is only one '1' left.
        while(count1>1)
        {
            ans+= '1';
            count1--;
        }
        
        // Add '0' characters to the result for all the remaining '0's.
        while(count0--)
        {
            ans+= '0';
        }
        
        // Finally, add a '1' character to the result to make the number odd.
        ans += '1';
        
        // Return the resulting string, which represents the maximum odd binary number.
        return ans;
    }
};


************************************************************************* 2nd APPROACH **************************************************************************************


class Solution {//TC--->O(N)          SC--->O(N)
public:
    string maximumOddBinaryNumber(string s) {
        
        // Count the number of '1's in the string
       int val = count(s.begin(), s.end(), '1'); 

        // Get the size of the input string
        int n = s.size();
        
        // Initialize the result string with n '0's
        string ans(n, '0'); 
        
        // Set the last character of the result string to '1'
        ans[n - 1] = '1'; 
        
        // Decrease the count of '1's
        val--; 
        
        
    // Iterate through the characters of the string 's' and set '1's in 'ans' until val becomes 0 or we reach the end of 's'
        for (int i = 0; i < n && val > 0; i++)
        {
            // Only update if the current character in 'ans' is '0'
            if (ans[i] == '0') 
            { 
                // Set the current character to '1'
                ans[i] = '1';
                
                // Decrease the count of '1's
                val--; 
            }
        }
        
        // Return the resulting string
        return ans;
    }
};
