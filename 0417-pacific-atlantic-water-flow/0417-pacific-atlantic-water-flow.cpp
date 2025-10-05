class Solution {
public:
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
int r,c;
vector<vector<int>>h;
vector<vector<bool>>bfs(queue<pair<int,int>>&q){
    vector<vector<bool>>v(r,vector<bool>(c,false));
    while(!q.empty()){
        auto cell=q.front();
        q.pop();
        int i=cell.first;
        int j=cell.second;
        v[i][j]=true;
        for(int d=0;d<4;d++){
            int newrow=i+dir[d][0];
            int newcol=j+dir[d][1];
            if( newrow<0 || newcol<0 || newrow>=r || newcol>=c){
                continue;
            }
            if( v[newrow][newcol] ){
                continue;
            }
            if(h[newrow][newcol]<h[i][j]){
                continue;
            }
            q.push({newrow,newcol});
        }
    }
    return v;
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r=heights.size();
        c=heights[0].size();
        h=heights;
        queue<pair<int,int>>pacbfs;
        queue<pair<int,int>>atlbfs;
        for(int i=0;i<r;i++){
            pacbfs.push({i,0});
            atlbfs.push({i,c-1});
        }
        for(int j=1;j<c;j++){
            pacbfs.push({0,j});
        }
        for(int j=0;j<c-1;j++){
            atlbfs.push({r-1,j});
        }
        vector<vector<bool>>pacific=bfs(pacbfs);
        vector<vector<bool>>atlantic=bfs(atlbfs);
        vector<vector<int>>ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};