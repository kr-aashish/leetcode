class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        priority_queue<pair<int, int>> maxFreq;
        for (auto character : s) {
            freq[character - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                maxFreq.push({freq[i], i});
            }
        }

        string reorganizeString = "";
        while (!maxFreq.empty()) {
            auto topFreqPair = maxFreq.top();
            maxFreq.pop();

            int topChar = topFreqPair.second;

            if (!reorganizeString.empty() and 
                (reorganizeString.back() - 'a') == topChar) {
                if (maxFreq.empty()) {
                    break;
                }
                auto secondTopCharPair = maxFreq.top();
                maxFreq.pop();

                int secondTopChar = secondTopCharPair.second;
                reorganizeString += (secondTopChar + 'a');

                int freq = secondTopCharPair.first;
                freq--;
                if (freq) {
                    maxFreq.push({freq, secondTopChar});
                }
                maxFreq.push(topFreqPair);
            } else {
                reorganizeString += (topChar + 'a');

                int freq = topFreqPair.first;
                freq--;
                if (freq) {
                    maxFreq.push({freq, topChar});
                }
            }
        }

        return reorganizeString.size() == s.size() ? reorganizeString : "";
    }
};