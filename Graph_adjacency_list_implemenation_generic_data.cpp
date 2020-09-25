//In this we have string name vertix with weight value

#include<iostream>
#include<cstring>
#include<list>
#include<unordered_map>          //for hash mapping
using namespace std;

class graph
{
    unordered_map<string,list<pair<string,int > > > l;
    public:

            void add_edge(string x,string y,bool bidir,int wt)
            {
                l[x].push_back(make_pair(y,wt));
                if(bidir)                                       //if it is bidirectional
                    l[y].push_back(make_pair(x,wt));
            }

            void print_edge()
            {
                for(auto p:l)
                {
                    string city=p.first;
                    list<pair<string,int>> nbrs=p.second;
                    cout<<city<<"->";

                    for(auto nbr:nbrs)
                    {
                        string dest=nbr.first;
                        int dist=nbr.second;

                        cout<<dest<<" "<<dist<<",";
                    }
                    cout<<endl;
                }
            }
};

int main()
{
    graph g;
    g.add_edge("A","B",true,20);
    g.add_edge("B","D",true,20);
    g.add_edge("A","C",true,20);
    g.add_edge("C","D",false,20);
    g.print_edge();

    return 0;
}
