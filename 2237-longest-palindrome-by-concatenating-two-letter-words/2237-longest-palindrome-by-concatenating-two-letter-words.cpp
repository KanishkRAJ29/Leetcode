class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>freq;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            freq[s]++;
        }
        int odd=0;
        int ans=0;
        for(auto&[key,value]: freq){
            string s=key;
            int f1=value;
            if(f1==0)continue;
            if(s[0]==s[1]){
               if(f1%2==1){
                if(f1>1){
                    ans+=2*(f1-1);
                }
                if(odd==0){
                    odd=1;
                    ans+=2;
                    continue;
                }
                continue;
            }else{
                ans+=2*f1;
            } 
            }else{
                string r = "";
                r += s[1];
                r += s[0];
                if(freq.count(r)){
                    ans+=min(freq[r],freq[s]);
                    ans+=min(freq[r],freq[s]);
                    ans+=min(freq[r],freq[s]);
                    ans+=min(freq[r],freq[s]);
                    freq[r]=0;
                    continue;
                }
            }
            
        }
        return ans;
    }
};