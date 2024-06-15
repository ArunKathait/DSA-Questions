
class Solution {// TC--->O(NlogN)               SC--->O(N)
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Vector to store pairs of (capital required, profit)
        vector<pair<int,int>>vec(n);
        
        // Fill the vector with the corresponding (capital, profit) pairs
        for(int i=0;i<n;i++)
        {
            vec[i] = {capital[i],profits[i]};
        }
        
        // Sort the vector based on the capital required in ascending order
        sort(vec.begin(),vec.end());
        
        // Max-heap (priority queue) to store available profits
        priority_queue<int>pq;
        
        // Index to traverse the sorted vector
        int i=0;
        
        // Iterate for k projects
        while(k--)
        {
            // Push all projects whose capital requirement is <= current available capital (w)
            while(i<n && vec[i].first <= w)
            {
                pq.push(vec[i].second);
                i++;
            }
            
            // If no projects can be taken with current capital, break out of loop
            if(pq.empty())
            {
                break;
            }
            
            // Take the project with the maximum profit available
            // Add the profit to current capital
            w += pq.top();
            
            // Remove the taken project's profit from the heap
            pq.pop();
        }
        
        // Return the final capital after completing up to k projects
        return w;
    }
};
