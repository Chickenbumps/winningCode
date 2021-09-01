#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n,0);
  for(auto& p:v)  cin >> p;
  sort(v.begin(),v.end());
  int x;
  cin >> x;
  int answer = 0;
  int start = 0, end = n-1;
  int sum = 0;
  for(auto p: v){
    if(binary_search(v.begin(),v.end(),x-p)){
      cout << p << "\n"; 
      answer++;
    }
  }
  cout << answer/2 << "\n";
  return 0;
}