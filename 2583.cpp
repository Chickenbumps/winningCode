#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[100][100];
int visited[100][100];
queue<pair<int,int> > q;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
  int m,n,k;
  cin >> m >> n >> k;
  for (int i = 0; i < k; i++)
  {
    int sx,sy,ex,ey;
    cin >> sx >> sy >> ex >> ey;
    for (int j = 0; j < m; j++)
    {
      for (int t = 0; t < n; t++)
      {
        if(t >= sx && t < ex && j >= sy && j < ey){
          map[j][t] = 1;
        }
      } 
    }  
  }

  int count = 0; 
  queue<int> c;
  vector<int> v;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(map[i][j] == 0 && !visited[i][j]){
        visited[i][j] = 1;
        q.push(make_pair(i,j));
        int ctt= 0;
        while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int t = 0; t < 4; t++)
          {
            int nx = x + dx[t];
            int ny = y + dy[t];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(map[nx][ny] == 0 && !visited[nx][ny]){
              visited[nx][ny] = 1;
              q.push(make_pair(nx,ny));
              ctt++;
            }
          }
        }
        v.push_back(ctt+1);
        count++;
      }
    }

  }
  cout << count <<'\n';
  sort(v.begin(),v.end());
  for (int i = 0; i < count; i++)
  {
    cout << v[i] << ' ';
  }
  

  
  return 0;
}