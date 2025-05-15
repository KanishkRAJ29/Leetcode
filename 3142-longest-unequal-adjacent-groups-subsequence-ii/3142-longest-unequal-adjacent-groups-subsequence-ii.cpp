class Solution {
public:
    vector<string> ans;
    int n;
    vector<string>* W;
    vector<int>* G;
    // memo[i][p] = best length from state (i, prev = p-1), or –1 if not yet computed
    vector<vector<int>> memo;
    int maxLen = 0;

    bool hamm(const string& a, const string& b) {
        int count = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != b[i] && ++count > 1) 
                return false;
        }
        return count == 1;
    }

    // returns the maximum additional length we can get starting at i with last taken = prev
    int dfs(int i, int prev) {
        if (i == n) return 0;
        int p = prev + 1;
        int& dp = memo[i][p];
        if (dp != -1) return dp;

        // Option 1: skip i
        int best = dfs(i + 1, prev);

        // Option 2: take i (if valid)
        bool canTake = (prev == -1)
          || ((*G)[prev] != (*G)[i]
              && (*W)[prev].size() == (*W)[i].size()
              && hamm((*W)[prev], (*W)[i]));
        if (canTake) {
            best = max(best, 1 + dfs(i + 1, i));
        }

        return dp = best;
    }

    // rebuild the actual sequence
    void build(int i, int prev, vector<string>& curr) {
        if (i == n) {
            if ((int)curr.size() > maxLen) {
                maxLen = curr.size();
                ans = curr;
            }
            return;
        }
        int p = prev + 1;
        int skipLen = dfs(i + 1, prev);

        bool canTake = (prev == -1)
          || ((*G)[prev] != (*G)[i]
              && (*W)[prev].size() == (*W)[i].size()
              && hamm((*W)[prev], (*W)[i]));
        int takeLen = canTake ? 1 + dfs(i + 1, i) : -1;

        // if taking gives strictly better (or equal, you can tie‐break as you like)
        if (takeLen >= skipLen && canTake) {
            curr.push_back((*W)[i]);
            build(i + 1, i, curr);
            curr.pop_back();
        } else {
            build(i + 1, prev, curr);
        }
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        W = &words;
        G = &groups;
        n = words.size();
        memo.assign(n + 1, vector<int>(n + 1, -1));
        // 1) fill memo with lengths
        dfs(0, -1);
        // 2) rebuild answer
        vector<string> curr;
        build(0, -1, curr);
        return ans;
    }
};
