#include <iostream>
#include<unordered_map>
#include<list>
#include <vector>
#include<stack>
using namespace std;
void preparelist(unordered_map<int,list<int>> &adjlist,vector<pair<int,int>>edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}
unordered_map<bool,int> reset(){
    unordered_map<bool,int> visited;
    return visited;
}
void printpathusingDFS(vector<pair<int,int>>edges,int src,int dst){
    unordered_map<int,list<int>> adjlist;
    preparelist(adjlist,edges);
    unordered_map<int,bool>visited;
    stack<vector<int>> q;
    vector<int>path;
    path.push_back(src);
    visited[src]=1;
    q.push(path);
    while(!q.empty()){
        path=q.top();
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
            {0,1},{0,2},{1,3},{2,3},{1,4},{3,4}
    };
    unordered_map<int,list<int>> adjlist;
    preparelist(adjlist,edges);
    int ind=0;
    int s=0;
    int d=4;
    vector<int>path;
    unordered_map<int,bool>visited;
    printpathusingDFS(edges,s,d);
}
