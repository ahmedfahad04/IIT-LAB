package Exception_Handling;

class IAFCamelCaseException extends Exception{

    public IAFCamelCaseException(String name){
    }
}

class IAFDigitCountException extends Exception{
    public IAFDigitCountException(String number){
    }
}


class IAFDomainNameError extends Exception{
    public IAFDomainNameError(String email){

    }
}