*********************************************APPROACH 1st*********************************************************

class Solution {// TC--->O(N)                   SC--->O(1)
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // Get the size of the customers array
        int n = customers.size();
        
        // Initialize the current unsatisfied customer count
        
        int currentUnsat = 0;
        
        // Calculate the initial number of unsatisfied customers in the first 'minutes' window
        for(int i=0;i<minutes;i++)
        {
            // If the owner is grumpy at minute i
            if(grumpy[i] == 1)
            {
                // Add the number of customers to the unsatisfied count
                currentUnsat += customers[i];
            }
        }
        
        // Start of the sliding window
        int i = 0;
        
        // End of the sliding window (exclusive)
        int j = minutes;
        
        // Track the maximum number of unsatisfied customers that can be converted to satisfied
        int maxUnsatisfied = currentUnsat;
        
        // Use a sliding window approach to find the maximum possible 'unsatisfied to satisfied' conversion in any 'minutes' window
        while(j < n)
        {
            // If the owner is grumpy at the end of the current window
            if(grumpy[j] == 1)
            {
                // Add the number of customers to the unsatisfied count
                currentUnsat += customers[j];
            }
            
            // If the owner was grumpy at the start of the previous window
            if(grumpy[i] == 1)
            {
                // Remove the number of customers from the unsatisfied count
                currentUnsat -= customers[i];
            }
            
            // Update the maximum unsatisfied count if the current one is larger
            maxUnsatisfied = max(maxUnsatisfied,currentUnsat);
            
            // Move the window start to the right
            i++;

            // Move the window end to the right
            j++;    
                
        }
        
        // Initialize total satisfied count with the maximum unsatisfied count that can be converted
        int totalSatisfied = maxUnsatisfied;
        
        // Add all satisfied customers (where the owner is not grumpy)
        for(int i=0;i<n;i++)
        {
            // If the owner is not grumpy at minute i
            if(grumpy[i] == 0)
            {
                // Add the number of customers to the satisfied count
                totalSatisfied += customers[i];
            }
        }
        
        // Return the maximum number of satisfied customers
        return totalSatisfied;
    }
};

**********************************************APPROACH 2nd(MINOR CHANGES)*******************************************

class Solution {// TC--->O(N)                   SC--->O(1)
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // Get the size of the customers array
        int n = customers.size();
        
        // Initialize the current unsatisfied customer count  
        int currentUnsat = 0;
        
        // Calculate the initial number of unsatisfied customers in the first 'minutes' window
        for(int i=0;i<minutes;i++)
        {  
              // Add the number of customers to the unsatisfied count
              currentUnsat += customers[i] * grumpy[i];
        }
        
        // Start of the sliding window
        int i = 0;
        
        // End of the sliding window (exclusive)
        int j = minutes;
        
        // Track the maximum number of unsatisfied customers that can be converted to satisfied
        int maxUnsatisfied = currentUnsat;
        
        // Use a sliding window approach to find the maximum possible 'unsatisfied to satisfied'                 // conversion in any 'minutes' window
        while(j < n)
        {
            // Add the number of customers to the unsatisfied count if the owner is grumpy at minute j
            currentUnsat += customers[j] * grumpy[j];
            
            // Remove the number of customers from the unsatisfied count
            currentUnsat -= customers[i] * grumpy[i];
            
            // Update the maximum unsatisfied count if the current one is larger
            maxUnsatisfied = max(maxUnsatisfied,currentUnsat);
            
            // Move the window start to the right
            i++;
            
            // Move the window end to the right
            j++;    
                
        }
        
        // Initialize total satisfied count with the maximum unsatisfied count that can be converted
        int totalSatisfied = maxUnsatisfied;
        
        // Add all satisfied customers (where the owner is not grumpy)
        for(int i=0;i<n;i++)
        {
            // If the owner is not grumpy at minute i
            if(grumpy[i] == 0)
            {
                // Add the number of customers to the satisfied count
                totalSatisfied += customers[i];
            }
        }
        
        // Return the maximum number of satisfied customers
        return totalSatisfied;
    }
};
