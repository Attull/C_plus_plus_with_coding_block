
#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<limits.h>
using namespace std;

template<typename T>

class graph
{
    map<T ,list<T>> l;

    public:
            void add_edge(int x,int y)
            {
                l[x].push_back(y);
                l[y].push_back(x);
            }

            void dfs_helper(T src,map<T,bool> &visited)
            {
                cout<<src<<" ";
                visited[src]=true;
                //go to allnbr of that node that is not visited
                for(T nbr:l[src])
                {
                    if(!visited[nbr])
                    {
                        dfs_helper(nbr,visited);
                    }
                }
            }

            void dfs(T src)
            {
                map<T,bool> visited;
                //mark all the nodes as not visited in the begining

                for(auto p:l)
                {
                    T node=p.first;
                    visited[node]=false;
                }

                int cnt=0;
                for(auto p:l)
                {
                    T node=p.first;

                    if(!visited[node])
                    {
                        cout<<"Component "<<cnt<<"-->";
                        dfs_helper(node,visited);
                        cnt++;
                        cout<<endl;
                    }
                }

            }

};

int main()
{
    graph<int> g;

    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(0,3);
    g.add_edge(3,4);
    g.add_edge(4,5);

    g.add_edge(8,8);
    g.dfs(0);
    return 0;
}

