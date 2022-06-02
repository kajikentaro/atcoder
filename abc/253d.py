import math
def sum( n,  a):
   return math.floor(n * a * (n + 1) / 2)


[n, a, b] = [int(i) for i in input().split()]
n_sum = sum(n, 1)
a_sum = sum(math.floor(n / a), a)
b_sum = sum(math.floor(n / b), b)
ab_sum = sum(math.floor(n / (a * b)), a * b)
ans = n_sum - a_sum - b_sum + ab_sum
print(ans)