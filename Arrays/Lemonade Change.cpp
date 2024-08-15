
class Solution {// TC--->O(N)                            SC--->O(1)
public:
    bool lemonadeChange(vector<int>& bills) {
        // Variables to keep track of the count of $5 and $10 bills
        int fives = 0,tens = 0;
        
        // Iterate through each bill in the 'bills' vector
        for(auto x:bills)
        {
            // If the customer gives a $5 bill, simply increase the count of $5 bills
            if(x == 5)
            {
                fives++;
            }
            // If the customer gives a $10 bill
            else if(x == 10)
            {
                // Check if we have a $5 bill to give as change
                if(fives > 0)
                {
                    // Give one $5 bill as change
                    fives--;
                    
                    // Increase the count of $10 bills
                    tens++;
                }
                else
                {
                    // If no $5 bill is available, return false
                    return false;
                }
                
            }
            // If the customer gives a $20 bill
            else if(x == 20)
            {
                // Check if we can give $15 change (one $10 bill and one $5 bill)
                if(fives > 0 && tens > 0)
                {
                    // Give one $5 bill
                    fives--;
                    
                    // Give one $10 bill
                    tens--;
                }
                // If we don't have a $10 bill, try to give three $5 bills as change
                else if(fives >= 3)
                {
                    // Give three $5 bills as change
                    fives -= 3;
                }
                else
                {
                    // If we can't give change, return false
                    return false;   
                }
            }
        }
        
        // If we successfully provided change for all customers, return true
        return true;
    }
};
