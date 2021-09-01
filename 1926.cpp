#include <iostream>
#include <vector>

using namespace std;

int map[501][501];
int visited[501][501];
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int paintNum = 0;
int maxPaint = 0;
int current= 0;

void dfs(int y, int x){
  visited[y][x] = 1;
  current += 1;
  maxPaint = max(maxPaint,current);

  for (int i = 0; i < 4; i++)
  {
    int xIndex = x + dx[i];
    int yIndex = y + dy[i];
    if(xIndex >=0 && xIndex < m && yIndex >=0 && yIndex < n && map[yIndex][xIndex] == 1 && visited[yIndex][xIndex] == 0){
      dfs(yIndex,xIndex);
    }
  }
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0;i < n;i++){
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }
  }
 
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(visited[i][j] == 0 && map[i][j] ==1){
        dfs(i,j);
        paintNum++;        
        current = 0;
      }
    }  
    
  }
  cout << paintNum << "\n" << maxPaint;
  return 0;
}