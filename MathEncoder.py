import itertools
T=int(input())
for _ in range(0,T):
    n=int(input())
    l=list(map(int,input().split()))
    diff=0
    for i in range(2,len(l)+1):
        k=list(itertools.combinations(l,i))
        for j in range(len(k)):
            diff=diff+k[j][len(k[j])-1]-k[j][0]
    print(diff%(pow(10,9)+7))