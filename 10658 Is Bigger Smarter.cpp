# include <iostream>
# include <algorithm>
# include <vector>
/*
 ind: 4    5   9     7
 w: 1000 1100 2000 8000
 I: 4000 3000 1900 1400
*/

/*
Seems very much like LIS (w.r.t. weights), but we have additional constraint (IQ)
Another difference is in LIS, we cannot sort yet here we can. We first try to sort the sequence w.r.t weight

el_num:   3  (4)  (5)  (9)  2    6    8    1    (7)
weight: 500 1000 1100 2000 6000 6000 6000 6008 8000
IQ:    2000 4000 3000 1900 2100 2000 1200 1300 1400

LDS:     1     1    2    3   3    4    5   5    5
LDS_from 0     1    1    2   2    4    5   5    5

In this case, we can ignore the weight constraint, and this might be a problem of pure LIS if we look only at IQ.
Note during weight sorting, if the two elephants have the same weight, we then sort (inversely) with IQ to ensure the maximized sequence length
*/

struct Elephant
{
    int num;
    int w;
    int iq;
}elephant[10000];

bool cmp(Elephant e1, Elephant e2)
{
    if (e1.w == e2.w)
        return e1.iq > e2.iq;
    return e1.w < e2.w;
}

int main(void)
{
    int ww, iqq, elephant_num = 0;
    while(std::cin >> ww >> iqq)
    {
        elephant[elephant_num].num = elephant_num + 1; // the elephant index starts from 1
        elephant[elephant_num].w = ww;
        elephant[elephant_num].iq = iqq;
        elephant_num += 1;
    }
    std::sort(elephant, elephant+elephant_num, cmp); // sort the elephants with increasing weight, and if the weights are the same, compare the iq.

    //for (int i = 0; i < elephant_num; i++)
        //std::cout << elephant[i].num << " ";

    // start LDS (longest increasing subsequence -> longest decreasing subsequence)
    int LDS[10000];
    int LDS_from[10000];
    // init LIS
    for (int i = 0; i < elephant_num; i++)
    {
        LDS[i] = 1;
        LDS_from[i] = i;
    }

    // update LDS
    for (int i = 0; i < elephant_num; i++)
        for (int j = 0; j < i; j++)
            // This ensures:
            // W[a[1]] < W[a[2]] < ... < W[a[n]]... the weights are strictly increasing
            // S[a[1]] > S[a[2]] > ... > S[a[n]]... the iqs are strictly decreasing
            if (elephant[i].iq < elephant[j].iq && elephant[i].w != elephant[j].w)
            {
                if (LDS[j] + 1 > LDS[i])
                {
                    LDS[i] = LDS[j] + 1;
                    LDS_from[i] = j;
                }
            }

    // find the LDS length
    int LDS_len = 0;
    int LDS_ind = 0;
    for (int i = 0; i < elephant_num; i++)
    {
        if (LDS[i] > LDS_len)
        {
            LDS_len = LDS[i];
            LDS_ind = i;
        }
    }
    //print result
    std::cout << LDS_len << std::endl;
    // backtrack where the LDS_ind comes from
    std::vector <int> ans;
    while(LDS_ind != LDS_from[LDS_ind])
    {
        // std::cout << LDS_ind << std::endl;
        // std::cout << elephant[LDS_ind].num << std::endl;
        ans.push_back(elephant[LDS_ind].num);
        LDS_ind = LDS_from[LDS_ind];
    }
    ans.push_back(elephant[LDS_ind].num);
    // std::cout << elephant[LDS_ind].num;
    for (int i = ans.size()-1; i >= 0; i--)
        std::cout << ans[i] << std::endl;


}
