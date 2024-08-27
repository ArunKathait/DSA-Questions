
class Solution {// TC--->O(ElogV)                    SC--->O(V + E)
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Create an adjacency list to store the graph
        unordered_map<int,vector<pair<int,double>>>adj;
        
        // Populate the adjacency list with edges and their success probabilities
        for(int i=0;i<edges.size();i++)
        {
            // Start of edge
            int u = edges[i][0];
            
            // End of edge
            int v = edges[i][1];
            
            // Probability of successfully traversing the edge
            double prob = succProb[i];
            
            // Since it's an undirected graph, add both directions to the adjacency list
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        
        // Initialize a probability vector to track the maximum probability of reaching each node
        // Initially set to 0 for all nodes
        vector<double>probability(n,0);
        
        // The start node has a probability of 1 to start with itself
        probability[start_node] = 1;
        
        // Create a max heap (priority queue) to keep track of the highest probability path
        // The pair in the priority queue is (probability, node)
        priority_queue<pair<double,int>>pq;
        
        // Start from the start node with probability 1
        pq.push({1,start_node});
        
        // Process nodes until the queue is empty
        while(!pq.empty())
        {
            // Get the node with the highest probability from the priority queue
            auto front = pq.top();
            pq.pop();
            
            // Current node being processed
            int currNode = front.second;
            
            // Current maximum probability to reach currNode
            double currProb = front.first;
            
            // Traverse all the neighbors of the current node
            for(auto &child:adj[currNode])
            {   
                // Adjacent node (neighbor)
                int adjNode = child.first;
                
                // Probability of moving from currNode to adjNode
                double adjProb = child.second;
                
                // Check if the path through currNode to adjNode is better than the known path
                if(probability[adjNode] < currProb * adjProb)
                {
                    // If it is, update the probability of reaching adjNode
                    probability[adjNode] = currProb * adjProb;
                    
                    // Push the new path with updated probability into the priority queue 
                    pq.push({probability[adjNode],adjNode});
                }
            }
        }
        
        // Return the maximum probability to reach the end node 
        return probability[end_node];
    }
};
