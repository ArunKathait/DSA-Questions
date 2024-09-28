
class MyCalendarTwo {// TC--->O(N)                    SC--->O(N)
public:
    // Vector to store intervals where double bookings happen
    vector<pair<int,int>>DoubleOverlappedRegion;
    
    // Vector to store all booked intervals
    vector<pair<int,int>>overallBookings;
    
    // Constructor to initialize the class (no specific initialization needed)
    MyCalendarTwo() {
        
    }
    
    // Function to check if two intervals overlap
    // start1, end1 -> represents the first interval
    // start2, end2 -> represents the second interval
    bool checkOverlap(int start1,int end1,int start2,int end2)
    {
        // If the maximum start time is less than the minimum end time, they overlap
        return max(start1,start2) < min(end1,end2);
    }
    
    // Function to find the overlapped region between two intervals
    // It returns the interval where both given intervals overlap
    pair<int,int> findOverlappedRegion(int start1,int end1,int start2,int end2)
    {
        // The overlap starts from the maximum of the start times and ends at the minimum of the end times
        return {max(start1,start2),min(end1,end2)};
    }
    
    // The main function to book a new interval [start, end)
    bool book(int start, int end) {
        // First, we check if the new booking would result in a triple overlap
        for(auto &region:DoubleOverlappedRegion)
        {
           
            // If the new booking overlaps with any double-overlapped region, it results in a triple booking 
            if(checkOverlap(region.first,region.second,start,end))
            {
                // Triple booking is not allowed, return false
                return false;
            }
        }
        
        // Next, check for overlaps with existing bookings and update the double-overlapped regions
        for(auto &booking:overallBookings)
        {
            // If the new booking overlaps with any existing booking      
            if(checkOverlap(booking.first,booking.second,start,end))
            {
              // Add the overlapped region to DoubleOverlappedRegion 
              DoubleOverlappedRegion.push_back(findOverlappedRegion(booking.first,booking.second,start,end));
            }
        }
        
        // After checking for triple overlaps, add the new booking to the list of overall bookings
        overallBookings.push_back({start,end});
        
        
        // The booking is successful
        return true;
    }
};

/* NOTE:

(1) checkOverlap() function:
This function is used to check whether two time intervals overlap.

Parameters:

* start1, end1: The start and end times of the first interval.
* start2, end2: The start and end times of the second interval.

  Logic:

*  max(start1, start2): This finds the later start time between the two intervals. This is the time at which both intervals
   have already started.
*  min(end1, end2): This finds the earlier end time between the two intervals. This is the time at which one of the 
   intervals ends.

  Condition:

  * If the later start time is before the earlier end time (i.e., max(start1, start2) < min(end1, end2)), it means the 
    intervals overlap.
  * If this condition is not true, then the intervals do not overlap.

    In simple terms: This function checks if the time when both intervals have already started is before the time when 
    one of the intervals has already ended. If yes, the two intervals overlap.

  (2) findOverlappedRegion() function:
       This function finds the exact overlapping part between two intervals.

  Parameters:
  * start1, end1: The start and end times of the first interval.
  * start2, end2: The start and end times of the second interval.

  Logic:
  * max(start1, start2): This gives the starting point of the overlapping region, which is the later of the 
    two start times.

  * min(end1, end2): This gives the ending point of the overlapping region, which is the earlier 
    of the two end times.

  In simple terms: This function finds the overlapping part by looking for where the overlap starts (the later start time) 
  and where it ends (the earlier end time). It returns this overlapping region as a pair of values.

Example to Understand Both Functions:

* Interval 1: [10, 20] (from time 10 to time 20)
* Interval 2: [15, 25] (from time 15 to time 25)

* checkOverlap(10, 20, 15, 25):
  * Later start: max(10, 15) = 15
  * Earlier end: min(20, 25) = 20
  * Since 15 < 20, these two intervals do overlap.

* findOverlappedRegion(10, 20, 15, 25):
  * The overlapping region starts at 15 (the later start) and ends at 20 (the earlier end).
  * So, the overlapping region is [15, 20].

  In summary, these functions help detect and identify overlapping time intervals.
  
  */
