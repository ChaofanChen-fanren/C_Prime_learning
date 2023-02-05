def str_reverse(s):
    l,u,n,o = 0,0,0,0
    for c in s:
        if c.isupper():
            u = u + 1
        elif c.islower():
            l = l + 1
        elif c.isdigit():
            n = n + 1
        else:
            o = o + 1
    return ("reverse str: "+ s[::-1],"lowercases: "+str(l),"uppercases: "+str(u),\
            "numbers: "+str(n),"other characters: "+str(o))
        
            
res = str_reverse("AaBb1234  &")
for temp in res:
    print(temp)
