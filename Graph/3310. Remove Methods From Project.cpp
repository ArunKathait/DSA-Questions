
class Solution {// TC ---> O(V + E)                                    SC ---> O(V + E)
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Adjacency list representing the directed graph.
        // u -> v means method u invokes method v.
        unordered_map<int, vector<int>> adj;

        // suspicious[i] = true means method i is suspicious
        // (either it is method k or can be reached from k).
        vector<bool> suspicious(n, false);

        // indegree[i] stores how many methods invoke method i.
        vector<int> indegree(n);

        // Build the graph and calculate indegree of every node.
        for (auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        // Start BFS from the suspicious method k.
        queue<int> q;
        q.push(k);

        // Mark k as suspicious.
        suspicious[k] = true;

        // Perform BFS to find all methods reachable from k.
        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            // Traverse all methods called by the current method.
            for (auto &neighbor : adj[current])
            {
                // Since current is suspicious,
                // we conceptually remove the edge current -> neighbor.
                indegree[neighbor]--;

                // If neighbor has not been marked suspicious,
                // mark it and continue BFS.
                if (!suspicious[neighbor])
                {
                    q.push(neighbor);
                    suspicious[neighbor] = true;
                }
            }
        }

        vector<int> ans;

        // Flag to check whether suspicious methods
        // can actually be removed.
        bool cannotRemove = false;

        // Check every method.
        for (int i = 0; i < n; i++)
        {
            // If a suspicious method still has indegree > 0,
            // it means some non-suspicious method still invokes it.
            // Therefore, suspicious methods cannot be removed.
            if (suspicious[i] && indegree[i] > 0)
            {
                cannotRemove = true;
                break;
            }

            // Collect all non-suspicious methods.
            if (!suspicious[i])
            {
                ans.push_back(i);
            }
        }

        // If suspicious methods cannot be removed,
        // return all methods.
        if (cannotRemove)
        {
            vector<int> temp(n);

            for (int i = 0; i < n; i++)
            {
                temp[i] = i;
            }

            return temp;
        }

        // Otherwise return only the remaining (non-suspicious) methods.
        return ans;
    }
};
