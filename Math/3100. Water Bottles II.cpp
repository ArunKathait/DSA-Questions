
class Solution {// TC--->O(numBottles)                              SC--->O(1)
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // Number of empty bottles initially is equal to the number of bottles you drink at start
        int emptyBottles = numBottles;

        // Total bottles drunk so far
        int drankBottles = numBottles;

        // Continue exchanging bottles as long as we have enough empty bottles 
        // to trade for a new full bottle
        while(emptyBottles >= numExchange)
        {
            // Use up 'numExchange' empty bottles to get 1 new full bottle
            emptyBottles -= numExchange;

            // Drink the new full bottle (so total drunk increases by 1)
            drankBottles++;

            // After drinking, that bottle becomes empty, so add 1 empty bottle back
            emptyBottles++;

            // IMPORTANT: Each time we exchange, the requirement to exchange increases by 1
            // i.e., now you need more bottles to do the next exchange
            numExchange++;
        }

        // Return the total number of bottles drunk
        return drankBottles;
    }
};
