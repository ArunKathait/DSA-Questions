
class Solution {// TC ---> O(N × 2ⁿ)                               SC ---> O(N × 2ⁿ)
public:
    // Pair to store (currentNode, visitedMask)
    typedef pair<int,int> P;

    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();   // Number of nodes in the graph

        // If graph has 0 or 1 node, no path needed
        if(n == 0 || n == 1)
        {
            return 0;
        }

        // Bitmask when ALL nodes are visited
        // Example: n = 4 -> 1111 (binary)
        int visitingAllNodes = (1 << n) - 1;

        // visited set stores states we have already processed
        // State = (node, mask)
        set<P> visited;

        // BFS queue storing (currentNode, visitedMask)
        queue<P> q;
        
        // Start BFS from every node (multi-source BFS)
        for(int i = 0; i < n; i++)
        {
            int maskValue = (1 << i);   // Only ith node visited
            q.push({i, maskValue});    // Push initial state
            visited.insert({i, maskValue});
        }
        
        int ans = 0;   // Distance / number of edges used

        // Standard BFS
        while(!q.empty())
        {
            int size = q.size();  // Nodes at current BFS level
            ans++;                // Each level means one more step

            while(size--)
            {
                auto current = q.front();
                q.pop();

                int currentNode = current.first;
                int currentMaskValue = current.second;

                // Visit all neighbors of current node
                for(auto &neighbor : graph[currentNode])
                {
                    // Update mask by marking neighbor as visited
                    int nextMaskValue = currentMaskValue | (1 << neighbor);

                    // If all nodes are visited, return steps
                    if(nextMaskValue == visitingAllNodes)
                    {
                        return ans;
                    }

                    // If this (node, mask) state is not visited before
                    if(visited.find({neighbor, nextMaskValue}) == visited.end())
                    {
                        visited.insert({neighbor, nextMaskValue});
                        q.push({neighbor, nextMaskValue});
                    }
                }
            }
        }

        // Should never reach here for a connected graph
        return -1;
    }
};
