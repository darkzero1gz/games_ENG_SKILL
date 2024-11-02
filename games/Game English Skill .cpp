#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const int MAX_SCORES = 10;        // Maximum number of scores to keep
string players[MAX_SCORES];       // Store player names
int highScores[MAX_SCORES] = {0}; // Store high scores
double times[MAX_SCORES] = {0};   // Store times taken to play
string modes[MAX_SCORES];         // Store game modes
int totalScores = 0;              // Number of scores stored

void displayMenu()
{

    cout << "\n--- English Tense Game ---\n";
    cout << "1. Present Simple\n";
    cout << "2. Past Simple\n";
    cout << "3. Future Simple\n";
    cout << "4. Show score board\n";
    cout << "5. Exit\n";
    cout << endl;
}

string getModeName(int choice)
{
    if (choice == 1)
        return "Present Simple";
    if (choice == 2)
        return "Past Simple";
    if (choice == 3)
        return "Future Simple";
    return "";
}

int playGame(int choice)
{
    int score = 0;
    if (choice == 1)
    {
        // 1
        cout << "1) What is the correct form of the verb in | 'He _ every day.'?\n";
        cout << "1. runs\n2. run\n3. ran" << endl;
        string answer;
        cout << "Your select answer: ";
        cin >> answer;
        // cout << endl;
        if (answer == "1" || answer == "runs")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'runs'.\n";
        }
        cout << endl;
        // 2
        cout << "2) Fill in the blank | 'He _ (play) football every day.'\n";
        string answer2;
        cout << "Your select answer: ";
        cin >> answer2;
        // cout << endl;
        if (answer2 == "plays")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'plays'.\n";
        }
        cout << endl;
        // 3
        cout << "3) What is the correct form of the verb in |'She _ not like spicy food.'?\n";
        cout << "1. do\n2. did\n3. does" << endl;
        string answer3;
        cout << "Your select answer: ";
        cin >> answer3;
        // cout << endl;
        if (answer3 == "3" || answer3 == "does")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'does'.\n";
        }
        cout << endl;
        // 4
        cout << "4) Fill in the blank |'They _ (do) not play video games in their free time.'?\n";
        string answer4;
        cout << "Your select answer: ";
        cin >> answer4;
        // cout << endl;
        if (answer4 == "do")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'do'.\n";
        }
        cout << endl;

        // 5
        cout << "5) What is the correct form of the verb in |'She _ to travel around the world.'?\n";
        cout << "1. love\n2. loves\n3. loved" << endl;
        string answer5;
        cout << "Your select answer: ";
        cin >> answer5;
        // cout << endl;
        if (answer5 == "2" || answer5 == "loves")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'loves'.\n";
        }
        cout << endl;

        // 6
        cout << "6) What is the correct form of the verb in |'They _ English fluently.'?\n";
        cout << "1. speak\n2. speaks\n3. speaked" << endl;
        string answer6;
        cout << "Your select answer: ";
        cin >> answer6;
        // cout << endl;
        if (answer6 == "1" || answer6 == "speak")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'speak'.\n";
        }
        cout << endl;

        // 7
        cout << "7) What is the correct form of the verb in |'_ he drink coffee in the morning.'?\n";
        cout << "1. Do\n2. Does\n3. How" << endl;
        string answer7;
        cout << "Your select answer: ";
        cin >> answer7;
        // cout << endl;
        if (answer7 == "2" || answer7 == "Does")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Does'.\n";
        }
        cout << endl;

        // 8
        cout << "8) What is the correct form of the verb in |'_ they study together every evening.'?\n";
        cout << "1. Do\n2. Does\n3. How" << endl;
        string answer8;
        cout << "Your select answer: ";
        cin >> answer8;
        // cout << endl;
        if (answer8 == "1" || answer8 == "Do")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Do'.\n";
        }
        cout << endl;

        // 9
        cout << "9) What is the correct form of the verb in |'The sun _ in the east.'?\n";
        cout << "1. rise\n2. rises\n3. rised" << endl;
        string answer9;
        cout << "Your select answer: ";
        cin >> answer9;
        // cout << endl;
        if (answer9 == "2" || answer9 == "rises")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'rises'.\n";
        }
        cout << endl;

        // 10
        cout << "10) Fill in the blank |'The train _ (arrive) at the station at 9 o'clock.'?\n";
        string answer10;
        cout << "Your select answer: ";
        cin >> answer10;
        // cout << endl;
        if (answer10 == "arrives")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'arrives'.\n";
        }
        cout << endl;

        ////////////////////////////////////////////////////////////////
    }

    else if (choice == 2)
    {
        // 1
        cout << "1) What is the past form of 'go'?\n";
        cout << "1. go\n2. went\n3. gone" << endl;
        string answer1;
        cout << "Your answer: ";
        cin >> answer1;
        if (answer1 == "2" || answer1 == "went")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'went'.\n";
        }
        cout << endl;
        // 2
        cout << "2) Fill in the blank | 'He _ (go) to the park yesterday.'?\n";
        string textAnswer1;
        cout << "Your answer: ";
        cin >> textAnswer1;
        if (textAnswer1 == "went")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'went'.\n";
        }
        cout << endl;
        // 3
        cout << "3) Fill in the blank | 'They _ (play) football last week.'?\n";
        string textAnswer3;
        cout << "Your answer: ";
        cin >> textAnswer3;
        if (textAnswer3 == "played")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'played'.\n";
        }
        cout << endl;
        // 4
        cout << "4) Fill in the blank | '_ you go to the market yesterday.'?\n";
        cout << "1. Do\n2. Did\n3. Are" << endl;
        string textAnswer4;
        cout << "Your answer: ";
        cin >> textAnswer4;
        if (textAnswer4 == "2" || textAnswer4 == "Did")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Did'.\n";
        }
        cout << endl;

        // 5
        cout << "5) What is the past form of 'eat'?\n";
        cout << "1. eating\n2. eaten\n3. ate" << endl;
        string textAnswer5;
        cout << "Your answer: ";
        cin >> textAnswer5;
        if (textAnswer5 == "3" || textAnswer4 == "ate")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'ate'.\n";
        }
        cout << endl;

        // 6
        cout << "6) Fill in the blank | 'They _ not play football last week.'?\n";
        cout << "1. are\n2. did\n3. was" << endl;
        string textAnswer6;
        cout << "Your answer: ";
        cin >> textAnswer6;
        if (textAnswer6 == "2" || textAnswer6 == "did")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'did'.\n";
        }
        cout << endl;

        // 7
        cout << "7)Create a question from the given | You studied English last week.'?\n";
        cout << "1. Are you study English last week. ?\n2. Did you study English last week. ?\n3. Do you study English last week. ?" << endl;
        cout << "Please answer between 1 - 3" << endl;
        string textAnswer7;
        cout << "Your answer: ";
        cin >> textAnswer7;
        if (textAnswer7 == "2")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Choice 2'.\n";
        }
        cout << endl;

        // 8
        cout << "8)Create a question from the given |  She went to the party last night.'?\n";
        cout << "1. Are She went to the party last night. ?\n2. Do She went to the party last night. ?\n3. Did She went to the party last night. ?" << endl;
        cout << "Please answer between 1 - 3" << endl;
        string textAnswer8;
        cout << "Your answer: ";
        cin >> textAnswer8;
        if (textAnswer8 == "3")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Choice 3'.\n";
        }
        cout << endl;

        // 9
        cout << "9)Change the sentence to negative form |  He watched a movie last weekend.'\n";
        cout << "1. He did not watch a movie last weekend. \n2. He do not watch a movie last weekend. \n3. He are not watch a movie last weekend. " << endl;
        cout << "Please answer between 1 - 3" << endl;
        string textAnswer9;
        cout << "Your answer: ";
        cin >> textAnswer9;
        if (textAnswer9 == "1")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Choice 1'.\n";
        }
        cout << endl;

        // 10
        cout << "10)Fill in the blanks with the correct past form of the verb | We (not/eat) ____ dinner at home yesterday.'\n";
        cout << "1. We do not eat dinner at home yesterday. \n2. We did not eat dinner at home yesterday. \n3. We are not eat dinner at home yesterday. " << endl;
        cout << "Please answer between 1 - 3" << endl;
        string textAnswer10;
        cout << "Your answer: ";
        cin >> textAnswer10;
        if (textAnswer10 == "2")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Choice 2'.\n";
        }
        cout << endl;
    }
    else if (choice == 3)
    {
        // 1
        cout << "1) Which one is Future Simple. ?\n";
        cout << "1. will go\n2. gone\n3. went" << endl;
        //cout << "Please answer between 1 - 3" << endl;
        string answer1;
        cout << "Your select answer: ";
        cin >> answer1;
        if (answer1 == "1" || answer1 == "will" || answer1 == "will go" )
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'will go'.\n";
        }
        cout << endl;

        // 2
        cout << "2) Fill in the blank | He _ (travel) to the park tomorrow.\n";
        string textAnswer2;
        cout << "Your select answer: ";
        cin >> textAnswer2;
        if ( textAnswer2 == "will")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'will travel'.\n";
        }
        cout << endl;

        // 3
        cout << "3) Change this sentence to Future Simple Tense | Do they work on Saturday. ?\n";
        cout << "1. Will they work on Saturday. \n2. Did they work on Saturday.\n3. Are they work on Saturday." << endl;
        cout << "Please answer between 1 - 3" << endl;
        int answer3;
        cout << "Your select answer: ";
        cin >> answer3;
        if (answer3 == 1)
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Choice 1'.\n";
        }
        cout << endl;

        // 4
        cout << "4) Fill in the blank | We ______ (finish) the project by Friday.\n";
        cout << "1. are\n2. will\n3. do" << endl;
        string answer4;
        cout << "Your select answer: ";
        cin >> answer4;
        if (answer4 == "2" || answer4 == "will")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'will'.\n";
        }
        cout << endl;

        // 5
        cout << "5) take this word (travel) to make Future simple tense.\n";
        cout << "1. I will travel Pattaya next month.\n2. We will travel Pattaya next month.\n3.Katarina just travel Pattaya next month." << endl;
        cout << "Please answer between 1 - 3" << endl;
        int answer5;
        cout << "Your select answer: ";
        cin >> answer5;
        if (answer5 == 1 || answer5 == 2)
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'Choice 1 and 2'.\n";
        }
        cout << endl;

        // 6
        cout << "6) Which sentence is in the Future tense? \n";
        cout << "1. I will go to the cinema.\n2. We are go to the cinema.\n3. They just go to the cinema." << endl;
        cout << "Please answer between 1 - 3" << endl;
        int answer6;
        cout << "Your select answer: ";
        cin >> answer6;
        if (answer6 == 1)
        {
            score++;
        }
        else
        {
            cout << "Incorrect! The correct answer is 'Choice 1'.\n";
        }
        cout << endl;

        // 7
        cout << "7) Which sentence is in the Future tense? \n";
        cout << "1. What will you do next weekend.\n2. What are you do next weekend.\n3. What is you do next weekend." << endl;
        cout << "Please answer between 1 - 3" << endl;
        int answer7;
        cout << "Your select answer: ";
        cin >> answer7;
        if (answer7 == 1)
        {
            score++;
        }
        else
        {
            cout << "Incorrect! The correct answer is 'Choice 1'.\n";
        }
        cout << endl;

        // 8
        cout << "8) Fill in the blank | When _ she arrive at the office. ?\n";
        cout << "1. are\n2. will\n3. do" << endl;
        string answer8;
        cout << "Your select answer: ";
        cin >> answer8;
        if (answer8 == "2" || answer8 == "will")
        {
            score++;
        }
        else
        {
            cout << "Incorrect ! The correct answer is 'will'.\n";
        }
        cout << endl;

        // 9
        cout << "9) Which sentence is in the Future tense? \n";
        cout << "1. When will you go to the party.\n2. When are you going to the party.\n3. When is you going to the party." << endl;
        cout << "Please answer between 1 - 3" << endl;
        int answer9;
        cout << "Your select answer: ";
        cin >> answer9;
        if (answer9 == 1)
        {
            score++;
        }
        else
        {
            cout << "Incorrect! The correct answer is 'Choice 1'.\n";
        }
        cout << endl;

        // 10
        cout << "10) Change this sentence is in Future sentence| Do they work on Saturday. ?\n";
        cout << "1. What they work on Saturday. ?\n2. Are they work on Saturday. ?\n3. Will they work on Saturday. ?" << endl;
        cout << "Please answer between 1 - 3" << endl;
        int answer10;
        cout << "Your select answer: ";
        cin >> answer10;
        if (answer10 == 3)
        {
            score++;
        }
        else
        {
            cout << "Incorrect! The correct answer is 'Choice 3'.\n";
        }
        cout << endl;
    }
    return score;
}

