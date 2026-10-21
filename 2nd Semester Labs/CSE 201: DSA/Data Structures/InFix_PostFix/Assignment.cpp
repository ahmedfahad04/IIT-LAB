#include <bits/stdc++.h>
#define N 100
using namespace std;

double int_stack[N] = {0};
int int_top = -1;
char char_stack[N] = {'\0'};
int char_top = -1;

// next 2 function is for pushing stack element
void push_int(double x)
{

    if (int_top == N - 1)
    {
        printf("Stack Overflow!!!\n");
    }
    else
    {
        int_stack[++int_top] = x;
    }
}

void push_char(char x)
{

    if (char_top == N - 1)
    {
        printf("Stack Overflow!!!\n");
    }
    else
    {
        char_stack[++char_top] = x;
    }
}

// next 2 function is for poping stack element
double pop_int()
{
    if (int_top == -1)
    {
        printf("Stack Underflow!!!\n");
        return -1;
    }
    else
    {

        return int_stack[int_top--];
    }
}

char pop_char()
{
    if (char_top == -1)
    {
        printf("Stack Underflow!!!\n");
        return '\0';
    }
    else
    {
        return char_stack[char_top--];
    }
}

// string to number conversion
int num(string x)
{

    int i, j, k, sum = 0;
    k = x.size();

    for (i = 0; i < x.size(); i++)
    {
        j = (x[i] - '0') * pow(10, k - 1);
        sum += j;
        k--;
    }

    return sum;
}

// operator(+,-,*,/) priority
int preference(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

string str_to_num(string x)
{

    int sum = num(x), j;
    string new_str;

    while (sum != 0)
    {
        j = sum % 10;
        sum /= 10;
        new_str += j + '0';
    }

    reverse(new_str.begin(), new_str.end());
    return new_str;
}

// next 2 function print the stack
void print_stack()
{
    if (char_top < 0)
        printf("No elements in the stack.\n");
    else
    {

        int i;
        for (i = char_top; i >= 0; i--)
        {
            printf("\nStack(CHAR)>> %c\n", char_stack[i]);
        }
        puts("");
    }
}

void print_stack_int()
{
    if (int_top < 0)
        printf("No elements in the stack.\n");
    else
    {

        int i;
        for (i = int_top; i >= 0; i--)
        {
            printf("\nStack>> %d\n", int_stack[i]);
        }
        puts("");
    }
}

// function for evaluating postfix expression******
void evaluation(string result)
{
    string ex, number;
    char ch[100], x;
    int i, j, cnt = 0;

    for (int i = 0; i < result.size(); i++)
    {
        if (isalnum(result[i]))
        {
            number += result[i];
            i++;
            while (isalnum(result[i]))
            {
                number += result[i++];
            }
            i--;

            push_int(num(number));

            number.clear();
        }
        else if (result[i] == ' ')
            continue;
        else if (result[i] == '+' || result[i] == '-' || result[i] == '*' || result[i] == '/')
        {

            double a = pop_int();
            double b = pop_int();

            if (result[i] == '+')
                push_int(b + a);
            else if (result[i] == '-')
                push_int(b - a);
            else if (result[i] == '*')
                push_int(b * a);
            else if (result[i] == '/')
                push_int(b / a);
        }
    }

    cout << "\nValue: " << pop_int() << endl;
}

// infix to postfix conversion******
string infix_to_postfix(string ex)
{
    string number,result="";
    char ch[100], x;
    int i, j, cnt = 0;

    for (i = 0; i < ex.size(); i++)
    {

        if (isalnum(ex[i])) //check wether it is a 0-9(digits)
        {
            number += ex[i];
            i++;
            while (isalnum(ex[i]))
            {
                number += ex[i];
                i++;
            }
            i--;

            if (number.size() > 1)
                result += str_to_num(number);
            else
                result += number;

            result += " ";
            cout << number << ", ";
            number.clear();
        }

        else if (ex[i] == '(') // check open braces
        {
            push_char('(');
        }

        else if (ex[i] == ')') // check closed braces
        {

            x = pop_char();

            while (x != '(')
            {
                result += x;
                result += " ";

                cout << x << ", ";
                x = pop_char();
            }
        }

        else if (ex[i] == ' ') // check spaces.
        {

            continue;
        }

        else // check for +,-,*,/
        {
            while (preference(char_stack[char_top]) >= preference(ex[i]))
            {
                x = pop_char();
                result += x;
                result += " ";
                cout << x << ", ";
            }
            push_char(ex[i]);
        }
    }
    fflush(stdin);

    while (char_top != -1) // check for the last elements left in the character stack
    {
        x = pop_char();
        result += x;

        cout << x << ", ";
    }

    return result;
}


int main()
{
    string ex, my_str;
    char ch[100];
    int i;

    cout << "Enter your Expression: ";
    gets(ch);
    
    for (int i = 0; i < strlen(ch); i++)
        ex += ch[i];

    cout << "Postfix Expression: ";
    // infix to postfix conversion---------------------------------------------------
    my_str = infix_to_postfix(ex);

    // postfix to evaluation starts------------------------------------------------
    evaluation(my_str);
}
