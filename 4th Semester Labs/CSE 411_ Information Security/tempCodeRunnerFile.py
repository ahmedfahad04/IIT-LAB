table = [
    [
        2, 3, 1, 1,
        1, 2, 3, 1,
        1, 1, 2, 3,
        3, 1, 1, 2
    ]
]

matrix = [
    [
        0x63, 0xEB, 0x9F, 0xA0,
        0x2F, 0x6E, 0x69, 0x54,
        0xAF, 0x65, 0x6E, 0x77,
        0xA2, 0x20, 0x65, 0x6F
    ]
]
c = 0
r = 1

ans = 0
for i in range(4):
  
    a = matrix[0][i*4+c]
    b = table[0][r*4+i]
    
    print(hex(a), '--', b)
    
    if b == 3:
        temp = hex((int(format(a, '02x'), 16) * (int(format(b-1, '02x'), 16)))^int(format(a, '02x'), 16))
    else:
        temp = hex(int(format(a, '02x'), 16) * int(format(b, '02x'), 16))
        
    print(temp)
    ans ^= int(temp, 16)

if len(format(ans, '02x')) == 3:
    print(hex(ans)[3:])
else:
    print(hex(ans))
    
    
    
    
# for row in range(4):
#     for col in range(4):
#         print(table[0][row*4+col])


# print(format(table[0][0], '08b')*format(matrix[0][0], '08b'))

# print(format(matrix[0][0], '08b'))
# print(type(format(matrix[0][0], '02x')) , 'and', type(hex(table[0][0])))
# print(hex(int(format(matrix[0][0], '02x'), 16) * int(format(table[0][0], '02x'), 16)))
