from collections import deque
MOD = 998244353
n = 10 ** 5

fact = [1]
for i in range(1, n + 1):
    fact.append(fact[-1] * i % MOD)

inv_fact = deque([pow(fact[n], -1, MOD)])
for i in range(n - 1, -1, -1):
    inv_fact.appendleft(inv_fact[0] * (i + 1) % MOD)
inv_fact = list(inv_fact)
