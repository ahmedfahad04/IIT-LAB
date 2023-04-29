package singleton;

public class PushButton implements Widgets{

    private String objectName;
    private String geoPos;

    public PushButton(String Name) {
        objectName = Name;
    }
    
    @Override
    public void setName() {
        this.objectName = "PushButton";
    }

    @Override
    public void setPosition() {
        this.geoPos = "2.5:2.9";
    }

    @Override
    public String getObjectName() {
        return this.objectName;
    }
}
