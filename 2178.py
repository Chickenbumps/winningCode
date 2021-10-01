import sys
# i = sys.stdin.readline()
n,m = map(int, sys.stdin.readline().split())

graph = [list(map(int,input())) for _ in range(n)]
# maps = [sys.stdin.readline().rstrip() for _ in range(n)]
visited = [[0]*m for _ in range(n)]

q = []
visited[0][0] = 1
q.append((0,0))


dx = [0,-1,0,1]
dy = [1,0,-1,0]

while q:
  x = q[0][0]
  y = q[0][1]
  q.pop(0)
  for a,b in zip(dx,dy):
    nx = x + a
    ny = y + b
    if nx >=n or nx < 0 or ny >= m or ny <0 or graph[nx][ny]==0 or visited[nx][ny] > 0 :
      continue
    visited[nx][ny] = visited[x][y] + 1
    q.append((nx,ny))


print(visited[n-1][m-1])
  




