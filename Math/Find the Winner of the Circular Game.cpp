************************************************APPROACH 1st(BRUTE FORCE)************************************************

class Solution {// TC--->O(N^2)               SC--->O(N)
public:
    int findTheWinner(int n, int k) {
        // Initialize a vector to store the participants numbered from 1 to n
        vector<int>vec;
        for(int i=1;i<=n;i++)
        {
            // Push each number from 1 to n into the vector
            vec.push_back(i);
        }
        
        // Initialize the starting index for elimination
        int i = 0;
        
        // Continue the elimination process until only one person remains
        while(vec.size() > 1)
        {
            // Calculate the index of the person to be removed
            // (i + k - 1) gives the position after moving k-1 steps from current index i
            // % vec.size() ensures the index wraps around if it exceeds the size of the vector
            int index = (i + k - 1)%vec.size();
            
            // Remove the person at the calculated index from the vector
            vec.erase(vec.begin() + index);
            
            // Update the starting index for the next round of elimination
            // The next elimination round starts from the index where the last person was removed
            i = index;
        }
        
        // Return the last remaining person in the vector, which is the winner
        return vec[0];
    }
};

*************************************************APPROACH 2nd(USING QUEUE)**********************************************

class Solution {//TC--->O(N*K)                SC--->O(N)
public:
    int findTheWinner(int n, int k) {
        // Initialize a queue to store participants numbered from 1 to n
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
            // Add each participant to the queue
            q.push(i);
        }
        
        // Continue until only one participant remains in the queue
        while(q.size() != 1)
        {
            // Move the first k-1 participants to the back of the queue
            for(int i=0;i<k-1;i++)
            {
                // Add the participant at the front to the back
                q.push(q.front());
                
                // Remove the participant from the front
                q.pop();
            }
            
            // Remove the k-th participant from the queue
            q.pop();
        }
        
        // The last remaining participant is the winner
        return q.front();
    }
};

*********************************************APPROACH 3rd(USING RECURSION)*********************************************

class Solution {// TC--->O(N)                 SC--->O(N)
public:
    int findWinnerIndex(int n,int k)
    {
        // Base case: when there is only one person left, they are the winner
        if(n == 1)
        {
            // 0-based index
            return 0;
        }
        
        // Recursive call to find the winner's index for (n-1) people
        int index = findWinnerIndex(n-1,k);
        
        // Update the index for n people by adding k and taking modulo n
        index = (index + k)%n;
        
        // 0-based index
        return index;
    }
    
    // Function to find the winner's index in 1-based indexing
    int findTheWinner(int n, int k) {
        
        // Call the recursive function to find the winner's 0-based index
        int winnerIndex = findWinnerIndex(n,k);
        
        // Convert the 0-based index to a 1-based index
        return winnerIndex + 1;
    }
};

***********************************************APPROACH 4th(OPTIMISED)*****************************************

class Solution {//TC--->O(N)                                SC--->O(1)
public:
    int findTheWinner(int n, int k) {
        // The position of the winner in 0-based index
        int winner = 0; 
        
        for (int i = 1; i <= n; i++) 
        {
            // Update the position of the winner for the current number of people
            winner = (winner + k) % i;
        }
        
        // Convert the position to 1-based index by adding 1
        return winner + 1;
    }
};
