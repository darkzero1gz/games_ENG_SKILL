#include <iostream>
using namespace std;
#include <cstring>
bool palindrome(char string[])
{
    int len = strlen(string);                 // strlen(text); ใช้คำนวณความยาวของข้อความ
    for (int i = 0; i < len / 2; i++)         // i = 0 // 0 < pop(3) / 2 // 0+1
    {                                         // pop[0] != pop[3 - 1 - (i)0]
                                              // p[0] != p[2]
                                              //  p o p  // 0 1 2
        if (string[i] != string[len - 1 - i]) // ต้อง - 1 เพราะ array เริ่มต้นที่ 0 เช่น POP(012) len(3) - 1 -i
                                              // POP(3) - 1 -i(0) = 2
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char text[99];
    cout << "This Program Check Palindrome " << endl;
    cout << "******************************" << endl;
   while (true)
   {
    
   
   
    
    cout << "Enter text : ";
    cin >> text;
    int len = strlen(text);
    cout << "--------------------------------" << endl;
  
    for (int k = 0; k < len; k++)
    {

        cout << text[k] << " = " << text[k] << endl;
    }

    if (palindrome(text))
    {
        cout << "Your text is Palindrome" << endl;
        cout << "--------------------------------" << endl;
    }
    else
    {
        cout << "Your text not Palindrome" << endl;
        cout << "-------------------------------" << endl;
    }
}
    return 0;
}