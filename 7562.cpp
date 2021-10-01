#include <iostream>
#include <queue>

using namespace std;

int map[300][300];
int visited[300][300];
queue<pair<int,int> > q;

int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tCase;
  cin >> tCase;
  for (int i = 0; i < tCase; i++)
  {
    int w;
    cin >> w;
    int startX,startY,endX,endY;
    cin >> startX >> startY >> endX >> endY;
    for (int j = 0; j < 300; j++)
    {
      for (int k = 0; k < 300; k++)
      {
        map[j][k] = 0;
        visited[j][k] = 0;
      }
      
    }
    map[startX][startY] = 1;
    q.push(make_pair(startX,startY));
    visited[startX][startY] = 1;

    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for (int k = 0; k < 8; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >= w && nx < 0 && ny >= w && ny < 0) continue;
        if(!visited[nx][ny]){
          q.push(make_pair(nx,ny));
          visited[nx][ny] = visited[x][y]+1;
        }
      }
    }

   cout << visited[endX][endY] - 1 << '\n';
  }
  
  return 0;
}