#include <iostream>
#include <ctime>
#include <string>
#include <limits> // สำหรับใช้ numeric_limits
using namespace std;

const int MAX_SCORES = 10; // จำนวนสูงสุดของคะแนนที่เก็บ
string players[MAX_SCORES]; // เก็บชื่อผู้เล่น
int highScores[MAX_SCORES] = {0}; // เก็บคะแนนสูงสุด
double times[MAX_SCORES] = {0}; // เก็บเวลาที่ใช้เล่น
int totalScores = 0; // จำนวนของคะแนนที่ถูกเก็บ

void displayMenu() {
    
    cout << "\n--- English Tense Game ---\n";
    cout << "1. Present Simple\n";
    cout << "2. Past Simple\n";
    cout << "3. Future Simple\n";
    cout << "4. Show score board\n";
    cout << "5. Exit\n";
}

int playGame(int choice) {
    int score = 0;
    if (choice == 1) {
        // Present Simple questions
        cout << "1) What is the correct form of the verb in 'He _ every day." << endl;
        cout << "please enter number to select answer: \n1.runs\n 2.run\n 3.ran" << endl;
        string answer;
        cout << "Your answer: ";
        cin >> answer;
        if (answer == "1" || "runs") score++; 
        
        cout << "2) Fill in the blank: He ___ (play) football every day.\n";
        string textAnswer;
        cout << "Your answer: ";
        cin >> textAnswer;
        if (textAnswer == "plays") score++;
    }
    else if (choice == 2) {
        // Past Simple questions
        cout << "1) What is the past form of 'go'?\n1. goes\n2. went\n3. gone\n";
        int answer;
        cout << "Your answer: ";
        cin >> answer;
        if (answer == 2) score++;
        
        cout << "2) Fill in the blank: He ___ (go) to the park yesterday.\n";
        string textAnswer;
        cout << "Your answer: ";
        cin >> textAnswer;
        if (textAnswer == "went") score++;
    }
    else if (choice == 3) {
        // Future Simple questions
        cout << "1) Which one is Future Simple?\n1. will go\n2. goes\n3. went\n";
        int answer;
        cout << "Your answer: ";
        cin >> answer;
        if (answer == 1) score++;
        
        cout << "2) Fill in the blank: He ___ (go) to the park tomorrow.\n";
        string textAnswer;
        cout << "Your answer: ";
        cin >> textAnswer;
        if (textAnswer == "will go") score++;
    }
    return score;
}

void updateHighScores(string playerName, int score, double timeTaken) {
    if (totalScores < MAX_SCORES) {
        players[totalScores] = playerName;
        highScores[totalScores] = score;
        times[totalScores] = timeTaken;
        totalScores++;
    } else {
        // Replace lowest score if current score is better
        int minIndex = 0;
        for (int i = 1; i < MAX_SCORES; i++) {
            if (highScores[i] < highScores[minIndex]) {
                minIndex = i;
            }
        }
        if (score > highScores[minIndex]) {
            players[minIndex] = playerName;
            highScores[minIndex] = score;
            times[minIndex] = timeTaken;
        }
    }
}

void sortScores() {
    for (int i = 0; i < totalScores - 1; i++) {
        for (int j = 0; j < totalScores - i - 1; j++) {
            if (highScores[j] < highScores[j + 1]) {
                // Swap scores
                swap(highScores[j], highScores[j + 1]);
                // Swap names
                swap(players[j], players[j + 1]);
                // Swap times
                swap(times[j], times[j + 1]);
            }
        }
    }
}

void displayHighScores() {
    cout << "\n--- High Scores ---\n";
    
    // เรียงลำดับคะแนนจากสูงไปต่ำก่อนแสดงผล
    sortScores();
    
    for (int i = 0; i < totalScores; i++) {
        cout << i + 1 << ". " << players[i] << " - Score: " << highScores[i] << " - Time: " << times[i] << " seconds\n";
    }
    cout << "--------------------\n";
}

bool isNumber(const string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) return false; // ถ้ามีตัวอักษรที่ไม่ใช่เลข จะคืนค่า false
    }
    return true; // คืนค่า true หากเป็นตัวเลขทั้งหมด
}

int main() {
    while (true) {
        // แสดงเมนูทุกครั้งก่อนเริ่มเกม
        displayMenu();
        
        string input;
        int choice = 0;

        cout << "Choose a mode: ";
        cin >> input;

        // ดักค่าการกรอกที่ไม่ใช่ตัวเลข
        if (!isNumber(input) || (choice = stoi(input)) < 1 || choice > 5) {
            cout << "Invalid input, please enter a number between 1 and 5.\n";
            continue;
        }

        if (choice == 5) {
            cout << "Exiting the game.\n";
            break;
        } else if (choice == 4) {
            // แสดงคะแนนสูงสุด
            displayHighScores();
            continue;
        }
    
        // ถามชื่อผู้เล่นใหม่ทุกครั้งเมื่อเลือกโหมดเกม
        string playerName;
        cout << "Enter your name: ";
        cin >> playerName;

        // เริ่มจับเวลา
        clock_t start = clock();

        // เล่นเกมตามโหมดที่เลือก
        int score = playGame(choice);

        // จบจับเวลา
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;

        // แสดงคะแนนของผู้เล่น
        cout << "Your score is: " << score << endl;
        cout << "Time taken: " << timeTaken << " seconds\n";

        // อัปเดตคะแนนสูงสุด
        updateHighScores(playerName, score, timeTaken);

        // ถามผู้เล่นว่าต้องการเล่นต่อหรือไม่
        cout << "Do you want to play again ? (y/n): ";
        char continueGame;
        cin >> continueGame;

        if (continueGame == 'n' || continueGame == 'N') {
            cout << "Returning to the main menu.\n";
        }
    }

    return 0;
}
