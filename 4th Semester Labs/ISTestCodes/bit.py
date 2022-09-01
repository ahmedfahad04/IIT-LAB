# def rotateRight(n, d,):

#     c = (n >> d) | (n << (32 - d))
#     return c

# ror = lambda n, d: format((n >> d) | (n << (64 - d)), '064x')[-64:]
# shr = lambda n, d: n << d
# sigma_0 = lambda x: int(ror(x, 1), 16) ^ int(ror(x, 8),16) ^ shr(x, 7)


# def shiftLeft(n, d):
    
#     c = (n << d)
#     return c 

# n = int(input())
# d = int(input())

# x = ror(n, d)
# print(format(n, '064x'))
# # print(n)
# print("M: ", x)
# # print("Modified HEX: ", hex(int(x, 2)))
# # print(int(x,2))
# print("S: ", (format(sigma_0(n), '064x')))
def ror(n, d): return format((n >> d) | (n << (64 - d)), '016x')[-16:]
def shr(n, d): return n >> d
def sigma_1(x): return int(ror(x, 19), 16) ^ int(ror(x, 61), 16) ^ shr(x, 6)
print(ror(11, 1))