#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while(1){
    system("gen.exe");
    system("C.exe");
    system("C_ans.exe");
    if(system("fc C.out C.txt"))
      break;
  }
  
  return 0;
}