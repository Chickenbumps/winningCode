#include <iostream>
#include <queue>

using namespace std;

struct tomato{
  int z,y,x;
};

int map[100][100][100];
int visited[100][100][100];
queue<tomato> q;

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n,h;
  cin >> m >> n >> h;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        cin >> map[i][j][k];
        if(map[i][j][k] == 1){
          tomato temp = {i,j,k};
          q.push(temp);
          visited[i][j][k] = 1;
        }
      } 
    }
  }

 
  while(!q.empty()){
    int x = q.front().x;
    int y = q.front().y;
    int z = q.front().z;
    q.pop();
    for (int t = 0; t < 6; t++)
    {
      int nx = x + dx[t];
      int ny = y + dy[t];
      int nz = z + dz[t];
      if(nx >= m || nx < 0 || ny >= n || ny < 0 || nz >= h || nz <0) continue;
      if(visited[nz][ny][nx] == 0 && map[nz][ny][nx] == 0){
        visited[nz][ny][nx] = visited[z][y][x] + 1;
        tomato t2 = {nz,ny,nx};
        q.push(t2);
      }
    }
  }
      
  int mn = 0;
  int count = 0;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        mn = max(mn,visited[i][j][k]);
        if(visited[i][j][k] == 0 && map[i][j][k] != -1){
          cout << -1;
          return 0;
        }
        if(map[i][j][k] == 1 || map[i][j][k] == -1){
          count++;
        }
        if(count == h * m* n){
          cout << 0;
          return 0;
        }
      }
    }
  }
  cout << mn-1 <<"\n";

  
  return 0;
}