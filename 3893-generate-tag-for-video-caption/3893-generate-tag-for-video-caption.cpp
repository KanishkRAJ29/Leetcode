class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        bool isFirstChar = true;
        bool newWord = true;

        for (int i = 0; i < caption.size(); i++) {
            if (ans.length() == 100) break;

            // Skip non-letters
            if (!isalpha(caption[i])) {
                newWord = true;
                continue;
            }

            char ch = caption[i];
            if (isFirstChar) {
                ans += tolower(ch);
                isFirstChar = false;
                newWord = false;
            } else {
                if (newWord) {
                    ans += toupper(ch);
                    newWord = false;
                } else {
                    ans += tolower(ch);
                }
            }
        }

        return ans;
    }
};
