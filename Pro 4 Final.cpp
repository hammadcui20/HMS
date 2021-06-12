#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
//structure to store patient details
struct patient
{
long long ID;
string firstname;
string lastname;
int age;
char blood[5];
char gender;
patient*next;
};
//structure for implementation of queue
struct linkedqueue
{
patient *head,*last;
char departmentname[50];
};
patient *head = NULL,*last = NULL;
//function to search item in patient records
int search(int item)
{
if(head==NULL)
return false;
else
{
int flag=0;
patient*p=new patient();
p=head;

while( p->next!=NULL && p->ID!=item )
{
p=p->next;
}
if(p->ID==item)
{
flag=1;
return true;
}
if(flag==0)
return false;
}
}
//function to read number from command line
int readnumber()
{
char b[20];
cin.getline(b, sizeof(b));
return atoi(b);
}
//function for patient details input
patient input()
{
int flag=0;
patient *p=new patient();
cout << "\n\tPlease enter data for patient\n";
cout<<"\n\tFirst name : ";
getline(cin,p->firstname);
cout << "\tLast name : ";
getline(cin,p->lastname);
again :
cout << "\tBlood Group : ";
cin>>p->blood;
if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
(strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
(strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
(strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
flag=1;
if(flag==0)
{
cout<<"\nWrong Entry...Enter a valid Blood Group..Try Again..";
goto again;

}
cout<<"\tGender : (m/f)";
cin>>p->gender;
cout<<"\tAge : ";
cin>>p->age;
cout<<"\tMobile number : ";
cin>>p->ID;


if(search(p->ID))
{
p->ID=0;
cout << "\n\tData not valid. Operation cancelled.";
}
return *p;
}
//function to print patient details
void output(patient *p)
{
cout<<"\n**********************************";
cout<<"\n\nPatient data:";
cout<<"\n\nFirst Name : "<<p->firstname;
cout<<"\nLast Name : "<<p->lastname;
cout<<"\nGender : "<<p->gender;
cout<<"\nAge : "<<p->age;
cout<<"\nBlood Group : "<<p->blood;
cout<<"\nMobile Number : "<<p->ID;
cout<<"\n\n**********************************";
}
//function to insert new patient details at the begining
void insertatbeg()
{
patient*p=new patient();
*p=input();
if(p->ID==0)
return;

if(head==NULL)

{
head=p;
last=p;
p->next=NULL;
}
else
{
p->next=head;
head=p;
}
system("cls");
cout << "\n\tPatient added:";
output(p);
}
//function to insert new patient details at the end
void insertatend()
{
patient*p=new patient();
*p=input();
if(p->ID==0)
return;

if(head==NULL)
{
head=p;
last=p;
p->next=NULL;
}
else
{
p->next=NULL;
last->next=p;
last=p;
}
system("cls");
cout << "\n\tPatient added:";
output(p);
}
//function to get patient out
void getpatientout()
{
system("cls");
if(head==NULL)
{
cout<<"\n\tNo Patient to operate";
}
else
{
patient*p=new patient();
p=head;
head=head->next;
cout << "\n\tPatient to operate:";
output(p);
}
}
//function to list of the patients
void listofpatients()
{
if(head==NULL)
{
cout<<"\n\tNo patient";
}
patient*p=new patient;
p=head;
while(p!=NULL)
{
cout<<"\nPatient data:";
cout<<"\nFirst Name : "<<p->firstname;
cout<<"\nLast Name : "<<p->lastname;
cout<<"\nGender : "<<p->gender;
cout<<"\nAge : "<<p->age;
cout<<"\nBlood Group : "<<p->blood;
cout<<"\nMobile Number : "<<p->ID;
cout<<"\n**********************************\n";
p=p->next;
}
cout<<"\n";
}
//function to show menu
void departmentmenu (linkedqueue * q)
{
int choice = 0, success;
patient p;
while (choice != 5)
{
system("cls");
cout<<"\n\n\tWelcome To Department : " << q->departmentname;
cout<<"\n\t\t[1] Add normal patient\n";
cout<<"\t\t[2] Add critically ill patient\n";
cout<<"\t\t[3] Take patient to Doctor\n";
cout<<"\t\t[4] Display list\n";
cout<<"\t\t[5] Change department or exit\n";
cout<<"\n\tPlease enter your choice : ";
choice=readnumber();

switch (choice)
{
case 1: insertatend();
cout << "\n\tPress any key";
getch();
break;

case 2: insertatbeg();
cout << "\n\tPress any key";
getch();
break;

case 3: getpatientout();
cout<<"\n\tPress any key";
getch();
break;

case 4: system("cls");
listofpatients();
cout<<"\n\tPress any key";
getch();
break;
}
}
}
//main function
int main ()
{
int i, choice = 0;
//creating departments array of four elements of type struct linkedqueue
struct linkedqueue departments[4];
//loop for choices
while(choice!=5)
{
strcpy(departments[0].departmentname,"General Clinic\n");
strcpy(departments[1].departmentname,"Heart Clinic\n");
strcpy(departments[2].departmentname,"Lung Clinic\n");
strcpy(departments[3].departmentname,"Plastic Surgery\n");
system("cls");
cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
cout<<"\n\tHOSPITAL MANAGEMENT SYSTEM\t";
cout<<"\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";

for (i = 0; i < 4; i++)
{
cout<<"\t"<<(i+1)<<": "<<departments[i].departmentname;
}
cout<<"\t5: Exit";
cout<<"\n\n\tPlease enter your choice : ";
choice=readnumber();
if(choice>=1 && choice<=4)
{
departmentmenu(&departments[choice-1]);
}

}
if(choice==5)
cout<<"\n\t\tThank you! \n";
exit(0);
}
