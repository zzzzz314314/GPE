# include <iostream>
# include <string>
# include <vector>

// the decompress is exactly the same process as compress
// one sided queue => use vector is good.
// for each encountered "word" or "num"
//     if is "num"
//         find the corresponding word indexed with num (reversely finding) and print
//         move the word to the last of vector
//     else if is "word"
//         print the word
//         append the word to the vector

/*
 * to compress:

Dear Sally,

   Please, please do it--it would please
Mary very, very much.  And Mary would
do everything in Mary's power to make
it pay off for you.

   -- Thank you very much--
much
very
Thank
you
for
off
pay
it
make
to
power
s
Mary
in
everything
do
would
And
please
Please
Sally
Dear

Dear Sally,
    Please, please do it -- 1 would 4
Mary very, 1 much. And 4 6
8 everything in 5's power to make
14 pay off for you.

  -- Thank 2 18 18--

*/

/*
 * to decompress:

Dear Sally,

   Please, please do it--1 would 4
Mary very, 1 much.  And 4 6
8 everything in 5's power to make
14 pay off for you.

   -- Thank 2 18 18--
0

would
Mary
And
much
very
please
it
do
Please
Sally
Dear

Dear Sally,

    Please, please do it--it would please
Mary very, very much. And Mary would

*/

int main(void)
{
    std::string s;
    std::vector <std::string> lookup;


    while(std::getline(std::cin, s) && s[0] != '0')
    {
        // 1. since numbers or words come char by char
        //    need some accumulation manner for numbers and words.
        // 2. how to know the end of one number, or word
        //    => identify by space is incorrect (Mary's = Mary and s)
        //    => char + (not char) and digit + (not digit)
        int num;
        std::string word;

        for (int i = 0; s[i]; i++)
        {
            // if this char is alphabet
            if (isalpha(s[i]))
            {
                word = ""; // init a empty accumulating word
                while(isalpha(s[i]))
                {
                    word.insert(word.end(), s[i]);
                    i += 1;
                }
                // This is necessary. Consider "Mary's"
                // i now goes to ' and in the next for (line:107), i indicates s
                // This way, the printing of ' is ignored.
                i -= 1; // the increment of last i += 1 shouldn't be done. It is tackled by for in line107
                lookup.push_back(word);
                std::cout << word;
            }

            // if this char is a digit
            else if (isdigit(s[i]))
            {
                num = 0;
                while(isdigit(s[i]))
                {
                    num = (num * 10) + (s[i] - '0');
                    i += 1;
                }
                // find the word in lookup indexed with num
                word = lookup[lookup.size() - num];
                // erase the word from lookup first
                lookup.erase(lookup.end() - num);
                // append the word to the bottom of lookup
                lookup.push_back(word);

                i -= 1;
                std::cout << word;
            }

            // if this char is space, ', just print out
            else
                std::cout << s[i];
        }
        std::cout << std::endl;
    }
}
