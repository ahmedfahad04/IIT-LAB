package SOIT;

public class Hospital{
    private String UpdateTime;
    private String Name;
    private String Address;
    private String ICU;
    private String Oxygen;
    private String Contact;
    private String key;

    public Hospital(String name, String address, String ICU, String oxygen, String contact, String Time, String key) {
        Name = name;
        Address = address;
        this.ICU = ICU;
        Oxygen = oxygen;
        this.key = key;
        Contact = contact;
        UpdateTime = Time;
    }


    public String getUpdateTime() {
        return UpdateTime;
    }

    public void setUpdateTime(String updateTime) {
        UpdateTime = updateTime;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String getAddress() {
        return Address;
    }

    public void setAddress(String address) {
        Address = address;
    }

    public String getICU() {
        return ICU;
    }

    public void setICU(String ICU) {
        this.ICU = ICU;
    }

    public String getOxygen() {
        return Oxygen;
    }

    public void setOxygen(String oxygen) {
        Oxygen = oxygen;
    }

    public String getContact() {
        return Contact;
    }

    public void setContact(String contact) {
        Contact = contact;
    }

    public String getKey() {
        return key;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public void info() {

    }

    @Override
    public String toString() {
        return  "Name= " + Name + '\n' +
                "Address= " + Address + '\n' +
                "ICU= " + ICU + '\n' +
                "Oxygen= " + Oxygen + '\n' +
                "Contact= " + Contact + '\n';
    }
}