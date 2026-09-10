class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (auto str : strs) {
            auto strCopy = str;
            sort(strCopy.begin(), strCopy.end());
            anagrams[strCopy].push_back(str);
        }
        vector<vector<string>> results;
        for (auto item : anagrams) {
            results.push_back(item.second);
        }
        return results;
    }
};