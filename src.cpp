#include <windows.h>
#include <iostream.h>
#include <math.h>
#include <time.h>
#include <string>
#include <fstream>
#include <Lmcons.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;


//REMINDER DEFAULTS TO 1 HOUR BUT CAN BE CHANGED, STORE IN MILLISECONDS
int reminder=3600000;
struct assignment{
       int dueDate;
       int timeRemaining;
       string className,assignmentName;
       };
bool autoRem=true;
TCHAR name [ UNLEN + 1 ];
DWORD size = UNLEN + 1;

void makeConfig()
{
     //Actually make the file, DEFAULT FILE PATH IS C:/
     string path="C:\\Program Files\\OpenSchedU\\";
     LPSECURITY_ATTRIBUTES attr;
     attr = NULL;
     CreateDirectory(path.c_str(),attr);
     ofstream mk_file("C:\\Program Files\\OpenSchedU\\config.txt", ios::in);
}
void findConfig()
{
     //find the config file for the program, if not there, create 
     ifstream ifile("C:\\Program Files\\OpenSchedU\\config.txt");
     if (!ifile)
         makeConfig();
}


void readConfig()
{
     ifstream rd_file("C:\\Program Files\\OpenSchedU\\config.txt", ios::in);
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
     
}
void addAssignment()
{
     
}

void deleteAssignment()
{
     
}
void autoRemove()
{
     //can be on or off, if user has it on, delete assignments that are past, store choice in config file , defaults to off (for now)
}
void mainMenu()
{
     //return user to main menu
     getName();
     system("cls");
     cout<<name<<"'s OpenSched-U Main Page ALPHA\n\n";
     cout<<"This page will eventually display your most important assignments\nPress 1 to view your other assignments.\n";
     
}  
int main()
{
     SetConsoleTitle("OpenSched-U ALPHA");
     mainMenu();
     findConfig();
     makeConfig();
    
    cin.ignore(1);
    return 0;
}
