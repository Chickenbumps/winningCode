#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  int ySum = 0,mSum =0;
  for(auto& p: v){
    ySum += (p / 30+1) * 10;
    mSum += (p / 60+1) * 15;
  }
  if(ySum < mSum){
    cout << "Y" << " "<< ySum;
  }else if(ySum > mSum){
    cout << "M" << " " <<mSum;
  }else{
    cout << "Y M" << " " << ySum;
  }

  return 0;

}