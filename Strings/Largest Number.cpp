*****************************************************APPROACH 1st********************************************************

class Solution {// TC--->O(NlogN)                                     SC--->O(N)
public:
    string largestNumber(vector<int>& nums) {
        // Create a vector of strings to store the integer numbers as strings.
        vector<string>vec;
        
        // Convert each integer from the 'nums' vector to a string and push it into 'vec'.
        for(auto &x:nums)
        {
            // Convert each integer in 'nums' to a string.
            vec.push_back(to_string(x));
        }
        
        // Define a custom comparator (lambda function) to determine the sorting order.
        auto myComparator = [](string &s1,string &s2)
        {
            // Compare the concatenated result of s1+s2 with s2+s1. 
            // We return true if s1+s2 is greater, so that s1 comes before s2 in the sorted order.
            if(s1 + s2 > s2 + s1)
            {
                return true;
            }
            // Otherwise, s1 comes after s2.
            return false;
        };
        
        // Sort the vector of strings 'vec' using the custom comparator defined above.
        sort(vec.begin(),vec.end(),myComparator);
        
        // If the largest number is "0", return "0". This handles the case where all numbers are 0.
        if(vec[0] == "0")
        {
            return "0";
        }
        
        // Concatenate all the strings in the sorted 'vec' to form the final result.
        string ans;
        for(auto x:vec)
        {
            // Append each string from 'vec' to the result string 'ans'.
            ans += x;
        }
        
        // Return the concatenated string as the largest possible number.
        return ans;
    }
};

***************************************************APPROACH 2nd*******************************************************

class Solution {// TC--->O(NlogN)                                     SC--->O(N)
public:
    string largestNumber(vector<int>& nums) {
        // Create a vector of strings to store the integer numbers as strings.
        vector<string>vec;
        
        // Convert each integer from the 'nums' vector to a string and push it into 'vec'.
        for(auto &x:nums)
        {
            // Convert each integer in 'nums' to a string.
            vec.push_back(to_string(x));
        }
        
        // Define a custom comparator (lambda function) to determine the sorting order.
        auto myComparator = [](string &s1,string &s2)
        {
            return s1 + s2 > s2 + s1;
        };
        
        // Sort the vector of strings 'vec' using the custom comparator defined above.
        sort(vec.begin(),vec.end(),myComparator);
        
        // If the largest number is "0", return "0". This handles the case where all numbers are 0.
        if(vec[0] == "0")
        {
            return "0";
        }
        
        // Concatenate all the strings in the sorted 'vec' to form the final result.
        string ans;
        for(auto x:vec)
        {
            // Append each string from 'vec' to the result string 'ans'.
            ans += x;
        }
        
        // Return the concatenated string as the largest possible number.
        return ans;
    }
};

/* 
NOTE: 

    auto myComparator = [](string &s1, string &s2) 
{
    // The logic compares the concatenated strings s1+s2 and s2+s1.
    // If s1+s2 is greater than s2+s1, it means s1 should come before s2
    // in the sorted order to form a larger number.

    // For example:
    // If s1 = "9" and s2 = "34":
    // Compare "934" (s1 + s2) with "349" (s2 + s1).
    // Since "934" is larger than "349", s1 ("9") should come before s2 ("34").
    
    // This ensures that the concatenation of numbers in this order
    // will form the largest possible number.

    return s1 + s2 > s2 + s1;
};

*/
