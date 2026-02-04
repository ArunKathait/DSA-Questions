
class Solution {// TC ---> O(L + R) ~ L = left.size(),R = right.size()         SC ---> O(1)
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        // ans will store the maximum time taken by any ant to fall
        int ans = 0;

        // Ants moving towards the LEFT
        // Time taken by an ant at position x to fall off = x (distance to 0)
        for (auto x : left) 
        {
            ans = max(ans, x);   // keep track of the maximum time
        }

        // Ants moving towards the RIGHT
        // Time taken by an ant at position x to fall off = n - x (distance to n)
        for (auto x : right)
        {
            ans = max(ans, n - x);   // update maximum time if needed
        }

        // The last moment is the maximum time among all ants
        return ans;
    }
};
