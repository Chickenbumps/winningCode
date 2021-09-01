#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(205,0);
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    if(temp<0) temp +=201;
    v[temp]++;
  }
  int num;
  cin >> num;
  if(num <0) num += 201;
  cout << v[num] << "\n";
  return 0;
  

}