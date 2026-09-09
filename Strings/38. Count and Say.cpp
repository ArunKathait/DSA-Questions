***********************************************APPROACH 1st(RECURSIVE)************************************************

class Solution {// Time: O(L₁ + L₂ + ... + Lₙ)                       Space: O(L + n)
public:
    string countAndSay(int n) {

        // Base case:
        // The first term of Count and Say is always "1".
        if(n == 1)
        {
            return "1";
        }

        // Recursively generate the previous term.
        //
        // Example:
        // countAndSay(5)
        //     ↓
        // countAndSay(4) → "1211"
        string say = countAndSay(n - 1);

        // This will store the current term
        // generated from 'say'.
        string ans;

        // Traverse the previous term from left to right.
        for(int i = 0; i < say.length(); i++)
        {
            // Store the current character.
            char ch = say[i];

            // We already have one occurrence of ch.
            int count = 1;

            // Count consecutive occurrences of the same character.
            //
            // Example:
            // say = "111221"
            //       ↑
            //       ch = '1'
            //
            // We keep moving while the next character
            // is also '1'.
            while(i < say.length() - 1 && ch == say[i + 1])
            {
                count++;
                i++;
            }

            // Add:
            // count + character
            //
            // Example:
            // count = 3
            // ch = '1'
            //
            // Add "31" to the answer.
            ans += to_string(count) + string(1, ch);
        }

        // Return the newly generated term.
        return ans;
    }
};

/*

╔══════════════════════════════════════════════════════╗
║             🔢 COUNT AND SAY — RECURSIVE             ║
╠══════════════════════════════════════════════════════╣
║                                                      ║
║ 🎯 CORE IDEA                                         ║
║                                                      ║
║ To generate term n:                                  ║
║                                                      ║
║        countAndSay(n)                                ║
║              ↓                                       ║
║        countAndSay(n-1)                              ║
║              ↓                                       ║
║        Get previous string                           ║
║              ↓                                       ║
║        Count consecutive digits                      ║
║              ↓                                       ║
║        Append count + digit                          ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║ 🛑 BASE CASE                                         ║
║                                                      ║
║ if(n == 1)                                           ║
║     return "1";                                      ║
║                                                      ║
║ First term is always "1".                            ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║ 🔄 RECURSION                                         ║
║                                                      ║
║ string say = countAndSay(n - 1);                     ║
║                                                      ║
║ This gives us the PREVIOUS term.                     ║
║                                                      ║
║ Example:                                             ║
║ countAndSay(5)                                       ║
║       ↓                                              ║
║ countAndSay(4) → "1211"                              ║
║       ↓                                              ║
║ Generate "111221"                                    ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║ 🧠 COUNT CONSECUTIVE CHARACTERS                      ║
║                                                      ║
║ char ch = say[i];                                    ║
║ int count = 1;                                       ║
║                                                      ║
║ while(i < say.length()-1 &&                          ║
║       ch == say[i+1])                                ║
║ {                                                    ║
║     count++;                                         ║
║     i++;                                             ║
║ }                                                    ║
║                                                      ║
║ Count ONLY consecutive characters.                   ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║ ⭐ KEY LINE                                          ║
║                                                      ║
║ ans += to_string(count) + string(1, ch);             ║
║                                                      ║
║ Example:                                             ║
║                                                      ║
║ count = 3                                            ║
║ ch = '1'                                             ║
║                                                      ║
║ → "3" + "1" = "31"                                  ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║ 📌 EXAMPLE                                           ║
║                                                      ║
║ 1                                                    ║
║ ↓                                                    ║
║ 11      → one 1                                      ║
║ ↓                                                    ║
║ 21      → two 1s                                     ║
║ ↓                                                    ║
║ 1211    → one 2, one 1                               ║
║ ↓                                                    ║
║ 111221  → one 1, one 2, two 1s                       ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║ ⏱️ COMPLEXITY                                       ║
║                                                      ║
║ Time:  O(L₁ + L₂ + ... + Lₙ)                         ║
║                                                      ║
║ Space: O(L + n)                                      ║
║                                                      ║
║ L → generated string length                          ║
║ n → recursion stack                                  ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║ 🎯 INTERVIEW PATTERN                                 ║
║                                                      ║
║ RECURSION                                            ║
║     +                                                ║
║ STRING SIMULATION                                    ║
║     +                                                ║
║ CONSECUTIVE GROUP COUNTING                           ║
║                                                      ║
╠══════════════════════════════════════════════════════╣
║ 🧩 REMEMBER                                          ║
║                                                      ║
║ Previous term                                        ║
║       ↓                                              ║
║ Read left → right                                    ║
║       ↓                                              ║
║ Count consecutive same characters                    ║
║       ↓                                              ║
║ count + character                                    ║
║       ↓                                              ║
║ Next term                                            ║
║                                                      ║
╚══════════════════════════════════════════════════════╝

*/

