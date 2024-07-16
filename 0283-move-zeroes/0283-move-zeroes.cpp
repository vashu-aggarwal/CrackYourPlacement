class Solution {
public:
    void moveZeroes(vector<int>& arr) {
       int i = 0, j = 1;
        while (j < arr.size()) {
            if (arr[i] == 0 && arr[j] != 0) {
                swap(arr[i], arr[j]);
                i++;
                j++;
            } else if (arr[i] == 0 && arr[j] == 0) {
                j++;
            } else {
                i++;
                if (i == j) {
                    j++;
                }
            }
        }
    }
};