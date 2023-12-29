import random
n = int(input())

def get(a):
    a = str(a)
    ret = 0
    for i in a:
        ret += int(i)
    return ret
big = 10 ** 30
for _ in range(n):
    a, b = map(int, input().split())
    if(get(a) % 9 != get(b) % 9):
        print("NO")
    else:
        k = random.randint(0, big)
        while True:
            if(get(a + k) == get(b + k)):
                print("YES", k)
                break
            k = random.randint(0, big)
            
    