
def solve():
    n = int(input())
    massive = list(map(int, input().split()))
    ans = list()
    flag = False
    cnt = 0
    if massive[0] % 2 == 0 and massive[n - 1] % 2 == 1:
        massive[n - 1] = massive[0]
        ans.append((0, n - 1))
        if 0 == n - 1:
            cnt += 1
        flag = True
    elif massive[0] % 2 == 1 and massive[n - 1] % 2 == 0:
        massive[n - 1] = massive[0]
        ans.append((0, n - 1))
        if 0 == n - 1:
            cnt += 1
        flag = True
    else:
        massive[0] = massive[n - 1]
        ans.append((0, n - 1))
        flag = True
        if 0 == n - 1:
            cnt += 1
        

    if massive[0] % 2 == 1 and massive[n - 1] % 2 == 1:
        for i in range(1, n):
            if massive[i] % 2 == 0:
                massive[i] = massive[0]
                ans.append((0, i))
        for i in range(n - 1):
            if flag:
                flag = False
                continue
            if massive[i] != massive[n - 1] and i != n - 1:
                massive[i] = massive[n - 1]
                
                ans.append((i, n - 1))
        print(len(ans) - cnt)
        for x, y in ans:
            # print(x + 1, y + 1)
            if x == y:
                continue
            print(min((x + 1, y + 1)), max(x + 1, y + 1))
            
    else:
        for i in range(1, n):
            if massive[i] % 2 != 0:
                massive[i] = massive[0]
                ans.append((0, i))
        for i in range(n - 1):
            if flag:
                flag = False
                continue
            if massive[i] != massive[n - 1] and i != n - 1:
                massive[i] = massive[n - 1]
                
                ans.append((i, n - 1))
        # print(len(ans))
        print(len(ans) - cnt)
        
        for x, y in ans:
            # print(x + 1, y + 1)
            if x == y:
                continue
            print(min((x + 1, y + 1)), max(x + 1, y + 1))
        
n = int(input())

for _ in range(n):
    solve()