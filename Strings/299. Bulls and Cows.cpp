
class Solution {// Time: O(n)                                         Space: O(1)
public:
    string getHint(string secret, string guess) {
        
        // Both strings have the same length in this problem.
        int n = secret.size();

        /*
            secretFreq[d] = frequency of digit d
                           in secret at positions that
                           are NOT bulls.

            guessFreq[d]  = frequency of digit d
                           in guess at positions that
                           are NOT bulls.

            Since digits are only 0-9, we only need
            arrays of size 10.
        */
        vector<int> secretFreq(10, 0);
        vector<int> guessFreq(10, 0);

        int bulls = 0;

        /*
            Traverse both strings at the same time.

            If secret[i] == guess[i]:
                Same digit at the same position
                => Bull

            Otherwise:
                They cannot be a bull, so store their
                frequencies for later cow calculation.
        */
        for(int i = 0; i < n; i++)
        {
            // Same digit AND same position
            // => This is a Bull.
            if(secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                /*
                    These positions are NOT bulls.

                    Store their frequencies separately
                    so that later we can find how many
                    digits exist in both strings.
                */
                secretFreq[secret[i] - '0']++;
                guessFreq[guess[i] - '0']++;
            }
        }

        int cows = 0;

        /*
            Now calculate Cows.

            For every digit 0-9:

            If secret has:
                3 occurrences of '5'

            and guess has:
                2 occurrences of '5'

            We can match only 2 of them.

            Therefore:
                cows += min(secretFreq[i], guessFreq[i]);
        */
        for(int i = 0; i < 10; i++)
        {
            cows += min(secretFreq[i], guessFreq[i]);
        }

        /*
            Result format:

            "xAyB"

            x = number of Bulls
            y = number of Cows

            Example:
                bulls = 1
                cows = 2

                return "1A2B"
        */
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

/*

┌────────────────────────────────────┐
│          BULLS AND COWS            │
├────────────────────────────────────┤
│ 1. Same position?                  │
│       ↓                            │
│    Bull++                          │
│                                    │
│ 2. Otherwise                       │
│    store frequency                 │
│                                    │
│ 3. For each digit 0-9:             │
│    cows += min(secretFreq[d],      │
│                guessFreq[d])       │
│                                    │
│ Time  : O(n)                       │
│ Space : O(1)                       │
└────────────────────────────────────┘

*/
