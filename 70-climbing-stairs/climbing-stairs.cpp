class Solution {
    // 0
    // dp(level) = dp(level - 1) + dp(level - 2);
    // dp[0] = 0, dp[1] = 1

public:
    int climbStairs(int n) {
        vector<int> numberOfWays(2, 0);
        numberOfWays[0] = 1;
        numberOfWays[1] = 1;

        for (int i = 2; i <= n; i++) {
            numberOfWays[i & 1] = numberOfWays[(i - 1) & 1] + numberOfWays[(i - 2) & 1];
        }

        return numberOfWays[n & 1];
    }
};