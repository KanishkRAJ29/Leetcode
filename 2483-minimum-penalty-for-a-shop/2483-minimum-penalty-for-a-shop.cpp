class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int>ybeforei(customers.size()+1);
        int y=0;
        for(int i=0;i<customers.size()+1;i++){
            ybeforei[i]=y;
            if(i<customers.size()&&customers[i]=='Y')y++;
        }
        y=0;
        vector<int>yafteroni(customers.size()+1);

        for(int i=customers.size();i>=0;i--){
            if(i<customers.size()&&customers[i]=='Y')y++;
            yafteroni[i]=y;
        }
        int ans=INT_MAX;
        int pan=INT_MAX;
        
        for(int i=0;i<customers.size()+1;i++){
            int lengthonleft=i;
            int case1=i-ybeforei[i];
            int case2=yafteroni[i];
            int currPan=case1+case2;
            if(currPan<pan){
                pan=currPan;
                ans=i;
            }
        }
        return ans;
    }
};