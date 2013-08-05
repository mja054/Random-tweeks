#include <iostream>

using namespace std;

int c;

void
addition(int a, int b)
{
        c = a + b;

        cout << "Addition of " << a << " and " << b << " is " << c << endl;
 
        return;
}

void
subtraction(int a, int b)
{
        c = a - b;

        cout << "subtraction of " << a << " and " << b << " is " << c << endl;
 
        return;
}

void
multiplication(int a, int b)
{
        c = a * b;

        cout << "multiplication of " << a << " and " << b << " is " << c << endl;
 
        return;
}

void
division(int a, int b)
{
        c = a / b;

        cout << "division of " << a << " and " << b << " is " << c << endl;
 
        return;
}

int
main ()
{
        int a, b;
        char flag, op;

        while (1) {
                cout << "Press\n";
                cout << "1 -> +\n";
                cout << "2 -> -\n";
                cout << "3 -> *\n";
                cout << "4 -> /\n";

                cin >> op;

                cout << "Enter two numbers:";
                cin >> a >> b;


                switch (op) {
                case '+': addition(a, b);
                        break;

                case '-': subtraction(a, b);
                        break;

                case '*': multiplication(a, b);
                        break;

                case '/': division(a, b);
                        break;
                }

                cout << "Do you want to go again(y/n):";
                cin >> flag;

                if (flag == 'y')
                        continue;
                else {
                        cout << "Terminating the program, is this what you want(y/n):";
                        cin >> flag;
                        if (flag == 'n')
                                break;
                }
        }
        return 0;
}

        
                
