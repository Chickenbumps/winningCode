#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin >> n >> k;
  vector<int> m(6,0),w(6,0);
  for(int i = 0; i< n; i++){
    int sx,grade;
    cin >> sx >> grade;
    if(sx == 0){
      w[grade-1]++;
    }else{
      m[grade-1]++;
    }
  }
  int total = 0;
  for(int i = 0; i < 6;i++){
    total += m[i] / k;
    if(m[i]%k)  total++;
    total += w[i] / k;
    if(w[i]%k)  total++;
  }
  cout << total << "\n";
  return 0;

}