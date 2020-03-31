 #include <iostream>
#include <stdio.h>
using namespace std;

class student
{
    private:
            int rollno;
            char name[25];
            float marks;
            char grade;
    public:
            void calc_grade();
            void readstudent()                          //mutator (it modifying data)
            {
                cout<<"\n enter rollno: ";
                cin>>rollno;
                cout<<"\n enter name: ";
                cin>>name;
                cout<<"\n enter marks: ";
                cin>>marks;
            }

            void dispstudent()
            {
                calc_grade();
                cout<<"roll no: "<<rollno<<endl;
                cout<<"name: "<<name<<endl;
                cout<<"marks: "<<marks<<endl;
                cout<<"grade: "<<grade<<endl;
            }

            int getrollno()
            {
                return rollno;
            }

            int getmarks()
            {
                return marks;
            }

};


void student ::calc_grade()                               //  to define function outside the class use "::"
{
    if(marks >= 75)
        grade='A+';
    else if(marks >=60)
        grade='A';
    else if(marks >=50)
        grade='B';
    else if(marks >=40)
        grade='C';
    else
        grade='F';
}

int main()
{
    student stu[10];
    for(int i=0;i<2;++i)
    {
        cout<<"enter details of student "<<i+1<<":";
        stu[i].readstudent();
    }

    int choice,rno,highmarks=0,pos;
    do
    {
        int choice;
        cout<<"select option \n";
        cout<<"1. specific student \n";
        cout<<"2. topper \n";
        cout<<"3. exit \n";
        cout<<"Enter your choice \n";
        cin>>choice;

        switch(choice)
        {
            case 1:
                    cout<<"enter roll no of student for its detail \n";
                    cin>>rno;
                    for(int i=0;i<2;++i)
                    {
                        if(stu[i].getrollno()==rno)
                        {
                            stu[i].dispstudent();
                            break;
                        }
                        break;
                    }
            case 2:
                    for(int i=0;i<2;++i)
                    {
                        if(stu[i].getmarks()>highmarks)
                        {
                            pos=i;
                            highmarks=stu[i].getmarks();
                        };
                    }
                    stu[pos].dispstudent();
                    break;
            case 3:
                    break;
        }
    }while(choice>=1 && choice <3);
     return 0;
}
