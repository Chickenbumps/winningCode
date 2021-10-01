#include <iostream>
#include <queue>

using namespace std;

struct tri{
  int a,b,c;
};

char map[1001][1001];
int visited[1001][1001][2];

queue<tri> q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }
  }
  
  struct tri temp = {0,0,0};
  q.push(temp);
  visited[0][0][0] = 1;

  while(!q.empty()){
    int x = q.front().a;
    int y = q.front().b;
    int z = q.front().c;
    q.pop();
    for(int k=0;k <4; k++){
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(nx < 0 || ny < 0 || nx >= n || ny >=m) continue;
      if(!visited[nx][ny][z]){
        if(map[nx][ny] == '1' && z == 0){
          visited[nx][ny][1] = visited[x][y][z] + 1;
          struct tri temp = {nx,ny,1};
          q.push(temp);
        }else if(map[nx][ny]=='0'){
          visited[nx][ny][z] = visited[x][y][z] + 1;
          struct tri temp = {nx,ny,z};
          q.push(temp);
        }
      }
    }
  }

 if(!visited[n-1][m-1][0] && !visited[n-1][m-1][1]){
   cout << -1;
 }else if(!visited[n-1][m-1][0] || !visited[n-1][m-1][1]){
    cout << max(visited[n-1][m-1][0],visited[n-1][m-1][1]);
 }else{
   cout << min(visited[n-1][m-1][0],visited[n-1][m-1][1]);
 }

  return 0;
}