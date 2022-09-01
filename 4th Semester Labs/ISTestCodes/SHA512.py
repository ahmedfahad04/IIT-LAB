def ror(n, d): return format((n >> d) | (n << (64 - d)), '016x')[-16:]
def shr(n, d): return n >> d


def sigma_0(x): return int(ror(x, 1), 16) ^ int(ror(x, 8), 16) ^ shr(x, 7)
def sigma_1(x): return int(ror(x, 19), 16) ^ int(ror(x, 61), 16) ^ shr(x, 6)
def sigma_a(e): return int(ror(e, 28), 16) ^ int(ror(e, 34), 16) ^ int(ror(e, 39), 16)


def ch(e: int, f: int, g: int) -> int: return ((e & f) ^ ((~e) & g))
def maj(a: int, b: int, c: int) -> int: return (a & b) ^ (a & c) ^ (b & c)

# =======================================================
# ===================== VARIABLES =======================
# =======================================================

msg = "abc"
msg_len = 0
binary_content = ""
hex_content = ""
m_blocks = []

# =======================================================
# ===================== CONSTANTS =======================
# =======================================================

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

# =======================================================
# ======================= PADDING =======================
# =======================================================

# converting msg to string representation and calculating msg length
for i in msg:
    binary = format(ord(i), '08b')
    msg_len += len(binary)
    binary_content += (binary)

# calculating padding and adding 1
needed_msg_len = 896 - (msg_len % 1024)
binary_content += "1"

# adding padding using 0's
for i in range(needed_msg_len-1):
    binary_content += "0"

# converting binary to hex
for i in range(0, len(binary_content), 4):
    hex_content += hex(int(binary_content[i:i+4], 2))[2:]

# adding length of msg in binary
hex_content += format(msg_len, '032x')

# print(len(hex_content)*4)
# print(hex_content)

# splitting hex content into blocks of 1024 bits
id = 0
tmp_size = len(hex_content)*4

while True:
    m_blocks.append(hex_content[id*1024:(id+1)*1024])
    tmp_size -= 1024

    if tmp_size <= 0:
        break

# ==================================================================
# ======================= INSIDE F BLOCK ===========================
# ==================================================================

# working on each block of 1024 bits
for block in m_blocks:
    w = []

    # splitting block into 80 words of 64 bits
    for i in range(80):

        if i < 16:
            w.append(block[i*16:(i+1)*16])

        else:

            value = format( (sigma_0(int(w[i-15], 16)) + int(w[i-16], 16) + sigma_1(int(w[i-2], 16)) + int(w[i-7], 16)), '016x')
            
            # if i >=16 and i<40:
            #     print(i-15, format(sigma_0(int(w[i-15], 16)), '016x'))
            #     print(i-16, format(int(w[i-16], 16), '016x'))
            #     print(i-2, format(sigma_1(int(w[i-2], 16)), '016x'))
            #     print(i-7, format((int(w[i-7], 16)), '016x'))
            
            w.append(value)
            

    # round calculations
    for i in range(80):

        T1 = h + int(ch(e, f, g), 16) + int(w[i], 16) + k[i]
        T2 = sigma_a(e) + maj(a, b, c)
        
        print(bin(int(w[i], 16) ))
        a = (T1 + T2)
        b = a
        c = b
        d = c
        e = d + T1
        f = e
        g = f
        h = g

        # print("IA: ", ia)
        # print("A : ", a)
        # print("T1: ", T1, "Type: ", type(T1))
        # print("T1: ", T2, "Type: ", type(T2))
        # print("E :", e, "Type: ", type(e))
        # print(format((T1+T2), '016x'), "LEN: ", len(format((T1+T2), '016x')))
    
    ia = hex(a+ia)
    ib = hex(b+ib)
    ic = hex(c+ic)
    id = hex(d+id)
    ie = hex(e+ie)
    if_ = hex(f+if_)
    ig = hex(g+ig)
    ih = hex(h+ih)

# ia = format(ia, '08x')
# ib = format(ib, '08x')
# ic = format(ic, '08x')
# id = format(id, '08x')
# ie = format(ie, '08x')
# if_ = format(if_, '08x')
# ig = format(ig, '08x')
# ih = format(ih, '08x')
print(int(ia,16))