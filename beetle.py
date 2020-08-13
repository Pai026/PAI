import math
t= int(input())
m=list(map(int,input().split(',')))
k=[m[i:i+t]for i in range(0,len(m),t)]
distance=0
for i in range(1,len(k)):
    if(k[i][2]==k[i-1][2]):
        distance = 1.05
    else:
        x1,y1,z1,x2,y2,z2 = k[i-1][0],k[i-1][1],k[i-1][2],k[i][0],k[i][1],k[i][2]
        distance+=math.ceil(math.sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2)))
print(distance)