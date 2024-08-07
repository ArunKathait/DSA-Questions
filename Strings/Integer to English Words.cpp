
class Solution {// TC--->O(log10(N))                      SC--->O(log10(N))
public:
        // Maps for numbers below 10, below 20, and below 100
        unordered_map<int,string>below10 = {{0,""},{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},                                               {6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}};
        
        unordered_map<int,string>below20 = {{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},
                                            {14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},                                                           {17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};
        
        unordered_map<int,string>below100 = {{1,"Ten"},{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},                                              {6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};
    
    // Helper function to convert a number to words
    string solve(int num)
    {
        // If the number is less than 10, use below10 map
        if(num < 10)
        {
            return below10[num];
        }
        
        // If the number is between 10 and 19, use below20 map
        if(num < 20)
        {
            return below20[num];
        }
        
        // If the number is between 20 and 99
        if(num < 100)
        {
            // Use below100 map for tens place, and below10 for units place if not zero
            return below100[num/10] + ((num%10 != 0) ? " " + below10[num%10] : "");
        }
        
        // If the number is between 100 and 999
        if(num < 1000)
        {
            // Combine the hundreds place with the result of the remainder
            return solve(num/100) + " Hundred" + ((num%100 != 0) ? " " + solve(num%100) : "");
        }
        
        // If the number is between 1,000 and 999,999
        if(num < 1000000)
        {
            // Combine the thousands place with the result of the remainder
            return solve(num/1000) + " Thousand" + ((num%1000 != 0) ? " " + solve(num%1000) : "");
        }
        
        // If the number is between 1,000,000 and 999,999,999
        if(num < 1000000000)
        {
             // Combine the millions place with the result of the remainder
            return solve(num/1000000) + " Million" + ((num%1000000 != 0) ? " " + solve(num%1000000) : "");
        }
        // If the number is 1,000,000,000 or more
        // Combine the billions place with the result of the remainder
        
        return solve(num/1000000000) + " Billion" + ((num%1000000000 != 0) ? " " + solve(num%1000000000) : "");
    }
    
    // Main function to convert a number to words
    string numberToWords(int num) {
        
        // If the number is 0, return "Zero"
        if(num == 0)
        {
            return "Zero";
        }
        
        // Convert the number to words using the helper function
        return solve(num);
    }
};
