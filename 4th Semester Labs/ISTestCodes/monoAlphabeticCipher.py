def encrypt(text, key):
    modifiedText = ""
    
    for i in range(len(text)):
        asci = ord(text[i])
        
        if(asci >= 65 and asci <= 90):
            modifiedText += chr((asci - 65 + key) % 26 + 65) 
            
        elif (asci >= 97 and asci <= 122):
            modifiedText += chr((asci - 97 + key) % 26 + 97) 
            
        elif (asci >= 32 and asci <= 47):
            modifiedText += chr((asci - 32 + key) % 16 + 32) 
            
    return modifiedText  
        

def decrypt(modifiedText, key):
    plainText = ""
    
    for i in range(len(modifiedText)):
        asci = ord(modifiedText[i])
        
        if(asci >= 65 and asci <= 90):
            plainText += chr((asci - 65 - key)%26 + 65)
            
        elif (asci >= 97 and asci <= 122):
            plainText += chr((asci - 97 - key)%26 + 97)
            
        elif (asci >= 32 and asci <= 47):
            plainText += chr((asci - 32 - key)%16 + 32)
            
    return plainText  
    

def main():
    data = input("Enter your text: ")
    key = int(input("Enter your key: "))
    
    ecnryptedText = encrypt(data, key)  
    print("Encrypted Text:", ecnryptedText)
     
    decryptedText = decrypt(ecnryptedText, key)
    print("Decrypted Text:", decryptedText)
    
if __name__ == '__main__':
    main()
    