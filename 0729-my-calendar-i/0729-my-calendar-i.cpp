#include <vector>

class MyCalendar {
    vector<vector<int>> arr;
public:
    MyCalendar() {}

    bool book(int start, int end) {
        for (const auto& interval : arr) {
            int prevstart = interval[0];
            int prevend = interval[1];
            
            if (start < prevend && end > prevstart) {
                return false; 
            }
        }
        
        arr.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
