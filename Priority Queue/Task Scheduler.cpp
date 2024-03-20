class Solution {// TC--->O(N)         SC--->O(1)
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // Initialize a vector 'mp' to store the frequency of each task
        // Assuming tasks are uppercase English letters
        vector<int>mp(26,0);
        
        // Initialize time counter
        int time = 0;
        
        // Count the frequency of each task
        for(auto x:tasks)
        {
            // Convert task character to index (0-25) and increment frequency
            mp[x - 'A']++;
        }
        
        // Create a max heap (priority queue) to store task frequencies
        priority_queue<int>pq;
        for(int i=0;i<26;i++)
        {
            if(mp[i] > 0)
            {
                // Push non-zero frequencies to the priority queue
                pq.push(mp[i]);
            }
        }
        
        // Continue until the priority queue is empty
        while(!pq.empty())
        {
            // Temporary vector to store frequencies of tasks for each cooling interval
            vector<int>temp;
            
            // Execute tasks within the cooling interval
            for(int i=1;i<=n+1;i++)
            {
                // Check if there are tasks remaining in the priority queue
                if(!pq.empty())
                {
                    // Get the task with the highest frequency from the priority queue
                    int freq = pq.top();
                    
                    // Remove the task from the priority queue
                    pq.pop();
                
                    // Decrement frequency to indicate task execution
                    freq--;
                    
                    // Store updated frequency in temporary vector
                    temp.push_back(freq);
                }
            }
            
            // Restore tasks with remaining frequency back to the priority queue
            for(auto it:temp)
            {
                if(it>0)
                {
                    pq.push(it);
                }
            }
            
            // If the priority queue is empty, it means no more tasks are available for execution
            // Increment the time by the number of tasks executed in the last cooling interval
            // Otherwise, increment the time by the length of the cooling interval (n + 1)
            if(pq.empty())
            {
                time += temp.size();
            }
            else
            {
                time += (n+1);
            }
            
        }
        
        // Return the total time taken to execute all tasks
        return time;
    }
};
