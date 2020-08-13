def dcrItemDict(itemName,qty):
    diff = itemDict[itemName]-qty
    if(diff<=0):
        del itemDict[itemName]
    else:
        itemDict[itemName]=diff

def incItemDict(itemName,qty):
    if(itemName not in itemDict):
        itemDict[itemName]=itemDict.get(itemName,0)+qty
    else:
        itemDict[itemName]+=qty
        

def checkItemDict(itemName,qty):
    if(itemDict[itemName]>=qty):
        
        return True
    else:
        return False
try:
    T=int(input())
    assert(1<=T<=10)
    for _ in range(T):
        itemDict={}
        costDict={}
        cartDict={}
        items = ['SHIRT','SHOE']
        users = ['SM','S']
        while True:
            inputLine = input().split()
            if(inputLine[0]=="END" or inputLine[0]=="CMD"):
                if(inputLine[0] == "END"):
                    break
                user = inputLine[1]
                if(user not in users):
                    print(-1)
                else:
                    command = inputLine[2]
                    if(command not in ['ADD','REMOVE','GET_QTY','INCR','SET_COST','DCR','GET_ORDER_AMOUNT']):
                        print(-1)
                    if(user == 'SM'):
                        if(command == 'ADD'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                itemQty = int(inputLine[4])
                            # assert(itemQty>0)
                                if(itemName in itemDict or itemQty<=0):
                                    print(-1)
                                else:
                                    itemDict[itemName]=itemDict.get(itemName,0)+itemQty
                                    print(itemQty)
                        
                        if(command == 'REMOVE'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                if(itemName in itemDict):
                                    del itemDict[itemName]
                                    print(1)
                                else:
                                    print(-1)
                            
                        if(command == 'GET_QTY'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                if(itemName in itemDict):
                                    print(itemDict[itemName])
                                else:
                                    print(0)
                        
                        if(command == 'INCR'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                itemQty =int(inputLine[4])
                                #assert(itemQty>0)
                                if(itemName in itemDict and itemQty>0):
                                    itemDict[itemName]+=itemQty
                                    print(itemQty)
                                else:
                                    print(-1)
                        
                        if(command == 'DCR'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                itemQty = int(inputLine[4])
                                #assert(itemQty>0)
                                if(itemName in itemDict and itemQty>0):
                                    if(itemDict[itemName]-itemQty<=0):
                                        del(itemDict[itemName])
                                        print(itemQty)
                                    else:
                                        itemDict[itemName]-=itemQty
                                        print(itemQty)
                                else:
                                    print(-1)
                        
                        if(command == 'SET_COST'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                itemCost = float(inputLine[4])
                                #assert(itemCost>0)
                                if(itemCost<=0):
                                    print(-1)
                                else:
                                    costDict[itemName]=costDict.get(itemName,0)+itemCost
                                    print(format(itemCost,'.1f'))

                    elif(user == 'S'):
                        if(command == 'ADD'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                itemQty = int(inputLine[4])
                                #assert(itemQty>0)
                                if(itemName not in itemDict or itemQty<=0):
                                    print(-1)
                                else:
                                    if(itemName in cartDict):
                                        print(-1)
                                    else:
                                        if(checkItemDict(itemName,itemQty)):
                                            cartDict[itemName]=cartDict.get(itemName,0)+itemQty
                                            print(itemQty)
                                            dcrItemDict(itemName,itemQty)
                                        else:
                                            print(-1)

                        if(command == 'REMOVE'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                if(itemName in cartDict):
                                    del cartDict[itemName]
                                    print(1)
                                else:
                                    print(-1)

                        if(command == 'INCR'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                itemQty = int(inputLine[4])
                                #assert(itemQty>0)
                                if(itemName not in itemDict or itemQty<=0):
                                    print(-1)
                                else:
                                    if(itemName in cartDict):
                                        if(checkItemDict(itemName,itemQty)):
                                            cartDict[itemName]+=itemQty
                                            print(itemQty)
                                            dcrItemDict(itemName,itemQty)
                                        else:
                                            print(-1)
                                    else:
                                        print(-1)
                        
                        if(command == 'DCR'):
                            itemName = inputLine[3]
                            if(itemName not in items):
                                print(-1)
                            else:
                                itemQty = int(inputLine[4])
                                #assert(itemQty>0)
                                if(itemName in cartDict and itemQty>0):
                                    diff = cartDict[itemName]-itemQty
                                    print(itemQty)
                                    incItemDict(itemName,itemQty)
                                    if(diff<=0):
                                        del cartDict[itemName]
                                    else:
                                        cartDict[itemName] =diff
                                else:
                                    print(-1)
                        
                        if(command == 'GET_ORDER_AMOUNT'):
                            amount = 0
                            for i in cartDict:
                                if(i in costDict):
                                    amount+=cartDict[i]*costDict[i]
                                else:
                                    print(-1)
                                    break
                            print(format(amount,'.2f'))
            else:
                print(-1)
except:
    print(-1)


