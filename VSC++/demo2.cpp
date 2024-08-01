#include<iostream>
#include<vector>
using namespace std;
const int MAXV = 1000;
int n;//图有n个结点
vector<int> Adj[MAXV];
bool vis[MAXV] = {false};

void DFS(int u,int depth){
    vis[u] = true;
    for(int i = 0;i < Adj[u].size();i++){
        int v = Adj[u][i];
        if(vis[v] == false){
            DFS(v,depth+1);
        }
    }
}

void DFSTravel(){
    for(int i = 0;i < n;i++){
        if(vis[i] == false){
            DFS(i,1);
        }
    }
}


int main(){

}