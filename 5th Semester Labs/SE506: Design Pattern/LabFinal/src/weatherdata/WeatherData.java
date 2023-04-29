package weatherdata;

public class WeatherData {
	  private String city;
	  private String temperature;

	  private static WeatherData instance;

	  private WeatherData() {}

	  public static WeatherData getInstance() {
		  if(instance == null) {
			  instance = new WeatherData();
		  }

		  return instance;
	  }

	  public String getCity() {
	    return city;
	  }

	  public void setCity(String city) {
	    this.city = city;
	  }

	  public String getTemperature() {
	    return temperature;
	  }

	  public void setTemperature(String temperature) {
	    this.temperature = temperature;
	  }
	}

