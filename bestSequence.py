inputString = input().strip(' ')
damagedChar = list(map(str,input().split()))
length = int(len(damagedChar))
a=[]
flag=0
stringToCheck = [inputString[i:i+length] for i in range(0,len(inputString),length)]
string1 = [damagedChar[i] for i in range(0,len(damagedChar))]
for i in  stringToCheck:
    if(sorted(i)==sorted(string1)):
        a.append(i)
print(min(a))