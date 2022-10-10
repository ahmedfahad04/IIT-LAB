from math import ceil
import AES_ebc as aes_ebc


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


def AES_CBC_ENCRYPT(plaintext, encryption_key):
    number_of_block = ceil(len(plaintext)/16)
    cipher_sets = []

    # breaks IV into BLOCKS of Matrix(hex)
    IV = aes_ebc.text_to_matrix_conversion("Thats my Kung Fu")
    # break PLAINTEXT into BLOCKS of Matrix(hex)
    ptext = aes_ebc.text_to_matrix_conversion(plaintext)

    for i in range(1, number_of_block+1):

        xored_plain_text = xorwithIV(ptext[i], IV[1])    # XOR
        cipher_text = aes_ebc.AES_ECB_ENCRYPT(xored_plain_text, encryption_key)   # ENCRYPT
        IV = cipher_text    # REPLACE IV

        cipher_sets.append((cipher_text))

    return cipher_sets


def AES_CBC_DECRYPT(cipher_sets):
    IV = aes_ebc.text_to_matrix_conversion("Thats my Kung Fu")
    number_of_block = ceil(len(cipher_sets))
    plainText_set = []

    for i in range(0, number_of_block):
        decrypted_plain_text = aes_ebc.AES_ECB_DECRYPT(cipher_sets[i])

        if i == 0:
            final_plain_text = xorwithIV(decrypted_plain_text[1], IV[1])

        else:
            IV = cipher_sets[i-1]
            final_plain_text = xorwithIV(decrypted_plain_text[1], IV[1])

        plainText_set.append(aes_ebc.hex_to_text(final_plain_text))

    final_plain_text = "".join(plainText_set)

    return final_plain_text


if __name__ == '__main__':

    inputtext = ''
    encryption_key = "Thats my Kung Fu"

    with open("cinput.txt", "r") as f:
        inputtext = f.read()
    f.close()

    cipherText = AES_CBC_ENCRYPT(inputtext, "Thats my Kung Fu")
    decryptText = AES_CBC_DECRYPT(cipherText)
    
    print("\nCIPHER (CBC):", block_to_hex(cipherText))
    print("\nPLAINTEXT:", decryptText)

