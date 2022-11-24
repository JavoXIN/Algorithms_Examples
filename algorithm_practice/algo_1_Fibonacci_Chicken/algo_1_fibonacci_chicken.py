from math import sqrt, log, floor
phi = (1 + sqrt(5)) / 2
phi_sec = 1 - phi
def Func_of_Binet(i):
    return round((phi ** i - phi_sec ** i) / sqrt(5))
def inverse_fibo(N):
    return round(log(sqrt(5) * N) / log(phi))
def is_perfect(n):
    rootn = floor(sqrt(n))
    return True if rootn * rootn == n else False
def is_fibo(N):
    x, y = 5 * N * N + 4, 5 * N * N - 4
    return is_perfect(x) or is_perfect(y)
def FibonaChicken(N):
    if N <= 2:
        return 1
    i = inverse_fibo(N)
    if is_fibo(N):
        return Func_of_Binet(i - 1)
    else:
        while N > Func_of_Binet(i):
            i += 1
        return Func_of_Binet(i - 2) + FibonaChicken(N - Func_of_Binet(i - 1))

N = int(input(""))
C = FibonaChicken(N)
print("{}".format(C))
