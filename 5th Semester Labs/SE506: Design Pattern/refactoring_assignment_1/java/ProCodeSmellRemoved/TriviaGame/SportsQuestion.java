package ProCodeSmellRemoved.TriviaGame;

import java.util.LinkedList;

public class SportsQuestion implements IQuestions {

    LinkedList<String> sportsQuestions = new LinkedList<String>();

    public boolean matchCategory(String questionType) {
        return questionType.equalsIgnoreCase("sports");
    }


    @Override
    public void removeQuestion() {
        sportsQuestions.removeFirst();
    }

    @Override
    public void addQuestion(int index) {
        sportsQuestions.addLast( "Sports Question" + index);
    }

    @Override
    public boolean checkCategory(int location) {
        return (location-2 % 4) == 0;
    }

    @Override
    public String getQuestionType() {
        return "Sports";
    }
}
