# generate table
from ctypes.wintypes import PINT


upperCase = dict()
lowerCase = dict()

def generateTable():
    k = 0
    ch = 'A'
    for i in range(0, 26, 1):
        
        key = chr(ord('A') + i)
        tmp = []
        
        for j in range(1, 27, 1):
            tmp.append(ch)
            ch = chr((ord(ch)-65 + 1)%26+65)
        
        upperCase[key] = tmp
        key = chr((ord(key)-65 + 1)%26+65)
        ch = key 
        

    for k, v in upperCase.items():
        print(k, v)
    

def encrypt(text):
    
    eText = ""
    for i in range(len(text)):
        asci = ord(text[i])
        
        # handle lowercase letters
        alpha = ""
        if(asci >= 97 and asci <= 122):
            alpha = chr(ord(text[i]) - 32)
        elif (asci >= 65 and asci <= 90):
            alpha = text[i]
        else:   # handle other characters
            eText += chr((ord(text[i])+5)%127)
            continue
            
        # append characters
        pos = i%26
        eText += upperCase[alpha][pos]
      
        
    return eText


def decrypt(etext):
    dText = ""
    key = 'A'
    
    
    for i in range(len(etext)):
        asci = ord(etext[i])
        
        # handle lower case letters
        if(asci >= 97 and asci <= 122):
                alpha = chr(ord(etext[i]) - 32)   
        elif (asci >= 65 and asci <= 90):
            alpha = etext[i]
        else: 
            dText += chr((ord(etext[i])-5)%127)
            continue
                
        for j in range(26):
            pos = i%26
            if upperCase[key][pos] == alpha:
                dText += key
            
            key = chr((ord(key)-65 + 1)%26+65)
            
            
    return dText
        

def main():
    generateTable()
    data = input("Enter your text: ")
    
    ecnryptedText = encrypt(data)  
    print("Encrypted Text:", ecnryptedText)
     
    decryptedText = decrypt(ecnryptedText)
    print("Decrypted Text:", decryptedText)
    
    
main()