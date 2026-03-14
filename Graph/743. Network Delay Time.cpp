
class Solution {// TC ---> O((V + E) log V)                            SC ---> O(V + E)
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency list
        // Key = node
        // Value = list of {neighbor node, travel time}
        unordered_map<int,vector<pair<int,int>>> adj;

        // Build the graph from the given edge list
        for(auto x : times)
        {
            int u = x[0];      // source node
            int v = x[1];      // destination node
            int time = x[2];   // time to travel from u -> v

            adj[u].push_back({v,time});
        }

        // Distance array
        // distance[i] will store the shortest time to reach node i
        vector<int> distance(n + 1, INT_MAX);

        // Min heap (priority queue)
        // It stores {current shortest time , node}
        // The node with the smallest time will always be processed first
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        // Start from source node k
        pq.push({0,k});

        // Time to reach source node is 0
        distance[k] = 0;

        // Process nodes until heap becomes empty
        while(!pq.empty())
        {
            // Get node with the smallest time
            auto top = pq.top();
            pq.pop();

            int cost = top.first;   // current shortest time
            int node = top.second;  // current node

            // If we already found a better path earlier,
            // skip this outdated entry
            if(cost > distance[node])
            {
                continue;
            }

            // Explore all neighbors of the current node
            for(auto &neighbor : adj[node])
            {
                int adjNode = neighbor.first;   // neighbor node
                int time = neighbor.second;     // edge weight

                // Check if going through current node gives a shorter path
                if(distance[adjNode] > time + cost)
                {
                    // Update shortest distance
                    distance[adjNode] = time + cost;

                    // Push updated distance into heap
                    pq.push({time + cost, adjNode});
                }
            }
        }

        // Now find the maximum distance among all nodes
        // because signal reaches the last node at the maximum time
        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            // If any node is unreachable
            if(distance[i] == INT_MAX)
            {
                return -1;
            }

            ans = max(ans, distance[i]);
        }

        // Maximum time required for signal to reach all nodes
        return ans;
    }
};

/*   NOTE:
     1️⃣ One-line definition

Dijkstra works by always selecting the node with the smallest known distance from the source, 
because that distance is guaranteed to be the final shortest distance when all edge weights are non-negative.

2️⃣ Internal Flow (Why min distance first)

Steps of the algorithm:

Start from the source node.

Set its distance to 0.

Push (distance, node) into a min heap.

Always pop the node with the minimum distance.

Relax its neighbors.

Update their distances if a shorter path is found.

The critical rule:

When the smallest distance node is removed from the heap,
its shortest distance is already finalized.

This is why the heap must prioritize minimum distance first.

Why this works

This works because all edge weights are positive.

If we already reached a node with the smallest distance, there is no way another path later will give a smaller value.

Example logic:

current distance = 5
any other path must add positive edges

5 + positive number > 5
So the current value is final.

When Dijkstra fails

Dijkstra fails if there are negative edges.

Example:

1 → 2 = 5
1 → 3 = 2
3 → 2 = -4

Shortest path to 2 should be:

1 → 3 → 2 = -2

But Dijkstra will finalize 2 = 5 earlier.

For negative edges we use:
Bellman–Ford Algorithm

6️⃣ Intuition (Very Important)

Think of it like signal spreading in waves.

Source → closest node → next closest → next closest

Distances expand like circles:

0 → 1 → 2 → 3 → 4

So always choose the closest unexplored node.

✅ Final Rule

For Dijkstra's Algorithm always:

priority_queue stores (distance , node)

because the algorithm must process minimum distance first.

*/