void updateHighScores(string playerName, int score, double timeTaken, string mode)
{
    if (totalScores < MAX_SCORES)
    {
        players[totalScores] = playerName;
        highScores[totalScores] = score;
        times[totalScores] = timeTaken;
        modes[totalScores] = mode;
        totalScores++;
    }
    else
    {
        // Replace lowest score if current score is better or time is faster
        int minIndex = 0;
        for (int i = 1; i < MAX_SCORES; i++)
        {
            if (highScores[i] < highScores[minIndex] ||
                (highScores[i] == highScores[minIndex] && times[i] > times[minIndex]))
            {
                minIndex = i;
            }
        }
        if (score > highScores[minIndex] ||
            (score == highScores[minIndex] && timeTaken < times[minIndex]))
        {
            players[minIndex] = playerName;
            highScores[minIndex] = score;
            times[minIndex] = timeTaken;
            modes[minIndex] = mode;
        }
    }
}

void sortScores()
{
    for (int i = 0; i < totalScores - 1; i++)
    {
        for (int j = 0; j < totalScores - i - 1; j++)
        {
            // Sort by highScores (descending) and times (ascending)
            if (highScores[j] < highScores[j + 1] ||
                (highScores[j] == highScores[j + 1] && times[j] > times[j + 1]))
            {
                // Swap scores
                swap(highScores[j], highScores[j + 1]);
                // Swap names
                swap(players[j], players[j + 1]);
                // Swap times
                swap(times[j], times[j + 1]);
                // Swap modes
                swap(modes[j], modes[j + 1]);
            }
        }
    }
}

