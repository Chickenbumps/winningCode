#include <iostream>
#include <queue>

using namespace std;

char map[100][100];
int visitedR[100][100];
int visitedB[100][100];
int visitedG[100][100];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int,int> > qR;
queue<pair<int,int> > qB;
queue<pair<int,int> > qG;

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

  int area = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(!visitedR[i][j] && map[i][j] == 'R'){
        visitedR[i][j] = 1;
        qR.push(make_pair(i,j));
        while(!qR.empty()){
          int x = qR.front().first;
          int y = qR.front().second;
          qR.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!visitedR[nx][ny] && map[nx][ny] == 'R'){
              qR.push(make_pair(nx,ny));
              visitedR[nx][ny] = 1;
            }
          }
        }
        area++;
      }else if(!visitedB[i][j] && map[i][j] == 'B'){
        visitedB[i][j] = 1;
        qB.push(make_pair(i,j));
        while(!qB.empty()){
          int x = qB.front().first;
          int y = qB.front().second;
          qB.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!visitedB[nx][ny] && map[nx][ny] == 'B'){
              qB.push(make_pair(nx,ny));
              visitedB[nx][ny] = 1;
            }
          }
        }
        area++;
      }else if(!visitedG[i][j] && map[i][j] == 'G'){
        visitedG[i][j] = 1;
        qG.push(make_pair(i,j));
        while(!qG.empty()){
          int x = qG.front().first;
          int y = qG.front().second;
          qG.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!visitedG[nx][ny] && map[nx][ny] == 'G'){
              qG.push(make_pair(nx,ny));
              visitedG[nx][ny] = 1;
            }
          }
        }
        area++;
      }
    }
  }
  int rgArea = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      visitedR[i][j] = 0;
      visitedB[i][j] = 0;
      visitedG[i][j] = 0;
    }  
  }
  

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(!visitedR[i][j] && (map[i][j] == 'R' || map[i][j] == 'G')){
        visitedR[i][j] = 1;
        qR.push(make_pair(i,j));
        while(!qR.empty()){
          int x = qR.front().first;
          int y = qR.front().second;
          qR.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!visitedR[nx][ny] && (map[nx][ny] == 'R' || map[nx][ny] == 'G')){
              qR.push(make_pair(nx,ny));
              visitedR[nx][ny] = 1;
            }
          }
        }
        rgArea++;
      }else if(!visitedB[i][j] && map[i][j] == 'B'){
        visitedB[i][j] = 1;
        qB.push(make_pair(i,j));
        while(!qB.empty()){
          int x = qB.front().first;
          int y = qB.front().second;
          qB.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!visitedB[nx][ny] && map[nx][ny] == 'B'){
              qB.push(make_pair(nx,ny));
              visitedB[nx][ny] = 1;
            }
          }
        }
        rgArea++;
      }
    }
  }
  
  cout << area << ' '<< rgArea << '\n';
  
  return 0;
}