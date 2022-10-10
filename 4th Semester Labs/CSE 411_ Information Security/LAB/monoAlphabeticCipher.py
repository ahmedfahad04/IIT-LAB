def encrypt(text, key):
    modifiedText = ""
    
    for i in range(len(text)):
        if i%2 == 0:
            modifiedText += chr((ord(text[i]) + key)%127)
        else: 
            modifiedText += chr((ord(text[i]) + key + 12)%127)
                    
    return modifiedText  
        

def decrypt(modifiedText, key):
    plainText = ""
    
    for i in range(len(modifiedText)):
        if i%2 == 0:
            plainText += chr((ord(modifiedText[i]) - key)%127)
        else: 
            plainText += chr((ord(modifiedText[i]) - key - 12)%127)
            
            
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
    