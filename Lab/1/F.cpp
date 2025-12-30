#include <iostream>
#include <string>
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;

const int N=15;

int n,card[4*N],yon;

inline void dfs(int pos,int res){
  if(yon) return ;
  if(pos>37){
    yon|=(!res);
    return ;
  }
  if(!res){
    yon=true;
    return ;
  }
  if(!card[pos]){
    dfs(pos+1,res);
    return ;
  }
  if(card[pos]>=3){
    card[pos]-=3;
    dfs(pos,res-3);
    card[pos]+=3;
  }
  if(pos<30&&card[pos+1]&&card[pos+2]){
    card[pos]--,card[pos+1]--,card[pos+2]--;
    dfs(pos,res-3);
    card[pos]++,card[pos+1]++,card[pos+2]++;
  }
}

signed main(){
  IOS
  int T;
  cin>>T;
  while(T--){
    yon=false;
    for(int i=1;i<=37;++i) card[i]=0;
    for(int i=1;i<=14;++i){
      char a,b;
      cin>>a>>b;
      if(b=='b') card[a-'0']++;
      else if(b=='s') card[10+a-'0']++;
      else if(b=='w') card[20+a-'0']++;
      else card[30+a-'0']++;
    }
    for(int quetou=1;quetou<=37;++quetou){
      if(card[quetou]<2) continue;
      card[quetou]-=2;
      dfs(1,12);
      if(yon) break;
      card[quetou]+=2;
    }
    cout<<(yon?"Blessing of Heaven\n":"Bad luck\n");
  }

  return 0;
}