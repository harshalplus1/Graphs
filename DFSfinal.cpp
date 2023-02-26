#include <iostream>
#include<unordered_map>
#include<stack>
#include<list>
#include <vector>
using namespace std;


void prepareadjlist(unordered_map<int,list<int>> &adjlist,vector<pair<int,int>>edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    return;
}

void dfs(int node,unordered_map<int,list<int>> &adjlist,unordered_map<int, bool> &visited,vector<int> &ans){
    stack<int> s;
    s.push(node);
    visited[node]=1;
    ans.push_back(node);
    while(!s.empty()){
        int n=s.top();
        s.pop();
        if(!visited[n]){
            ans.push_back(n);
            visited[n]=1;
        }
        for(auto i:adjlist[n]){
            if(!visited[i]){
                s.push(i);
            }
        }
    }
}
vector<int> DFS(int nodes,vector<pair<int,int>>edges) {
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;
    vector<int>ans;
    prepareadjlist(adjlist,edges);
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            dfs(i,adjlist,visited,ans);
        }
    }
    return ans;

}
int main() {
    vector<pair<int,int>> edges;
    edges={
            {0,1},{0,2},{1,3},{2,3}
    };
    vector<int>anslist;
    anslist=DFS(4,edges);
    for(auto i:anslist){
        cout<<i<<" ";
    }
}
