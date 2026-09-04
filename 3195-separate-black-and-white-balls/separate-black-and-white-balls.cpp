class Solution {
public:
    long long minimumSteps(string s) {
        int len = s.length();

        long long swaps = 0;
        long long zeros = 0;
        for (int i = len - 1; i >= 0; i--) {
            zeros += (s[i] == '0');
            if (s[i] == '1') {
                swaps += zeros;
            }
        }

        return swaps;
    }
};