
class Solution {// TC ---> O(N log N)                   SC ---> O(N)
  public:
    int minCost(vector<int>& arr) {
        
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        
        int totalCost = 0;
        
        while(pq.size() >= 2)
        {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            
            int sum = (first + second);
            
            totalCost += sum;
            
            pq.push(sum);
            
        }
        return totalCost;
    }
};
