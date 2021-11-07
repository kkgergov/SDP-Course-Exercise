#include <iostream>
#include <string>
#include <stack>
using namespace std;

string repeatString(string str, int n)
{
    string result;

    for (int i = 0; i < n; i++)
        result += str;

    return result;
}

//my tests:
//   "1(2(3(AB)4(5(C)6(D)))7(Z))"

int main()
{
    //////FIRST WE NEED 2 STACKSs

    //first stack in which we keep number of repetitions of the top of the string stack

    stack<int> s1;

    //the second stack is where we are going to generate the string, we use sentinels to denote opening scopes(opening bracket is new scope so we add sentinel to stack)
    //when we see closing bracket in the input we compute everything in the stack up to the top-most sentinel and pop it, then copy it stack1.top() number of times
    //and push the result back in stack 2

    stack<string> s2; //we use "@" for sentinel

    //////INPUT
    string input;
    cin >> input;

    //////ITERATOR
    string::const_iterator cit = input.cbegin();

    //////SOLUTION
    while (cit != input.end())
    {
        char current_char = *cit;

        if (isspace(current_char))
        {
        }

        else if (isdigit(current_char)) //if we see digit, attempt to get the whole number
        {
            int result = 0;

            while (isdigit(*cit))
            {

                result = result * 10 + int(*cit - '0');
                ++cit;
            }

            s1.push(result);
            continue;
        }

        else if (isalpha(current_char)) //if we see letter, take the whole word
        {
            string result;

            while (isalpha(*cit))
            {
                result.push_back(*(cit++));
            }

            s2.push(result);
            continue;
        }

        else if (current_char == '(')
        {
            s2.push("@");
        }

        else
        { //we assume that if its none of the above we have ')'
            string result;

            while (s2.top() != "@")
            {
                result.insert(0, s2.top());
                s2.pop();
            }

            s2.pop();

            int n_repeats = s1.top();
            s1.pop();

            s2.push(repeatString(result, n_repeats));
        }

        ++cit;
    }

    cout << s2.top() << endl;

    system("pause");
    return 0;
}
