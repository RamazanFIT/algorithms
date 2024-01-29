def spygame(num):
    word007 = ""
    for i in num:
        word007 += str(i)
    if word007.find('007') != -1:
        return True
    else:
        return False 

someList = list(map(int, input().split()))

answer = bool(spygame(someList))

print(answer)



