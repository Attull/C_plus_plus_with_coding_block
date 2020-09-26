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

            void bfs(T src)
            {
                map<T,int> dist;
                queue<int> q;

                for(auto node_pair:l)
                {
                    T node=node_pair.first;
                    dist[node]=INT_MAX;
                }

                q.push(src);
                dist[src]=0;

                while(!q.empty())
                {
                    T node=q.front();
                    q.pop();

                    for(int nbr:l[node])
                     {
                        if(dist[nbr]==INT_MAX)
                        {
                            q.push(nbr);
                            dist[nbr]=dist[node]+1;
                        }
                     }
                }

                //print distance to every node
                for(auto node_pair:l)
                {
                    T node=node_pair.first;
                    int d=dist[node];
                    cout<<"Node "<<node<<" dist from src "<<d<<endl;
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

    g.bfs(0);
    return 0;
}
