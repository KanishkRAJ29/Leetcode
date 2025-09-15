class Solution {
    vector<string> getAllWords(const string& text) {
        vector<string> words;
        string word;

        for(const char& ch : text) {
            if(isspace(ch)) {
                words.push_back(word);
                word = "";
            }
            else {
                word += ch;
            }
        }
        words.push_back(word); // Add last word
        
        return words;
    }

    vector<string> getAllWordsByTokenization(const string& text) {
        stringstream ss(text);
        vector<string> words;
        string word;
        while(ss >> word) words.push_back(word); // Extract words
        return words;
    }

    bool canType(const string& word, const vector<bool>& isPresent) {
        for(const char& ch : word)
            if(isPresent[ch - 'a'])
                return false;

        return true;
    }

public:
    // O(N+M+K) & O(N+M) : Where N = total words in "text", M = text.size, K = brokenLetters.size
    int canBeTypedWords(const string& text, const string& brokenLetters) {
        vector<string> words = getAllWords(text);
        
        vector<bool> isPresent(26);
        for(const char& ch : brokenLetters) {
            isPresent[ch - 'a'] = true;
        }

        int res = 0;
        for(const auto& word : words) {
            if(canType(word, isPresent)) {
                res++;
            }
        }
        return res;
    }
};