class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& a) {
        int n=a.size();
         
        sort(a.begin(), a.end(), [](auto &x, auto &y){
            if (x[1] == y[1]) return x[0] > y[0];
            return x[1] < y[1];
        });

        vector<vector<int>> intervals;

        for (auto &p : a) {
            intervals.push_back({p[0], p[1]});
        }
        int ans=2;
        
        int ed=intervals[0][1];
        int st=ed-1;
        for(int i=1;i<n;i++){
            if(st>=intervals[i][0] && ed<=intervals[i][1]) continue;

            else if(ed>=intervals[i][0]){
                st=ed;
                ed=intervals[i][1];
                ans++;
            }

            else if(ed>=intervals[i][1]){
                st=ed-1;
                ans++;
            }

            else{
                ed=intervals[i][1];
                st=ed-1;
                ans+=2;
            }
        }
        return ans;
    }
};

