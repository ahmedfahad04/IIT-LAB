package FinalCodeSmellResolved.TriviaGame;

import java.util.ArrayList;
import java.util.List;

public class Questions {

    private static final List<IQuestions> questionCategory = new ArrayList<>(){{
        new PopQuestion();
        new ScienceQuestion();
        new SportsQuestion();
        new RockQuestion();
    }};

    public void createQuestions() {
        for (int i = 0; i < 50; i++) {
            for(IQuestions question: questionCategory) {
                question.addQuestion(i);
            }
        }
    }

    public void removeQuestions(String category) {
        for(IQuestions question: questionCategory) {
            if(question.matchCategory(category)) question.removeQuestion();
        }
    }

    public String getCategory(int playerLocation) {
        for(IQuestions question: questionCategory) {
            if(question.checkCategory(playerLocation)) return question.getQuestionType();
        }
        throw new IllegalArgumentException("Question type not found");
    }
}
