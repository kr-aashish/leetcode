class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int lo = 0;
        int hi = int(arr.size()) - 1;

        int idx = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            // 000011111
            if (arr[mid] - mid >= 0) {
                idx = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if (idx != -1 and arr[idx] != idx) {
            idx = -1;
        }

        return idx;
    }
};