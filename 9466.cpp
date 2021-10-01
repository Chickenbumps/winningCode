#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
using namespace std;
map<string,int> m;

int stu[100001];
int visited[100001];
int check[100001];
int flag = 0;
vector<int> v;



void dfs(int s,int start){
  int next = stu[s];
  if(check[s]) return;
  if(next == start && !visited[s]){
    visited[s] = 1;
    v.push_back(s);
    flag = 1;
    return ;
  }
  if(!visited[s] && s != next){
    visited[s] = 1;
    v.push_back(s);
    dfs(next,start);
  }
}

int main(){
  int tCase;
  cin >> tCase;

  for (int i = 0; i < tCase; i++)
  {
    int n;
    cin >> n;
    int count = n;
    for (int j = 0; j < n; j++)
    {
      int temp;
      cin >> temp;
      stu[j] = temp - 1;
    }

    for (int j = 0; j < n; j++)
    {
      if(check[j]) continue;
      dfs(j,j);
      if(flag == 1){
        count -= v.size();
      }
      for (int k = 0; k < n; k++)
      {
        if(k < v.size() && v[k]) check[k] = 1;
        stu[k] = 0;
        visited[k] = 0;
      }
      v.clear();
      flag = 0;
    }
    cout << count << '\n';
    
  }

  return 0;
}
