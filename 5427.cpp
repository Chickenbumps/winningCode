#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};




int main(){
  int tCase;
  cin >> tCase;
  for (int i = 0; i < tCase; i++)
  {
    int w,h;
    cin >> w >> h;

    char map[h][w];
    int visited[h][w];
    int fvisited[h][w];
    queue<pair<int,int> > q,f;
    while(!q.empty()){
      q.pop();
    }

    for (int j = 0; j < h; j++)
    {
      for (int k = 0; k < w; k++)
      {
        visited[j][k] = 0;
        fvisited[j][k] = 0;
        map[j][k] = 0;
        cin >> map[j][k];
        if(map[j][k] == '@'){
          q.push(make_pair(j,k));
          visited[j][k] = 1;
        }
        if(map[j][k] == '*'){
          f.push(make_pair(j,k));
          fvisited[j][k] = 1;
        }
      }
    }

    while(!f.empty()){
      int fx = f.front().first;
      int fy = f.front().second;
      f.pop();
      for (int k = 0; k < 4; k++)
      {
        int fnx = fx + dx[k];
        int fny = fy + dy[k];
        if(fnx >= h || fny >= w || fnx < 0 || fny < 0 || map[fnx][fny]=='#' || fvisited[fnx][fny]>0) continue;
        fvisited[fnx][fny] = fvisited[fx][fy] + 1;
        f.push(make_pair(fnx,fny));
      }
    }
    int flag = 0;

    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || ny < 0 || nx >= h || ny >= w){
          cout << visited[x][y] << '\n';
          flag = 1;
          break;
        }
        if(map[nx][ny]=='#' || visited[nx][ny] >0 || map[nx][ny] == '*') continue;
        if((fvisited[nx][ny] > visited[x][y]+1) || fvisited[nx][ny]==0){
          visited[nx][ny] = visited[x][y] + 1;
          q.push(make_pair(nx,ny));
        }
      }
      if(flag == 1){
        break;
      }
    }
    if(flag == 0){
      cout << "IMPOSSIBLE" <<'\n';
    }

  }
  

  return 0;
}