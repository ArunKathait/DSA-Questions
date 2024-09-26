
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

