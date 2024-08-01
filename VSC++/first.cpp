#include<iostream>
#include<map>
using namespace std;


int main(){
  int a = 10;
  int* aa = &a;
  cout<<"aa的地址是： "<<aa<<endl;
  cout<<*aa<<endl;

  int b = 20;
  int& bb = b;
  cout<<bb<<endl<<b<<endl;
  return 0;
}

