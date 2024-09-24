#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;
int calscore(int midterm, int final, int homework, int assingnment, int classroom);
string calculatetotalscore(int sum);
int main()
{
    srand(time(0));
    int score = 0; //,midterm,final,assingnment,homework,classroom;
    int time;
    cout << endl;
    system("CLS");
    cout << " ----------------------------------------" << endl;
    cout << "         Program Calculate Grade         " << endl;
    cout << " ----------------------------------------" << endl;
    cout << endl;
    cout << "Please enter quantity of student : ";
    cin >> time;
    cout << endl;

    string personNames[50] = {
        "John", "Jane", "Alice", "Supra", "Charlie", "David", "Emily", "Yuumi", "Grace", "Parker",
        "Sangsom", "Phupha", "Katarina", "Yasuo", "Grace", "Putawan", "Thanapon", "Paul", "Poonpon", "Kasapat",
        "Steve", "Tina", "Patrick", "Victor", "Wendy", "Xander", "Lee", "Thanatorn", "Amy", "Ben",
        "Catherine", "Dylan", "Eva", "Felix", "Peter", "Helen", "Vayne", "Julie", "Kevin", "Laura",
        "Lauren", "Nika", "Oscar", "Ahri", "Quinn", "Riley", "Sarah", "Tom", "Darius", "Vince"};
    for (int i = 0; i < time; i++)
    {
        int final = rand() % 31;
        int midterm = rand() % 31;
        int assingment = rand() % 16;
        int classroom = rand() % 11;
        int homework = rand() % 16;

        while (true)
        {

            cout << "| Name (Name and Surname): " << personNames[rand() % 50] + " " + personNames[rand() % 50] << endl;
            cout << "| Midterm score (0 - 30 Point) : ";
            cout << midterm;
            cout << endl;
            if (midterm < 0 || midterm > 30)
            {
                cout << "The score entered is incorrect. Plesase enter score (0 - 30 Point)" << endl;
                midterm = rand() % 31;
                continue;
            }
            break;
        }
        while (true)
        {
            cout << "| Final score (0 - 30 Point) : ";
            cout << final;
            cout << endl;
            if (final < 0 || final > 30)
            {
                cout << "The score entered is incorrect. Plesase enter score (0 - 30 Point)" << endl;
                int final = rand() % 31;
                continue;
            }
            break;
        }
        while (true)
        {

            cout << "| Homework score (0 - 15 Point) : ";
            cout << homework;
            cout << endl;
            if (homework < 0 || homework > 15)
            {
                cout << "The score entered is incorrect. Plesase enter score (0 - 15 Point)" << endl;
                assingment = rand() % 16;
                continue;
            }
            break;
        }

        while (true)
        {

            cout << "| Affective score (0 - 10 Point) : ";
            cout << classroom;
            cout << endl;
            if (classroom < 0 || classroom > 10)
            {
                cout << "The score entered is incorrect. Plesase enter score (0 - 10 Point)" << endl;
                classroom = rand() % 11;
                continue;
            }
            break;
        }

        while (true)
        {

            cout << "| Report score (0 - 15 Point) : ";
            cout << assingment;
            cout << endl;
            if (assingment < 0 || assingment > 15)
            {
                cout << "The score entered is incorrect. Plesase enter score (0 - 15 Point)" << endl;
                homework = rand() % 16;
                continue;
            }
            break;
        }
        while (true)
        {
            if (score > 100)
            {
                cout << "!!! score exceeds 100. Please enter valid score again. !!!" << endl;
                continue;
            }
            break;
        }
        int scoref = calscore(midterm, final, homework, assingment, classroom);
        string grade = calculatetotalscore(scoref);
        cout << "| Student " << i + 1 << " total score is " << scoref << " get grade : " << grade << endl;
        cout << "----------------------------------------------------" << endl;
    }
}
int calscore(int midterm, int final, int homework, int assingnment, int classroom)
{
    int sum = midterm + final + homework + assingnment + classroom;
    return sum;
}

string calculatetotalscore(int sum)
{

    string grade;

    if (sum >= 76)
    {
        grade = "A";
    }
    else if (sum >= 75)
    {
        grade = "B+";
    }

    else if (sum >= 70)
    {
        grade = "B";
    }
    else if (sum >= 65)
    {
        grade = "C+";
    }
    else if (sum >= 60)
    {
        grade = "C";
    }
    else if (sum >= 55)
    {
        grade = "D+";
    }
    else if (sum >= 50)
    {
        grade = "D";
    }
    else if (sum >= 0)
    {
        grade = "F";
    }
    return grade;
}