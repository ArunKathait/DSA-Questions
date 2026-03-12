
class Solution {// TC ---> O(E * k)                                SC ---> O(n + E)
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // adjacency list representation of graph
        // key = city
        // value = list of {neighbor city, flight cost}
        unordered_map<int, vector<pair<int,int>>> adj;

        // build the graph from the flights list
        for(auto &flight : flights)
        {
            int from = flight[0];   // starting city
            int to = flight[1];     // destination city
            int cost = flight[2];   // flight cost

            // store edge in adjacency list
            adj[from].push_back({to, cost});
        }
        
        // distance[i] stores the minimum cost to reach city i
        // initially all distances are infinity
        vector<int> distance(n, INT_MAX);

        // cost to reach source city is 0
        distance[src] = 0;

        // queue used for BFS traversal
        // each element contains {current city, cost to reach that city}
        queue<pair<int,int>> q;

        // start BFS from source city
        q.push({src, 0});

        // stops represents how many flights (levels) we have taken
        int stops = 0;

        // BFS traversal allowed only up to k stops
        while(!q.empty() && stops <= k)
        {
            // number of nodes in current level
            int size = q.size();

            // process all nodes in current level
            while(size--)
            {
                // get current city
                int currCity = q.front().first;

                // cost to reach this city
                int currCost = q.front().second;

                q.pop();

                // explore all neighboring cities
                for(auto &neighbor : adj[currCity])
                {
                    int nextCity = neighbor.first;      // next city
                    int flightCost = neighbor.second;   // cost to reach next city

                    // relaxation step (shortest path logic)
                    // if new cost is smaller than the stored cost
                    if(distance[nextCity] > currCost + flightCost)
                    {
                        // update minimum cost to reach next city
                        distance[nextCity] = currCost + flightCost;

                        // push next city into queue with updated cost
                        q.push({nextCity, currCost + flightCost});
                    }
                }
            }

            // increase number of stops after finishing this level
            stops++;
        }

        // if destination city is unreachable return -1
        // otherwise return minimum cost
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

/* NOTE : 

Why did you use BFS instead of Dijkstra?

Best answer:

Since the problem restricts the number of stops to k, we can perform a BFS traversal up to k levels. 
Each level represents one flight. During traversal we relax the cost similar to shortest path logic. 
Because the depth is bounded by k, BFS with a queue is sufficient instead of using Dijkstra with a priority queue.

✅ Short summary

Approach	Use Case
BFS + Queue	--------> when stops/levels are limited
Dijkstra	 ---------> when we need global minimum cost

*/
