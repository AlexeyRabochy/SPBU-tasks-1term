/*
Alexey Rabochy 26.12.13
Recursive descent
*//*
Grammar:
Expr ::= Term(('+'|'-')Term)*
Term ::= Factor(('*'|'/')Factor)*
Factor ::= Number | '(' Expr ')'
*/
#include <stdio.h>
#include <stdlib.h>

#define LENGH 1000
#define NUMBER 1
#define SIGN 2
#define ERROR 3
#define EOF 4
#define OPEN_BR 5
#define CLOSE_BR 6

typedef struct Token
{
    int type;
    char sign;
    int value;
} Token;

char s[LENGH];
int cur = 0;
Token token;

void nextToken();
int expr();
int factor();
int term();

void nextToken()
{
    int num = 0;
    token.type = 0;

    while (s[cur] == ' ')
    {
        cur++;
    }

    while (s[cur] >= '0' && s[cur] <= '9')
    {
        num *= 10;
        num += (int)(s[cur] - '0');
        token.type = NUMBER;
        cur++;
    }
    if (token.type == NUMBER)
    {
        token.value = num;
    }
    else if (s[cur] == '+' || s[cur] == '-' || s[cur] == '*' || s[cur] == '/')
    {
        token.sign = s[cur];
        token.type = SIGN;
        cur++;
    }
    else if (s[cur] == '\n')
    {
        token.type = EOF;
    }
    else if (s[cur] == '(')
    {
        token.type = OPEN_BR;
        cur++;
    }
    else if (s[cur] == ')')
    {
        token.type = CLOSE_BR;
        cur++;
    }
    else
    {
        token.type = ERROR;
    }
}


int expr()
{
    int result = term();

    while (token.type == SIGN && (token.sign == '+' || token.sign == '-'))
    {
        char sign = token.sign;
        nextToken();

        if (sign == '+')
        {
            result += term();
        }
        else
        {
            result -= term();
        }
    }
    return result;
}

int term()
{
    int result = factor();
    int n = 0;
    int num = 0;
    char c;

    while (token.type == SIGN && (token.sign == '*' || token.sign == '/'))
    {
        char sign = token.sign;
        nextToken();

        if (sign == '*')
        {
            result *= factor();
        }
        else
        {
            int tmp = factor();

            if (tmp == 0)
            {
                printf("Error: Division by zero");
                exit(1);
            }

            result /= tmp;
        }
    }

    return result;
}

int factor()
{
    if (token.type == NUMBER)
    {
        int tmp = token.value;
        nextToken();
        return tmp;
    }
    else if (token.type == OPEN_BR)
    {
        nextToken();
        int tmp = expr();

        if (token.type == CLOSE_BR)
        {
            nextToken();
            return tmp;
        }
        else
        {
            printf("Error: ')' expected.");
            exit(1);
        }
    }
    else
    {
        printf("Error: Syntax error.");
        exit(1);
    }
}

int main()
{
    int result = 0;
    fgets(s, 1000, stdin);
    nextToken();
    result = expr();
    if (token.type != EOF)
    {
        printf("Error: end of file expected.");
        return(1);
    }
    printf("Result: %d\n", result);
	system("pause");
    return 0;
}