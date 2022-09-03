# include <iostream>
# include <string>
# define N 50

long long out[N];

// [2*[5+[-2]]]
void parse(std::string s, int n)
{
    // iterate thru each char
    // 1. find m
    // 2. find the base [-2]
    int m = 0;
    int sign = 1;
    char post;
    int i;
    for (i = 1; s[i]; i++) //discard '['
    {
        if (s[i] == '-')
            sign = -1;
        else if (s[i] >= '0' && s[i] <= '9')
            m = (m * 10) + (s[i] - '0'); // since we process chars one by one
        else
        {
            // s[i] = '*' or '+' or ']'
            // NOTICE: NOT POSSIBLE TO HAVE '[' (since '[' follows '*' or '+')
            post = s[i];
            break;
        }
    }
    m = m * sign;

    if (post == '*')
    {
        parse(s.substr(i + 1), n);
        out[0] = m * out[0];
        for (int i = 1; i < n; i++)
            out[i] = out[i-1] * out[i];
    }

    else if (post == '+')
    {
        parse(s.substr(i + 1), n);
        long long temp1 = out[0];
        out[0] = m;
        for (int i = 1; i < n; i++)
        {
            long long temp2 = out[i];
            out[i] = out[i - 1] + temp1;
            temp2 = temp1;

        }
    }
    else // post == ']'. This reaches the end of the recursion. Build base array.
    {
        for (int i = 0; i < n; i++)
        {
            out[i] = m;
        }
    }
}

int main(void){
    std::string s;
    int n;
    while(std::cin >> s >> n)
    {
        parse(s, n);
        for (int i = 0; i < n; i++)
            std::cout << out[i] << " ";
        std::cout << std::endl;
    }
}
