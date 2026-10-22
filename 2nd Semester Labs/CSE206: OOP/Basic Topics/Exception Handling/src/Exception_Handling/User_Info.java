package Exception_Handling;

import java.util.Arrays;
import java.util.Locale;

public class User_Info {
    String name, NID, email;

    private String getName() {
        return name;
    }

    private String getMobile_no() {
        return NID;
    }

    private String getEmail() {
        return email;
    }


    public void setName(String name) throws IAFCamelCaseException {
        this.name = name;

        String[] words = name.split("\\s");
        int cnt = 0;
        int segment = words.length;

        for (String word : words) {
            char ch = word.charAt(0);
            if (ch >= 'A' && ch <= 'Z') {
                cnt++;
            } else throw new IAFCamelCaseException(word);
        }
        if (cnt == segment) System.out.println("User Name OK!!");
    }

    public void setMobile_no(String nid) throws IAFDigitCountException {
        this.NID = nid;
        int len = NID.length();
        String code = nid.substring(0, 4);

        // check option 1
        if (len == 10) {
            System.out.println("NID OK!!");
        } else throw new IAFDigitCountException(NID);


    }

    public void setEmail(String email) throws IAFDomainNameError {
        this.email = email;
        String[] domain = email.split("@");

        if (domain[1].equals("iit.du.ac.bd")) {
            System.out.println("Email OK!!");
        } else throw new IAFDomainNameError(email);

    }


}
