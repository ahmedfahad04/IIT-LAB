

# # Function to fill the matrix with the hex values of given data;
# letter = 0
# for i in range(0,len(data),16):
#     for row in range(0, 4, 1):
#         cell = []
        
#         for col in range(0, 4, 1):

#             if i < len(data):
#                 cell.append(hex(ord(data[i])))
#             else:
#                 cell.append(hex(ord('Z')))
#             i += 1
#             # print("I: ", i)
#             # print('[', row, ']', '[', col, '] = ', chr(int(cell[col],16)))

#         matrix.append(cell)
        
#     input_matrix.append(matrix)
#     matrix = []
            

# print("INITIAL MATRIX....")
# # for i in range(1, len(input_matrix)):
# #     for row in range(0, 4, 1):
# #         for col in range(0, 4, 1):
            
# #             # swapping the rows and columns to implement transponse of input matrix
            
# #             swap(input_matrix[i][row][col], input_matrix[i][col][row])
                
# #             # print(row,col, " ", end='')
# #             # print(matrix[row][col], " ", end='')   

# #         # print()

# for i in range(1, len(input_matrix)):
#     for row in range(0, 4, 1):
#         for col in range(0, 4, 1):
            
#             val = chr(int(input_matrix[i][row][col],16))
#             print(val, " ", end='')

#         print()
#     print()
             
        
# print("\nSTATE MATRIX....")
# # letter = 0
# for i in range(1, len(input_matrix)):
#     for row in range(0, 4, 1):
       
#         for col in range(0, 4, 1):
#             cell_value = input_matrix[i][row][col]
#             char_value = bin(int(cell_value, 16))
            
#             # retrieving the row and col valus from the INPUT MATRIX
#             nrow = int(char_value[2:5], 2)
#             ncol = int(char_value[5:10], 2)
            
#             # access the following row and col value in S-box
#             new_cell_value = hex(s_box[0][(nrow)*16+(ncol)])

#             print(new_cell_value," ", end=' ')

#         print()
        
#     print()

#         # print(char_value, ">> ", nrow, 'and', ncol , end='---')
