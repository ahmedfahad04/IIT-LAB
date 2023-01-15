package FinalCodeSmellResolved.TriviaGame;

public interface IQuestions {
    boolean matchCategory(String questionType);
    void removeQuestion();
    void addQuestion(int index);
    boolean checkCategory(int location);
    public String getQuestionType();
}
