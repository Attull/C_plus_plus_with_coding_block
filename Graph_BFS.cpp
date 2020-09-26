#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

template<typename T>

class graph
{
    map<T,list<T> > l;

    public:
            void add_edge(int x,int y)
            {
                l[x].push_back(y);
                l[y].push_back(x);
            }

            void bfs(T src)
            {
                map<T,int> visited;         //to store which node is visited
                queue<T> q;

                q.push(src);                //push source node in queue
                visited[src]=true;          //mark as visited

                while(!q.empty())
                {
                    T node=q.front();         //store visited node from queue
                    q.pop();                //pop it
                    cout<<node<<" ";
                    for(int nbr:l[node])    //now check  for all neighbors of current visited element
                    {
                        if(!visited[nbr])   //if not visited
                        {
                            q.push(nbr);
                            visited[nbr]=true;
                        }
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
    g.add_edge(3,4);
    g.add_edge(4,5);

    g.bfs(0);
    return 0;
}
