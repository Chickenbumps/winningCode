#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int arr[26]={0};
  for(auto p:s){
    arr[p-'a']++;
  }
  for(int i = 0; i < 26;i++)
  cout << arr[i] << " ";

  return 0;
}