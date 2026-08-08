
class Solution {
public:

    vector<int> findAnagrams(string s, string p) {

        // This vector will store the starting indices
        // of all anagrams of p found in s.
        vector<int> ans;


        // If p is longer than s, it is impossible
        // to find an anagram of p inside s.
        if(p.length() > s.length())
        {
            return ans;
        }


        // pFreq stores the frequency of every character
        // present in string p.
        //
        // Index 0 -> 'a'
        // Index 1 -> 'b'
        // ...
        // Index 25 -> 'z'
        vector<int> pFreq(26, 0);


        // Count the frequency of each character in p.
        for(auto x : p)
        {
            pFreq[x - 'a']++;
        }

        /*
            Example:

            p = "abc"

            pFreq:

            a -> 1
            b -> 1
            c -> 1
        */


        // currentFreq stores the frequency of characters
        // in the current sliding window of s.
        vector<int> currentFreq(26, 0);


        // Create the first window.
        //
        // Window size must be equal to p.length()
        // because an anagram of p must have the same length.
        for(int i = 0; i < p.length(); i++)
        {
            currentFreq[s[i] - 'a']++;
        }


        // Check whether the first window is an anagram of p.
        //
        // If both frequency arrays are equal,
        // the characters and their frequencies are the same.
        if(currentFreq == pFreq)
        {
            // First window starts at index 0.
            ans.push_back(0);
        }


        // i represents the LEFT side of the window.
        int i = 0;

        // j represents the next character that will
        // enter the window.
        //
        // Initially j is equal to p.length()
        // because the first window already contains
        // indices 0 to p.length() - 1.
        int j = p.length();


        // Continue sliding the window until j reaches
        // the end of string s.
        while(j < s.length())
        {

            // Add the new character entering the window.
            currentFreq[s[j] - 'a']++;


            // Remove the old character leaving the window.
            currentFreq[s[i] - 'a']--;


            // Move the left pointer forward.
            //
            // This keeps the window size equal to p.length().
            i++;


            // Now the window has exactly p.length()
            // characters again.
            //
            // If frequencies match, this window is
            // an anagram of p.
            if(currentFreq == pFreq)
            {
                // i is the starting index of the
                // current window.
                ans.push_back(i);
            }


            // Move the right pointer forward.
            //
            // j will represent the next character
            // entering the window.
            j++;
        }


        // Return all starting indices where
        // anagrams of p were found.
        return ans;
    }
};
