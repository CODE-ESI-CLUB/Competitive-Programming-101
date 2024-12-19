def find_lw7dani(inv):
    counts = {}
    for i in inv:
        if i in counts:
            counts[i]+=1
        else:
            counts[i]=1
    
    for i,c in counts.items():
        if c==1:
            return i
        
n = int(input())

for i in range(1,n+1):
    G = int(input())
    inv = list(map(int,input().split()))
    lw7dani = find_lw7dani(inv)
    print(f"Case #{i}: {lw7dani}")