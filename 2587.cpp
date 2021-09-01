#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> v;
  for(int i =0; i < 5; i++){
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());
  int sum = 0, avg = 0,mid = v[2];
  for(auto& p: v){
    sum += p; 
  } 
  cout << sum / 5 << "\n" << mid << "\n";
  return 0;
}