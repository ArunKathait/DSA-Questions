
class Solution {// TC--->O(N)                      SC--->O(1)
public:
    string fractionAddition(string expression) {
        // Initialize numerator and denominator for the result fraction
        // Start with a numerator of 0
        int numerator = 0;
        
        // Start with a denominator of 1 (representing 0/1)
        int denominator = 1;
        
        // Initialize index variables
        // Index for traversing the input string
        int i = 0;
        
        // Get the size of the input string
        int n = expression.size();
        
        // Loop through the input string to process each fraction
        while(i < n)
        {
            // To store numerator of the current fraction
            int currentNumerator = 0;
            
            // To store denominator of the current fraction
            int currentDenominator = 0;
            
            // Check if the current fraction is negative
            bool isNegative = (expression[i] == '-');
            
            // Skip '+' or '-' sign at the beginning of the fraction
            if(expression[i] == '+' || expression[i] == '-')
            {
                i++;
            }
            
            // Read the numerator of the current fraction
            while(i < n && isdigit(expression[i]))
            {
                 // Convert character to integer
                int val = expression[i] - '0';
                
                // Build the numerator
                currentNumerator = (currentNumerator * 10) + val;
                i++;
            }
            
            // Skip the '/' character separating numerator and denominator
            i++;
            
            // Convert the numerator to negative if needed
            if(isNegative == true)
            {
                currentNumerator *= -1;
            }
            
            
            // Read the denominator of the current fraction
            while(i < n && isdigit(expression[i]))
            {
                // Convert character to integer
                int val = expression[i] - '0';
                
                // Build the denominator
                currentDenominator = currentDenominator * 10 + val;
                i++;
            }
            
            // Update the global numerator and denominator by adding the current fraction
            numerator = numerator * currentDenominator + currentNumerator * denominator;
            denominator = denominator * currentDenominator;
        }
        
        // Compute the greatest common divisor (gcd) of the numerator and denominator to simplify the fraction
        int gcd = abs(__gcd(numerator,denominator));
        
        // Simplify the numerator and denominator by dividing by the gcd
        numerator = numerator/gcd;
        denominator = denominator/gcd;
        
        // Return the result fraction as a string in the format "numerator/denominator"
        return to_string(numerator) + "/" + to_string(denominator);
    }
};
