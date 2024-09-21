****************************************************APPROACH 1st********************************************************

class Solution {// TC--->O(NlogN)                       SC--->O(N)
public:
    // Function to return a vector of integers sorted in lexicographical order from 1 to n
    vector<int> lexicalOrder(int n) {
        // Declare a vector to store the integers
        vector<int>vec;
        
        // Loop to populate the vector with integers from 1 to n
        for(int i=1;i<=n;i++)
        {
            // Add each integer to the vector
            vec.push_back(i);
        }
        
        // Lambda function to compare two integers lexicographically
        // [&] is used to capture all variables by reference from the surrounding scope
        auto lambda = [&](int &a,int &b)
        {
            // Convert both integers 'a' and 'b' to strings
            string s1 = to_string(a);
            string s2 = to_string(b);
            
            // Compare the two strings lexicographically
            // Return true if s1 is less than s2, which means 'a' should come before 'b'
            return s1 < s2;
        };
        
        // Sort the vector 'vec' based on the lexicographical comparison defined by the lambda function
        sort(vec.begin(),vec.end(),lambda);
        
        // Return the sorted vector
        return vec;
    }
};

****************************************************APPROACH 2nd(GOOD APPROACH)*************************************

class Solution {// TC--->O(N)                         SC--->O(number of digits in n) ~ O(log10) 
public:
    
    // Recursive function that builds lexicographical numbers
    // 'currentNum' is the current number being constructed, 'limit' is n, and 'ans' stores the result
    void solve(int currentNum,int limit,vector<int>&ans)
    {
        // Base case: If current number exceeds the limit, stop further recursion
        if(currentNum > limit)
        {
            // Exit the recursion
            return ;
        }
        
        // Add the current number to the result list
        ans.push_back(currentNum);
        
        // Try appending digits from 0 to 9 to 'currentNum' to form new numbers
        for(int append=0;append<=9;append++)
        {
            // Create a new number by appending 'append' to 'currentNum'
            int newNum = (currentNum * 10) + append;
            
             // If the newly formed number exceeds the limit, stop further recursion for this path
            if(newNum > limit)
            {
                // Exit this loop iteration
                return ;
            }
            
            // Recursively build lexicographically larger numbers
            solve(newNum,limit,ans);
        }
    }
    
    // Main function to return numbers from 1 to n in lexicographical order
    vector<int> lexicalOrder(int n) {
        // Vector to store the result
        vector<int>ans;
        
        // Start recursion for each digit from 1 to 9 (since 0 isn't considered a valid start)
        for(int i=1;i<=9;i++)
        {
            // Generate lexicographical numbers starting with 'i'
            solve(i,n,ans);
        }
        
        // Return the final result
        return ans;
    }
};
