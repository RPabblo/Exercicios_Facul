import pandas as pd
import matplotlib.pyplot as plt

x = list()
y = list()

x = [35.6, 59, 25.2, 22.5, 24.41]
y = [12.7, 29.4, 8.6, 8.3, 12.4]

sum_xi_yi = 0
produto_sum_xi_yi = 0
sum_xi_2 = 0
sum_2_xi = 0

# Equação da reta: y = ax + b + e, sendo e a margem de erro.

for(xi, yi) in zip(x, y):
    sum_xi_yi = sum_xi_yi + xi * yi

for xi in x:
    sum_xi_2 = sum_xi_2 + xi * xi

sum_2_xi = (sum(x)) * (sum(x))
produto_sum_xi_yi = sum(x) * sum(y)

n = len(x)

a = (n * sum_xi_yi - sum(x) * sum(y)) / (n * sum_xi_2 - sum_2_xi)

b = sum(y) / len(y) - a * sum(x) / len(x)

if b >= 0:
    print(f'Y = {a:.2f}X + {b:.2f}')
else:
    print(f'Y = {a:.2f}X - {abs(b):.2f}')

lista = list(range(1, 1001))

plt.bar(1000, lista)
plt.show()
