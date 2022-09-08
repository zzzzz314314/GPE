# include <iostream>
# include <cmath>
// maximum bipartite matching using ¦I¤ú§Qºâªk
// https://blog.csdn.net/dark_scope/article/details/8880547
int adj[100][100];
struct pos
{
    double x, y;
}gopher[100], hole[100];
int hole_visited[100];
int n, m, s, v;
int hole_assigned_to[100];

int DFS(int i) // find hole for gopher i
{
    // try out each hole
    // if 1. the hole is connected to the gopher AND 2. is not visited
    // 2. is important or the recursion will not stop
    //    see https://web.ntnu.edu.tw/~algo/AlternatingTree1.png
    //    The tree will grow nonstop if 2. is not considered
    //    Hence hole_visited means differently to hole_assigned_to
    for (int j = 0; j < m; j++)
    {
        if (adj[i][j] && !hole_visited[j]) // can stop the recursion (condition)
        {
            hole_visited[j] = 1;
            // if 1. the hole is not assigned
            // OR 2. the hole is assigned to say gopher_x, ask gopher_x to try finding some other holes
            // then the hole can be assigned to this gopher i
            if (hole_assigned_to[j] == -1 || DFS(hole_assigned_to[j]))
            {
                hole_assigned_to[j] = i;
                return 1;
            }
        }
    }
    return 0;
}


int main(void)
{


    while(std::cin >> n >> m >> s >> v)
    {
        int saved_gospher = 0;
        // read
        for (int i = 0; i < n; i++)
            std::cin >> gopher[i].x >> gopher[i].y;
        for (int i = 0; i < m; i++)
            std::cin >> hole[i].x >> hole[i].y;
        // build adj
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if ((sqrt(pow(gopher[i].x-hole[j].x, 2) + pow(gopher[i].y-hole[j].y, 2)) / double(v)) > double(s))
                    adj[i][j] = 0;
                else
                    adj[i][j] = 1;
        // init
        for (int i =0; i < m; i++)
            hole_assigned_to[i] = -1;
        // try to assign hole for each gopher
        for (int i = 0; i < n; i++)
        {
            // clear hole visited
            for (int j = 0; j < 100; j++)
                hole_visited[j] = 0;
            if (DFS(i))
                saved_gospher += 1;

        }
        std::cout << n - saved_gospher << std::endl;
    }
}
