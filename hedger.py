import math
try:
    N,K,A = list(map(int,input().split()))
    assert(0 <= A <= 10**6)
    assert(1 <= K <= 100)
    assert(1 <= N <= 10**4)
    stocks = list(map(float,input().split()))
    profitPercentage = list(map(float,input().split()))
    profit = 0
    for i in range(0,K):
        index = profitPercentage.index(max(profitPercentage))
        
        if(i==K-1):
            K=K-1
        profit+=K*((stocks[index]*profitPercentage[index])/100)
        stocks.remove(stocks[index])
    
        profitPercentage.remove(profitPercentage[index])
    
    print(math.floor(profit))
except:
    pass