**********************************************APPROACH 1st(USING MAX HEAP)**************************************

class Solution {// TC--->O((NlogN + MlogN))               SC--->O(N)
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Number of jobs
        int n = difficulty.size();
        
        // Priority queue to store jobs, sorted by profit in descending order
        priority_queue<pair<int,int>>pq;
        
        // Push each job's profit and difficulty as a pair into the priority queue
        for(int i=0;i<n;i++)
        {
            pq.push({profit[i],difficulty[i]});
        }
        
        // Sort the worker array in descending order to assign the most capable workers first 
        sort(worker.begin(),worker.end(),greater<int>());
        
        int totalProfit = 0;
        
        // Iterate through each worker
        for(auto x:worker)
        {
            // Remove jobs that are too difficult for the current worker
            while(!pq.empty() && pq.top().second > x)
            {
                pq.pop();
            }
            
            // If the priority queue is not empty, add the highest profit job the worker can do
            if(!pq.empty())
            {
                totalProfit += pq.top().first;
            }
        }
        // Return the total profit
        return totalProfit;
    }
};

****************************************APPROACH 2nd(USING BINARY SEARCH)**************************************

class Solution {// TC--->O(NlogN)              SC--->O(N)
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Number of jobs
        int n = difficulty.size();
        
        // Number of workers
        int m = worker.size();
        
        // Vector to store pairs of (difficulty, profit)
        vector<pair<int,int>>vec;
        
        // Populate the vec with (difficulty, profit) pairs
        for(int i=0;i<n;i++)
        {
          vec.push_back({difficulty[i],profit[i]});
        }
        
        // Sort the vec by difficulty (and by profit if difficulties are the same)
        sort(vec.begin(),vec.end());
        
        // Update the profit in vec to be the maximum profit achievable up to that difficulty
        for(int i=1;i<n;i++)
        {
            vec[i].second = max(vec[i].second,vec[i-1].second);
        }
        
        int totalProfit = 0;
        
        // Iterate through each worker
        for(int i=0;i<m;i++)
        {
            int workerDiffLevel = worker[i];
            
            // Binary search to find the maximum profit a worker can achieve given their ability
            int low = 0,high = vec.size()-1;
            int maxProfit = 0;
            while(low <= high)
            {
                int mid = low + (high-low)/2;
                if(vec[mid].first <= workerDiffLevel)
                {
                    // If the job's difficulty is less than or equal to the worker's ability, consider this profit
                    maxProfit = max(maxProfit,vec[mid].second);
                    low = mid + 1;
                }
                else
                {
                    // If the job's difficulty is too high, search in the lower half
                    high = mid - 1;
                }
            }
            
            // Add the best profit found for this worker to the total profit
            totalProfit += maxProfit;
        }
        
        // Return the total profit accumulated
        return totalProfit;
    }
};

*********************************************APPROACH 3rd(USING SORTING AND 2 POINTERS)****************************

class Solution {// TC--->O(NlogN + MlogN + M + N)       SC--->O(N)
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Number of jobs
        int n = difficulty.size();
        
        // Number of workers
        int m = worker.size();
        
        // Vector to store pairs of (difficulty, profit)
        vector<pair<int,int>>vec;
        
        // Populate the vec with (difficulty, profit) pairs
        for(int i=0;i<n;i++)
        {
            vec.push_back({difficulty[i],profit[i]});
        }
        
        // Sort the vec by difficulty (ascending order)
        sort(vec.begin(),vec.end());
        
        // Sort the worker array (ascending order)
        sort(worker.begin(),worker.end());
        
        // Initialize totalProfit to accumulate the total profit
        int totalProfit = 0;
        
        // Initialize j to iterate over the sorted jobs
        int j = 0;
        
        // Initialize maxProfit to keep track of the maximum profit achievable
        int maxProfit = 0;
        
        // Iterate through each worker
        for(int i=0;i<m;i++)
        {
            // While there are jobs available and the current worker can do the job
            while(j < n && worker[i] >= vec[j].first)
            {
                // Update maxProfit with the maximum profit found so far
                maxProfit = max(maxProfit,vec[j].second);
                
                // Move to the next job
                j++;
            }
            
            // Add the maxProfit for the current worker to the totalProfit
            totalProfit += maxProfit;
        }
        
        // Return the total profit accumulated
        return totalProfit;
    }
};
