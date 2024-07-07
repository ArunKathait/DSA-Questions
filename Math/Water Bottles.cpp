*********************************************APPROACH 1st*******************************************************
  
class Solution {// TC--->O(log(N))                SC--->O(1)
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Initialize ans with the initial number of bottles
        int ans = numBottles;
        
        // Continue exchanging bottles as long as the number of empty bottles
        // is greater than or equal to the exchange rate
        while(numBottles >= numExchange)
        {
            // Calculate the number of new bottles that can be obtained by exchange
            int newBottles = numBottles/numExchange;
            // Add the new bottles to the total count
            ans += newBottles;
            
            // Update the number of bottles: new bottles plus the remainder of empty bottles
            numBottles = newBottles + (numBottles%numExchange);
            
        }
        
        // Return the total number of bottles consumed
        return ans;
    }
};

************************************************APPROACH 2nd(OPTIMISED APPROACH)*************************************

class Solution {// TC--->O(1)            SC--->O(1)
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Return the total number of water bottles that can be drunk
        // The total is the initial number of bottles plus the additional bottles obtained through exchanges
        return numBottles + (numBottles - 1)/(numExchange - 1);
    }
};
