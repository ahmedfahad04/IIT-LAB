from math import ceil
from pydoc import plain
import AES_ebc as aes_ebc

def hex_to_string(hex_string):
    hex_string = hex(hex_string)[2:]
    
    string = ''
    for i in range(0, len(hex_string), 2):
        string += chr(int(hex_string[i:i+2], 16))
    return string


def string_to_hex(s):
    hex_string = ''   # temp hex string to store hex value as one single string
    # for first char
    h = hex(ord(s[0]))
    hex_string += h

    for i in range(1, len(s)):
        h = hex(ord(s[i]))
        hex_string += h[2:]
        
    return int(hex_string,16)


def xorwithIV(hex_text, IV):

    xored_data = [[]]
    matrix = []

    for row in range(0, 4, 1):
        cell = []

        for col in range(0, 4, 1):

            value = int(hex_text[row][col], 16) ^ int(IV[row][col], 16)
            cell.append(hex(value))

        matrix.append(cell)

    xored_data.append(matrix)
    matrix = []

    return xored_data


def block_to_hex(blocks):
    final_cipher_text = ''

    for block in range(0, len(blocks)):
        for row in range(4):
            for col in range(4):
                final_cipher_text += blocks[block][1][col][row][2:]

    return final_cipher_text


def AES_CTR_ENCRYPT(plaintext, encryption_key, counter):
    number_of_block = ceil(len(plaintext)/16)
    cipher_sets = []

    # breaks IV into BLOCKS of Matrix(hex)
    hex_counter = aes_ebc.text_to_matrix_conversion(counter)
    int_counter = string_to_hex(counter)
    
    # break PLAINTEXT into BLOCKS of Matrix(hex)
    ptext = aes_ebc.text_to_matrix_conversion(plaintext)

    for i in range(1, number_of_block+1):

        temp_cipher = aes_ebc.AES_ECB_ENCRYPT(hex_counter, encryption_key)   # ENCRYPT
        # print(temp_cipher)
        cipher_text = xorwithIV(ptext[i], temp_cipher[1])    # XOR
        
        int_counter += 1
        temp_counter = hex_to_string((int_counter))
        hex_counter = aes_ebc.text_to_matrix_conversion(temp_counter)
        
        cipher_sets.append((cipher_text))

    return cipher_sets


def AES_CTR_DECRYPT(cipher_sets, counter, encryption_key):
    
    number_of_block = ceil(len(cipher_sets))
    
    # breaks IV into BLOCKS of Matrix(hex)
    hex_counter = aes_ebc.text_to_matrix_conversion(counter)
    int_counter = string_to_hex(counter)
    
    plain_text_set = []
    
    for i in range(1, number_of_block+1):

        temp_cipher = aes_ebc.AES_ECB_ENCRYPT(hex_counter, encryption_key)   # ENCRYPT
        cipher_text = xorwithIV(temp_cipher[1], cipher_sets[i-1][1])    # XOR
        
        int_counter += 1
        temp_counter = hex_to_string((int_counter))
        hex_counter = aes_ebc.text_to_matrix_conversion(temp_counter)
        
        plain_text_set.append(aes_ebc.hex_to_text(cipher_text))
        
    ans =  "".join(plain_text_set)

    return ans


if __name__ == '__main__':

    inputtext = ''
    encryption_key = "Thats my Kung Fu"
    counter = "Thats my Kung Fu"

    with open("cinput.txt", "r") as f:
        inputtext = f.read()
    f.close()

    cipherText = AES_CTR_ENCRYPT(inputtext, encryption_key, counter)
    # print(cipherText[1][1])
    decryptText = AES_CTR_DECRYPT(cipherText, encryption_key, counter)
    
    print("\nCIPHER (CBC):", block_to_hex(cipherText))
    print("\nPLAINTEXT:",  decryptText)
