#include <iostream>
#include <queue>
using namespace std;

int map[501][501];
int visited[501][501];
queue<pair<int,int> > q;
int maxPaint = 0;
int paintNum = 0;
int current = 0;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i =0;i<n; i++){
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(map[i][j] == 1 && visited[i][j] == 0){
        q.push(make_pair(i,j));
        visited[i][j] = 1;
      
        while(!q.empty()){
          current++;
          int startX = q.front().first;
          int startY = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++)
          {
          int x = startX + dx[k];
          int y = startY + dy[k];
            if(0 <= x && x < n && 0 <= y && y < m && map[x][y] && !visited[x][y] ){
              q.push(make_pair(x,y));
              visited[x][y] = 1;
            }
          }
        }
      paintNum++;
      maxPaint = max(maxPaint,current);
      current = 0;
      }
    }
  }
  cout << paintNum << "\n" << maxPaint;

  return 0;
}