*********************************************************************APPROACH 1st(USING BINARY SEARCH)*****************************************************

class Solution {// TC--->O(N * log(max_element))     SC--->O(1)
public:
    // Function to determine the number of bouquets that can be made by day `mid`
    int canMakeMBouquet(vector<int>&bloomDay,int mid,int k)
    {
        // To count the number of bouquets we can make
        int bouquetCount = 0;
        
        // To count consecutive blooming flowers
        int consecutiveCount= 0;
        
        // Iterate through each day in the bloomDay array
        for(int i=0;i<bloomDay.size();i++)
        {
            // Check if the current flower has bloomed by day `mid`
            if(bloomDay[i] <= mid)
            {
                // Increment the count of consecutive blooming flowers
                consecutiveCount++;
            }
            else
            {
                // Reset the count if the current flower has not bloomed
                consecutiveCount = 0;
            }
            
            // If we have enough consecutive blooming flowers to make a bouquet
            if(consecutiveCount == k)
            {
                // Increment the bouquet count
                bouquetCount++;
                
                // Reset consecutive count to start counting for the next bouquet
                consecutiveCount = 0;
            }
        }
        // Return the total number of bouquets we can make by day `mid`
        return bouquetCount;
    }
    
    // Function to find the minimum number of days required to make `m` bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Start of the search range (minimum possible days)
        int startDay = 0;
        
        // End of the search range (maximum bloom day in the array)
        int endDay = *max_element(bloomDay.begin(),bloomDay.end());
        
        // Variable to store the result (minimum days to make `m` bouquets)
        int minDay = -1;
        
        // Perform binary search within the range of days
        while(startDay <= endDay)
        {
            // Calculate the middle day
            int mid = startDay + (endDay - startDay)/2;
            
            // Check if we can make at least `m` bouquets by day `mid`
            if(canMakeMBouquet(bloomDay,mid,k) >= m)
            {
                 // Update the result with the current middle day
                minDay = mid;
                
                // Try to find a smaller possible day
                endDay = mid - 1;
            }
            else
            {
                // If we can't make enough bouquets, try a larger day
                startDay = mid + 1;
            }
        }
        // Return the minimum days required to make `m` bouquets, or -1 if not possible
        return minDay;
    }
};

**********************************************************APPROACH 2nd(MINOR CHANGE)***********************************************************************

class Solution {// TC--->O(N * log(max_element))     SC--->O(1)
public:
    // Function to determine the number of bouquets that can be made by day `mid`
    int canMakeMBouquet(vector<int>&bloomDay,int mid,int k)
    {
        // To count the number of bouquets we can make
        int bouquetCount = 0;
        
        // To count consecutive blooming flowers
        int consecutiveCount= 0;
        
        // Iterate through each day in the bloomDay array
        for(int i=0;i<bloomDay.size();i++)
        {
            // Check if the current flower has bloomed by day `mid`
            if(bloomDay[i] <= mid)
            {
                // Increment the count of consecutive blooming flowers
                consecutiveCount++;
            }
            else
            {
                // Reset the count if the current flower has not bloomed
                consecutiveCount = 0;
            }
            
            // If we have enough consecutive blooming flowers to make a bouquet
            if(consecutiveCount == k)
            {
                // Increment the bouquet count
                bouquetCount++;
                
                // Reset consecutive count to start counting for the next bouquet
                consecutiveCount = 0;
            }
        }
        // Return the total number of bouquets we can make by day `mid`
        return bouquetCount;
    }
    
    // Function to find the minimum number of days required to make `m` bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Start of the search range (minimum possible day in the array)
        int startDay = *min_element(bloomDay.begin(),bloomDay.end());
        
        // End of the search range (maximum bloom day in the array)
        int endDay = *max_element(bloomDay.begin(),bloomDay.end());
        
        // Variable to store the result (minimum days to make `m` bouquets)
        int minDay = -1;
        
        // Perform binary search within the range of days
        while(startDay <= endDay)
        {
            // Calculate the middle day
            int mid = startDay + (endDay - startDay)/2;
            
            // Check if we can make at least `m` bouquets by day `mid`
            if(canMakeMBouquet(bloomDay,mid,k) >= m)
            {
                 // Update the result with the current middle day
                minDay = mid;
                
                // Try to find a smaller possible day
                endDay = mid - 1;
            }
            else
            {
                // If we can't make enough bouquets, try a larger day
                startDay = mid + 1;
            }
        }
        // Return the minimum days required to make `m` bouquets, or -1 if not possible
        return minDay;
    }
};
