package FinalCodeSmellResolved.TriviaGame;

import java.util.LinkedList;

public class RockQuestion implements IQuestions {

    LinkedList<String> rockQuestions = new LinkedList<>();

    public boolean matchCategory(String questionType) {
        return questionType.equalsIgnoreCase("rock");
    }

    @Override
    public void removeQuestion() {
        rockQuestions.removeFirst();
    }

    @Override
    public void addQuestion(int index) {
        rockQuestions.addLast("Rock Question" + index);
    }

    @Override
    public boolean checkCategory(int location) {
        return  ((location-3 % 4) == 0 || (location>10));
    }

    @Override
    public String getQuestionType() {
        return "Rock";
    }
}
