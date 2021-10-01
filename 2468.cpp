#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int visited[101][101];

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};


int cMax = 0;

void dfs(int x, int y,int h,int n){
  visited[x][y] =1;
  for (int i = 0; i < 4; i++)
  {
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(map[nx][ny] <= h||visited[nx][ny] || nx < 0 || ny < 0 || nx >=n || ny>=n){
      continue;
    }
    
    dfs(nx,ny,h,n);
    
  }
  
}


int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }

  for (int k = 0; k < 101; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        visited[i][j] = 0;
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(!visited[i][j] && map[i][j]>k){
          dfs(i,j,k,n);
          cnt++;
        }
      }
    }
    cMax = max(cnt,cMax);
  }
  

  cout << cMax <<'\n';
  


  return 0;
}