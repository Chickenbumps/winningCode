#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
  int test;
  cin >> test;
  for (int i = 0; i < test; i++)
  {
    int m,n,cabb;
    cin >> m >> n >> cabb;
    int map[n][m];
    int visited[n][m];
    queue<pair<int,int> > q;
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        map[j][k] = 0;
        visited[j][k] = 0;
      }
    }
    for (int j = 0; j < cabb; j++)
    {
      int x,y;
      cin >> y >> x;
      map[x][y] = 1;
    }
    int jee = 0;
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        if(map[j][k] && !visited[j][k]){
          visited[j][k] = 1;
          q.push(make_pair(j,k));
          while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int t = 0; t < 4; t++)
            {
              int nx = x + dx[t];
              int ny = y + dy[t];
              if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || !map[nx][ny])continue;
              visited[nx][ny] = 1;
              q.push(make_pair(nx,ny));
            }
            
          }
          jee++;
        }
      }
      
    } 
  cout<< jee << '\n';
  }
  
}

