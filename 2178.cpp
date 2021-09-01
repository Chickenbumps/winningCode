#include <iostream>
#include <queue>
using namespace std;

char map[100][100];
int visited[100][100];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int,int> > q;

int main(){
  int n,m;
  cin >> n >> m;
  for (int  i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }  
  }
  
        q.push(make_pair(0,0));
        visited[0][0] = 1;
        while(!q.empty()){
          int startX = q.front().first;
          int startY = q.front().second;
          if(startX == n-1 && startY == m-1){
            break;
          }
          q.pop();
          for (int k = 0; k < 4; k++)
          {
            int x = startX + dx[k];
            int y = startY + dy[k];
            if(visited[x][y] == 0 && map[x][y] == '1' && x>=0 && x < n && y >= 0 && y < m){
              q.push(make_pair(x,y));
              visited[x][y] = visited[startX][startY] + 1;
            }
          }
          
    
  }
  cout << visited[n-1][m-1] << "\n";
  return 0;
  
}