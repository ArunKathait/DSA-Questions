***********************************************APPROACH 1st***********************************************************
    
class MyCalendar {// TC--->O(NlogN)                        SC--->O(N)
public:
    // Use a set to store the intervals of booked events. Each interval is stored as a pair (start, end).
    // The set keeps the pairs sorted based on the first value (start time) of the pair.
    set<pair<int,int>>set;
    
    // Constructor to initialize the MyCalendar object
    MyCalendar() {
        // No specific initialization is needed, as the set is empty by default.
    }
    
    // Function to book an event in the calendar.
    // The event is represented by its start and end time, and the function returns true if the event can be booked
    // without overlapping with any previously booked events; otherwise, it returns false.
    bool book(int start, int end) {
        
        // Find the first event in the set where the start time is >= the given start time using lower_bound.
        // This gives us the next event that might conflict with the current event.
        auto it = set.lower_bound({start,end});
        
        // Check if the found event starts before the end time of the current event.
        // This would mean there's an overlap, so we cannot book this event.
        if(it != set.end() && it->first < end)
        {
            // Return false if there is an overlap with the next event.
            return false;
        }
        
        // Check the previous event (if there is one) to see if it ends after the start time of the current event.
        // This would mean there's an overlap with the previous event.
        if(it != set.begin())
        {
            // Get the previous event.
            auto prevIt = prev(it);
            if(prevIt->second > start)
            {
                // Return false if there's an overlap with the previous event.
                return false;
            }
        }
        
        // If no overlap was found, insert the new event (start, end) into the set.
        set.insert({start,end});
        
        // Successfully booked the event, so return true.
        return true;
    }
};

/*

   NOTE:  In an interval problem, where you're trying to check whether two intervals overlap, the 
          condition a < e && s < b can be interpreted as follows:
          
           Let's assume:
                        * Interval 1: [a, b) (i.e., starts at a and ends before b)
                        * Interval 2: [s, e) (i.e., starts at s and ends before e)
          Interpretation:
                        The condition a < e && s < b ensures that:

                        * The end of Interval 2 (e) is after the start of Interval 1 (a).
                        * The end of Interval 1 (b) is after the start of Interval 2 (s).
                        
           In simpler terms, this condition checks that:

                        * Interval 1 and Interval 2 are not completely disjoint.
                        * It rules out cases where one interval completely occurs before or after the other.

Conclusion:
           * The condition a < e && s < b checks whether two intervals overlap by ensuring neither interval is completely 
             before or after the other. If both parts of the condition hold, the intervals overlap; if either part fails,
             they do not overlap.

    */


***************************************************APPROACH 2nd(OPTIMISED APPROACH)**************************************

class MyCalendar {// TC--->O(N)                         SC--->O(N)
public:
    // Vector to store all bookings, where each booking is represented as a pair (start, end).
    // Each pair contains the start time and end time of an event.
    vector<pair<int,int>>bookings;
    
    // Constructor (doesn't need to initialize anything specific in this case).
    MyCalendar() {
        // The bookings vector will be empty when a new MyCalendar object is created.
    }
    
    // Function to book a new event in the calendar.
    // Takes two integers as input: 'start' (start time) and 'end' (end time) of the event.
    bool book(int start, int end) {
        
        // Iterate over all existing bookings to check for overlaps.
        for(auto &x:bookings)
        {
            // The condition max(x.first, start) < min(x.second, end) checks for overlap:
            // x.first is the start time of the existing booking.
            // x.second is the end time of the existing booking.
            // If the maximum of the two start times is less than the minimum of the two end times,
            // it means the time intervals overlap.

            // For example:
            // Event A: [5, 10], Event B: [7, 12]
            // max(5, 7) < min(10, 12) --> 7 < 10 --> overlap exists, so return false.
            if(max(x.first,start) < min(x.second,end))
            {
                // If there is an overlap with any existing booking, return false.
                return false;
            }
        }
        
        // If no overlap is found with any existing booking, add the new booking.
        // push_back() appends the new booking (start, end) to the bookings vector.
        bookings.push_back({start,end});
        
        // Since the booking was successfully added, return true.
        return true;
    }
};

/*
    NOTE:
The condition max(x.first, start) < min(x.second, end) is checking if two time intervals overlap. 
Here's a simple explanation:

* x.first: This is the start time of an existing booking.
* x.second: This is the end time of the existing booking.
* start: This is the start time of the new booking you want to add.
* end: This is the end time of the new booking.

What does the condition mean?
* max(x.first, start): This gives the later of the two start times (either the start time of the existing booking or the 
start time of the new booking). It asks, "Which event starts later?"

* min(x.second, end): This gives the earlier of the two end times (either the end time of the existing booking or the end 
time of the new booking). It asks, "Which event ends sooner?"

Overlap Condition:
* If the later start time is before the earlier end time, then the two bookings overlap.
* The condition max(x.first, start) < min(x.second, end) checks this exact situation.

Example:
(1) Existing booking: [10, 20]
(2) New booking: [15, 25]

* The later start time is max(10, 15) = 15.
* The earlier end time is min(20, 25) = 20.

Since 15 < 20, the two intervals overlap.

If the condition is true (max(x.first, start) < min(x.second, end)), it means the new booking overlaps with the existing 
one, and you should reject the new booking (return false).

*/
