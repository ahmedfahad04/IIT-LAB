# generate table
from ctypes.wintypes import PINT
from gettext import lngettext


upperCase = dict()
lowerCase = dict()
start = '\0'
length = 127
column = 10

def generateTable(start, size, column):
    k = 0
    ch = start
    
    for i in range(0, size, 1):
        
        key = chr(ord(start) + i)
        tmp = []
        
        for j in range(1, column+1, 1):
            tmp.append(ch)
            ch = chr((ord(ch) + 1)%127)
        
        upperCase[key] = tmp
        key = chr((ord(key) + 1)%127)
        ch = key 
        

    for k, v in upperCase.items():
        print(k, v)
    

def encrypt(text, column):
    
    eText = ""
    for i in range(len(text)):
        
        pos = i%column
        eText += upperCase[text[i]][pos]
        
        
    return eText


def decrypt(etext, start, column, size):
    dText = ""
    key = start 
    
    
    for i in range(len(etext)):
        
       
        key = start     
        for j in range(size):
            pos = i%column
            if upperCase[key][pos] == etext[i]:
                dText += key
                break
            
            key =  chr((ord(key) + 1)%127)
            
            
    return dText
        

def main():
    generateTable(start, length, column)
    data = input("Enter your text: ")
    
    ecnryptedText = encrypt(data, column)  
    print("Encrypted Text:", ecnryptedText)
     
    decryptedText = decrypt(ecnryptedText,start,column,length)
    print("Decrypted Text:", decryptedText)
    
    
main()