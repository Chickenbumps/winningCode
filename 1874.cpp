#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v, dv;
  stack<int> s;
  string ans;
  int count = 1;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    v.push_back(temp);
    for (int j = count; j <= temp; j++)
    {
      s.push(j);
      ans += "+";
      count++;
    }    
    if(temp == s.top()){
      ans += "-";
      dv.push_back(s.top());
      s.pop();
    }
  }
  int noFlag = 0;
  for(int i = 0; i< n; i++){
    if(v[i] != dv[i]){
      noFlag =1;
      break;
    }
  }
  if(noFlag){
    cout << "NO";
  }else{
    for(auto p:ans){
      cout << p << '\n';
    }
  }


  return 0;
  
}

