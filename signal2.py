import math
try:
    N = int(input())
    assert(1<=N<10**5)
    lat=[float(x) for x in input().split()]
    lon=[float(x) for x in input().split()]  
    height =[int(x) for x in input().split()]
    count = 0
    jLat,jLon =[float(x) for x in input().split()]
    #equation from geek for geeks
    for i in range(N):
        signalrange = math.sqrt(2*6371*height[i])
        #lat[i] = math.radians(lat[i])
        #jLat = math.radians(jLat)
        #lon[i] = math.radians(lon[i])
        #jLon = math.radians(jLon)
        #dlon = jLon - lon[i]
        #dlat = jLat - lat[i]
        #a = math.sin(dlat / 2)*2 + math.cos(lat[i]) * math.cos(jLat) * math.sin(dlon / 2)*2
        #d = 2 * math.asin(math.sqrt(a)) * 6371
        theta = lon[i] - jLon
        d = math.sin(radians(lat[i])) * math.sin(math.radians(jLat)) + math.cos(math.radians(lat[i])) * math.cos(math.radians(jLat)) * math.cos(math.radians(theta)) 
        d = math.acos(d)
        d = math.degrees(d)
        d = d*60*1.1515*1.609344
        if(signalrange-d>0):
            count+=1
    print(count)
except:
    pass