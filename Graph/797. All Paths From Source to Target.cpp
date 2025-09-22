**********************************************APPROACH 1st(USING DFS)***********************************************

class Solution {//Time Complexity: O(2^n * n)              Space Complexity: O(2^n * n)(for result) + O(n) (recursion stack)
public:
    // Depth-First Search function to explore all paths
    void dfs(int source, int target, vector<int>& path,vector<vector<int>>& ans, vector<vector<int>>& graph)
    {
        // ✅ Base case: if we reached the target node
        if (source == target) 
        {
            // store the current path
            ans.push_back(path); 

            // return because this path is complete  
            return;                
        }

        // Explore all neighbors of the current node
        for (auto neighbor : graph[source]) 
        {
            // ➡️ choose: include neighbor in current path
            path.push_back(neighbor);  

            // 🔁 explore deeper recursively           
            dfs(neighbor, target, path, ans, graph); 

            // ⬅️ backtrack: remove neighbor to explore other paths
            path.pop_back();                      
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // total number of nodes in the graph
        int n = graph.size();  

        // ✅ stores all valid paths from 0 → n-1
        vector<vector<int>> ans; 

        // ✅ keeps track of the current path being built
        vector<int> path; 

        // start path from source node (always 0)       
        path.push_back(0);      

        // start DFS from node 0 to node (n-1)
        dfs(0, n - 1, path, ans, graph);

        // return all possible paths
        return ans;  
    }
};

************************************************APPROACH 2nd(USING BFS)**********************************************

class Solution {// TC--->O(2^n * n)                         SC--->O(2^n * n)
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // total number of nodes in the graph
        int numNodes = graph.size(); 

        // stores all complete paths from source to target            
        vector<vector<int>> allPaths;            

        // queue to store partial paths during BFS
        queue<vector<int>> pathsQueue;           
        int sourceNode = 0;
        int targetNode = numNodes - 1;

        // Initialize BFS with the source node as the first path
        pathsQueue.push({sourceNode});

        while (!pathsQueue.empty()) 
        {
            // get the front path from the queue
            vector<int> currentPath = pathsQueue.front(); 
            pathsQueue.pop();

            // the last node in the current path
            int currentNode = currentPath.back();         

            // If we reached the target node, store this path as a valid path
            if (currentNode == targetNode) 
            {
                allPaths.push_back(currentPath);
            } 
            else 
            {
                // Otherwise, extend the path by each neighbor of the current node
                for (int neighbor : graph[currentNode]) 
                {
                    // copy the current path
                    vector<int> newPath = currentPath;  

                    // add the neighbor to the path 
                    newPath.push_back(neighbor);

                    // add the new path to the queue for further exploration         
                    pathsQueue.push(newPath);            
                }
            }
        }
        
        // return all possible paths from source to target
        return allPaths;   
    }
};
