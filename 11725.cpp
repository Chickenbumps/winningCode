#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100001

queue<int> q;
vector<int> map[MAX];
int visited[MAX];

int main(){
  int n;
  cin >> n;

  for (int i = 0; i < n-1; i++)
  {
    int a,b;
    cin >> a >> b;
    map[a].push_back(b);
    map[b].push_back(a);
  }

  vector<int> v(n+1,0);
  visited[1] = 1;
  q.push(1);
  while(!q.empty()){
    int s = q.front();
    q.pop();
    for (auto i = map[s].begin(); i != map[s].end(); i++)
    {
      if(!visited[*i]){
        visited[*i]=1;
        q.push(*i);
        v[*i]=s;
      }
    }
  }
  
  for(int i = 2; i <= n;i++){
    cout << v[i] << '\n';
  }
  return 0;
}