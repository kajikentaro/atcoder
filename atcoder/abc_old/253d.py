import math
def sum(n, a):
   return (n * a * (n + 1) // 2)
def lcm(a, b):
   g = math.gcd(a, b)
   return a * b // g



[n, a, b] = [int(i) for i in input().split()]
n_sum = sum(n, 1)
a_sum = sum((n // a), a)
b_sum = sum((n // b), b)
ab_sum = sum((n // lcm(a, b)), lcm(a, b))
ans = n_sum - a_sum - b_sum + ab_sum
print(ans)
