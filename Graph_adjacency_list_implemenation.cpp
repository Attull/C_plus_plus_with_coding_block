#include<iostream>
#include<list>
using namespace std;

class graph
{
    int v;
    list<int> *l;      //define pointer that points to list of array (array in which each element is a list)

    public:
            graph(int v)
            {
                this->v=v;
                l=new list<int> [v];
            }

            void add_edge(int x,int y)     //edge from x to y or y to x i.e. bidirectional graph
            {
                l[x].push_back(y);
                l[y].push_back(x);
            }

            void print_edgelist()
            {
                for(int i=0;i<v;++i)
                {
                    cout<<"Vertices "<<i<<"->";
                    for(int nbr:l[i])
                        cout<<nbr<<",";

                cout<<endl;
                }
            }
};

int main()
{
    graph g(4);

    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(2,3);
    g.add_edge(1,2);

    g.print_edgelist();

    return 0;
}
