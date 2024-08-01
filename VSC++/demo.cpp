/*
  按f9设置断点，程序运行到断点处就会停止
  到断点以后，按一下F10就会往下执行一行
  按F5程序开始调试，直到断点停下来，再按F5程序将继续向下运行

  二进制书写时必须以0b或者0B开头  int a = 0b101;
  八进制书写的时候必须以0开头
  十六进制书写的时候必须以0x或者0X开头
  C++11原始字面量可以直接表示字符串的实际含义，不需要转义和连接   语法：R"(字符串的内容)"
  用斜线可以连接多行字符串
  string str = "qqq \
    www \
    eee \
    rrr";
  多个字符串的拼接：用 + 进行拼接，如果要拼接的字符串都是常量，那就不用 +
  当表达式中含有浮点型操作数时，所有操作数都将转化为浮点型
  自动类型转换进行截断的时候是从高位开始截断而不是从末尾开始
  强制类型转换的运算符优先级比较高，所以没把握就加括号


  指针用于存放变量在内存中的起始地址,不管什么类型的指针占用的内存都是8字节  指针赋值语句：指针 = &变量名
  指针的名字也是标识符，不能与其他的普通变量重名，指针名表示的是地址
  *运算符称为解引用运算符，*p就是对p解引用，将它用于指针，可以得到该地址的内存中存储的值例如：
  int no = 1;int* ptr = &no;(no 和 *ptr的值都是8)
  指针变量在没有赋初始值之前，里面都是很乱的值，这个时候不能使用指针
  函数的形参用void*，就可以接受任意类型的地址而不用强制类型转换（其它类型的指针赋值给void*不需要转换，
  但是void*指针赋值给其他类型的指针需要转换；不能对void*指针直接解引用，要先转换成其它类型的指针）
  指针又叫指针变量，是变量那就有地址，二级指针用于存放指针变量的地址，语法：数据类型** 指针名
  int ii = 8;       cout<<"ii="<<ii<<",ii的地址是："<<&ii<<endl;
  int* pii = &ii;   cout<<"pii="<<pii<<",pii的地址是："<<&pii<<".*pii="<<*pii<<endl;
  int** ppii = &pii;cout<<"ppii="<<ppii<<",ppii的地址是："<<&ppii<<".*ppii="<<*ppii<<endl;
  cout<<"*ppii="<<*ppii<<endl;//对ppii解引用，就是得到ppii该地址中存储的值，而ppii这个地址&pii，它的值就是pii的值
  cout<<"**ppii="<<**ppii<<endl;//就是ii的值也就是8
  在函数中，如果传递普通变量的地址，形参用指针，传递指针的地址，形参用二级指针（把普通变量的地址传入函数后可以
  在函数中修改变量的值；把指针变量的地址传入函数后可以在函数中修改指针的值）
  void func(int** pp){//二级指针来存放指针的地址
  *pp = new int(3);*pp就是p的值
  cout<<"pp="<<pp<<",*pp="<<*pp<<endl;
  }
  int main() 
  {
    int* p = 0;
    func(&p);//想要修改指针的值就要传指针的地址
    cout<<"p="<<p<<",*p="<<*p<<endl;
  }


  动态分配内存：
  int* p = new int(5);//此时*p为5
  *p = 8;
  delete p;

*/
/*邻接矩阵实现DFS
#include<iostream>
#include<vector>
using namespace std;
const int MAXV = 1000;
const int INF = 10000000;
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
  for(int i = 0;i < n;i++){
    if(vis[i] == false){
      DFS(i,1);
    }
  }
}
*/
#include<iostream>
#include<queue>
using namespace std;
const int maxv = 100;
bool inq[maxv][maxv];
char inf_m[maxv][maxv];
int n,m;
int X[4] = {1,-1,0,0};
int Y[4] = {0,0,1,-1};
struct node{
  int x,y;
  int step;
}S,T,temnode;
bool test(int x,int y){
  if(x >= n|| x < 0||y >=m || y<0) return false;
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
    if(top.x == T.x && top.y == T.y) return top.step;
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