*********************************************APPROACH 2nd(OPTIMAL-->ITERATIVE)****************************************

class Solution {// Time: O(L₁ + L₂ + ... + Lₙ)                   Space: O(L)
public:
    string countAndSay(int n) {

        // The first term of the sequence is always "1".
        string ans = "1";

        // We need to generate terms from 2 up to n.
        for(int i = 2; i <= n; i++)
        {
            // This will store the next term.
            string next = "";

            // Start reading the current string from left to right.
            int j = 0;

            while(j < ans.size())
            {
                // Store the current digit.
                char ch = ans[j];

                // Count how many times this digit occurs
                // consecutively.
                int count = 0;

                // Keep moving while the same digit continues.
                while(j < ans.size() && ans[j] == ch)
                {
                    count++;
                    j++;
                }

                // First write the count.
                // Example: three 1s → "3"
                next += to_string(count);

                // Then write the digit.
                // Example: three 1s → "31"
                next += ch;
            }

            // The newly generated string becomes
            // the current term for the next iteration.
            ans = next;
        }

        // Return the nth term.
        return ans;
    }
};

/*

╔══════════════════════════════════════════════════════════╗
║                 🔥 COUNT AND SAY — CHEAT BOX             ║
╠══════════════════════════════════════════════════════════╣
║                                                          ║
║ 🎯 CORE IDEA                                             ║
║                                                          ║
║ Each term DESCRIBES the previous term.                   ║
║                                                          ║
║ 1 → "one 1"                  → 11                        ║
║ 11 → "two 1s"                → 21                        ║
║ 21 → "one 2, one 1"          → 1211                      ║
║ 1211 → "one 1, one 2, two 1s" → 111221                   ║
║                                                          ║
║ Scan the previous string and count CONSECUTIVE           ║
║ identical digits.                                        ║
║                                                          ║
╠══════════════════════════════════════════════════════════╣
║ 🧠 PATTERN                                               ║
║                                                          ║
║ String Simulation + Consecutive Group Counting           ║
║                                                          ║
║ For every group:                                         ║
║                                                          ║
║              COUNT → DIGIT                               ║
║                                                          ║
║ Example: "111" → "31"                                    ║
║          "22"  → "22"                                    ║
║                                                          ║
╠══════════════════════════════════════════════════════════╣
║ ⭐ MOST IMPORTANT PART                                   ║
║                                                          ║
║ Count CONSECUTIVE digits, NOT total frequency.           ║
║                                                          ║
║ "1211"                                                   ║
║                                                          ║
║ 1  → one 1                                               ║
║ 2  → one 2                                               ║
║ 11 → two 1s                                              ║
║                                                          ║
║ Therefore: "111221"                                      ║
╠══════════════════════════════════════════════════════════╣
║ 🔑 KEY CODE                                              ║
║                                                          ║
║ while(j < ans.size())                                    ║
║ {                                                        ║
║     char ch = ans[j];                                    ║
║     int count = 0;                                       ║
║                                                          ║
║     while(j < ans.size() && ans[j] == ch)                ║
║     {                                                    ║
║         count++;                                         ║
║         j++;                                             ║
║     }                                                    ║
║                                                          ║
║     next += to_string(count);                            ║
║     next += ch;                                          ║
║ }                                                        ║
║                                                          ║
╠══════════════════════════════════════════════════════════╣
║ 🔄 DRY RUN                                               ║
║                                                          ║
║ ans = "1211"                                             ║
║                                                          ║
║ j=0 → '1' → count=1 → append "11"                        ║
║ j=1 → '2' → count=1 → append "12"                        ║
║ j=2 → '1' → count=2 → append "21"                        ║
║                                                          ║
║ Final: next = "111221"                                   ║
║                                                          ║
╠══════════════════════════════════════════════════════════╣
║ ⏱️ COMPLEXITY                                            ║
║                                                          ║
║ Time:  O(L₁ + L₂ + ... + Lₙ)                             ║
║ Space: O(L)                                              ║
║                                                          ║
║ Each previous term is scanned once.                      ║
║                                                          ║
╠══════════════════════════════════════════════════════════╣
║ 🎤 INTERVIEW ONE-LINER                                   ║
║                                                          ║
║ "I generate each term by grouping consecutive identical  ║
║ digits and appending their count followed by the digit." ║
║                                                          ║
╠══════════════════════════════════════════════════════════╣
║ 🧠 REMEMBER                                              ║
║                                                          ║
║       PREVIOUS STRING                                    ║
║              ↓                                           ║
║     GROUP CONSECUTIVE DIGITS                             ║
║              ↓                                           ║
║        COUNT + DIGIT                                     ║
║              ↓                                           ║
║          NEXT TERM                                       ║
║                                                          ║
║             🔥 COUNT → DIGIT 🔥                         ║
╚══════════════════════════════════════════════════════════╝

*/
