
class Solution {// TC--->O(m * (V + E))                                  SC--->O(V + E)
public:
    // DFS helper function to find the lexicographically smallest character 
    // in the connected component of the graph starting from 'currentChar'
    char DFSFindMinChar(char currentChar, unordered_map<char, vector<char>>& adj, vector<int>& visited) {
        // Mark current character as visited
        visited[currentChar - 'a'] = 1;   
        
        // Assume currentChar is the minimum initially
        char minChar = currentChar;       

        // Traverse all connected (equivalent) characters
        for (auto& v : adj[currentChar]) 
        {
            if (!visited[v - 'a']) 
            {
                // Recur for unvisited connected node and update minChar
                minChar = min(minChar, DFSFindMinChar(v, adj, visited));
            }
        }
        
        // Return the smallest character in this connected component
        return minChar;  
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Length of mapping strings
        int n = s1.length(); 

        // Length of baseStr to transform    
        int m = baseStr.length();

        // Step 1: Build the graph from character equivalences
        unordered_map<char, vector<char>> adj;
        for (int i = 0; i < n; i++) 
        {
            char u = s1[i];
            char v = s2[i];

            // Add both directions since equivalence is bidirectional
            adj[u].push_back(v); 
            adj[v].push_back(u);
        }

        string ans;
        // Step 2: For each character in baseStr, find its smallest equivalent
        for (int i = 0; i < m; i++) 
        {
            char ch = baseStr[i];

            // Reset visited for each DFS call
            vector<int> visited(26, 0);

            // Use DFS to find the smallest character in the same component
            char minChar = DFSFindMinChar(ch, adj, visited);

            // Append the smallest equivalent character to the result
            ans += minChar;
        }
        
        // Return the final transformed string
        return ans; 
    }
};
