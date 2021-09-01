#include <iostream>
#include <queue>

using namespace std;

char map[10][10];
queue<pair<int,int> > rq,bq;
queue<int> cq;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visited[10][10][10][10];

int main(){
  int n,m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if(map[i][j] == 'R'){
        rq.push(make_pair(i,j));
      }
      if(map[i][j] == 'B'){
        bq.push(make_pair(i,j));
      }
    }
  }

  cq.push(0);
  int minC = 10000000;
  while(!rq.empty() && !bq.empty()){
    int rx = rq.front().first;
    int ry = rq.front().second;
    int bx = bq.front().first;
    int by = bq.front().second;
    int c = cq.front();
    rq.pop(); bq.pop(); cq.pop();
    if(c >= 10) break;
    for (int k = 0; k < 4; k++)
    {
      int nrx=rx, nry=ry, nbx=bx, nby=by;
      while(map[nrx+ dx[k]][nry+dy[k]] != '#' && map[nrx][nry] != 'O'){
        nrx += dx[k];
        nry += dy[k];
      }
      while(map[nbx+ dx[k]][nby+dy[k]] != '#' && map[nbx][nby] != 'O'){
        nbx += dx[k];
        nby += dy[k];
      }
      if(map[nbx][nby] == 'O') continue;
      if(map[nrx][nry] == 'O'){
        minC = min(c+1,minC);
      }
      if(nrx == nbx && nry ==nby){
        if(abs(nrx -rx) + abs(nry-ry) > abs(nbx - bx) + abs(nby-by)){
          nrx -= dx[k];
          nry -= dy[k];
        }else{
          nbx -= dx[k];
          nby -= dy[k];
        }
      }
      if(visited[nrx][nry][nbx][nby]) continue;
      visited[nrx][nry][nbx][nby] = 1;
      rq.push(make_pair(nrx,nry));
      bq.push(make_pair(nbx,nby));
      cq.push(c+1);
    }
  }
  if(minC == 10000000){
    cout << -1<< '\n';
  }else{
    cout << minC << '\n';
  }
  return 0;
}

