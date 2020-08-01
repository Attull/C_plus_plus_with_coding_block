#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<char> q;
    int freq[27]={0};

    //running a stream until a '.' ,i.e take input until we get '.'
    char ch;
    cin>>ch;

    while(ch!='.')
    {
        //logic
        q.push(ch);                              //push character in queue
        freq[ch-'a']++;                         //update its frequency in freq array

        while(!q.empty())
        {
            int idx=q.front() -'a';             //index of element present in front of queue
            if(freq[idx]>1)                     //check its frequency whether its is greater than 1 or not
            {
                q.pop();                        //pop if freq is greater than 1
            }
            else
            {
                cout<<q.front()<<endl;          //else print character
                break;
            }
        }

        if(q.empty())
        {
            cout<<"-1"<<endl;
        }

        cin>>ch;
    }
    return 0;
}

