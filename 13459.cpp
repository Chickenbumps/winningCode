#include <iostream>
#include <queue>

using namespace std;

char map[10][10];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visited[10][10][10][10];

queue<pair<int,int> > r,b;
queue<int> cq;

int main(){
  int n,m;
  cin >> n >> m;
  for (int  i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if(map[i][j] == 'R') {
        r.push(make_pair(i,j));
      }
      if(map[i][j] == 'B'){
        b.push(make_pair(i,j));
      }
    }
  }
  cq.push(0);
  while(!b.empty()){
    int rx = r.front().first;
    int ry = r.front().second;
    int bx = b.front().first;
    int by = b.front().second;
    r.pop();
    b.pop();
    int c = cq.front();
    cq.pop();
    if(c >= 10) break;
    for (int k = 0; k < 4; k++)
    {
      int nrx = rx; int nry = ry;
      int nbx = bx; int nby = by;
      while(map[nrx + dx[k]][nry+ dy[k]] != '#' && map[nrx][nry] != 'O'){
        nrx += dx[k];
        nry += dy[k];
      }
      while(map[nbx + dx[k]][nby+dy[k]] != '#' && map[nbx][nby] != 'O'){
        nbx += dx[k];
        nby += dy[k];
      }
      if(map[nbx][nby] == 'O') continue;
      if(map[nrx][nry] == 'O'){
        cout << "1\n";
        return 0;
      }
      if(nrx == nbx && nry == nby){
        if(abs(nrx-rx) + abs(nry-ry) > abs(nbx-bx) + abs(nby-by)){
          nrx -= dx[k];
          nry -= dy[k];
        }else{
          nbx -= dx[k];
          nby -= dy[k];
        }
      }
      if(visited[nrx][nry][nbx][nby]) continue;
      visited[nrx][nry][nbx][nby] = 1;
      r.push(make_pair(nrx,nry));
      b.push(make_pair(nbx,nby));
      cq.push(c+1);
    }
  }

  cout << "0\n"; 

  return 0;

}