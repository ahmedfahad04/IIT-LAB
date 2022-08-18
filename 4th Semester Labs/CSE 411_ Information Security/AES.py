from os import stat
import pprint

s_box = [
    [0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
     0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
     0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
     0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
     0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
     0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
     0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
     0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
     0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
     0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
     0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
     0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
     0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
     0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
     0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
     0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
     ]
]


# key expansion should be performed

key = [
    [
        0x54, 0x4F, 0x4E, 0x20,
        0x77, 0x6E, 0x69, 0x54,
        0x6F, 0x65, 0x6E, 0x77,
        0x20, 0x20, 0x65, 0x6F
    ]
]

def swap (x,y):
    t = x
    x = y
    y = t
    
    return x , y


def text_to_matrix_conversin(data):
    
    input_matrix = [[]]
    matrix = []

    letter = 0
    initial_value = 0
    temp = 0
    for i in range(0, len(data), 16):
        for row in range(0, 4, 1):
            cell = []
            inital_value = i    # helps to create the 2nd list of the matrix
            temp = i            # helps to insert element coloumn wise

            for col in range(0, 4, 1):

                if i < len(data):
                    cell.append(hex(ord(data[i])))
                else:
                    cell.append(hex(ord('Z')))
                i += 4

                # print('[', row, ']', '[', col, '] = ', chr(int(cell[col],16)))

            matrix.append(cell)
            temp += 1
            i = temp

        input_matrix.append(matrix)
        matrix = []

        i = inital_value

    return input_matrix


def add_round_key(input_matrix):

    matrix = []
    final_matrix = [[]]

    letter = 0
    initial_value = 0
    k = 1
    for i in range(0, (len(input_matrix)-1)*16, 16):
        for row in range(0, 4, 1):
            cell = []
            inital_value = i    # helps to create the 2nd list of the matrix (repressents a single blocks of 16bits)

            for col in range(0, 4, 1):

                value = int(input_matrix[k][row][col][2:], 16) ^ key[0][(row) * 4 + (col)]
                cell.append(hex(value))
                i += 4

            matrix.append(cell)
            # print()

        final_matrix.append(matrix)
        matrix = []
        k += 1
        i = inital_value
        # print()

    return final_matrix


def shift_rows(state_matrix):
    
    for i in range(1, len(state_matrix),1):
        for row in range(0,4,1):
            for col in range(0,3,1):
                
                if row == 0: continue
                
                elif row == 1:
                    a = state_matrix[i][row][col]
                    b = state_matrix[i][row][col+1]
                    state_matrix[i][row][col], state_matrix[i][row][col+1] = swap(a,b)
                    
                elif row == 2 and col < 2:
                    a = state_matrix[i][row][col]
                    b = state_matrix[i][row][col+2]
                    state_matrix[i][row][col], state_matrix[i][row][col+2] = swap(a,b)
                    
                elif row == 3:
                    a = state_matrix[i][row][col]
                    b = state_matrix[i][row][3]
                    state_matrix[i][row][col], state_matrix[i][row][3] = swap(a,b)
                                
    return state_matrix                
    

def substitution_bytes(input_matrix):
    matrix = []
    state_matrix = [[]]

    # calculate the final state matrix
    k = 1
    for i in range(0, (len(input_matrix)-1)*16, 16):
        for row in range(0, 4, 1):
            cell = []
            inital_value = i    # helps to create the 2nd list of the matrix
            temp = i            # helps to insert element coloumn wise

            for col in range(0, 4, 1):

                cell_value = input_matrix[k][row][col]

                char_value = str(bin(int(cell_value, 16)))[2:]
                char_value = char_value.rjust(8, '0')

                # retrieving the row and col valus from the INPUT MATRIX
                nrow = int(char_value[0:4], 2)

                ncol = int(char_value[4:8], 2)

                # access the following row and col value in S-box
                new_cell_value = hex(s_box[0][(nrow) * 16 + (ncol)])

                # now adding the calculated value in state matrix, this is the 1st list
                cell.append(new_cell_value)

                i += 4

            # this is 2nd list
            matrix.append(cell)
            temp += 1
            i = temp

        # this is the 3rd and final list
        state_matrix.append(matrix)
        matrix = []
        i = inital_value
        k += 1

    return state_matrix


if __name__ == '__main__':
    
    # list/array initialization
    st_matrix = [[]]
    initial_matrix = [[]]
    round_key = [[]]

    # plain text input
    text = "Thats my Kung Fu"
    print("\nDATA: ", text, end='\n\n')

    
    initial_matrix = text_to_matrix_conversin(text)
    print("INITIAL MATRIX....")
    pprint.pprint(initial_matrix)
    
    round_key = add_round_key(initial_matrix)
    print("\nROUND KEY....")
    pprint.pprint(round_key)
        
    st_matrix = substitution_bytes(round_key)
    print("\nSUBSTITUTION BYTES....")
    pprint.pprint(st_matrix)
    
    st_matrix = shift_rows(st_matrix)
    print("\nSHIFT ROWS....")
    pprint.pprint(st_matrix)
    

    
