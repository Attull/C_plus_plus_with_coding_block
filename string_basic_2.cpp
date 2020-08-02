 #include<iostream>
 #include<string>
 using namespace std;

 int main()
 {
    string s1("hello");
    string s2= "hello world";

    string s3(s2);
    string s4=s1;

    char a[]={'a','b','c','\0'};

    string s5(a);

    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;

    s1.clear() ;                    //clear string
    cout<<s3.length()<<endl;            //print length of string

    //compare two string
    s1="apple";
    s2="mango";
    cout<<s1.compare(s2)<<endl;     //returns an integer ==0 equal ,>0,<0 (lexicographically compare)

    string s="i am atul cool";
    int idx=s.find("atul");         //gives the index of particular word
    cout<<idx<<endl;

    //iterate over all the character in the string

    for(int i=0;i<s1.length();++i)
        cout<<s1[i]<<" ";

    cout<<endl;
    for(auto k=s.begin();k!=s.end();++k)
         cout<<*k<<" ";

 }
