#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
int visited[100][100];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int> > q;

int main(){

  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
      visited[i][j] = 0;
    }
  }


  int cont=0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(map[i][j]==1 && !visited[i][j]){
        cont++;
        visited[i][j] = cont;
        q.push(make_pair(i,j));
        while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >=n || ny >= n || visited[nx][ny] > 0 || map[nx][ny]== 0) continue;
            visited[nx][ny] = cont;
            q.push(make_pair(nx,ny));
          }
        }
      }
    }
    
  }

  int minL = 10000;
  int cVisited[n][n];
  for (int a = 1; a <= cont; a++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cVisited[i][j] = 0;
        if(visited[i][j]==a){
          cVisited[i][j] = a;
          q.push(make_pair(i,j));
        }
      }
      
    }

    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || ny < 0 || nx >=n || ny >= n || cVisited[nx][ny] > 0) continue;
        if(visited[nx][ny] != a && visited[nx][ny]>0){
          minL = min(minL,cVisited[x][y]-a);
        }
        cVisited[nx][ny] = cVisited[x][y] + 1;
        q.push(make_pair(nx,ny));
      }
    }
  }
  
  cout << minL;

  return 0;

}