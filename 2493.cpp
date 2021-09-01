#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<pair<int,int> > s;
  s.push(make_pair(100000001,0));
  for(int i = 1; i <= n; i++){
    int temp;
    cin >> temp;
    while(s.top().first < temp){
      s.pop();
    }
    cout << s.top().second << " ";
    s.push(make_pair(temp,i));
  }

  return 0;
}

