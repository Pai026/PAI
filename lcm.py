import math
def lcm (a,b):
    
    gcd = math.gcd(a,b)
    ans = (a*b)//gcd
    return ans

T=int(input())
for case in range(T):
    N=int(input())
    arr  = list(map(int,input().split()))
    arr=[0]+arr
    running_lcm = 1

    repeated_frequencies = [1]*len(arr)
    visited =[False]*len(arr)
    for i in range(1,len(arr)):
        curr_index = i
        if not visited[curr_index]:
            visited[curr_index]=True
            next_index = arr[curr_index]
            while(next_index!=curr_index):
                if not visited[next_index]:
                    visited[next_index] = True
                    next_index = arr[next_index]
                    repeated_frequencies[curr_index]+=1
        running_lcm=lcm(running_lcm,repeated_frequencies[curr_index])
    print(running_lcm)
