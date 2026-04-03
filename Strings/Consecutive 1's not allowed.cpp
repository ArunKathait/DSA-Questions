
class Solution {// TC ---> O(N)                             SC ---> O(1)
  public:

    // Function to count binary strings of length n 
    // such that no two consecutive 1's are present
    int binaryStrings(int n)
    {
        // Base Case 1:
        // For n = 1 → possible strings: "0", "1"
        // Total = 2
        if(n == 1)
        {
            return 2;
        }

        // Base Case 2:
        // For n = 2 → possible strings: "00", "01", "10"
        // (Note: "11" is not allowed)
        // Total = 3
        if(n == 2)
        {
            return 3;
        }
        
        // previousCount1 → stores result for length (i-1)
        int previousCount1 = 3;   // for n = 2
        
        // previousCount2 → stores result for length (i-2)
        int previousCount2 = 2;   // for n = 1
        
        // Loop from 3 to n to build answer using DP
        for(int i = 3; i <= n; i++)
        {
            // Recurrence Relation:
            // f(n) = f(n-1) + f(n-2)
            // Why?
            // 1. Add '0' to all strings of length (n-1)
            // 2. Add '10' to all strings of length (n-2)
            int currentCount = previousCount1 + previousCount2;
            
            // Update values for next iteration
            previousCount2 = previousCount1;
            previousCount1 = currentCount;
        }

        // Final answer stored in previousCount1
        return previousCount1;
    }
    
    int countStrings(int n) {
        return binaryStrings(n);
    }
};
