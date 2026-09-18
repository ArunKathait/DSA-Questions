
class Solution {// Time Complexity  → O(N)                  Space Complexity → O(N)
public:

    vector<string> maxNumOfSubstrings(string s) {

        int n = s.length();

        // start[c] = first occurrence of character c
        // end[c]   = last occurrence of character c
        //
        // Example:
        // s = "adefaddaccc"
        //
        // For 'a':
        // start['a'] = 0
        // end['a']   = 7
        vector<int> start(26, -1);
        vector<int> end(26, -1);


        // isValid[c] tells whether we can create
        // a valid substring starting from character c.
        //
        // Initially assume every character is valid.
        vector<bool> isValid(26, true);


        // Stores our final answer.
        vector<string> ans;


        // ---------------------------------------------------------
        // STEP 1: Find first and last occurrence of every character
        // ---------------------------------------------------------

        for(int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';

            // If this is the first time we see this character,
            // store its first position.
            if(start[index] == -1)
            {
                start[index] = i;
            }

            // Every time we see the character,
            // update its last occurrence.
            end[index] = i;
        }


        // ---------------------------------------------------------
        // STEP 2: Find valid intervals for every character
        // ---------------------------------------------------------

        for(char ch = 0; ch < 26; ch++)
        {
            // If this character does not exist in the string,
            // there is nothing to process.
            if(start[ch] == -1)
            {
                continue;
            }


            // Initially consider the interval:
            //
            // [first occurrence of ch ... last occurrence of ch]
            //
            // We scan every character inside this interval.
            for(int i = start[ch]; i <= end[ch]; i++)
            {
                int currentChar = s[i] - 'a';

                // If the current character appeared BEFORE
                // the starting position of ch,
                // then we cannot make a valid substring starting
                // from ch.
                //
                // Why?
                //
                // A valid substring must contain ALL occurrences
                // of every character that appears inside it.
                //
                // If currentChar has an occurrence before start[ch],
                // that occurrence would be outside our substring.
                if(start[currentChar] < start[ch])
                {
                    isValid[ch] = false;
                    break;
                }


                // The current character may have its last occurrence
                // farther to the right.
                //
                // Therefore, we must expand our interval.
                //
                // Example:
                //
                // Current interval = [0 ... 3]
                // Character inside interval has last occurrence = 7
                //
                // New interval = [0 ... 7]
                end[ch] = max(end[ch], end[currentChar]);
            }
        }


        // ---------------------------------------------------------
        // STEP 3: Select maximum number of non-overlapping intervals
        // ---------------------------------------------------------

        // Stores the starting position of the last selected substring.
        //
        // We scan from RIGHT to LEFT.
        int lastTakenStart = INT_MAX;


        for(int i = n - 1; i >= 0; i--)
        {
            int ch = s[i] - 'a';


            // If this character cannot form a valid substring,
            // simply skip it.
            if(!isValid[ch])
            {
                continue;
            }


            // We only want to process the FIRST occurrence
            // of this character.
            //
            // i == start[ch]
            //
            // This means i is the left boundary of its valid interval.
            //
            // Also:
            //
            // end[ch] < lastTakenStart
            //
            // guarantees that the current substring lies completely
            // BEFORE the previously selected substring.
            if(i == start[ch] && end[ch] < lastTakenStart)
            {
                // Extract the substring:
                //
                // starting index = i
                // length = end[ch] - i + 1
                //
                // Example:
                // i = 2, end[ch] = 5
                // length = 5 - 2 + 1 = 4
                ans.push_back(s.substr(i, end[ch] - i + 1));


                // Update the boundary of the last selected substring.
                lastTakenStart = i;
            }
        }


        // Return all selected non-overlapping substrings.
        return ans;
    }
};

/*

╔════════════════════════════════════════════╗
║     MAX NUMBER OF SUBSTRINGS — GREEDY      ║
╠════════════════════════════════════════════╣
║ Pattern: Interval Expansion + Greedy       ║
║                                            ║
║ start[c] → first occurrence of c           ║
║ end[c]   → last occurrence of c            ║
║                                            ║
║ Step 1: Find first & last position         ║
║                                            ║
║ Step 2: Build interval [start[c], end[c]]  ║
║ → Scan characters inside the interval      ║
║ → Expand end[c] if needed                  ║
║                                            ║
║ Invalid:                                   ║
║ start[s[i]-'a'] < start[c]                 ║
║ → character occurs before our interval     ║
║ → mark c as invalid                        ║
║                                            ║
║ Valid substring:                           ║
║ → contains ALL occurrences of its chars    ║
║                                            ║
║ Step 3: Greedy selection                   ║
║ → Scan right → left                        ║
║ → Select valid intervals                   ║
║ → end[c] < lastTakenStart → no overlap     ║
║                                            ║
║ Key Idea:                                  ║
║ → Find smallest valid intervals            ║
║ → Smaller intervals leave more space       ║
║   for other substrings                     ║
║                                            ║
║ TC → O(N)                                  ║
║ SC → O(N)                                  ║
╚════════════════════════════════════════════╝

*/
