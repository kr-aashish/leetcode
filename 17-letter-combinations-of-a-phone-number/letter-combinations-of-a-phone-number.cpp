const string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
    void buildAllCombinations(int level, string &digits, string &currStr, 
        vector<string> &result) {
        // base
        if (level == digits.size()) {
            result.push_back(currStr);
            return;
        }
        // push
        int currentDigit = digits[level] - '0';
        for (int i = 0; i < keypad[currentDigit].size(); i++) {
            currStr.push_back(keypad[currentDigit][i]);
            buildAllCombinations(level + 1, digits, currStr, result);
            currStr.pop_back();
        }
        // next
        // pop
    }

public:
    vector<string> letterCombinations(string digits) {
        string currStr = "";
        vector<string> result;
        buildAllCombinations(0, digits, currStr, result);
        return result;
    }
};