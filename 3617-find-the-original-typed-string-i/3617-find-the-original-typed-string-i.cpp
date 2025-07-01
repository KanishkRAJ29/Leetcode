class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        int count=0;
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1]){
                count++;
            }
        }
        return ans+count;
    }
};