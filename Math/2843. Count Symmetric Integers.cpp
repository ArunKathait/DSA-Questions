
class Solution {// TC--->O(high - low  + 1)                         SC--->O(1)
public:
    // Function to check if a number is symmetric
    // A number is symmetric if it has even number of digits and
    // the sum of the first half digits equals the sum of the second half digits
    bool check(int num)
    {
        // Convert the number to a string for easy digit access
        string str = to_string(num);

        // If number of digits is odd, it can't be symmetric
        if(str.length() % 2 != 0)
        {
            return false;
        }

        // Find the middle index
        int mid = str.length()/2;

        int leftSum = 0;

        // Calculate sum of first half digits
        for(int i=0;i<mid;i++)
        {
            // Convert character digit to int and add
            leftSum += str[i] - '0';
        }

        int rightSum = 0;

        // Calculate sum of second half digits
        for(int i=mid;i<str.length();i++)
        {
            // Convert character digit to int and add
            rightSum += str[i] - '0';
        }

        // Return true if both halves have equal sum
        return (leftSum == rightSum);
    }
    
    // Function to count symmetric integers between given range
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
 
        // Traverse all numbers in range [low, high]
        for(int i = low; i <= high; i++)
        {
            // If number is symmetric
            if(check(i))
            {
                // Increase the count
                ans++;
            }
        }

        // Return total count of symmetric numbers
        return ans;
    }
};
