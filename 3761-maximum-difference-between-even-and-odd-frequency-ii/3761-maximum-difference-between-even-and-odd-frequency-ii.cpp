class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus = [](int cnt_a, int cnt_b) -> int {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };

        int n = s.size();
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) {
                    continue;
                }
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);
                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] =
                            min(best[left_status], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int right_status = getStatus(cnt_a, cnt_b);
                    if (best[right_status ^ 0b10] != INT_MAX) {
                        ans =
                            max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }
};


/*
class Solution {
public:
    int maxDifference(string s, int k) {
        vector<int>freq(5,0);
        int maxDiff=MIN_INT;
        for(int i=0;i<s.size()-k;i++){
            
            for(int j=i;j<=i+k;j++){
                freq[s[j]-'0']++;
            }
            int maxo=0;
            char odd='';
            char even='';
            int mine=INT_MAX;
            for(int j=0;j<5;j++){
                if(freq[j]!=0||freq[j]%2==0){
                    if(freq[j]<mine){
                        mine=freq[j];
                        even=i+'0';
                    }
                }
                else if(freq[j]!=0||freq[j]%2!=0){
                     if(freq[j]>maxo){
                        maxo=freq[j];
                        odd=i+'0';
                    }
                }
            }
            if(maxo!=0&&mine!=INT_MAX){
                maxDiff=max(maxo-mine,maxDiff);
            }
            char next='';
            int toadd=0;
            int tosub=0;
            for(int j=i+k+1;j<s.size();i++){
                next=s[j];
                if(s[j]==odd)toadd++;
                else if(s[j]==even)tosub--;
                
            }

        }
    }
};*/