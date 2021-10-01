#include <iostream>
#include <queue>

using namespace std;

int map[301][301];
int visited[301][301];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

queue<pair<int,int> > q1,q2;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }
  }
int year = 0;
while(1){
  cnt = 0;
  year += 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(map[i][j]>0){
        q1.push(make_pair(i,j));
        visited[i][j] = 1;
      }
    }
  }

  while(!q1.empty()){
    int x = q1.front().first;
    int y = q1.front().second;
    q1.pop();
    for (int k = 0; k < 4; k++)
    {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny]>0) continue;
      if(map[x][y]>0 && !visited[nx][ny]){
        map[x][y]--;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      visited[i][j] = 0;
    }
    
  }
  


  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(map[i][j]>0 && !visited[i][j]){
        q2.push(make_pair(i,j));
        while(!q2.empty()){
          int x = q2.front().first;
          int y = q2.front().second;
          q2.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny]==0) continue;
            if(!visited[nx][ny]){
             visited[nx][ny] = 1;
             q2.push(make_pair(nx,ny));
            }
          }
        }
        cnt++;
      }
    }
  }

  if(cnt == 0){
    year = 0;
    break;
  }

  if(cnt >= 2){
    break;
  }
}
  cout << year;
  



  return 0;
} 