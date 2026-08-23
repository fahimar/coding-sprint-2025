n = int(input())
p = {}

for _ in range(n):
    x = int(input())
    p[x] = p.get(x,0)+1
    
customers = 0

max_val = 0

for price in sorted(p, reverse = True):
    customers += p[price]
    
    revenue = price * customers
    
    max_val = max(max_val, revenue)
    
print(max_val)