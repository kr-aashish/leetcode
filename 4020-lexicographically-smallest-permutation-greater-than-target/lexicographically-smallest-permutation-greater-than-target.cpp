class Solution {
    string minString(vector<int> freq) {
        string minString = "";
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                minString += (i + 'a');
                freq[i]--;
            }
        }
        return minString;
    }

public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (auto character : s) {
            freq[character - 'a']++;
        }
        for (auto character : target) {
            freq[character - 'a']--;
        }

        int len = s.length();
        for (int i = len - 1; i >= 0; i--) {
            freq[target[i] - 'a']++;

            if (*min_element(freq.begin(), freq.end()) < 0) {
                continue;
            }

            int currentChar = target[i] - 'a';
            // BUG: SAME i
            // for (int i = currentChar + 1; i < 26; i++) {
            //     if (freq[i]) {
            //         freq[i]--;
            //         target[i] = 'a' + i;
            //         return target.substr(0, i + 1) + minString(freq);
            //     }
            // }
            for (int j = currentChar + 1; j < 26; j++) {
                if (freq[j]) {
                    freq[j]--;
                    target[i] = 'a' + j;
                    return target.substr(0, i + 1) + minString(freq);
                }
            }
        }
        return "";
    }
};