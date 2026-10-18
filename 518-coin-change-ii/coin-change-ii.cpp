class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<vector<unsigned long long>> count(len, vector<unsigned long long> (amount + 1, 0));
        // count[0][coins[0]] = 1; // leak: this one is not suffice!
        for (int i = 0; i < len; i++) { // leak: this base thought about later on, fixed on own
            count[i][0] = 1;
        }

        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= amount; j++) { // leak: j iterted from 0, overriding the base case, fixed on own
                if (i) {
                    count[i][j] += count[i - 1][j];
                }
                if (j >= coins[i]) {
                    count[i][j] += count[i][j - coins[i]];
                }
            }
        }

        return count[len - 1][amount];
    }
};

/*
class Solution {
    int recur(int level, int amountLeft, vector<vector<int>> &count, 
        int len, vector<int>& coins) {
        // prune
        if (amountLeft < 0) {
            return 0;
        }
        
        // base case
        if (level == -1) {
            return amountLeft == 0;
        }

        // memo
        if (count[level][amountLeft] != -1) {
            return count[level][amountLeft];
        }

        // ans
        int ans = 0;
        ans += recur(level - 1, amountLeft, count, len, coins);
        ans += recur(level, amountLeft - coins[level], count, len, coins);

        // return
        return count[level][amountLeft] = ans;
    }

public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<vector<int>> count(len, vector<int> (amount + 1, -1));
        return recur(len - 1, amount, count, len, coins);
    }
};
*/

/*
class Solution {
    int recur(int level, int amountLeft, vector<vector<int>> &count, 
        int len, vector<int>& coins) {
        // prune
        if (amountLeft < 0) {
            return 0;
        }
        
        // base case
        if (level == len) {
            return amountLeft == 0;
        }

        // memo
        if (count[level][amountLeft] != -1) {
            return count[level][amountLeft];
        }

        // ans
        int ans = 0;
        ans += recur(level + 1, amountLeft, count, len, coins);
        ans += recur(level, amountLeft - coins[level], count, len, coins);

        // return
        return count[level][amountLeft] = ans;
    }

public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<vector<int>> count(len, vector<int> (amount + 1, -1));
        return recur(0, amount, count, len, coins);
    }
};
*/