n = int(input())
visited = [0] * (n+1)
m = [[] for _ in range(n+1)]
for i in range(n-1):
    a, b = map(int, input().split())
    a-=1
    b-=1
    m[a].append(b)
    m[b].append(a)

q = [0]
visited[0] = 1
ans = [0] *(n+1)


while q:
    s = q[0]
    q.pop(0)
    for p in m[s]:
        if visited[p] == 0:
            visited[p] = 1
            ans[p] = s
            q.append(p)

for i in range(1,n):
    print(ans[i]+1)











