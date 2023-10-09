#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>getAdjacency(vector<vector<int>>edges,int n){
    vector<vector<int>>list(n+1);
    for (auto edge : edges) {
        list[edge[0]].push_back(edge[1]);
        list[edge[1]].push_back(edge[0]);
    }
    return list;

}

vector<int>getDegree(vector<vector<int>>adj,int source,int n){
    vector<int>ans(n+1,-1);
    ans[source]=0;
    vector<bool>visited(n+1,false);
    queue<int>dfsq;
    dfsq.push(source);
    while(!dfsq.empty()){
        int curr=dfsq.front();
        visited[curr]=true;
        dfsq.pop();
        for(int i=0;i<adj[curr].size();i++){
            if(ans[adj[curr][i]]==-1){
                ans[adj[curr][i]]=ans[curr]+1;
            }
            if(!visited[adj[curr][i]]) dfsq.push(adj[curr][i]);
        }
    }
    return ans;
}

int main(){
    int n=10;
    vector<vector<int>>edges={{1,2},{1,3},{1,4},{1,6},{4,5},{5,7},{5,6},{6,8},{7,8},{3,10},{8,10},{7,9}};
    vector<vector<int>>adjlist=getAdjacency(edges,n);
    vector<int>ans=getDegree(adjlist,1,n); // 1 is my source
    for(int i=0;i<ans.size();i++){
        cout<<i<<": "<<ans[i]<<endl;
    }
    return 0;
    
}
