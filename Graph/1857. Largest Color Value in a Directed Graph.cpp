
class Solution {// Time = O(N + E)                             Space = O(N + E)
public:

    // Returns the largest color value in the directed graph
    int largestPathValue(string colors, vector<vector<int>>& edges) {

        int n = colors.size();

        // ---------------------------------------------------------
        // Step 1: Build adjacency list
        // adj[u] contains all nodes that can be reached from u
        // ---------------------------------------------------------
        unordered_map<int, vector<int>> adj;

        // indegree[i] = number of incoming edges to node i
        vector<int> indegree(n, 0);

        for(auto &x : edges)
        {
            int u = x[0];
            int v = x[1];

            // Directed edge: u -> v
            adj[u].push_back(v);

            // v has one more incoming edge
            indegree[v]++;
        }

        // ---------------------------------------------------------
        // t[i][c] = maximum number of color c that we can have
        //            on any path ending at node i
        //
        // There are only 26 possible colors: a -> z
        // ---------------------------------------------------------
        vector<vector<int>> t(n, vector<int>(26, 0));

        // Queue used for Kahn's topological sort
        queue<int> q;

        // ---------------------------------------------------------
        // Step 2: Find all nodes having indegree = 0
        //
        // These nodes can be processed first because nobody
        // needs to come before them.
        // ---------------------------------------------------------
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);

                // The path starts from this node.
                // Therefore, its own color has frequency 1.
                t[i][colors[i] - 'a'] = 1;
            }
        }

        int ans = 0;

        // Number of nodes processed by topological BFS
        int countNodes = 0;

        // ---------------------------------------------------------
        // Step 3: Kahn's BFS / Topological Sort
        // ---------------------------------------------------------
        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            // The color of node u is colors[u].
            //
            // t[u][colors[u]-'a'] tells us the maximum number
            // of this color on a path ending at u.
            //
            // Update the global maximum answer.
            ans = max(ans, t[u][colors[u] - 'a']);

            // We successfully processed one node
            countNodes++;

            // -----------------------------------------------------
            // Process all neighbors of u
            //
            // For every edge:
            //
            //          u ---> v
            //
            // We try to extend every possible color-count path
            // from u to v.
            // -----------------------------------------------------
            for(auto &v : adj[u])
            {
                // Try all 26 colors
                for(int c = 0; c < 26; c++)
                {
                    // t[u][c] = maximum number of color c
                    //            on a path ending at u
                    //
                    // If color c is the same as v's color,
                    // we add 1.
                    //
                    // Otherwise, we add 0.
                    //
                    // Take max because v may have multiple
                    // incoming paths.
                    t[v][c] = max(t[v][c],t[u][c] + (colors[v] - 'a' == c));
                }

                // We have now processed edge u -> v,
                // so remove this incoming edge from v.
                indegree[v]--;

                // If v has no remaining incoming edges,
                // all its prerequisites are processed.
                //
                // Therefore, we can add v to the queue.
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // ---------------------------------------------------------
        // Step 4: Cycle detection
        //
        // In a DAG, topological sort processes every node.
        //
        // If countNodes < n, some nodes were never processed.
        // That means there is a cycle.
        //
        // The problem asks us to return -1 if a cycle exists.
        // ---------------------------------------------------------
        if(countNodes < n)
        {
            return -1;
        }

        // No cycle.
        // Return the maximum color frequency found.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│        LARGEST COLOR VALUE — CHEAT BOX       │
├──────────────────────────────────────────────┤
│ Pattern:                                     │
│ Multi-source Topological BFS + DP            │
│                                              │
│ 1. Build adjacency list                      │
│ 2. Calculate indegree                        │
│ 3. Put all indegree-0 nodes in queue         │
│ 4. DP[node][26] = max count of each color    │
│ 5. BFS using Kahn's algorithm                │
│ 6. If processed nodes < N → cycle → -1       │
│ 7. Otherwise return maximum DP value         │
└──────────────────────────────────────────────┘

*/
