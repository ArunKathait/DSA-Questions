
class Solution { // Time: O(n × m × log(n × m))                            Space: O(n × m)
public: 
    // Stores:
    // {height, {row, col}}
    //
    // Example:
    // {5, {2, 3}}
    // means:
    // cell = (2,3)
    // current effective boundary height = 5
    typedef pair<int,pair<int,int>> PP; 

    int trapRainWater(vector<vector<int>>& heightMap) { 
        
        int n = heightMap.size();       // Number of rows
        int m = heightMap[0].size();    // Number of columns
 
        // Min Heap:
        // The cell having the smallest height will come out first.
        //
        // Why?
        // We always want to process the LOWEST boundary first,
        // because that boundary determines how much water can
        // actually be trapped.
        priority_queue<PP,vector<PP>,greater<PP>> boundaryCells; 

        // visited[i][j] = true means this cell has already been
        // added to the heap.
        //
        // We mark a cell visited when pushing it into the heap
        // so that we don't add the same cell multiple times.
        vector<vector<bool>> visited(n,vector<bool>(m,false)); 
 
        // --------------------------------------------------
        // STEP 1: Put LEFT and RIGHT boundary cells in heap
        // --------------------------------------------------
        for(int i=0;i<n;i++) 
        { 
            // Left boundary
            boundaryCells.push({heightMap[i][0],{i,0}}); 

            // Right boundary
            boundaryCells.push({heightMap[i][m-1],{i,m-1}}); 

            // Mark them visited
            visited[i][0] = true; 
            visited[i][m-1] = true; 
        } 
 
        // --------------------------------------------------
        // STEP 2: Put TOP and BOTTOM boundary cells in heap
        // --------------------------------------------------
        for(int j=0;j<m;j++) 
        { 
            // Top boundary
            boundaryCells.push({heightMap[0][j],{0,j}}); 

            // Bottom boundary
            boundaryCells.push({heightMap[n-1][j],{n-1,j}}); 

            // Mark them visited
            visited[0][j] = true; 
            visited[n-1][j] = true; 
        } 
 
        int ans = 0;   // Total trapped water
 
        // These arrays are used to move in 4 directions:
        //
        //          (-1,0)
        //             ↑
        //             |
        // (0,-1) ←  cell  → (0,1)
        //             |
        //             ↓
        //          (1,0)
        vector<int>delRow = {-1,0,1,0}; 
        vector<int>delCol = {0,1,0,-1}; 
 
        // --------------------------------------------------
        // STEP 3: Process boundary cells
        // --------------------------------------------------
        while(!boundaryCells.empty()) 
        { 
            // Get the LOWEST boundary cell from the min heap.
            //
            // height = effective boundary height
            // cell   = {row, col}
            auto [height,cell] = boundaryCells.top(); 
            boundaryCells.pop(); 
 
            int row = cell.first; 
            int col = cell.second; 
 
            // --------------------------------------------------
            // STEP 4: Check all 4 neighbors
            // --------------------------------------------------
            for(int k=0;k<4;k++) 
            { 
                int newRow = row + delRow[k]; 
                int newCol = col + delCol[k]; 
 
                // Ignore the neighbor if:
                //
                // 1. It is outside the matrix
                // 2. It has already been visited
                if(newRow < 0 || newRow >= n || 
                   newCol < 0 || newCol >= m || 
                   visited[newRow][newCol]) 
                { 
                    continue; 
                } 
 
                // --------------------------------------------------
                // STEP 5: Calculate trapped water
                // --------------------------------------------------
                //
                // If boundary height = 5
                // Neighbor height  = 2
                //
                // Water trapped = 5 - 2 = 3
                //
                // If neighbor is higher than boundary:
                //
                // max(5 - 7, 0) = 0
                //
                // So no water is trapped.
                ans += max(height - heightMap[newRow][newCol],0); 
                 
                // --------------------------------------------------
                // STEP 6: Add neighbor to the min heap
                // --------------------------------------------------
                //
                // The new effective height is:
                //
                // max(current boundary height, neighbor height)
                //
                // Example 1:
                // current boundary = 5
                // neighbor = 2
                // effective height = 5
                //
                // Example 2:
                // current boundary = 5
                // neighbor = 7
                // effective height = 7
                //
                // Why?
                // If neighbor is lower than the boundary, water fills
                // it up to the boundary level.
                boundaryCells.push({
                    max(height,heightMap[newRow][newCol]),
                    {newRow,newCol}
                }); 

                // Mark visited immediately after adding it to heap.
                visited[newRow][newCol] = true; 
            } 
        } 
 
        // Return total amount of trapped water.
        return ans; 
    } 
};

/* 

🧠 Easy way to remember the whole algorithm

Put all boundary cells
        ↓
    Min Heap
        ↓
Take lowest boundary
        ↓
Check 4 neighbors
        ↓
Is neighbor lower?
     /       \
   YES        NO
    ↓          ↓
water =       0
height-cell
    ↓
Push neighbor with
max(height, cell height)
        ↓
      Repeat

/*

┌──────────────────────────────────────────┐
│        TRAPPING RAIN WATER II            │
├──────────────────────────────────────────┤
│                                          │
│ We start from the boundary cells         │
│ because water can escape from boundary.  │
│                                          │
│ Put all boundary cells in MIN HEAP       │
│                                          │
│ MIN HEAP → lowest boundary first         │
│                                          │
│ Pop:                                     │
│                                          │
│     height = current boundary height     │
│     cell   = current row, col            │
│                                          │
│ Check 4 neighbours                       │
│                                          │
│ If neighbour is lower:                   │
│                                          │
│     water = height - neighbourHeight     │
│                                          │
│ Otherwise:                               │
│                                          │
│     water = 0                            │
│                                          │
│ Then push neighbour into heap:           │
│                                          │
│     effectiveHeight =                    │
│     max(height, neighbourHeight)         │
│                                          │
│ Why max()?                               │
│                                          │
│ If boundary = 5 and cell = 2             │
│                                          │
│     water = 5 - 2 = 3                    │
│                                          │
│ After filling, effective height = 5      │
│                                          │
│ Mark neighbour as visited                │
│                                          │
│ Repeat until heap becomes empty          │
│                                          │
│ Pattern:                                 │
│ Min Heap + BFS + Boundary + Visited      │
│                                          │
│ Time  : O(n × m × log(n × m))            │
│ Space : O(n × m)                         │
└──────────────────────────────────────────┘

*/
