#include<iostream>
#include<vector>
using namespace std;
const int MAXV = 1000;
const int INF = 100000000;
//用邻接矩阵实现DFS
//n为顶点数，MAXV为最大顶点数，如果顶点i已经被访问，那么vis[i]=true.
int n,G[MAXV][MAXV];
bool vis[MAXV] = {false};
void DFS(int u,int depth){
    vis[u] = true;
    for(int v = 0;v < n;v++){
        if(vis[v] == false && G[u][v] != INF){
            DFS(v,depth+1);
        }
    }
}
void DFSTravel(){
    for(int v = 0;v < n;v++){
        if(vis[v] == false){
            DFS(v,1);
        }
    }
}

int main(){

    return 0;
}