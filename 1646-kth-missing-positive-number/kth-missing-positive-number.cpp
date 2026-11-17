class Solution {
    // arr = [2,3,4,7,11], k = 5
    //        1 2 3 4 5
    // delta: 1 1 1 3 6
    //        1 0 0 2 3
    //        1 0 0 3 6

public:
    int findKthPositive(vector<int>& arr, int k) {
        int len = arr.size();
        vector<int> processed(len);

        // convert to idx diff
        for (int i = 1; i <= len; i++) {
            processed[i - 1] = (arr[i - 1] - i);
        }

        for (auto val : processed) {
            cout << val << " ";
        }
        cout << endl;

        // convert to delta with previous
        int temp = processed[0];
        for (int i = 1; i < len; i++) {
            // processed[i] = processed[i] - processed[i - 1];
            int newTemp = processed[i];
            processed[i] = processed[i] - temp;
            temp = newTemp;
        }

        for (auto val : processed) {
            cout << val << " ";
        }
        cout << endl;

        // take prefix sum
        for (int i = 1; i < len; i++) {
            processed[i] += processed[i - 1];
        }

        for (auto val : processed) {
            cout << val << " ";
        }
        cout << endl;

        auto idx = lower_bound(processed.begin(), processed.end(), k) - processed.begin();
        int element = 0;
        int processedVal = 0;
        if (idx != 0) {
            idx--;
            element = arr[idx];
            processedVal = processed[idx];
            cout << element << " " << processedVal << endl;
        }
        int result = element + (k - processedVal);

        return result;
    }
};