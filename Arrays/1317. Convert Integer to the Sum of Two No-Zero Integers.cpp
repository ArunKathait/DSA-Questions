****************************************************APPROACH 1st*******************************************************
class Solution {// TC--->O(NLogN)                             SC--->O(LogN)
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans; // Result vector to store two numbers

        // Loop through possible values of i starting from 1
        // Only need to check until i <= n-i (to avoid duplicate checks)
        for (int i = 1; i <= n - i; i++) 
        {
            // The second number is automatically determined
            int j = n - i; 

            // Convert both numbers to strings (to check if they contain '0')
            string str1 = to_string(i);
            string str2 = to_string(j);

            // Assume both numbers are valid initially
            bool flag = true; 

            // Check if number i contains any '0'
            for (int k = 0; k < str1.length(); k++) 
            {
                if (str1[k] == '0') 
                {
                    // Found a zero → invalid
                    flag = false; 
                    break;
                }
            }

            // Check if number j contains any '0'
            for (int k = 0; k < str2.length(); k++) 
            {
                if (str2[k] == '0') 
                {
                    // Found a zero → invalid
                    flag = false; 
                    break;
                }
            }

            // If both numbers are valid (no '0' found in either)
            if (flag) 
            {
                ans.push_back(i); // Store the first number
                ans.push_back(j); // Store the second number
                return ans;       // Return the result immediately
            }
        }
        // Just a safeguard (though problem guarantees a solution)
        return ans; 
    }
};


****************************************************APPROACH 2nd(OPTIMISED)****************************************

class Solution {// TC ---> O(log n)                 SC ---> O(1)
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;   // Start with 'a' as n (we will adjust it)
        int b = 0;   // Start with 'b' as 0 (we will build it digit by digit)
        
        int placeValue = 1;  // Tracks the current digit place (1, 10, 100, ...)
        
        // Process each digit of n from right to left (least significant to most)
        while(n > 1)
        {
            int take = 1;   // Default: shift 1 unit to 'b' for this digit

            // If the current digit of n is 1, shifting "1" would make 'a' digit = 0
            // But we don’t want zeros → so we shift 2 instead of 1
            if(n % 10 == 1)
            {
                take = 2;
            }

            // Subtract 'take' * current place from 'a'
            a = a - (take * placeValue);

            // Add 'take' * current place to 'b'
            b = b + (take * placeValue);

            // Reduce n by the amount we "took", then move to the next digit
            n = (n - take) / 10;

            // Update place value for the next digit (1 → 10 → 100 → …)
            placeValue = placeValue * 10;
        }

        // At this point, 'a' and 'b' are both no-zero integers and sum = original n
        return {a, b};
    }
};
