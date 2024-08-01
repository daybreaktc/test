#include<iostream>
#include<vector>
using namespace std;
//用邻接表来实现DFS
struct Node{
    int v;//边的终点编号
    int w;//边的边权
    Node(int _v,int _w) : v(_v), w(_w) {}
};
const int MAXV = 1000;
const int INF = 100000000;
vector<int> Adj[MAXV];
bool vis[MAXV] = {false};
int n;
void DFS(int u,int depth){
    vis[u] = true;
    for(int i = 0;i < Adj[u].size();i++){
         //Adj[u]就是邻接表其中的一条链表，这里Adj[u][i]存储的是顶点编号
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
    return 0;
}