
class Solution {// TC ---> O(E log V)                             SC ---> O(V + E)
public:
    // P will store {distance, node}
    typedef pair<int,int> P;

    int minCost(int n, vector<vector<int>>& edges) {

        // Adjacency list:
        // adj[u] -> list of {v, cost}
        unordered_map<int, vector<P>> adj;

        // Build the graph
        for (auto &x : edges) 
        {
            int u = x[0];
            int v = x[1];
            int weight = x[2];

            // Edge from u to v with given weight
            adj[u].push_back({v, weight});

            // Reverse edge from v to u with DOUBLE cost
            // (problem-specific condition)
            adj[v].push_back({u, 2 * weight});
        }

        // ans[i] = minimum cost to reach node i from node 0
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;   // cost to reach source is 0

        // Min-heap priority queue
        // Stores {current_distance, node}
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from node 0
        pq.push({0, 0});

        // Dijkstra's algorithm
        while (!pq.empty()) 
        {

            // Get node with minimum distance
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If destination node is reached,
            // we can return the minimum cost
            if (node == n - 1) 
            {
                return ans[n - 1];
            }

            // Relax all adjacent edges
            for (auto &p : adj[node]) 
            {
                int adjNode = p.first;   // neighboring node
                int dist = p.second;     // edge weight

                // If a shorter path to adjNode is found
                if (distance + dist < ans[adjNode]) 
                {
                    ans[adjNode] = distance + dist;
                    
                    // Push the updated distance to PQ
                    // (even if not optimal yet, PQ will handle it)
                    pq.push({distance + dist, adjNode});
                }
            }
        }

        // If destination cannot be reached
        return -1;
    }
};
