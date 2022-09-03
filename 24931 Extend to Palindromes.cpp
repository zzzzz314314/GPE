# include <iostream>
# include <string>

/*
 s = aaaa
 p = aaaa (inverse of p)
 Compare s and p. During matching, when s_index moves to the last,
 p_index also moves to the last. Nothing in p needs to be concatenated
 to s to complete the palindrome.

 s = abba
 p = abba
 Compare s and p. During matching, when s_index moves to the last,
 p_index also moves to the last. Nothing in p needs to be concatenated
 to s to complete the palindrome.

 s = amanaplanacanal
 p =       lanacanalpanama
 Compare s and p. During matching, when s_index moves to the last,
 p_index moves to lanacanal"p"anama. Complete the palindrome of s with
 panama.
*/

int * construct_LPS(std::string p)
{
    int p_len = p.length();
    // static int LPS[p_len];
    // THIS IS IMPORTANT!
    int * LPS = new int [p_len];
    LPS[0] = 0;
    int len = 0;

    for (int p_index = 1; p_index < p_len; p_index++)
    {
        while (len != 0 && p[len] != p[p_index])
            len = LPS[len - 1];
        if (p[len] == p[p_index])
            len += 1;
        LPS[p_index] = len;
    }
    return LPS;
}

int KMP(std::string s, std::string p)
{
    // construct LPS array of p first
    int * LPS = construct_LPS(p);

    int s_len = s.length();
    int p_len = p.length();
    int p_index = 0;

    for (int s_index = 0; s_index < s_len; s_index++)
    {
        while (p_index != 0 && s[s_index] != p[p_index])
            p_index = LPS[p_index - 1];
        if (s[s_index] == p[p_index])
            p_index += 1;
        //if (p_index == p_len){
            // std::cout << "Pattern found at s_index " << s_index - (p_index - 1);
            // p_index = LPS[p_index - 1];
        //}
    }
    return p_index;

}

int main(void){
    std::string s;
    int len;
    int index_p;

    while(std::cin >> s)
    {
        // p = inverse s
        std::string p = s;
        len = s.length();
        for (int i = 0; i < len; i++)
            p[i] = s[len - 1 - i];

        // KMP matching of p and s
        index_p = KMP(s, p);
        // std::cout << "index_p " << index_p <<std::endl;
        // print result
        std::cout << s;
        for (int i = index_p; i < len; i++)
            std::cout << p[i];
        std::cout << "\n";
    }

}
