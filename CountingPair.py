def countingPair(numbers,k):
    numbers=set(numbers)
    numbers=list(numbers)
    count=0
    visitedi=[]
    visitedj=[]
    for i in range(len(numbers)):
        for j in range(i+1,len(numbers)):
            if(((numbers[i]+k) == numbers[j])and ((numbers[i] not in visitedi) or (numbers[j] not in visitedj))):
                visitedi.append(numbers[i])
                visitedj.append(numbers[j])
                count+=1
    return count
n=int(input())
numbers=[]
for i in range(n):
    numbers.append(int(input()))
k=int(input())
print(countingPair(numbers,k))