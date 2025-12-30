#include <iostream>
#include <cstring>
using namespace std;

const int N=1000;

char s[N][N];

signed main(){
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--){
    int a,b,c;
    cin>>a>>b>>c;
    int n=(b+c)*2+1,m=(a+b)*2+1;
    for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
        s[i][j]='.';
    for(int i=1;i<=a;++i)//
      for(int j=1;j<=c;++j){
        s[n-j*2+2][i*2-1]='+';
        s[n-j*2+1][i*2-1]='|';
        s[n-j*2+2][i*2]='-';
      }
    
    for(int i=1;i<=b*2+1;++i){//
      if(i&1){
        for(int j=1;j<=a;++j)
          s[b*2+1-i+1][i+(j-1)*2]='+',s[b*2+1-i+1][i+(j-1)*2+1]='-';
        for(int j=1;j<=c;++j)
          s[n-i+1-j*2+2][a*2+i]='+',s[n-i+1-j*2+1][a*2+i]='|';
      } else{
        for(int j=1;j<=a;++j)
          s[b*2+1-i+1][i+(j-1)*2]='/';
        for(int j=1;j<=c;++j)
          s[n-i+1-j*2+2][a*2+i]='/';
      }
    }

    for(int i=1;i<=b;++i){
      s[i*2-1][m-i*2+2]='+';
      s[i*2][m-i*2+1]='/';
    }
    s[b*2+1][m-b*2]='+';

    for(int i=1;i<=n;++i,cout<<'\n')
      for(int j=1;j<=m;++j)
        cout<<s[i][j];
  }
  return 0;
}