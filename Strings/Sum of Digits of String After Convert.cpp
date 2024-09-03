
class Solution {// TC--->O(N + K * logN)                          SC--->O(N)
public:
    int getLucky(string s, int k) {
        // Get the length of the input string 's'
        int n = s.length();
        
        // Initialize an empty string to store numeric representation of 's'
        string str;
        
        // Loop through each character in the string 's'
        for(int i=0;i<n;i++)
        {
            // Convert each character to a number (1 for 'a', 2 for 'b', ..., 26 for 'z')
            int val = (s[i] - 'a') + 1;
            
            // Convert the number to a string and append it to 'str'
            str += to_string(val);
        }
        
        // Initialize 'sum' to store the sum of digits
        int sum = 0;
        
        // Repeat the following process 'k' times
        while(k--)
        {
            // Reset 'sum' to 0 for each iteration
            sum = 0;
            
            // Loop through each character in the current string 'str'
            for(auto &ch : str)
            {
                // Convert character to its integer value (digit) and add to 'sum'
                sum += (ch - '0');
            }
            
            // Convert the calculated sum back to string for the next iteration
            str = to_string(sum);
        }
        
        // After 'k' iterations, return the final sum
        return sum;
    }
};
