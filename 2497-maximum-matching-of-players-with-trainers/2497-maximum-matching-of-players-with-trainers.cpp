class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
    if(p.size()==0||t.size()==0)return 0;
    if(p.size()==1||t.size()==1){
        if(p[0]<=t[0])return 1;
        else return 0;}
     int ans=0;
     sort(p.begin(),p.end());
     sort(t.begin(),t.end());
    if(p==t)return p.size();
     for(int i=0;i<p.size();i++){
        int x=p[i];
        int y=-1;
        int j;
        int low=0;
        int high=t.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(t[mid]>=x){
                high=mid-1;
                y=t[mid];
                j=mid;
            }else low=mid+1;
        }
        if(y>=x){
            ans++;
            t.erase(t.begin()+j);
        }
        
     }   
     return ans;
    }
};