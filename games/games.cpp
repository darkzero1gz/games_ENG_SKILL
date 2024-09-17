#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

struct Player {
    string name;
    int score;
    double timeTaken;
};

vector<Player> highScores;

void displayMenu();
int startGame(string mode);
int askQuestion(string question, vector<string> choices, int correctAnswer);
int fillInTheBlanks(string question, string correctAnswer);
void showHighScores();
double calculateTime(clock_t start, clock_t end);

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
        if (choice == 1) mode = "Present Simple";
        else if (choice == 2) mode = "Past Simple";
        else if (choice == 3) mode = "Future Simple";
        else {
            cout << "Invalid choice, please select again.\n";
            continue;
        }

        clock_t start = clock();
        int score = startGame(mode); // Start the game and get the score
        clock_t end = clock();

        double timeTaken = calculateTime(start, end);

        // Store player details
        Player player;
        player.name = name;
        player.score = score;
        player.timeTaken = timeTaken;

        // Add to highScores list
        highScores.push_back(player);

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
        score += askQuestion("What is the correct form of the verb in 'He ___ every day.'", { "runs", "run", "ran" }, 1);
        score += fillInTheBlanks("He _____ (play) football every day.", "plays");
    }

    // Example questions for Past Simple
    else if (mode == "Past Simple") {
        score += askQuestion("What is the past form of 'go'?", { "goes", "went", "gone" }, 2);
        score += fillInTheBlanks("He _____ (go) to the park yesterday.", "went");
    }

    // Example questions for Future Simple
    else if (mode == "Future Simple") {
        score += askQuestion("Which one is Future Simple?", { "will go", "goes", "went" }, 1);
        score += fillInTheBlanks("He _____ (go) to the park tomorrow.", "will go");
    }

    return score; // Return the total score
}

int askQuestion(string question, vector<string> choices, int correctAnswer) {
    cout << question << endl;
    for (int i = 0; i < choices.size(); i++) {
        cout << i + 1 << ". " << choices[i] << endl;
    }

    int answer;
    cout << "Your choice: ";
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
