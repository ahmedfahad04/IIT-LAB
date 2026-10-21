package practice.observer;

import java.util.ArrayList;
import java.util.List;

public class Office {
    private List<People> people = new ArrayList<>();
    private String news;

    public String getNews() {
        return news;
    }

    public void attach(People person){
        this.people.add(person);
    }

    private void notifyAllPeople(){
        for (People people :people) {
            people.update();
        }
    }

    public void setNews(String news) {
        this.news = news;
        this.notifyAllPeople();
    }
}
