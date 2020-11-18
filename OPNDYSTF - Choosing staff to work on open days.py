def fact(n):
    sum = 1
    for i in range(1,n+1):
        sum = sum*i

    return sum

x = input().split()

n = int(x[0])
m = int(x[1])


sum  = fact(n)
a = fact(m)
b = fact(n-m)

total = float(float(sum/b)/a)

total = int(total)

print(total)
