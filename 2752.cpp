#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v;
  for(int i=0;i<3;i++)  {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());
  for(auto& p:v)  cout << p << " ";
  
  return 0;
  

}