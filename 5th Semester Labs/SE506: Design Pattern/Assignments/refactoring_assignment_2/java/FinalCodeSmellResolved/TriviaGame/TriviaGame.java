package FinalCodeSmellResolved.TriviaGame;

import java.util.ArrayList;

/*
   1. Primitive Obsession {int[]}

   2. Long Method {add(), roll()}

   3. Duplicate Code {currentCategory(), askQuestion(), wasCorrectlyAnswered()}

   4. Inappropriate Name {add(), roll()}

   5. Redundant code / Dead Code {createRockQuestion()}
 */

public class TriviaGame {
    ArrayList<String> players = new ArrayList<>();
    int[] places = new int[6];
    int[] purses = new int[6];
    boolean[] inPenaltyBox = new boolean[6];


    public Questions questions = new Questions();

    int currentPlayer = 0;

    boolean isGettingOutOfPenaltyBox;

    public TriviaGame() {
        questions.createQuestions();
    }

    public boolean isPlayable() {
        return (howManyPlayers() >= 2);
    }

    public boolean add(String playerName) {
        players.add(playerName);
        places[howManyPlayers()] = 0;
        purses[howManyPlayers()] = 0;
        inPenaltyBox[howManyPlayers()] = false;

        announce(playerName + " was added");
        announce("They are player number " + players.size());
        return true;
    }

    public int howManyPlayers() {
        return players.size();
    }

    public void roll(int roll) {
        announce(players.get(currentPlayer) + " is the current player");
        announce("They have rolled a " + roll);

        if (inPenaltyBox[currentPlayer]) {
            if (roll % 2 != 0) {
                isGettingOutOfPenaltyBox = true;

                announce(players.get(currentPlayer) + " is getting out of the penalty box");
                places[currentPlayer] = places[currentPlayer] + roll;
                if (places[currentPlayer] > 11) places[currentPlayer] = places[currentPlayer] - 12;

                announce(players.get(currentPlayer)
                        + "'s new location is "
                        + places[currentPlayer]);
                announce("The category is " + currentCategory());
                askQuestion();
            } else {
                announce(players.get(currentPlayer) + " is not getting out of the penalty box");
                isGettingOutOfPenaltyBox = false;
            }

        } else {

            places[currentPlayer] = places[currentPlayer] + roll;
            if (places[currentPlayer] > 11) places[currentPlayer] = places[currentPlayer] - 12;

            announce(players.get(currentPlayer)
                    + "'s new location is "
                    + places[currentPlayer]);
            announce("The category is " + currentCategory());
            askQuestion();
        }

    }

    private void askQuestion() {
        questions.removeQuestions(currentCategory());
    }


    private String currentCategory() {
        return questions.getCategory(places[currentPlayer]);
    }

    public boolean wasCorrectlyAnswered() {
        if (inPenaltyBox[currentPlayer]) {
            if (isGettingOutOfPenaltyBox) {
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
            } else {
                currentPlayer++;
                if (currentPlayer == players.size()) currentPlayer = 0;
                return true;
            }


        } else {

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
    }

    public boolean wrongAnswer() {
        announce("Question was incorrectly answered");
        announce(players.get(currentPlayer) + " was sent to the penalty box");
        inPenaltyBox[currentPlayer] = true;

        currentPlayer++;
        if (currentPlayer == players.size()) currentPlayer = 0;
        return true;
    }

    private boolean didPlayerWin() {
        return (purses[currentPlayer] != 6);
    }

    protected void announce(Object message) {
        System.out.println(message);
    }
}