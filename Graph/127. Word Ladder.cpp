
class Solution {// TC--->O(N * L * 26) ~ O(N * L)                      SC--->O(N * L)
public:         // N = number of words in wordList , L = length of each word

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Create a set of all words for O(1) lookup
        unordered_set<string> set(wordList.begin(), wordList.end());

        // Queue to perform BFS → stores {current word, current transformation steps}
        queue<pair<string,int>> q;
        q.push({beginWord, 1}); // start from the beginWord with 1 step

        // BFS traversal
        while(!q.empty())
        {
            // Extract the current word and the number of steps taken so far
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If the current word matches the endWord → return the number of steps
            if(word == endWord)
            {
                return steps;
            }

            // Try changing each character in the current word
            for(int i = 0; i < word.length(); i++)
            {
                // Copy the current word (so we can modify it safely)
                string temp = word;

                // Replace the i-th character with every possible lowercase letter
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp[i] = ch; // change one letter

                    // If the new word exists in our set → it's a valid transformation
                    if(set.find(temp) != set.end())
                    {
                        // Remove it from the set to mark it as visited
                        set.erase(temp);

                        // Push this new word into the queue with +1 step
                        q.push({temp, steps + 1});
                    }
                }
            }
        }

        // If BFS ends without finding endWord → transformation not possible
        return 0;
    }
};
