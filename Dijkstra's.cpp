#include<bits/stdc++.h>
using namespace std;

struct mycmp{
    bool operator()(pair<int,int>p1,pair<int,int>p2){
        return p1.second>p2.second;
    }
};

vector<vector<pair<int,int>>>getAdjacency(vector<vector<int>>edges,int n){
    vector<vector<pair<int,int>>>list(n+1);
    for (auto edge : edges) {
        list[edge[0]].push_back(make_pair(edge[1],edge[2]));
        list[edge[1]].push_back(make_pair(edge[0],edge[2]));
    }
    return list;

}

vector<int>dijksta(vector<vector<pair<int,int>>>adj,int n,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp>pq;
    vector<bool>visited(n+1,false);
    vector<int>ans(n+1,INT_MAX);
    pq.push(make_pair(src,0));
    while(!pq.empty()){
        pair<int,int>curr=pq.top();
        visited[curr.first]=true;
        pq.pop();
        if(ans[curr.first]>curr.second) ans[curr.first]=curr.second;
        for(pair<int,int> neighbor:adj[curr.first]){
            neighbor.second+=curr.second;
            cout<<neighbor.second<<" ";
            if(visited[neighbor.first]==false) pq.push(neighbor);
        }
    }
    return ans;


}

int main(){
    int n=7;
    vector<vector<int>>edges={{0,1,3},{0,3,7},{0,5,4},{1,2,4},{1,3,2},{2,6,5},{2,4,6},{2,3,5},{4,6,2},{4,5,6},{5,3,2},{4,3,4}};
    vector<vector<pair<int,int>>>adj=getAdjacency(edges,n);
    vector<int>ans=dijksta(adj,n,0); // 0 is my source
    for(int i=0;i<adj.size();i++){
        cout<<i<<": ";
        for(auto adja:adj[i]){
            cout<<"["<<adja.first<<","<<adja.second<<"]"<<"->";
        }
        cout<<endl;
        
    }

    cout<<endl<<endl;
    for(int i = 0 ; i < ans.size() ; ++i ){
        cout<<i<<":"<<ans[i]<<endl;
    }
    return 0;

    
}
