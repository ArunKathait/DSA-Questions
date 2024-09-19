**************************************************APPROACH 1st*********************************************************

class Solution {// TC--->O(NlogK)                       SC--->O(k + N) 
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Priority queue (max heap) to store points based on their squared distance from the origin.
        // The top of the queue will always have the point with the largest distance, so we can remove it if the size exceeds k.
        priority_queue<pair<int,pair<int,int>>>pq;
        
        // Iterate through each point in the input points vector
        for(auto &x:points)
        {
            // The x-coordinate of the point
            int first = x[0];
            
            // The y-coordinate of the point
            int second = x[1];
            
            // Calculate the squared distance of the point from the origin (0,0) using the formula: distance^2 = x^2 + y^2
            int difference = first*first + second*second;
            
            // Push the point into the priority queue. The queue stores pairs where the first element is the squared distance,
            // and the second element is another pair storing the point coordinates.
            pq.push({difference,{first,second}});
            
            // If the size of the priority queue exceeds 'k', we remove the point with the largest distance (from the top of the max heap).
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        // Vector to store the 'k' closest points to the origin.
        vector<vector<int>>ans;
        
        // Pop elements from the priority queue (which are the k closest points).
        while(!pq.empty())
        {
            // Extract the point from the top of the heap
            pair<int,int>p = pq.top().second;
            
            // The x-coordinate
            int a = p.first;
            
            // The y-coordinate
            int b = p.second;
            
            // Add the point to the answer.
            ans.push_back({a,b});
            
            // Remove the top element from the heap.
            pq.pop();
        }
        
        // Return the k closest points.
        return ans;
        
        
    }
};

***************************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(NlogK)                      SC--->O(k + N)
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Priority queue (max heap) to store pairs of distance and index.
        priority_queue<pair<int,int>>pq;
        
        // Iterate through each point in the input points vector
        for(int i=0;i<points.size();i++)
        {
            // The x-coordinate of the point
            int first = points[i][0];
            
            // The y-coordinate of the point
            int second = points[i][1];
            
            // Calculate the squared distance of the point from the origin (0,0) using the formula:
            // distance^2 = x^2 + y^2
            int difference = first*first + second*second;
            
            // Push the squared distance and the index of the point into the priority queue
            pq.push({difference,i});
            
            // If the size of the priority queue exceeds 'k', we remove the point with the largest distance
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        // Vector to store the 'k' closest points to the origin.
        vector<vector<int>>ans;
        
        // Pop elements from the priority queue and add the corresponding points to the result vector.
        while(!pq.empty())
        {
            // Get the index of the point from the priority queue
            int index = pq.top().second;
            
            // Add the corresponding point to the answer
            ans.push_back(points[index]);
            
            // Remove the top element from the heap.
            pq.pop();
        }
        
        // Return the k closest points.
        return ans;
    }
};
