#include <iostream>
#include <string>
using namespace std;
int calscore(int midterm, int final, int homework, int assingnment, int classroom);
string calculatetotalscore(int sum);
int main()
{
    int score = 0, midterm, final, homework, assingnment, classroom;
    string name;
    cout << endl;
    system("CLS");
	cout << " ----------------------------------------" << endl;
	cout << "         Program Calculate Grade         " << endl;
	cout << " ----------------------------------------" << endl;
    cout << endl;
	cout << "Please enter your name : ";
	getline(cin,name);
	cout << endl;
    while (true)
    {
        cout << "Enter midterm score (0 - 30 Point) : ";
        cin >>midterm;
        cout << endl;
        if (midterm < 0 || midterm > 30)
        {
            cout << "The score entered is incorrect. Plesase enter score (0 - 30 Point)" << endl;
            continue;
        }
        break;
    }
    while (true)
    {
        cout << "Enter final score (0 - 30 Point) : ";
        cin >> final;
        cout << endl;
        if (final < 0 || final > 30)
        {
            cout << "The score entered is incorrect. Plesase enter score (0 - 30 Point)" << endl;
            continue;
        }
        break;
    }
    while (true)
    {

         cout << "Enter homework score (0 - 15 Point) : ";
         cin >> homework;
         cout << endl;
         if (homework < 0 || homework > 15)
         {
             cout << "The score entered is incorrect. Plesase enter score (0 - 15 Point)" << endl;
             continue;
         }
         break;
    }
    
    while (true)
    {

         cout << "Enter affective score (0 - 10 Point) : ";
         cin >> classroom;
         cout << endl;
         if (classroom < 0 || classroom > 10)
         {
             cout << "The score entered is incorrect. Plesase enter score (0 - 10 Point)" << endl;
             continue;
         }
         break;
    }

    while (true)
    {

        cout << "Enter report score (0 - 15 Point) : ";
        cin >> assingnment;
        cout << endl;
        if (assingnment < 0 || assingnment > 15)
        {
            cout << "The score entered is incorrect. Plesase enter score (0 - 15 Point)" << endl;
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
    int scoref = calscore( midterm,  final,  homework,  assingnment,  classroom);
    string grade = calculatetotalscore(score);
	
    cout << "Your total score is " << scoref << endl;
    cout << endl;
    cout <<"Your grade is " << grade << endl;
    
}

int calscore(int midterm, int final, int homework, int assingnment, int classroom)
{
    int sum = midterm + final + homework + assingnment + classroom;
    return sum;
}

string calculatetotalscore(int sum)
{
   
    string grade;

     if (sum >= 55 && sum <= 59)
    {
        grade = "D";
    }
    else if (sum >= 60 && sum <= 64)
    {
        grade = "D+";
    }

    else if (sum >= 65 && sum <= 69)
    {
        grade = "C";
    }
    else if (sum >= 70 && sum <= 74)
    {
        grade = "C+";
    }
    else if (sum >= 75 && sum <= 79)
    {
        grade = "B";
    }
    else if (sum >= 80 && sum <= 84)
    {
        grade = "B+";
    }
    else if (sum >= 80 && sum <= 89)
    {
        grade = "A";
    }
    else if (sum >= 0 && sum < 50 )
    {
        grade = "F";
    }
    return grade;
}
