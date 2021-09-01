#include <iostream>
#include <queue>
using namespace std;


char map[1002][1002];
int visited[1002][1002];
int visitedF[1002][1002];
queue<pair<int,int> > qj,qf;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
  int r,c;
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> map[i][j];
      if(map[i][j] == 'J')  {
        qj.push(make_pair(i,j));
        visited[i][j] = 1;
      }
      if(map[i][j] == 'F')  {
        qf.push(make_pair(i,j));
        visitedF[i][j] = 1;
      }
    }
  }


  while(!qf.empty()){
    int fx = qf.front().first;
    int fy = qf.front().second;
    qf.pop();
    for (int k = 0; k < 4; k++)
    {
      int x = fx + dx[k];
      int y = fy + dy[k];
      if(map[x][y] == '.' &&  x >= 0 && x < r && y >=0 && y <c && visitedF[x][y]==0){
        visitedF[x][y] = visitedF[fx][fy] + 1;
        qf.push(make_pair(x,y));
      }
    }
  }

  while(!qj.empty()){
    int jx = qj.front().first;
    int jy = qj.front().second; 
    qj.pop();
    for (int k = 0; k < 4; k++)
    {
      int njx = jx + dx[k];
      int njy = jy + dy[k];
      if(njx < 0 || njy < 0 || njx >= r || njy >=c){
        cout << visited[jx][jy];
        return 0;
      }
      
      if(visited[njx][njy] > 0 || map[njx][njy] == '#') continue;
      if(visitedF[njx][njy] > 0 && visitedF[njx][njy] <= visited[jx][jy] +1 ) continue;
      visited[njx][njy] = visited[jx][jy] + 1;
      qj.push(make_pair(njx,njy));
    }
  }
  
  cout << "IMPOSSIBLE";

  return 0;
}