#include <iostream>
#include<unordered_map>
#include<list>
#include <vector>
#include <queue>
using namespace std;
void preparelist(unordered_map<int,list<int>> &adjlist,vector<pair<int,int>>edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}


void printpath(vector<int> path){
    for(auto i:path){
        cout<<i;
    }
}


bool isvisited(unordered_map<int,bool> &visited,int i){
    if(!visited[i]){
        return 0;
    }
    return 1;
}
void printpathusingBFS(vector<pair<int,int>>edges,int src,int dst){
    unordered_map<int,list<int>> adjlist;
    preparelist(adjlist,edges);
    unordered_map<int,bool>visited;
    queue<vector<int>> q;
    vector<int>path;
    path.push_back(src);
    visited[src]=1;
    q.push(path);
    while(!q.empty()){
        path=q.front();
        q.pop();
        int last=path[path.size()-1];
        if(last==dst){
            for(auto i:path){
                cout<<i;
            }
            cout<<endl;
        }
        else{
            for(auto i:adjlist[last]){
                if(!visited[i]){
                    vector<int> npath(path);//important step
                    npath.push_back(i);
                    q.push(npath);
                    visited[i]=1;
                }
            }
        }
        visited[dst]=0;


    }

}
int main() {
    vector<pair<int,int>>edges;
    edges={
            {0,1},{0,2},{1,3},{2,3}
    };
    printpathusingBFS(edges,0,3);
}
