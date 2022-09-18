# include <iostream>
# include <string>
# include <cmath>
# include <stack>
# include <limits>

int eval(std::string s)
{
    std::stack <int> st;

    // process from the back
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];

        // we are reading a number (operand)
        if (c >= '0' && c <= '9')
        {
            int num = 0;
            int digits = 0;
            while(s[i] >= '0' && s[i] <= '9')
            {
                num += std::pow(10, digits) * (s[i] - '0');
                i -= 1;
                digits += 1;
            }
            st.push(num);
        }

        // we are reading an operator
        if (c == '+' || c == '-' || c == '*' || c =='/' || c == '%')
        {
            if (st.size() < 2)
                return std::numeric_limits<int>::max(); // wrong expression: lack of operand
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            int temp;
            switch (c)
            {
                case '+': temp = op1 + op2; break;
                case '-': temp = op1 - op2; break;
                case '*': temp = op1 * op2; break;
                case '/': temp = op1 / op2; break;
                case '%': temp = op1 % op2; break;
            }
            st.push(temp);
        }

    }
    if (st.size() == 1)
        return st.top();
    else
        return std::numeric_limits<int>::max(); // wrong expression: additional operand
}
int main(void)
{
    std::string s;
    while(getline(std::cin, s) && s[0] != '.')
    {
        int result = eval(s);

        if (result == std::numeric_limits<int>::max())
            std::cout << "illegal" << std::endl;
        else
            std::cout << result << std::endl;
    }
}
