#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  stack<int> s;
  long long answer = 0;
  for(int i = 0; i < n; i++){
    long long temp;
    cin >> temp;
    while(!s.empty() && s.top() <= temp){
      s.pop();
    }
    answer += s.size();
    s.push(temp);
  }
  cout << answer;
  return 0;
}



