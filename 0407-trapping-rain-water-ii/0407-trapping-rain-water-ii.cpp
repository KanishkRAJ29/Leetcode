class Solution {
public:
    typedef pair<int,pair<int,int>>PP;
    vector<vector<int>>direction={{0,1},{1,0},{0,-1},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        priority_queue<PP,vector<PP>,greater<>>boundaryCells;
        for(int i=0;i<m;i++){
            for(int j:{0,n-1}){
                boundaryCells.push({heightMap[i][j],{i,j}});
                vis[i][j]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j:{0,m-1}){
                boundaryCells.push({heightMap[j][i],{j,i}});
                vis[j][i]=1;
            }
        }
        int water=0;
        while(!boundaryCells.empty()){
            PP p= boundaryCells.top();
            boundaryCells.pop();
            int height=p.first;
            int i=p.second.first;
            int j=p.second.second;
            for(vector<int>dir:direction){
                int nexti=i+dir[0];
                int nextj=j+dir[1];
                if(nexti<0||nextj<0||nexti>m-1||nextj>n-1||vis[nexti][nextj])   {continue;}
                water+=max(height-heightMap[nexti][nextj],0);
                boundaryCells.push({max(height,heightMap[nexti][nextj]),{nexti,nextj}});
                
                vis[nexti][nextj]=1;
            }
        }
        return water;
    }
};