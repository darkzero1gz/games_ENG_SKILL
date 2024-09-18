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
        cout << "Choose a mode: ";
        cin >> choice;

        // Check for invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input, please enter a number between 1 and 4.\n";
            continue;
        }

        // Check if the choice is valid
        if (choice == 4) break;

        string mode;
        bool validChoice = true;
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
        default:
            validChoice = false;
            break;
        }

        if (!validChoice) {
            cout << "Invalid choice, please select again.\n";
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
}

int startGame(string mode) {
    int score = 0;

    // Questions for Present Simple
    if (mode == "Present Simple") {
        score += askQuestion("What is the correct form of the verb in 'He _ every day.'", { "runs", "run", "ran" }, 1);
        score += fillInTheBlanks("He ___ (play) football every day.", "plays");
        score += askQuestion("Which is the correct question form: '___ she go to school every day?'", { "Do", "Does", "Is" }, 2);
        score += fillInTheBlanks("They _____ (not go) to school on Sundays.", "do not go");
        score += askQuestion("My dad ___ English with me.", { "Speak", "Speaks", "speaked" }, 2);
        score += askQuestion("Choose the correct sentence: 'She _ to the market every week.'", { "go", "goes", "gone" }, 2);
        score += fillInTheBlanks("I ___ (eat) breakfast at 7 a.m. every day.", "eat");
        return score;
    }

    // Questions for Past Simple
    else if (mode == "Past Simple") {
        score += askQuestion("What is the past form of 'go'?", { "goes", "went", "gone" }, 2);
        score += fillInTheBlanks("He ___ (go) to the park yesterday.", "went");
        score += askQuestion("What is the correct past form in 'She _ to the store.'", { "goed", "went", "goes" }, 2);
        score += fillInTheBlanks("They _____ (not see) the movie last week.", "did not see");
        score += askQuestion("What did they ___ yesterday?", { "do", "did", "done" }, 1);
        score += askQuestion("Choose the correct past tense form: 'He _ the book last night.'", { "reads", "read", "reading" }, 2);
        score += fillInTheBlanks("She ___ (meet) her friend last Friday.", "met");
        return score;
    }

    // Questions for Future Simple
    else if (mode == "Future Simple") {
        score += askQuestion("Which one is Future Simple?", { "will go", "goes", "went" }, 1);
        score += fillInTheBlanks("He ___ (go) to the park tomorrow.", "will go");
        score += askQuestion("What is the correct future form of 'She ___ a party next week.'", { "will have", "has", "had" }, 1);
        score += fillInTheBlanks("They _____ (not go) to school tomorrow.", "will not go");
        score += askQuestion("Will they ___ to the concert?", { "go", "went", "going" }, 1);
        score += askQuestion("Choose the correct future tense form: 'I _ my homework later.'", { "do", "did", "will do" }, 3);
        score += fillInTheBlanks("We ___ (travel) to Paris next summer.", "will travel");
        return score;
    }

    return score; // Return the total score
}

int askQuestion(string question, vector<string> choices, int correctAnswer) {
    int answer = 0;
    while (true) {
        cout << question << endl;
        for (int i = 0; i < choices.size(); i++) {
            cout << i + 1 << ". " << choices[i] << endl;
        }

        cout << "Your answer: ";
        cin >> answer;

        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid choice, please enter a number between 1 and " << choices.size() << ".\n";
            continue;
        }

        if (answer >= 1 && answer <= choices.size()) {
            break; // Exit the loop if the answer is valid
        } else {
            cout << "Invalid choice, please try again.\n";
        }
    }

    if (answer == correctAnswer) {
        cout << "Correct!\n";
        return 1;
    } else {
        cout << "Wrong!\n";
        return 0;
    }
}

int fillInTheBlanks(string question, string correctAnswer) {
    string answer;
    while (true) {
        cout << question << endl;
        cout << "Your answer: ";
        cin.ignore(); // Clear the newline left in the buffer
        getline(cin, answer); // Use getline to handle spaces in answers

        if (!answer.empty()) {
            break; // Exit the loop if the answer is not empty
        } else {
            cout << "Empty answer is not allowed, please try again.\n";
        }
    }

    if (answer == correctAnswer) {
        cout << "Correct!\n";
        return 1;
    } else {
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
