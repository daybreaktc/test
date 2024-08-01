//迷宫问题
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
//(x,y)坐标和步数
struct node {
    int x,y;
    int step;
}temnode,S,T;
const int maxv = 100;
//迷宫的行列
int n,m;
char inf_m[maxv][maxv];
bool inq[maxv][maxv] = {false};
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

bool test(int x,int y){
    if(x >= n || x < 0 || y >= m || y < 0) return false;
    if(inf_m[x][y] == '*') return false;
    if(inq[x][y] == true) return false;
    return true;
}

int BFS(){
    queue<node> q;
    q.push(S);
    while(!q.empty()){
        node top = q.front();
        q.pop();
        if(top.x == T.x && top.y == T.y){
            return top.step;
        }
        for(int i = 0;i < 4;i++){
            int newx = top.x + X[i];
            int newy = top.y + Y[i];
            if(test(newx,newy)){
                temnode.x = newx;
                temnode.y = newy;
                temnode.step = top.step + 1;
                q.push(temnode);
                inq[newx][newy] = true;
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d %d",&n,&m);
    getchar();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            inf_m[i][j] = getchar();
        }
        getchar();
    }

    scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
    S.step = 0;
    printf("%d\n",BFS());
    return 0;
}
/*
5 5
.....
.*.*.
.*S*.
.***.
...T*  
2 2 4 3
*/