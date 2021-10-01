#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char map[25][25];
int visited[25][25];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int,int> > q;
vector<int> v;

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(!visited[i][j] && map[i][j] == '1'){
        int count = 1;
        q.push(make_pair(i,j));
        visited[i][j] = 1;
        while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
            if(!visited[nx][ny] && map[nx][ny] == '1'){
              q.push(make_pair(nx,ny));
              visited[nx][ny] = 1;
              count++;
            }
          }
        }
      v.push_back(count);
      }
    }
  }

  cout << v.size() << '\n';
  sort(v.begin(),v.end());
  for(auto p:v)
    cout << p << '\n';
  
  return 0;
}