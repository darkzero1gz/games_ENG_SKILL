#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
    double timeTaken;
};

// Function declarations
vector<Player> highScores;

void displayMenu();
int startGame(string mode);
int askQuestion(string question, vector<string> choices, int correctAnswer);
int fillInTheBlanks(string question, string correctAnswer);
void showHighScores();
double calculateTime(clock_t start, clock_t end);
void updateHighScores(Player player);

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        if (choice == 4) break;

        string mode;
        switch (choice)
        {
        case 1:
            mode = "Present Simple";
            break;
        case 2:
            mode = "Past Simple";
            break;
        case 3:
            mode = "Future Simple";
            break;
        default:cout << "Invalid choice, please select again.\n";
            break;
            continue;
        }

        clock_t start = clock();
        int score = startGame(mode); // Start the game and get the score
        clock_t end = clock();

        double timeTaken = calculateTime(start, end);

        // Create a new player object
        Player player;
        player.name = name;
        player.score = score;
        player.timeTaken = timeTaken;

        // Update the high score list with the new player
        updateHighScores(player);

        // Show the player's score
        cout << "Your score is: " << player.score << endl;

        // Display the high scores
        showHighScores();
    }
    return 0;
}

void displayMenu() {
    cout << "\n--- English Tense Game ---\n";
    cout << "1. Present Simple\n";
    cout << "2. Past Simple\n";
    cout << "3. Future Simple\n";
    cout << "4. Exit\n";
    cout << "Choose a mode: ";
}

int startGame(string mode) {
    int score = 0;

    // Example questions for Present Simple
    if (mode == "Present Simple") {
        score += askQuestion("What is the correct form of the verb in 'He _ every day.'", { "runs", "run", "ran" }, 1);
        score += fillInTheBlanks("He ___ (play) football every day.", "plays");
    }

    // Example questions for Past Simple
    else if (mode == "Past Simple") {
        score += askQuestion("What is the past form of 'go'?", { "goes", "went", "gone" }, 2);
        score += fillInTheBlanks("He ___ (go) to the park yesterday.", "went");
    }

    // Example questions for Future Simple
    else if (mode == "Future Simple") {
        score += askQuestion("Which one is Future Simple?", { "will go", "goes", "went" }, 1);
        score += fillInTheBlanks("He ___ (go) to the park tomorrow.", "will go");
    }

    return score; // Return the total score
}

int askQuestion(string question, vector<string> choices, int correctAnswer) {
    cout << question << endl;
    for (int i = 0; i < choices.size(); i++) {
        cout << i + 1 << ". " << choices[i] << endl;
    }

    int answer;
    cout << "Your answer: ";
    cin >> answer;

    if (answer == correctAnswer) {
        cout << "Correct!\n";
        return 1;
    }
    else {
        cout << "Wrong!\n";
        return 0;
    }
}

int fillInTheBlanks(string question, string correctAnswer) {
    cout << question << endl;
    string answer;
    cout << "Your answer: ";
    cin >> answer;

    if (answer == correctAnswer) {
        cout << "Correct!\n";
        return 1;
    }
    else {
        cout << "Wrong! The correct answer is: " << correctAnswer << endl;
        return 0;
    }
}

void showHighScores() {
    cout << "\n--- High Scores ---\n";
    for (auto player : highScores) {
        cout << player.name << " - Score: " << player.score << " - Time: " << player.timeTaken << " seconds\n";
    }
    cout << "--------------------\n";
}

double calculateTime(clock_t start, clock_t end) {
    return double(end - start) / CLOCKS_PER_SEC;
}

void updateHighScores(Player player) {
    bool updated = false;

    for (auto& highScorePlayer : highScores) {
        if (highScorePlayer.name == player.name) {
            // If the player already exists, update if the score is higher or time is lower
            if (player.score > highScorePlayer.score) {
                highScorePlayer = player;
            } else if (player.score == highScorePlayer.score && player.timeTaken < highScorePlayer.timeTaken) {
                highScorePlayer.timeTaken = player.timeTaken;
            }
            updated = true;
            break;
        }
    }

    if (!updated) {
        // If player does not exist in the high score list, add the player
        highScores.push_back(player);
    }

    // Sort the high scores in descending order by score, and by time in ascending order for ties
    sort(highScores.begin(), highScores.end(), [](Player a, Player b) {
        if (a.score == b.score)
            return a.timeTaken < b.timeTaken;
        return a.score > b.score;
    });
}
