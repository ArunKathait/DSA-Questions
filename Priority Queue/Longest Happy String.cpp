
class Solution {// TC--->O(a + b + c)                  SC--->O(1)
public:
    // A pair where 'first' represents the count of a character and 'second' represents the character itself.
    typedef pair<int,char>P;
    string longestDiverseString(int a, int b, int c) {
        // A max-heap (priority queue) to store the characters and their counts, sorted by the count.
        priority_queue<P>pq;
        
        // Push 'a' with its count if 'a' has at least 1 occurrence.
        if(a > 0)
        {
            pq.push({a,'a'});
        }
        
        // Push 'b' with its count if 'b' has at least 1 occurrence.
        if(b > 0)
        {
            pq.push({b,'b'});
        }
        
        // Push 'c' with its count if 'c' has at least 1 occurrence.
        if(c > 0)
        {
            pq.push({c,'c'});
        }
        
        // Result string to store the longest diverse string.

        string ans = "";
        
        // Continue building the string until the priority queue is empty.
        while(!pq.empty())
        {
            // Get the character with the highest count (largest element in the max-heap).
            int currentCount = pq.top().first;
            int currentChar = pq.top().second;
            pq.pop();
            
            // If the last two characters in 'ans' are the same as 'currentChar', we need to avoid adding it.
            if(ans.length() >= 2 && ans[ans.length() - 1] == currentChar && ans[ans.length() - 2] == currentChar)
            {
                // If no other characters are left, break the loop since we can't add this character anymore.
                if(pq.empty())
                {
                    break;
                }
            
                // Otherwise, get the next most frequent character.
                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();
            
                // Add the next character to the result.
                ans.push_back(nextChar);
                
                // Decrease the count of the next character since we used one occurrence.
                nextCount--;
            
                // Push the next character back into the heap if its count is still positive.
                if(nextCount > 0)
                {
                     pq.push({nextCount,nextChar});   
                }
            }
            else
            {
                // If the last two characters are not the same as 'currentChar', it's safe to add 'currentChar'.
                ans.push_back(currentChar);
                
                // Decrease the count of 'currentChar' since we used one occurrence.
                currentCount--;
            }
            
            // Push 'currentChar' back into the heap if its count is still positive after using it.
            if(currentCount > 0)
            {
                pq.push({currentCount,currentChar});
            }
        }
        
        // Return the longest diverse string constructed.
        return ans;
    }
};
