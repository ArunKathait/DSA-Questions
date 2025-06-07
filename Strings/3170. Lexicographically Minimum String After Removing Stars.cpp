
class Solution {// TC--->O(NLogN)                            SC--->O(N)
public: 
    // Define a type alias 'P' for a pair of character and integer (char, index)
    typedef pair<char, int> P;

    // Custom comparator for the priority queue
    struct myComp 
    {
        bool operator()(P &p1, P &p2) 
        {
            // If characters are the same, prioritize the one that comes *later* (higher index)
            if (p1.first == p2.first) 
            {
                return p1.second < p2.second; // later index is "smaller" in the queue
            }
            // Otherwise, prioritize the lexicographically smaller character
            return p1.first > p2.first; // smaller char is "greater" in min-heap style
        }
    };

    string clearStars(string s) {
        int n = s.length();

        // Priority queue to keep track of characters with their indices based on the custom order
        priority_queue<P, vector<P>, myComp> pq;

        // Traverse the string
        for (int i = 0; i < n; i++) 
        {
            if (s[i] != '*') 
            {
                // Push non-star characters with their index into the priority queue
                pq.push({s[i], i});
            } 
            else 
            {
                // On encountering a '*', remove the character with highest priority
                int index = pq.top().second;
                pq.pop();
                // Mark the corresponding character in the string as '*'
                s[index] = '*';
            }
        }

        // Construct the answer string by skipping all '*' characters
        string ans;
        for (int i = 0; i < n; i++) 
        {
            if (s[i] != '*') 
            {
                ans += s[i];
            }
        }

        return ans;
    }
};
