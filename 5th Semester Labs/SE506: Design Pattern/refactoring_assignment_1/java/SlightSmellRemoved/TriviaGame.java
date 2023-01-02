package SlightSmellRemoved;

import java.util.ArrayList;
import java.util.LinkedList;

class Players {

    ArrayList<String> players = new ArrayList<String>();
    int[] places = new int[6];
    int[] purses = new int[6];
    boolean[] inPenaltyBox = new boolean[6];
    int currentPlayer = 0;
    boolean isGettingOutOfPenaltyBox;

    TriviaGame triviaGame = new TriviaGame();


    public boolean addPlayersAndDetails(String playerName) {

        players.add(playerName);
        places[triviaGame.howManyPlayers()] = 0;
        purses[triviaGame.howManyPlayers()] = 0;
        inPenaltyBox[triviaGame.howManyPlayers()] = false;

        announce(playerName + " was added");
        announce("They are player number " + players.size());
        return true;
    }

    private boolean didPlayerWin() {
        return !(purses[currentPlayer] == 6);
    }

    public void rollPlayerLocation(int roll) {
        announce(players.get(currentPlayer) + " is the current player");
        announce("They have rolled a " + roll);

        if (inPenaltyBox[currentPlayer]) {
            if (roll % 2 != 0) {
                isGettingOutOfPenaltyBox = true;
                announce(players.get(currentPlayer) + " is getting out of the penalty box");
                resetPlayerLocationAndAskQuestion(roll);

            } else {
                announce(players.get(currentPlayer) + " is not getting out of the penalty box");
                isGettingOutOfPenaltyBox = false;
            }

        } else resetPlayerLocationAndAskQuestion(roll);
    }

    private void resetPlayerLocationAndAskQuestion(int roll) {
        places[currentPlayer] = places[currentPlayer] + roll;
        if (places[currentPlayer] > 11) places[currentPlayer] = places[currentPlayer] - 12;

        announce(players.get(currentPlayer)
                + "'s new location is "
                + places[currentPlayer]);
        announce("The category is " + triviaGame.currentCategory());
        triviaGame.askQuestion();
    }

    public boolean wasCorrectlyAnswered() {
        if (inPenaltyBox[currentPlayer]) {
            if (isGettingOutOfPenaltyBox) return getWinningStatus();
            else {
                currentPlayer++;
                if (currentPlayer == players.size()) currentPlayer = 0;
                return true;
            }

        } else return getWinningStatus();
    }

    private boolean getWinningStatus() {
        announce("Answer was correct!!!!");
        purses[currentPlayer]++;
        announce(players.get(currentPlayer)
                + " now has "
                + purses[currentPlayer]
                + " Gold Coins.");

        boolean winner = didPlayerWin();
        currentPlayer++;
        if (currentPlayer == players.size()) currentPlayer = 0;

        return winner;
    }

    public boolean wrongAnswer() {
        announce("Question was incorrectly answered");
        announce(players.get(currentPlayer) + " was sent to the penalty box");
        inPenaltyBox[currentPlayer] = true;

        currentPlayer++;
        if (currentPlayer == players.size()) currentPlayer = 0;
        return true;
    }

    protected void announce(Object message) {
        System.out.println(message);
    }

}

public class TriviaGame {

    LinkedList<String> popQuestions = new LinkedList<String>();
    LinkedList<String> scienceQuestions = new LinkedList<String>();
    LinkedList<String> sportsQuestions = new LinkedList<>();
    LinkedList<String> rockQuestions = new LinkedList<>();

    Players player = new Players();

    public TriviaGame() {
        for (int i = 0; i < 50; i++) {
            popQuestions.addLast("Pop Question " + i);
            scienceQuestions.addLast(("Science Question " + i));
            sportsQuestions.addLast(("Sports Question " + i));
            rockQuestions.addLast("Rock Question " + i);
        }
    }

    public boolean isPlayable() {
        return (howManyPlayers() >= 2);
    }

    public int howManyPlayers() {
        return player.players.size();
    }

    void askQuestion() {
        updateQuestionSet("Pop", popQuestions);
        updateQuestionSet("Science", scienceQuestions);
        updateQuestionSet("Sports", sportsQuestions);
        updateQuestionSet("Rock", rockQuestions);
    }

    private void updateQuestionSet(String category, LinkedList<String> questionSet) {
        if (currentCategory().equals(category))
            player.announce(questionSet.removeFirst());
    }

    String currentCategory() {
        int players = player.places[player.currentPlayer];

        if (players%4 == 0 && players < 9) return "Pop";
        else if ((players-1)%4 == 0 && players < 10) return "Science";
        else if ((players-2)%4 == 0 && players < 11) return "Sports";
        else return "Rock";
    }

}