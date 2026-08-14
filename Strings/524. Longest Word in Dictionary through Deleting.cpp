
class Solution  // TC --->  O(N × S)                      SC ---> O(L)
{
public:

    // Check whether "word" is a subsequence of "s"
    //
    // Example:
    // s    = "abpcplea"
    // word = "apple"
    //
    // We need to check whether we can form "apple"
    // by deleting some characters from "s".
    bool isSubsequence(string &word, string &s)
    {
        int n = s.length();
        int m = word.length();

        // i -> pointer for string s
        // j -> pointer for word
        int i = 0;
        int j = 0;

        // Continue until we reach the end of either string
        while(i < n && j < m)
        {
            // If characters match
            if(s[i] == word[j])
            {
                // We found the current character of word
                // Move both pointers
                i++;
                j++;
            }
            else
            {
                // Characters don't match
                // Skip this character of s
                i++;
            }
        }

        // If we matched all characters of word,
        // then word is a subsequence of s
        return j == m;
    }


    string findLongestWord(string s, vector<string>& dictionary)
    {
        int n = s.length();

        // Stores the best answer found so far
        string ans;


        // Check every dictionary word
        for(string &word : dictionary)
        {
            // Check whether this word can be formed
            // from s by deleting some characters
            if(isSubsequence(word, s))
            {
                // Case 1:
                // Current word is longer than our answer
                if(ans.length() < word.length())
                {
                    ans = word;
                }

                // Case 2:
                // Both words have the same length
                // Choose lexicographically smaller word
                else if(ans.length() == word.length() && word < ans)
                {
                    ans = word;
                }
            }
        }


        // Return the longest valid word
        return ans;
    }
};
