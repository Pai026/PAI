import math
try:
    N = int(input())
    assert(1<=N<10**5)
    latitude=[float(x) for x in input().split()]
    longitude=[float(x) for x in input().split()]  
    height =[int(x) for x in input().split()]
    count = 0
    jasonLatitude,jasonLongitude =[float(x) for x in input().split()]
    #formula from geek for geeks
    for i in range(N):
        broadcastdistance = math.sqrt(2*6371*height[i])
        phi1 = math.radians(latitude[i]) 
        phi2 = math.radians(jasonLatitude) 
        tetaPhi = math.radians(jasonLatitude-latitude[i])
        tetaLambda = math.radians(jasonLongitude-longitude[i])
        a = math.pow(math.sin(tetaPhi/2),2)+math.cos(phi1)*math.cos(phi2)*math.pow(math.sin(tetaLambda/2),2)
        c = 2*math.asin(math.sqrt(a))
        d = 6371*c
        if(broadcastdistance>=d):
            count+=1
    print(count)
except:
    pass