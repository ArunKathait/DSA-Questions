*********************************************APPROACH 1st***************************************************

class Solution {// TC--->O(N)          SC--->O(N)
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Initialize time required to buy tickets
        int time_required = 0;
        
        // Create a queue to store positions
        queue<int>q;
        
        // Push all positions into the queue
        for(int i=0;i<tickets.size();i++)
        {
            q.push(i);
        }
        
        // Continue buying tickets until the queue becomes empty
        while(!q.empty())
        {
            // Get the front position from the queue
            int front = q.front();
            
            // Remove the front position from the queue
            q.pop();
            
            // Increment the time required to buy tickets
            time_required++;
            
            // Decrease the number of available tickets at the current position
            tickets[front]--;
            
            // If the current position is the desired position 'k' and no more tickets are available at             // this position, return the time required
            if(front == k && tickets[front] == 0)
            {
                return time_required;
            }
            
            // If there are still tickets available at the current position, push it back to the queue
            if(tickets[front] != 0)
            {
                q.push(front);
            }
        }
        
        // Return the time required to buy tickets
        return time_required;
    }
};

*****************************************APPROACH 2nd**********************************************************
// BETTER APPROACH FOR LARGE TEST CASES.
  
class Solution {// TC--->O(N)          SC--->O(1)
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        // Initialize the variable to store the total time required to buy tickets
        int time_required = 0;
        
        // Iterate through each ticket position
        for(int i=0;i<tickets.size();i++)
        {
            // If the current position is before or at the target position 'k'
            if(i <= k)
            {
                
      // Add the minimum of available tickets at position 'k' and current position 'i' to the total time
                time_required += min(tickets[k],tickets[i]); 
            }
             // If the current position is after the target position 'k'
            else
            {
                
// Add the minimum of (available tickets at position 'k' - 1) and current position 'i' to the total time
// (tickets at position 'k' - 1 because we assume we buy one ticket at position 'k')
                time_required += min(tickets[k] - 1,tickets[i]);
            }
        }
        
        // Return the total time required to buy tickets
        return time_required;
    }
};
