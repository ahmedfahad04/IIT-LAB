package ProCodeSmellRemoved.TriviaGame;

import java.util.LinkedList;

public class PopQuestion implements IQuestions {

    LinkedList<String> popQuestions = new LinkedList<String>();

    public boolean matchCategory(String questionType) {
        return questionType.equalsIgnoreCase("pop");
    }

    @Override
    public void removeQuestion() {
        popQuestions.removeFirst();
    }

    @Override
    public void addQuestion(int index) {
        popQuestions.addLast("Pop Question " + index);
    }

    @Override
    public boolean checkCategory(int location) {
        return (location % 4) == 0;
    }

    @Override
    public String getQuestionType() {
        return "Pop";
    }

}
