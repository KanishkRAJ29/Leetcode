class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int omax=0;
        int emin=INT_MAX;
        for(int i=0;i<26;i++){
            if((freq[i]%2==0)&&(freq[i]!=0)){
                emin=min(emin,freq[i]);
            }else {
               omax=max(omax,freq[i]); 
            }
        }
        return omax-emin;
    }
};