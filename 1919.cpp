#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a,b;
  cin >> a >> b;
  vector<int> va(26,0),vb(26,0);
  for(auto p: a){
    va[p-'a']++;
  }
  for(auto p: b){
    vb[p-'a']++;
  }
  
  int count = 0;
  for(int i= 0; i < 26;i++){
    if(va[i] != vb[i]){
      count += abs(va[i]-vb[i]);
    }
  }
  cout << count;
  return 0;


}