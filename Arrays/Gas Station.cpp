*******************************************APPROACH 1st(BRUTE FORCE)**************************************************


class Solution {// TC--->O(N^2)               SC--->O(1)
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Get the number of gas stations
        int n = gas.size();
        
        // Iterate through each gas station
        for(int i=0;i<n;i++)
        {
            // If the gas at station i is less than the cost to travel from i to i+1, skip to next station
            if(gas[i] < cost[i])
            {
                continue;
            }
            
            // Start from the current station
            // j is the next station to move to in a circular manner
            int j = (i+1)%n;
            
            // Start with the gas at current station
            int currentGas = gas[i];
            
            // Update the gas after traveling from station i to j
            currentGas = currentGas - cost[i] + gas[j];
            
            // Traverse through the stations until we return to the starting point or run out of gas
            while(j != i)
            {
                // If we run out of gas before reaching station j, break the loop
                if(currentGas < cost[j])
                {
                    break;
                }
                
                // Store the cost of moving from current station (j) to next station
                int costForMovingfromThisj = cost[j];
                
                // Move to the next station in a circular manner
                j = (j+1)%n;
                
                // Store the gas available at the next station
                int gasEarnInNextStationj = gas[j];
                
                // Update the gas after traveling from station j to the next station
                currentGas = currentGas - costForMovingfromThisj + gasEarnInNextStationj ;
                
            }
            
            // If we return to the starting station, return its index
            if(i == j)
            {
                return i;
            }
        }
        
        // If we cannot complete the circuit, return -1
        return -1;
    }
};

*********************************************APPROACH 2nd************************************************************

class Solution {// TC--->O(N)                 SC--->O(1)
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Get the number of gas stations
        int n = gas.size();
        
        // Calculate the total gas available
        int gasSum = accumulate(gas.begin(),gas.end(),0);
        
        // Calculate the total cost of travel
        int costSum = accumulate(cost.begin(),cost.end(),0);
        
        // If the total gas available is less than the total cost, it's impossible to complete the circuit
        if(gasSum < costSum)
        {
            return -1;
        }
        
        // Initialize the index of a valid starting station
        int validIndex = 0;
        
        // Initialize the total gas balance
        int totalSum =0 ;
        
        // Iterate through each gas station
        for(int i=0;i<n;i++)
        {
            // Calculate the balance of gas at this station
            totalSum += gas[i] - cost[i];
            
            // If the gas balance becomes negative, the current station cannot be the starting point
            // Move to the next station as a possible starting point and reset the gas balance
            if(totalSum < 0)
            {
                 // Update the valid starting index
                validIndex = i+1;
                
                // Reset the gas balance
                totalSum = 0;
            }
        }
        
        // Return the index of the valid starting station
        return validIndex;
    }
};


********************************************APPROACH 3rd**************************************************************


class Solution {// TC--->O(N)             SC--->O(1)
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // Get the number of gas stations
        int n = gas.size();
        
        // Calculate the total gas and cost by summing up all elements in the respective vectors
        // Total gas available
        int gasSum = 0;
        
        // Total cost of travel
        int costSum = 0;
        for(int i=0;i<n;i++)
        {
            // Accumulate gas
            gasSum += gas[i];
            
            // Accumulate cost
            costSum += cost[i];
        }
        
        // If the total gas available is less than the total cost, it's impossible to complete the circuit
        if(gasSum < costSum)
        {
            return -1;
        }
        
        // Initialize the total gas balance
        int totalSum = 0;
        
        // Initialize the index of a valid starting station
        int validIndex = 0;
        
        // Iterate through each gas station
        for(int i=0;i<n;i++)
        {
            // Calculate the balance of gas at this station
            totalSum += gas[i] - cost[i];
            
            // If the gas balance becomes negative, the current station cannot be the starting point
            // Move to the next station as a possible starting point and reset the gas balance
            if(totalSum < 0)
            {
                // Update the valid starting index
                validIndex = i + 1;
                
                // Reset the gas balance
                totalSum = 0;
            }
        }
        
        // Return the index of the valid starting station
        return validIndex;
        
    }
};
