
class StockSpanner {// TC ---> O(N)                             SC ---> O(N)
public:

    // Stack stores {price, span}
    //
    // price -> Stock price of that day.
    // span  -> Number of consecutive days (including that day)
    //          for which the stock price was less than or equal
    //          to this price.
    stack<pair<int,int>> st;

    StockSpanner() {

    }

    int next(int price) {

        // Today's span is at least 1
        // (today itself is always counted).
        int span = 1;

        // Remove all previous prices that are
        // less than or equal to today's price.
        //
        // Why?
        // They can never become the previous greater element
        // for today's price or for any future larger price.
        while(!st.empty() && st.top().first <= price)
        {
            // Instead of counting every previous day one by one,
            // directly add the span already calculated for
            // the popped price.
            span += st.top().second;

            // Remove the useless element.
            st.pop();
        }

        // Store today's price along with its span.
        // This span can be reused by future prices.
        st.push({price, span});

        // Return today's stock span.
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 *
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
