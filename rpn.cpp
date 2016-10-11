
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{
    string input;
    cout << input ;
    getline(cin,input);
    istringstream iss(input);
    stack <double> stack;
    
    while (iss>> input)
    {
            stack.push(input);
        
        
        else if (input == "+"||input == "-"||input == "*"||input == "/")
        {
            if (stack.size() < 2)
            {
                cout << "stack underflow" <<endl;
                exit(0);
            }
            double num2 = stack.top();
            stack.pop();
            double num1 = stack.top();
            stack.pop();
            
            switch (input[0])
            {   case '+':
                {
                    stack.push(num1 + num2);
                    break;
                }
                case '-':
                {
                    stack.push(num1 - num2);
                    break;
                }
                case '*':
                {
                    stack.push(num1 * num2);
                    break;
                }
                case '/':
                {
                    if(num2 != 0)
                    {
                        stack.push(num1 / num2);
                    }
                    else{
                        cout << "division by zero" <<endl;
                        exit(0);
                    }
                    break;
                }
            }//end switch
        } //end else if
        else
        {
            cout << "invalid input" << endl;
            exit(0);
        }
    }//end while
    while (!stack.empty())
    {
        cout <<stack.top() <<endl;
        stack.pop();
    }
}
