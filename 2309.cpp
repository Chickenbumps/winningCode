#include <bits/stdc++.h>

using namespace std;

vector<int> answer;
int flag = 0;
void solve(vector<int> &vv,int index,int sum){
  if(index > 9||sum > 100 || answer.size() > 7){
    return ;
  }
  if(sum == 100){
    if(answer.size() == 7 && flag == 0){
      cout << '\n';
      sort(answer.begin(),answer.end());
      for(auto&p : answer){
        cout << p << "\n";
      }
      flag = 1;
    }
    return ;
  }
  answer.push_back(vv[index]);
  solve(vv,index+1,sum+vv[index]);
  answer.pop_back();
  solve(vv,index+1,sum);
}

int main(){
  vector<int> v;
  for (int i = 0; i < 9; i++)
  {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  // sort(v.begin(),v.end());
  solve(v,0,0);
  return 0;
}