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
ror=lambda x,y :((x >> y) | (x << (64-y))) & 0xFFFFFFFFFFFFFFFF
def shr(n, d): return n >> d
def sigma_0(x): return ror(x, 1) ^ ror(x, 8) ^ shr(x, 7)
def sigma_1(x): return ror(x, 19) ^ ror(x, 61) ^ shr(x, 6)
def sigma_a(x): return ror(x, 28) ^ ror(x, 34) ^ ror(x, 39)

def ch(x, y, z): return (x & y) ^ ((~x) & z)
def maj(x, y, z): return (x & y) ^ (x & z) ^ (y & z)

# print((bin(ror(0b1011, 4))))
# print(len(hex(sigma_1(0b1011))))

a = hex(95)
print(a)
print(bin(95))
