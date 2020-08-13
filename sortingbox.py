n,k = input().split()
n,k = int(n),int(k)
k=k-1
flag=0
l=list(map(int,input().split()))
effort = 2*l[k]*min(l)+max(l)*min(l)
l.remove(l[k])
z=min(l)

l.remove(max(l))
l1=l[:]
l1.sort()
if(l1!=l):
    print(l1[0],l[0])
    effort+=2*min(l1)*l1[len(l1)-2]+max(l1)*min(l1)
    if(l1[0]!=l[0]):
        effort+=l1[0]*l[0]

print(effort)