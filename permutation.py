import itertools
getInput= list(map(int,input().split(" ")))
print(getInput)
result=[]
for i in itertools.permutations(getInput,len(getInput)):
    result.append("".join(map(str,i)))
print(max(result))
