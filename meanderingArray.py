def meanderingArray(unsorted):
    sortedArray=[]
    while(len(unsorted)>1):
        unsorted.sort()
        max1,min1=unsorted.index(max(unsorted)),unsorted.index(min(unsorted))
        print(max1,min1)
        sortedArray.append(max(unsorted))
        sortedArray.append(min(unsorted))
        unsorted.pop(max1)
        unsorted.pop(min1)
    if(len(unsorted)==1):
        sortedArray.append(unsorted[0])
    return sortedArray

n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
print(l)
print(meanderingArray(l))