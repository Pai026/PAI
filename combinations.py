import itertools
string = input()
char_dict={}
index=0
for char in string:
    if(char in char_dict):
        char_dict[char].append(index)
    else:
        char_dict[char]=[index]
    index+=1
count=0
print(char_dict)
for char in char_dict:
    if(len(char_dict[char])>1):
        occur_list=char_dict[char]
        print()
        print(occur_list)
        occur_pair=list(itertools.combinations(occur_list,2))
        print()
        print(occur_pair)
        for (x,y) in occur_pair:
            print()
            print(x,y)
            sliced=string[x:y+1]
            if(sliced==sliced[::-1]):
                count+=1
print()
print(count)