
class MedianFinder {
public:

    // Max Heap
    // Stores the smaller half of the numbers.
    // The largest element of the smaller half is always at the top.
    priority_queue<int> small;

    // Min Heap
    // Stores the larger half of the numbers.
    // The smallest element of the larger half is always at the top.
    priority_queue<int, vector<int>, greater<int>> large;

    // Constructor
    MedianFinder() {

    }

    // TC ---> O(log n)
    void addNum(int num) {

        // If small heap is empty OR
        // the new number belongs to the smaller half,
        // insert it into the max heap.
        if (small.empty() || num <= small.top())
        {
            small.push(num);
        }
        else
        {
            // Otherwise insert into the larger half.
            large.push(num);
        }

        // ---------------- Balance the Heaps ----------------

        // If the max heap has more than one extra element,
        // move its largest element to the min heap.
        if (small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }

        // If the min heap has more elements,
        // move its smallest element to the max heap.
        else if (small.size() < large.size())
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    // TC ---> O(1)
    double findMedian() {

        // If both heaps have the same number of elements,
        // the median is the average of the two middle elements.
        if (small.size() == large.size())
        {
            return (small.top() + large.top()) / 2.0;
        }

        // Otherwise, the max heap always has one extra element.
        // Its top is the median.
        else
        {
            return small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 *
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double ans = obj->findMedian();
 */
