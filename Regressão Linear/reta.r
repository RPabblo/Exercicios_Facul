# Equação da reta linear em R
x = c(35.6, 59, 25.2, 22.5, 24.41)
y = c(12.7, 29.4, 8.6, 8.3, 12.4)

sum_xi_yi = sum(x * y)

sum_x_x = sum(x * x)

produto_sum_xi_yi = sum(x) * sum(y)

sum_2_x = sum(x) * sum(x)

n = length(x)

a = (n * sum_xi_yi - sum(x) * sum(y)) / (n * sum_x_x - sum_2_x)

b = sum(y) / length(y) - a * sum(x) / length(x)

a
b
