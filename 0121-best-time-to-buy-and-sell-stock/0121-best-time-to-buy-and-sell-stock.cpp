class Solution {
public:
 int maxProfit(vector<int>& arr) {
    if (arr.empty()) {
        return 0; // No profit can be made with an empty array.
    }

    int mini = arr[0]; // Initialize minimum to the first element.
    int maxProfit = 0;

    for (int i = 0; i < arr.size(); i++) {
            mini=min(mini,arr[i]);
            maxProfit = max(maxProfit, arr[i] - mini);
        }

    return maxProfit;
}
};