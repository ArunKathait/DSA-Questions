****************************************APPROACH 1st(BRUTE FORCE)***************************************

class Solution {// TC--->O(N * MAXPILELEMENT)                          SC--->O(1)
public:
    
    // Function to calculate the total hours required to eat all bananas at a given eating speed
    long long getTotalHours(vector<int>&piles,int eatingSpeed)
    {
        long long totalHours = 0;

        // Iterate over each pile of bananas
        for(int i=0;i<piles.size();i++)
        {
            // Calculate the number of hours required to finish this pile at the current speed
            // Since division of two integers results in integer division, we cast one operand to double
            // to ensure floating-point division before applying ceil()
            totalHours += (int)ceil((double)piles[i]/eatingSpeed);
        }

        // Return the total hours needed
        return totalHours;
    }

    // Function to find the minimum speed required to eat all bananas within 'h' hours
    int minEatingSpeed(vector<int>& piles, int h) {
        // Number of banana piles
        int n = piles.size();

        // Find the maximum pile size since Koko cannot eat faster than this speed
        int maxPileSize = *max_element(piles.begin(),piles.end());

        // Try all speeds from 1 banana per hour up to maxPileSize bananas per hour
        for(int speed=1;speed<=maxPileSize;speed++)
        { 
            // Check if eating at this speed allows Koko to finish within h hours
            if(getTotalHours(piles,speed) <= h)
            {
                // Return the minimum speed that meets the condition
                return speed;
            }
        }

        // This case won't occur because maxPileSize is always a valid option
        return -1;

    }
};


***************************************APPROACH 2nd(BINARY SEARCH)******************************************

class Solution {// TC--->O(N * O(LOG M)) M---->Maximum pile size          SC--->O(1)
public:
    // Function to calculate the total hours required to eat all bananas at a given speed
    long long getTotalHours(vector<int>&piles,int eatingSpeed)
    {
        // Stores the total hours needed to eat all bananas
         long long totalHours = 0;

         // Iterate over each pile and calculate the total time needed
         for(int i=0;i<piles.size();i++)
         {
            // Using ceil to ensure that if there are leftover bananas, Koko takes an extra hour
            totalHours += ceil(double(piles[i])/eatingSpeed);
         }
         return totalHours;
    }

    // Function to find the minimum speed Koko can eat bananas within 'h' hours
    int minEatingSpeed(vector<int>& piles, int h) {
        // Number of banana piles
        int n = piles.size();

        // The minimum speed Koko can eat (1 banana per hour)
        int minSpeed = 1;

        // Maximum pile size (upper bound for speed)
        int maxSpeed = *max_element(piles.begin(),piles.end());

        // Variable to store the optimal minimum speed
        int ans = -1;

        // Perform Binary Search on eating speed
        while(minSpeed <= maxSpeed)
        {
            // Calculate the middle speed
            int midSpeed = minSpeed + (maxSpeed - minSpeed)/2;

             // Check if Koko can eat all bananas at midSpeed within h hours
            if(getTotalHours(piles,midSpeed) <= h)
            {
                // Store the current speed as a potential answer
                 ans = midSpeed;

                 // Try to find a smaller feasible speed
                 maxSpeed = midSpeed - 1;
            }
            else
            {
                 // Increase speed to eat faster
                minSpeed = midSpeed + 1;
            }
        }

        // Return the minimum speed required to finish all bananas on time
        return ans;
    }
};
