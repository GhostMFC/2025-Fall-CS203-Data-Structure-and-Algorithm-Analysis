#include <iostream>
#include <string>
#define ll long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100010;

int ls,lt;
char s[N],t[N];
ull hsh[N],tmp[N];

inline void merge(int l,int r){
  if(l==r) return ;
  int mid=(l+r)>>1;
  merge(l,mid); merge(mid+1,r);
  int i=l,j=mid+1,pos=l;
  while(i<=mid&&j<=r){
    if(hsh[i]<hsh[j]) tmp[pos++]=hsh[i++];
    else tmp[pos++]=hsh[j++];
  }
  while(i<=mid) tmp[pos++]=hsh[i++];
  while(j<=r) tmp[pos++]=hsh[j++];
  for(int i=l;i<=r;++i) hsh[i]=tmp[i];
}

inline bool check(int x){
  int len=0;
  ull mul=0,_10003=10003;
  for(int i=1;i<x;++i) mul=mul*10003+s[i],_10003*=10003;
  for(int i=x;i<=ls;++i){
    mul=mul*10003+s[i]-s[i-x]*_10003;
    hsh[++len]=mul;
  }
  merge(1,len);
  mul=0; 
  // if(x==2) cout<<_10003<<'\n';
  // if(x==2) for(int i=1;i<=len;++i) cout<<hsh[i]<<' ';
  // cout<<'\n';
  for(int i=1;i<x;++i) mul=mul*10003+t[i];
  for(int i=x;i<=lt;++i){
    mul=mul*10003+t[i]-t[i-x]*_10003;
    // if(x==2) cout<<mul<<' ';
    int l=1,r=len;
    while(l<r){
      int mid=(l+r)>>1;
      if(hsh[mid]<mul) l=mid+1;
      else r=mid;
    }
    if(hsh[l]==mul) return true;
  }
  // cout<<'\n';
  return false;
}

signed main(){
  IOS
  cin>>s+1;
  cin>>t+1;
  while(s[ls+1]) ++ls;
  while(t[lt+1]) ++lt;
  int l=0,r=min(ls,lt);
  while(l<r){
    int mid=(l+r+1)>>1;
    if(check(mid)) l=mid;
    else r=mid-1;
  } cout<<l<<'\n';
  return 0;
}