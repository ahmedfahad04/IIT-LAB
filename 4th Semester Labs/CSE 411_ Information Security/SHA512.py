ror=lambda x,y :((x >> y) | (x << (64-y))) % 2**64
def shr(n, d): return n >> d

def sigma_0(x) -> int: return ror(x, 1) ^ ror(x, 8) ^ shr(x, 7)
def sigma_1(x) -> int: return ror(x, 19) ^ ror(x, 61) ^ shr(x, 6)
def sigma_a(x) -> int: return ror(x, 28) ^ ror(x, 34) ^ ror(x, 39)

def ch(x, y, z) -> int: return (x & y) ^ ((~x) & z)
def maj(x, y, z) -> int: return (x & y) ^ (x & z) ^ (y & z)

msg = ""
m_blocks = []

ia = a = 0x6a09e667f3bcc908
ib = b = 0xbb67ae8584caa73b
ic = c = 0x3c6ef372fe94f82b
id = d = 0xa54ff53a5f1d36f1
ie = e = 0x510e527fade682d1
if_ = f = 0x9b05688c2b3e6c1f
ig = g = 0x1f83d9abfb41bd6b
ih = h = 0x5be0cd19137e2179

k = [0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538,
     0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe,
     0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
     0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
     0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab,
     0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
     0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,
     0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
     0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
     0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
     0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373,
     0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
     0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c,
     0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6,
     0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
     0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817]

def take_input():
    global msg
    
    with open("input.txt", 'r') as f:
        msg = f.read()
    f.close()

def pad_message():
    
    msg_len = 0
    binary_content = ""
    hex_content = ""

    # converting msg to string representation and calculating msg length
    for i in msg:
        binary = format(ord(i), '08b')
        msg_len += len(binary)
        binary_content += (binary)

    # calculating pad_message and adding 1
    needed_msg_len = 896 - (msg_len % 1024)
    binary_content += "1"

    # adding pad_message using 0's
    for i in range(needed_msg_len-1):
        binary_content += "0"

    # converting binary to hex
    for i in range(0, len(binary_content), 4):
        hex_content += hex(int(binary_content[i:i+4], 2))[2:]

    # adding length of msg in binary
    hex_content += format(msg_len, '032x')

    print("Message: " + msg)
    # print("Message Length (in bits):",len(hex_content)*4)

    # splitting hex content into blocks of 1024 bits
    id = 0
    tmp_size = len(hex_content)*4

    while True:
        m_blocks.append(hex_content[id*1024:(id+1)*1024])
        tmp_size -= 1024

        if tmp_size <= 0:
            break

def split_into_words(block, word):
    
    # splitting block into 80 words of 64 bits
    for i in range(80):

        if i < 16:
            word[i]= (int((block[i*16:(i+1)*16]), base=16) % 2**64) 
            
        else:
            value = ((sigma_0(word[i-15]) + word[i-16] + sigma_1(word[i-2]) + word[i-7]) % 2**64)
            word[i] = (value)     
    
def round_calculations(word):
    
    global a, b, c, d, e, f, g, h
    global ia, ib, ic, id, ie, if_, ig, ih
    
    # round calculations
    for i in range(80):

        T1 = h + ch(e, f, g) + word[i]+ k[i]
        T2 = sigma_a(e) + maj(a, b, c)
                
        a = ((T1 + T2) % 2**64 )
        b = a
        c = b
        d = c
        e = ((d + T1) % 2**64) 
        f = e
        g = f
        h = g
        
    # finally add the newly derived vectors with inital vectors
    ia = (b+ia) % 2**64 
    ib = (b+ib) % 2**64 
    ic = (c+ic) % 2**64
    ia = (a+ia) % 2**64 
    id = (d+id) % 2**64
    ie = (e+ie) % 2**64
    if_ = (f+if_) % 2**64
    ig = (g+ig) % 2**64
    ih = (h+ih) % 2**64
    
def calculate_f_block():

    # working on each block of 1024 bits
    for block in m_blocks:
        w = [0]*80

        split_into_words(block, w)
        round_calculations(w)
        
def message_digest():
    
    global a, b, c, d, e, f, g, h
    global ia, ib, ic, id, ie, if_, ig, ih 
    
    ia = hex(ia)[2:]
    ib = hex(ib)[2:]
    ic = hex(ic)[2:]
    id = hex(id)[2:]
    ie = hex(ie)[2:]
    if_ = hex(if_)[2:]
    ig = hex(ig)[2:]
    ih = hex(ih)[2:]

    message_digest = str((ia) + (ib) + (ic) + (id) + (ie) + (if_) + (ig) + (ih))

    return message_digest

if __name__ == '__main__':

    take_input()
    pad_message()
    calculate_f_block()
    hash_value = message_digest()
    
    print("Hex Value:", hash_value)
    
    