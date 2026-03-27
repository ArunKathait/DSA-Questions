
class Solution {// TC ---> O(N)                                           SC ---> O(N)
public:
    // DFS function to traverse graph and detect cycles
    void dfs(int u, vector<int>& edges, vector<bool>& visited,vector<bool>& inRecursion, vector<int>& count, int &ans)
    {
        // Mark current node as visited
        visited[u] = true;

        // Mark current node as part of current DFS path (recursion stack)
        inRecursion[u] = true;

        // Get the next node (since each node has at most one outgoing edge)
        int v = edges[u];

        // Case 1: If next node exists and is not visited → continue DFS
        if(v != -1 && !visited[v])
        {
            // Increase depth (distance from starting node)
            count[v] = count[u] + 1;

            // DFS call on next node
            dfs(v, edges, visited, inRecursion, count, ans);
        }

        // Case 2: If next node exists and is already in recursion stack
        // → cycle detected
        else if(v != -1 && inRecursion[v] == true)
        {
            // Cycle length = difference in depth + 1
            ans = max(ans, count[u] - count[v] + 1);
        }

        // Backtracking step:
        // Remove current node from recursion stack
        inRecursion[u] = false;
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();

        // Track visited nodes
        vector<bool> visited(n, false);

        // Track nodes in current recursion path (for cycle detection)
        vector<bool> inRecursion(n, false);

        // Store depth (or step count) of each node
        vector<int> count(n, 1);

        // Store maximum cycle length
        int ans = -1;

        // Try DFS from every unvisited node
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                // Start DFS from node i
                dfs(i, edges, visited, inRecursion, count, ans);
            }
        }

        // Return longest cycle length (or -1 if none)
        return ans;
    }
};
