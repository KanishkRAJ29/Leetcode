class Solution {
public:
    bool ispalindrome(string sub) {
        int i = 0, j = sub.size() - 1;
        while (i <= j) {
            if (sub[i] != sub[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void recursive(int index, vector<string>& temp, vector<vector<string>>& ans, string& s) {
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string sub = s.substr(index, i - index + 1);  // correct substring
            if (ispalindrome(sub)) {
                temp.push_back(sub);
                recursive(i + 1, temp, ans, s);
                temp.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recursive(0, temp, ans, s);
        return ans;
    }
};