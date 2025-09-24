**************************************************APPROACH 1st(USING DFS)********************************************

class Solution {// TC--->O(n + E)(where n = number of rooms, E = total number of keys in all rooms).
                // SC--->O(n) + O(n) = O(n).
public:
    // Depth-First Search function to explore rooms
    void dfs(int source, vector<vector<int>>& rooms, vector<bool>& visited) {
        // Mark the current room as visited
        visited[source] = true;

        // Explore all the keys (neighbors) in the current room
        for (auto &neighbor : rooms[source]) 
        {
            // If the neighbor room is not visited yet, go visit it
            if (!visited[neighbor]) 
            {
                dfs(neighbor, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // total number of rooms
        int n = rooms.size();  

        // Create a visited array to keep track of visited rooms
        vector<bool> visited(n, false);

        // Start DFS from room 0 (we always begin from room 0)
        dfs(0, rooms, visited);

        // After DFS, check if all rooms were visited
        for (auto room : visited) 
        {
            if (room != true) 
            {  
                // If any room is not visited, return false
                return false;
            }
        }

        // If all rooms are visited, return true
        return true;
    }
};

*********************************************APPROACH 2nd(USING BFS)*************************************************

class Solution {// Time Complexity: O(n + E)                              Space Complexity: O(n)
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // total number of rooms
        int n = rooms.size();  

        // visited[i] = true means room i has been visited
        vector<bool> visited(n, false);

        // Queue for BFS traversal
        queue<int> q;

        // Start from room 0
        q.push(0);

        // Mark room 0 as visited         
        visited[0] = true; 

        // Standard BFS loop
        while (!q.empty()) 
        {
            // Get the current room
            auto room = q.front(); 
            q.pop();

            // Explore all keys in the current room
            for (auto &neighbor : rooms[room]) 
            {
                // If we haven't visited this neighbor room yet
                if (!visited[neighbor]) 
                {
                    // Add it to queue for exploration
                    q.push(neighbor); 

                    // Mark as visited      
                    visited[neighbor] = true; 
                }
            }
        }

        // After BFS finishes, check if every room has been visited
        for (auto room : visited) 
        {
            if (room != true) 
            {   // if any room is still false → not visited
                return false;   // Not all rooms are reachable
            }
        }

        // If all rooms are visited, return true
        return true;
    }
};
