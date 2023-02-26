#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;


void prepareadjlist(vector<pair<int,int>>edges,unordered_map<int, list<int>> &adjlist){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    return;
}

void bfs(int node, unordered_map<int, list<int>> adjlist, unordered_map<int, bool> &visited,vector<int> &ans){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto i:adjlist[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> BFS(int nodes,vector<pair<int,int>>edges) {
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;
    vector<int>ans;
    prepareadjlist(edges,adjlist);
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            bfs(i,adjlist,visited,ans);
        }
    }
    return ans;

}

int main(){
    vector<pair<int,int>>edges;
    vector<int>anslist;
    edges={
            {0,1},{0,2},{1,3},{2,3}
    };
    anslist=BFS(4,edges);
    for(auto i:anslist){
        cout<<anslist[i]<<" ";
    }
}