void displayHighScores()
{
    cout << "\n--- High Scores ---\n";

    // Sort scores from highest to lowest before displaying
    sortScores();

    for (int i = 0; i < totalScores; i++)
    {
        cout << i + 1 << ". " << players[i] << " (Mode: " << modes[i] << ") - Score: "
             << highScores[i] << " - Time: " << times[i] << " seconds\n";
    }
    cout << "--------------------\n";
}

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false; // If there's a non-numeric character, return false
    }
    return true; // Return true if all characters are digits
}

int main()
{

    string playerName;
    cout << "Please enter your username: ";
    getline(cin, playerName);

    while (true)
    {
        displayMenu();

        string input;
        int choice = 0;

        cout << "Choose a mode (1-5): ";
        cin >> input;

        // Check if input is a number and within range 1-5
        if (!isNumber(input))
        {
            cout << "Invalid input. Please enter a number.\n";
            continue; // Go back to displaying the menu
        }

        choice = stoi(input);

        if (choice < 1 || choice > 5)
        {
            cout << "Invalid choice. Please select a number between 1 and 5.\n";
            continue;
        }

        if (choice == 5)
        {
            cout << "Exiting the game.\n";
            break;
        }
        else if (choice == 4)
        {
            // Display high scores
            displayHighScores();
            continue;
        }

        // Start timer
        clock_t start = clock();

        // Play the game according to the selected mode
        int score = playGame(choice);

        // End timer
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;

        // Show player's score
        cout << "Your score is: " << score << endl;
        cout << "Time taken: " << timeTaken << " seconds\n";

        // Update high scores
        string mode = getModeName(choice);
        updateHighScores(playerName, score, timeTaken, mode);

        // Ask player if they want to play again
        cout << "Do you want to play again? (y/n): ";
        char continueGame;
        cin >> continueGame;

        if (continueGame == 'n' || continueGame == 'N')
        {
            cout << "Returning to the main menu.\n";
        }
    }

    return 0;
}
