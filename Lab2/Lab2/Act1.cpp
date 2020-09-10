// C++ program for expression tree 
#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

class ExprAritmeticas {
public:             
    string expr;
    stack<int> celtic;
    stack<string> pairs;
    
    string postF(string str) {
        string fin = "";
        stack<char> temp;
        for (int i = 0; i < str.length(); i++) {
            if (isalpha(str.at(i))) {
                fin = fin + str.at(i);
            }
            else if (str.at(i) == '(') {
                temp.push(str.at(i));
            }
            else if (str.at(i) == ')') {
                while (!temp.empty()) {
                    char a = temp.top();
                    temp.pop();
                    if (a != '(') {
                        fin = fin + a;
                    }
                    else {
                        break;
                    }
                }
            }
            else if (str.at(i) == '+' || str.at(i) == '-' || str.at(i) == '*' || str.at(i) == '/') {
                if (temp.empty()) {
                    temp.push(str.at(i));
                }
                else {
                    while (!temp.empty()) {
                        char a = temp.top();
                        temp.pop();
                        if (a == '(') {
                            temp.push(a);
                            break;
                        }
                        else if (str.at(i) == '+' || str.at(i) == '-' || str.at(i) == '*' || str.at(i) == '/') {
                            //temp.push(a);
                            fin = fin + a;
                            break;
                        }
                    }
                    temp.push(str.at(i));
                }
            }
        }

        while (!temp.empty()) {
            fin = fin + temp.top();
            temp.pop();
        }

        return fin;
    }

    double Results(string letters) {
        double res = 0;
        stack<double> numbers;
        for (int i = 0; i < letters.length(); i++) {
            if (isalpha(letters.at(i))) {
                double num = letters.at(i) - 96;
                numbers.push(num);
            }
            else if (letters.at(i) == '+' || letters.at(i) == '-' || letters.at(i) == '*' || letters.at(i) == '/') {
                double b = numbers.top();
                numbers.pop();
                double a = numbers.top();
                numbers.pop();
                switch (letters.at(i)) {
                case '+':
                    res = a + b;
                    break;

                case'-':
                    res = a - b;
                    break;

                case '*':
                    res = a * b;
                    break;

                case '/':
                    res = a / b;
                    break;
                }
                numbers.push(res);
            }
        }

        double tmp = numbers.top();
        numbers.pop();
        return tmp;
    }


};

int main()
{
    string exp = "x/(f/b)";
    ExprAritmeticas arm;
    cout<<arm.postF(exp)<<"\n";
    cout << arm.Results(arm.postF(exp));

    return 0;
}
