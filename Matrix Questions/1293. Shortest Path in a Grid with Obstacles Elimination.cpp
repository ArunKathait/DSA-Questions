
class Solution {// TC ---> O(n * m * k)                                   SC ---> O(n * m * k)
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {

        int n = grid.size();          // number of rows
        int m = grid[0].size();       // number of columns
        
        // visited[row][col][obstacle]
        // row, col -> current cell
        // obstacle -> how many obstacle removals are still left
        
        bool visited[41][41][1601];
        memset(visited,false,sizeof(visited));   // initially nothing is visited

        // queue will store {row, col, remaining obstacle removals}
        queue<vector<int>>q;

        int steps = 0;                // distance from start

        // start BFS from (0,0) with k obstacle removals
        q.push({0,0,k});
        visited[0][0][k] = true;

        while(!q.empty())
        {
            int size = q.size();      // number of nodes at current BFS level

            while(size--)
            {
                vector<int>temp = q.front();
                q.pop();

                int row = temp[0];
                int col = temp[1];
                int obstacle = temp[2];   // remaining obstacle removals

                // if destination reached
                if(row == n - 1 && col == m - 1)
                {
                    return steps;
                }

                // directions for 4 movement (up, right, down, left)
                vector<int>delRow = {-1,0,1,0};
                vector<int>delCol = {0,1,0,-1};

                for(int d=0;d<4;d++)
                {
                    int newRow = row + delRow[d];
                    int newCol = col + delCol[d];

                    // check boundary
                    if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= m)
                    {
                        continue;
                    }

                    // CASE 1: next cell is EMPTY
                    if(grid[newRow][newCol] == 0 && !visited[newRow][newCol][obstacle])
                    {
                        q.push({newRow,newCol,obstacle});
                        visited[newRow][newCol][obstacle] = true;
                    }

                    // CASE 2: next cell is OBSTACLE and we can remove it
                    else if(grid[newRow][newCol] == 1 && obstacle > 0 && !visited[newRow][newCol][obstacle-1])
                    {
                        q.push({newRow,newCol,obstacle-1});
                        visited[newRow][newCol][obstacle-1] = true;
                    }
                }
            }

            // after exploring one BFS level -> increase distance
            steps++;
        }

        // destination not reachable
        return -1;
    }
};

// We can also write visited like:
// vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k)));
