package FinalCodeSmellResolved.TriviaGame;

import java.util.LinkedList;

public class ScienceQuestion implements IQuestions {

    LinkedList<String> scienceQuestions = new LinkedList<>();


    public boolean matchCategory(String questionType) {
        return questionType.equalsIgnoreCase("science");
    }

    @Override
    public void removeQuestion() {
        scienceQuestions.removeFirst();
    }

    @Override
    public void addQuestion(int index) {
        scienceQuestions.addLast("Science Question " + index);
    }

    @Override
    public boolean checkCategory(int location) {
        return (location-1 % 4) == 0;
    }

    @Override
    public String getQuestionType() {
        return "Science";
    }
}
