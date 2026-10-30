
class Solution {// Time Complexity: O((n+m)k log(nk))              Space Complexity: O(nk + mk)
public:
    // Stores three values in the priority queue:
    // {current distance, current node, consecutive character count}
    typedef tuple<int, int, int> T;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        // Build adjacency list for the directed weighted graph.
        // adj[u] stores all outgoing neighbours of node u
        // along with their edge weights.
        unordered_map<int, vector<vector<int>>> adj;

        for (auto &x : edges) 
        {
            int u = x[0];
            int v = x[1];
            int weight = x[2];

            // Directed edge from u to v with weight.
            adj[u].push_back({v, weight});
        }

        // Min heap: processes the state having the minimum distance first.
        priority_queue<T, vector<T>, greater<T>> pq;

        // distance[node][count] stores the minimum cost to reach
        // a particular node with 'count' consecutive identical characters.
        //
        // count ranges from 1 to k.
        vector<vector<int>> distance(n, vector<int>(k + 1, INT_MAX));

        // Start from node 0.
        // Initially, we have visited one node, so consecutive count = 1.
        // Initial cost = 0.
        pq.push({0, 0, 1});
        distance[0][1] = 0;

        // Process states until the priority queue becomes empty.
        while (!pq.empty()) 
        {
            // Extract the state with minimum distance.
            auto [d, node, count] = pq.top();
            pq.pop();

            // If we have already found a better distance for this state,
            // skip this outdated entry.
            if (distance[node][count] < d) 
            {
                continue;
            }

            // If we reach the destination, return its minimum cost.
            // Dijkstra guarantees that the first popped destination state
            // has the minimum valid path cost.
            if (node == n - 1) 
            {
                return d;
            }

            // Explore all outgoing neighbours of the current node.
            for (auto &vec : adj[node]) 
            {
                int adjNode = vec[0];
                int wt = vec[1];

                int newCount;

                // If current and next node have the same character,
                // increase the consecutive character count.
                //
                // Otherwise, a new character sequence starts,
                // so reset the count to 1.
                newCount = (labels[node] == labels[adjNode]) ? count + 1 : 1;

                // If consecutive identical characters exceed k,
                // this transition is invalid.
                if (newCount > k) 
                {
                    continue;
                }

                // Calculate the total cost to reach the neighbour.
                int newDist = d + wt;

                // If this new path gives a smaller cost for the
                // (adjNode, newCount) state, update the distance.
                if (newDist < distance[adjNode][newCount]) {

                    distance[adjNode][newCount] = newDist;

                    // Push the updated state into the min heap.
                    pq.push({newDist, adjNode, newCount});
                }
            }
        }

        // If the priority queue becomes empty without reaching
        // the destination, no valid path exists.
        return -1;
    }
};

/*

┌──────────────────────────────────────────┐
│Dijkstra + State (Node, Consecutive Count)│
├──────────────────────────────────────────┤
│ 1. Build Adjacency List                  │
│    Store {neighbour, edge weight}        │
│                                          │
│ 2. Min Heap                              │
│    Store {distance, node, count}         │
│    Process minimum distance first        │
│                                          │
│ 3. Distance Array                        │
│    dist[node][count] = minimum cost      │
│    Maintain separate states for counts   │
│                                          │
│ 4. State Transition                      │
│    Same character     → count + 1        │
│    Different character → count = 1       │
│    count > k          → Skip             │
│                                          │
│ 5. Relaxation                            │
│    newDist = dist + edgeWeight           │
│    If smaller → Update & Push into heap  │
│                                          │
│ 6. Termination                           │
│    Destination popped → Return distance  │
│    No valid path       → Return -1       │
├──────────────────────────────────────────┤
│ Time Complexity:  O((n+m)k log(nk))      │
│ Space Complexity: O(nk + mk)             │
└──────────────────────────────────────────┘

*/
