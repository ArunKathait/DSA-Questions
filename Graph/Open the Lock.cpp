class Solution {// TC--->O(n^w)          SC--->O(n^w)
public:
    
    // Function to check neighbors of the current lock combination
    void checkNeighbours(unordered_set<string>&set,queue<string>&q,string &current)
    {
        // Iterate through each digit of the lock combination (4 digits in total)
        for(int i=0;i<4;i++)
        {
            // Store the current digit
            char ch = current[i];
            
            // Calculate the digit after increasing it by 1 (cycling from '9' to '0' if needed)
            char increase = ch == '9' ? '0' : ch + 1;
            
            // Calculate the digit after decreasing it by 1 (cycling from '0' to '9' if needed)
            char decrease = ch == '0' ? '9' : ch - 1;
            
            // Try increasing the current digit and check if it leads to a valid lock combination
            current[i] = increase;
            
            // If the resulting combination is not in the set of deadends, add it to the set and the queue
            if(set.find(current) == set.end())
            {
                set.insert(current);
                q.push(current);
            }
            
            // Try decreasing the current digit and check if it leads to a valid lock combination
            current[i] = decrease;
            
            // If the resulting combination is not in the set of deadends, add it to the set and the queue
            if(set.find(current) == set.end())
            {
                set.insert(current);
                q.push(current);
            }
            
            // Restore the current digit back to its original value
            current[i] = ch;
        }
    }
    
    // Function to find the minimum number of turns required to reach the target combination
    int openLock(vector<string>& deadends, string target) {
        
        // Create a set to store deadends for quick lookup 
        unordered_set<string>set(deadends.begin(),deadends.end());
        
        // Define the starting combination of the lock
        string start = "0000";
        
        // If the starting combination is in the set of deadends, return -1 (impossible to open the lock)
        if(set.find(start) != set.end())
        {
            return -1;
        }
        
        // Create a queue to perform BFS (breadth-first search)
        queue<string>q;
        q.push(start);
        
        // Initialize the level (number of turns) to 0
        int level = 0;
        
        // Continue BFS until the queue is empty
        while(!q.empty())
        {
            // Get the number of lock combinations in the current level
            int size = q.size();
            
            // Process all lock combinations in the current level
            while(size--)
            {
                 // Get the current lock combination from the queue
                auto current = q.front();
                q.pop();
                
                // If the current combination matches the target, return the current level
                if(current == target)
                {
                    return level;
                }
                
                // Check neighbors of the current combination and add them to the queue if valid
                checkNeighbours(set,q,current);
            }
            
            // Increment the level (number of turns)
            level++;
        }
        
         // If the target combination cannot be reached, return -1
        return -1;
    }
};
