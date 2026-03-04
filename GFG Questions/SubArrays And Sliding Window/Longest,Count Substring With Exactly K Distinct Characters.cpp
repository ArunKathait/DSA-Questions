
1️⃣ Longest Substring With Exactly K Distinct Characters
Problem

You are given a string s consisting of lowercase alphabets and an integer k.

Find the length of the longest substring that contains exactly k distinct characters.

If no such substring exists, return -1.

Example

Input:
s = "aabacbebebe"
k = 3

Output:
7

Explanation:
Longest substring with exactly 3 distinct characters = "cbebebe"
Length = 7

Approach (Sliding Window)

1. Use two pointers i and j.

2. Expand window using j.

3. Maintain frequency using a hashmap.

4. If distinct characters become greater than k, shrink window.

5. Update answer only when distinct characters == k.

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int i = 0, j = 0;
        int ans = -1;

        unordered_map<char,int> mp;

        while(j < s.length())
        {
            mp[s[j]]++;

            while(mp.size() > k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            if(mp.size() == k)
                ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};

Time Complexity : O(N)
Space Complexity : O(K)


2️⃣ Count Substrings With Exactly K Distinct Characters

Problem

Given a string s and an integer k, return the number of substrings that contain exactly k distinct characters.

Example

Input:
s = "pqpqs"
k = 2

Output:
7

Valid substrings:

pq
pqp
pqpq
qp
qpq
pq
qs

Key Trick

Instead of directly counting exactly k, we compute:

exactly(k) = atMost(k) - atMost(k-1)

This trick only works for counting substrings, not for longest length.

Step 1: Count Substrings With At Most K Distinct
Idea

If a window is valid (≤ k distinct), then all substrings ending at j are valid.

Count added:

j - i + 1

class Solution {
public:

    int countAtMostK(string s, int k)
    {
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<char,int> mp;

        while(j < s.length())
        {
            mp[s[j]]++;

            while(mp.size() > k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            ans += (j - i + 1);
            j++;
        }

        return ans;
    }

    int substrCount(string s, int k)
    {
        return countAtMostK(s,k) - countAtMostK(s,k-1);
    }
};

*******************************************************************************************************************************************
⚠️ Important Points to Remember
1️⃣ Two different sliding window patterns

Pattern A — Longest Window

ans = max(ans, j-i+1)

Used in:

Longest substring without repeating characters

Longest substring with k distinct characters

Max consecutive ones

Pattern B — Counting Substrings

ans += (j-i+1)

Used in:

Count substrings with at most K distinct

Count binary subarrays with sum ≤ k

Count nice subarrays

2️⃣ The formula trick
exactly(k) = atMost(k) - atMost(k-1)

Works only for count problems.

3️⃣ When to shrink window

Always shrink when:

condition becomes invalid

Example:

mp.size() > k

4️⃣ Always initialize correctly

For longest substring problems:

ans = -1

Because maybe no valid substring exists.

⭐ Interview Tip

Most substring sliding window problems fall into 3 templates:

1️⃣ Longest window

ans = max(ans, window_length)

2️⃣ Count windows

ans += window_length

3️⃣ Exactly K trick

exactlyK = atMostK - atMost(K-1)
