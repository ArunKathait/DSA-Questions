🔥 Pattern Recognition Cheat Sheet

┌─────────────────────────────────────────────────┐
│              ARRAY PATTERNS                     │
├─────────────────────────────────────────────────┤
│                                                 │
│ Fixed-size window                               │
│ → Sliding Window                                │
│                                                 │
│ "Longest substring with at most K..."           │
│ → Sliding Window                                │
│                                                 │
│ "Minimum window satisfying condition..."        │
│ → Sliding Window                                │
│                                                 │
│ Positive / non-negative + sum condition         │
│ → Sliding Window                                │
│                                                 │
│ "Subarray sum exactly K"                        │
│ → Prefix Sum + HashMap                          │
│                                                 │
│ Negative numbers + sum exactly K                │
│ → Prefix Sum + HashMap                          │
│                                                 │
│ "Count subarrays with sum K"                    │
│ → Prefix Sum + HashMap                          │
│                                                 │
│ "Longest subarray with sum K"                   │
│ → Prefix Sum + HashMap                          │
│                                                 │
└─────────────────────────────────────────────────┘
🧠 Interview shortcut

When you see a subarray sum question, ask these 3 questions:

1. Are negative numbers possible?
        ↓
      YES
        ↓
   Prefix Sum + Map


2. If numbers are positive/non-negative:
        ↓
   Can I maintain a window
   based on sum/condition?
        ↓
      YES
        ↓
   Sliding Window


3. Does the question say:
   "exactly sum K"
   "count subarrays"
   "longest subarray"
        ↓
Strong hint → Prefix Sum + HashMap


The simplest rule to memorize
Positive numbers + condition can be maintained by shrinking
→ Sliding Window

Negative numbers + exact subarray sum
→ Prefix Sum + HashMap
