#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000];
int visited[1000][1000];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int,int> > q;

int main(){
  int m,n;
  cin >> m >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if(map[i][j] == 1)  {
        q.push(make_pair(i,j));
        visited[i][j] = 1;
      }
    }
  }
  
  while(!q.empty()){
    int startX = q.front().first;
    int startY = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++)
    {
      int x = startX + dx[k];
      int y = startY + dy[k];
      if(x >= 0 && x < n && y >=0 && y < m && map[x][y] == 0 && visited[x][y] == 0){
         q.push(make_pair(x,y));
         visited[x][y] = visited[startX][startY] +1;
       }
     }      
  }
    
  int maxDay= 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(map[i][j] != -1 && visited[i][j] ==0){
        cout << -1;
        return 0;
      }
      maxDay = max(maxDay,visited[i][j]);
    }
  }
  if(maxDay == 0){
    cout << 0;
    return 0;
  }
  cout << maxDay-1;
  return 0;
}