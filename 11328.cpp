#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  string s,newS;
  vector<int> v(26,0);
  for (int i = 0; i < test; i++)
  {
    // for(int i =0 ;i < 26;i++) v[i] = 0;
    for(auto& p: v) p = 0;
    cin >> s >> newS;
    if(s.length() != newS.length()){
      cout << "Impossible\n";
      continue;
    }else{
      for(auto p: s){
        v[p-'a']++;
      }
      for(auto p: newS){
        v[p-'a']--;
      }
      int flag = 1;
      for(auto& p: v){
        if(p != 0){
          cout << "Impossible\n";
          flag = 0;
          break;
        }
      }
      if(flag) cout << "Possible\n";
    }
  }
  
  return 0;
}