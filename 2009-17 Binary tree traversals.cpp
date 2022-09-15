# include <iostream>
# include <map>
# include <deque>
std::deque <char> pre;
std::map <char, int> in;

struct Node
{
    char val;
    Node * left = NULL;
    Node * right = NULL;
};

Node * build_tree(int left, int right)
{
    if (left > right)
        return NULL;

    char val = pre.front();
    pre.pop_front();

    int index_inorder = in[val];

    Node * root = new Node; // THIS "new" is necessary
    root -> val = val;
    root -> left = build_tree(left, index_inorder - 1);
    root -> right = build_tree(index_inorder + 1, right);
    return root;
}

void print(Node * root)
{
    if (root == NULL)
        return;
    print(root -> left);
    print(root -> right);
    std::cout << root -> val << " ";
}

int main(void)
{
    int num_case;
    int n;
    char temp;


    std::cin >> num_case;
    for (int i = 0; i < num_case; i++)
    {
        std::cin >> n;
        // queue for preorder
        for(int i = 0; i < n; i++)
        {
            std::cin >> temp;
            pre.push_back(temp);
        }
        // map for inorder
        for(int i = 0; i < n; i++)
        {
            std::cin >> temp;
            in[temp] = i;
        }
        // build tree
        Node * root = build_tree(0, n - 1);

        // post order traversal
        print(root);
        std::cout << std::endl;

    }
}
