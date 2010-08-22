#include <windows.h>
#include <iostream.h>
#include <time.h>
#include <string>
#include <fstream>
#include <Lmcons.h>
#include <vector>
using namespace std;
struct assignmentType{
       string dueDate;
       string className;
       string assignmentName;
       }assignments[10];
int i;
string line;
int numLines=0;
bool autoRem=false;
TCHAR name [ UNLEN + 1 ];
DWORD size = UNLEN + 1;
int choice=0;
int numAssignments=0;
int cont=1;
void makeConfig()
{
     //Actually make the file, DEFAULT FILE PATH IS C:/
     string path="C:\\Program Files\\OpenSchedU\\";
     LPSECURITY_ATTRIBUTES attr;
     attr = NULL;
     CreateDirectory(path.c_str(),attr);
     ofstream mk_file("C:\\Program Files\\OpenSchedU\\config.txt", ios::out);
     mk_file<<"0\n";
}
void findConfig()
{
     //find the config file for the program, if not there, create 
     ifstream ifile("C:\\Program Files\\OpenSchedU\\config.txt",ios::in);
     if (!ifile)
         makeConfig();
}


void readConfig()
{
     ifstream rd_file("C:\\Program Files\\OpenSchedU\\config.txt", ios::in);
     //gets the content of lines
     i=0;
     while( getline( rd_file, line ) ) 
     {
            if(i<10)
            {
                    getline(rd_file,assignments[i].assignmentName,',');
                    getline(rd_file,assignments[i].className,',');
                    getline(rd_file,assignments[i].dueDate,',');
                    i++;
            }
     }
}


TCHAR getName()
{
     if (GetUserName( (TCHAR*)name, &size ))
        return *name;
     else
         cout<<"COULD NOT READ USERNAME. PLEASE ENTER USER NAME.";
         cin>>name;
         return *name;
}
void viewAssignments()
{
     system("CLS");
     cout<<"Assignments:\n\n";
     readConfig();
     for(int j=0;j<10;j++)
         cout<<j+1<<": "<<assignments[j].assignmentName<<' '<<assignments[j].className<<' '<<assignments[j].dueDate<<'\n';
}
void writeConfig()
{
     ofstream write_file("C:\\Program Files\\OpenSchedU\\config.txt", ios::app);
     for(int l=0;l<numAssignments;l++)
     {
        write_file<<assignments[l].assignmentName<<','<<assignments[l].className<<','<<assignments[l].dueDate<<','<<'\n';             
     }
}
void addAssignments()
{
     system("cls");
     numAssignments=0;
     
     while(numAssignments<1 || numAssignments>10)
     {
           cout<<"This page will let you add assignments. Currently you may have up to 10\nHow many assignments to add? ";
           cin>>numAssignments;
     }
     for(int k=0;k<numAssignments;k++)
     {
            system("cls");
            cout<<"Assignment "<<k+1<<": \n";
            cout<<"Input the name of the assignment: ";
            cin>>assignments[k].assignmentName;
            cout<<"Input the name of the class: ";
            cin>>assignments[k].className;
            cout<<"Input the due date in the form MM/DD/YY: ";
            cin>>assignments[k].dueDate;
     }
     
     writeConfig();
     
}

void deleteAssignments()
{
     cout<<"deleting";
}
void autoRemove()
{
     //can be on or off, if user has it on, delete assignments that are past, store choice in config file , defaults to off (for now)
}
void mainMenu()
{
     choice=0;
     //return user to main menu
     getName();
     system("cls");
     cout<<name<<"'s OpenSched-U Main Page ALPHA\n\n";
     cout<<"This page will display your assignments\n";
     while(choice<1 || choice > 3)
     {
          cout<<"Press 1 to add assignments, 2 to view, and 3 to remove.\n";
          cin>>choice;
     }
     if(choice==1)
          addAssignments();
     else if(choice==2)
          viewAssignments();
     else
         deleteAssignments();
}  

int main()
{
     while(cont!=0)
     {
     SetConsoleTitle("OpenSched-U ALPHA");
     findConfig();
     readConfig();
     mainMenu();
     //for(int j=0;j<10;j++)
      //   cout<<assignments[j].assignmentName<<' '<<assignments[j].className<<' '<<assignments[j].dueDate<<'\n';
     cout<<"\nContinue using program? Type 0 to quit or any other number to continue ";
     cin>>cont;
    }cin.ignore(1);
    return 0;
}
