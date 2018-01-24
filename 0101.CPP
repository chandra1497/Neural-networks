#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<time.h>
#include<iomanip.h>
#include<fstream.h>

void manage();
void can();
void user();
void data(); //database
void res();
void reserve();
void displaypassdetail();  //password details
void cancel();
void enquiry();

char f[10]="f";
int addr,ad,flag,d,m,i,amt;
float tamt;


class login
{

public:

char id[100];
char pass[100];
char *password;

void getid()
{
cout<<"\n Enter your id:";
gets(id);
password=getpass("\n Enter the password:"); //echo disabled by getpass
strcpy(pass,password); //copies password to pass
}

void displayid()
{
cout<<"\n Id:";
puts(id);
cout<<"\n Password:";
puts(pass);
}

};

class detail
{

public:

int tno;
int d,y,m;
char tname[100];
char bp[100];
char dest[100];
int c,fare;

void getdetail()
{
cout<<"\n Enter the details as follows\n";
cout<<"\n\n Date of travel:";
cin>>d;
cout<<"\n Enter month of travel:";
cin>>m;
cout<<"\n Year of travel:";
cin>>y;
cout<<"\n Train no:";
cin>>tno;
cout<<"\n Train name:";
gets(tname);
cout<<"\n Boarding point:";
gets(bp);
cout<<"\n Destination pt:";
gets(dest);
cout<<"\n No of seats: ";
cin>>c;
cout<<"\n Enter fare per ticket: ";
cin>>fare;

}

void dispdetail()
{
cout<<tno<<"\t"<<tname<<"\t"<<bp<<"\t"<<dest<<"\t";
cout<<c<<"\t"<<fare;
cout<<d<<"-"<<m<<"-"<<y<<"\t"<<endl;
}
};

class reser
{

public:

int pnr,tno,age[80],nosr,i,d,y,m,amc;
char tname[100],bp[10],dest[100],pname[10][100],clas[10];

void getresdet()  //reservation details
{
cout<<"\n Enter the details as follows\n";
cout<<"\n Train no:";
cin>>tno;
cout<<"\n Train name:";
gets(tname);
cout<<"\n Boarding point:";
gets(bp);
cout<<"\n Destination pt:";
gets(dest);
cout<<"\n No of seats required:";
cin>>nosr;

for(i=0;i<nosr ;i++)  //no of seats
{
cout<<"\n Passenger name:";
gets(pname[i]);
cout<<"\n Passenger age:";
cin>>age[i];
}

cout<<"\n Enter the class:- f-first class or s-second class:";
gets(clas);
cout<<"\n Date of travel: ";
cin>>d;
cout<<"\n Month of travel: ";
cin>>m;
cout<<"\n Year of travel: ";
cin>>y;

}

void dispresdet()  //display reservation details
{
cout<<"\n\n Pnr no: "<<pnr;
cout<<"\n Train no: "<<tno;
cout<<"\n Train name: ";
puts(tname);
cout<<"\n Boarding point: ";
puts(bp);
cout<<"\ Destination pt: ";
puts(dest);
cout<<"\n No of seats reserved: "<<nosr;

for(i=0;i<nosr;i++)
{
cout<<"\n Passenger name: ";
puts(pname[i]);
cout<<"\n Passenger age: "<<age[i];
}

cout<<"\n Your class: ";
puts(clas);
cout<<"\n Date of reservation:"<<d<<"-"<<m<<"-"<<y;
cout<<"\n You must pay:"<<amc<<"\n";  //end of reservation
}
};

class canc
{

public:

int pnr,tno,age[80],nosc,i,d,y,m;      // same as that of reser

char tname[100],bp[10],dest[100],pname[10][100],clas[10];

float amr;

void getcancdet()
{
cout<<"\n Enter the details as follows\n";
cout<<"\n Pnr no:";
cin>>pnr;
cout<<"\n Date of cancellation:";
cin>>d;
cout<<"\n Month of travel: ";
cin>>m;
cout<<"\n Year of travel: ";
cin>>y;          //end of getting details

}

void dispcancdet()  //display cancelled data
{
cout<<"\n\n Pnr no: "<<pnr;
cout<<"\n Train no: "<<tno;
cout<<"\n Train name: ";
puts(tname);
cout<<"\n Boarding point: ";
puts(bp);
cout<<"\n Destination pt: ";
puts(dest);
cout<<"\n Your class: ";
puts(clas);
cout<<"\n No of seats to be cancelled: "<<nosc;

for(i=0;i<nosc;i++)
{
cout<<"\n Passenger name: ";
puts(pname[i]);
cout<<"\n Passenger age: "<<age[i];
}

cout<<"\n Date of cancellation: "<<d<<"-"<<m<<"-"<<y;
cout<<"\n You can collect: "<<amr<<"$"<<"\n";  //end of cancellation
}
};



void main() //void main
{

clrscr();
int ch;
cout<<"\n Menu"; //under construction

do
{
cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
cout<<"\n 1.Admin mode";
cout<<"\n 2.User mode";
cout<<"\n 3.Exit\n";
cout<<"\n Enter your choice: ";
cin>>ch;
cout<<endl;

switch(ch)
{

case 1:	data(); //admin mode
	break;

case 2:	user();    //user mode
	break;

case 3:	exit(0);

default:
	cout<<"\n Enter a valid choice!!!";

}
}while(ch<=3);

getch();
}


void data()
{
char *password;
char *pass="12345678";
password=getpass("Enter the admininistrator password: ");//password is entered by the user

detail ask;  //object of class detail
fstream fio;  //stream object for both input and output

int ch;
char c;

if(strcmp(pass,password)!=0)
{
cout<<"\n Enter the password correctly \n";
cout<<"\n You are denied the permission to load the next page \n";
goto label; //label
}

if(strcmp(pass,password)==0)
{
char choice;

do
{
cout<<"\n Welcome to admin menu " ;//construct
cout<<"\n 1.Create detail record database";
cout<<"\n 2.Add details";
cout<<"\n 3.Display details";
cout<<"\n 4.User management";
cout<<"\n 5.Display passenger details";
cout<<"\n 6.Return to main menu";
cout<<"\n Enter your choice:";
cin>>ch;


cout<<"\n";
switch(ch)
{

case 1:
fio.open("t.txt",ios::out|ios::binary); //t.txt for details
do
{
ask.getdetail();
fio.write((char *) & ask,sizeof(ask));   //binary file
cout<<"\n Do you want to add one more record?";
cout<<"\n y-for Yes \ n-for No\n";
cin>>choice;
}while(choice=='y' || choice=='Y');

fio.close();
break;

case 2:
fio.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
ask.getdetail();
fio.write((char *) & ask,sizeof(ask));
fio.close();
break;

case 3:
fio.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
fio.seekg(0); //put the pointer to 0th byte
while(fio.read((char *) & ask,sizeof(ask))) //same as while(!fio.eof())
{
ask.dispdetail();
}
fio.close();
break;

case 4:
manage();
break;

case 5:
displaypassdetail();
break;

}
}while(ch<=5);

fio.close();
}
label:
}

void reserve() //no use found
{
int ch;
do
{
cout<<"\n 1.Reserve";
cout<<"\n 2.Return to the main menu";
cout<<"\n Enter your choice: ";
cin>>ch;
cout<<endl;
switch(ch)
{
case 1:
res(); //reserve    no use found
break;
}
}while(ch==1);
getch();
}

void res()
{
detail ask;  //actually a
reser rese;  //actually b
fstream fio1,fio2;
time_t t;

fio1.open("leo.txt",ios::in|ios::out|ios::binary);
fio2.open("messi.txt",ios::in|ios::out|ios::binary|ios::app);
int ch;
rese.getresdet();
while(fio1.read((char *) &ask,sizeof(ask)))
{
	if(ask.tno==rese.tno)
	{
		if(strcmp(rese.clas,f)==0)
		{
			if(ask.c>=rese.nosr)
			{
			amt=ask.fare;
			addr=fio1.tellg();
			ad=sizeof(ask.c);
			fio1.seekp(addr-(7*ad));
			ask.c=(ask.c)-(rese.nosr);
			fio1.write((char *) & ask.c,sizeof(ask.c));
			rese.amc=rese.nosr*amt;
			srand((unsigned) time(&t));
			rese.pnr=rand();
			fio2.write((char *) & rese,sizeof(rese));
			rese.dispresdet();//display reservation data
			}   /*cout<<"-----------------End of reservation menu-------\n";*/

			else
			{
			cout<<"**********Sorry required seats not available********\n";
			}
		}
	getch();
	goto label;
	}

	else  //if train no. does not match
	{
	flag=0;
	}

}

if(flag==0)
{
cout<<"............Wrong train no......................\n";
cout<<"......Enter the train no from the data base.....\n";
}
fio1.close();
fio2.close();
getch();
label:
}

void displaypassdetail()   //display
{
fstream fio;
reser rese;
fio.open("messi.txt",ios::in|ios::out|ios::binary);
fio.seekg(0);
while(fio.read((char *) & rese,sizeof(rese)))
{
rese.dispresdet();
}
fio.close();
getch();
}

void enquiry()
{

fstream fio;
fio.open("leo.txt",ios::in|ios::out|ios::binary);
detail ask;
while(fio.read((char *) & ask,sizeof(ask)))
{
ask.dispdetail();
}
getch();
}


void cancel()
{
detail ask;  //a
reser rese;//b
canc ca;//c

fstream fio1,fio2,fio3; //f1,f2,f3
fio1.open("leo.txt",ios::in|ios::out|ios::binary);
fio2.open("messi.txt",ios::in|ios::out|ios::binary);
fio3.open("fcb.txt",ios::in|ios::out|ios::binary);
cout<<"**********CANCELLATION MENU*********\n";
ca.getcancdet();

while(fio2.read((char *) & rese,sizeof(rese)))
{
	if(rese.pnr==ca.pnr)
	{
	ca.tno=rese.tno;
	strcpy(ca.tname,rese.tname);
	strcpy(ca.bp,rese.bp);
	strcpy(ca.dest,rese.dest);
	ca.nosc=rese.nosr;

		for(int j=0;j<ca.nosc;j++)
		{
		strcpy(ca.pname[j],rese.pname[j]);
		ca.age[j]=rese.age[j];
		}

		strcpy(ca.clas,rese.clas);

		if(strcmp(ca.clas,f)==0)
		{
			while(fio1.read((char *) & ask,sizeof(ask)))
			{

			if(ask.tno==ca.tno)
			{
			ask.c=ask.c+ca.nosc;
			d=ask.d;
			m=ask.m;
			addr=fio1.tellg();
			ad=sizeof(ask.c);
			fio1.seekp(addr-(7*ad));
			fio1.write((char *) & ask.c,sizeof(ask.c));
			tamt=rese.amc;

			if((ca.d==d)&&(ca.m==m))
			{
			cout<<"\n You are cancelling at the date of departure";
			ca.amr=tamt-((tamt*60)/100);
			}

			else if(ca.m==m)
			{
			cout<<"\n You are cancelling at the month of departure";
			ca.amr=tamt-((tamt*50)/100);
			}

			else if(m>ca.m)
			{
			cout<<"\n You are cancelling one month before the date of departure\n";
			ca.amr=tamt-((tamt*20)/100);
			}

			else
			{
			cout<<"\n Cancelling after the departure";
			cout<<"\n Your request cannot be completed";
			}
			goto label;
			ca.dispcancdet();

			}
			}
		}

	}

	else   //no match found
	{
	flag=0;
	}

}
label:

if(flag==0)
{
cout<<"Enter the correct pnr no\n";    //pnr-passenger name record
}
fio1.close();
fio2.close();
fio3.close();
getch();
}

void can() //cancellation menu
{
int ch;

do
{
cout<<".................CANCELLATION MENU.........\n";
cout<<"\n 1.Cancel";
cout<<"\n 2.Return to the main menu";
cout<<"\n Enter your choice:";
cin>>ch;
cout<<"\n";

switch(ch)
{
case 1:
cancel();
break;
}
}while(ch==1);

getch();
}

void user()
{
login a; //object of the class
int ch;
cout<<"*****************************************************\n";
cout<<"***********WELCOME TO THE USER MENU**\n";
cout<<"****************************************************\n";
char *password;

fstream fio;
fio.open("user.txt",ios::in|ios::out|ios::binary);
char id[100];
puts("Enter your id:");
gets(id);
password=getpass("Enter your password:");

while(fio.read((char *) & a,sizeof(a))) //while(!fio.eof())
{

	if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
	{

	do
	{
	cout<<"\n1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
	cout<<"\n Enter your choice:";
	cin>>ch;
	cout<<endl;

		switch(ch)
		{
		case 1:
		reserve();
		break;

		case 2:
		cancel();
		break;

		case 3:
		enquiry();
		break;
		}
	}while(ch<=3);

	goto end;

	}

	else
	{
	d=1;
	}

}  //end of while

if(d==1)
{
cout<<"\n Enter your user id and password correctly\n";
}
getch();

end:
}


void manage()
{
int ch;
fstream fio;
char choice;
login a;
cout<<".........WELCOME TO THE USER MANAGEMENT MENU........\n";
do
{
cout<<"\n 1.Create id data base";
cout<<"\n 2.Add details";
cout<<"\n 3.Display details" ;
cout<<"\n 4.Return to the main menu";
cout<<"\n Enter your choice:";
cin>>ch;
cout<<"\n";

switch(ch)
{
	case 1:
	fio.open("id.txt",ios::out|ios::binary);

	do
	{
		a.getid();
		fio.write((char *) & a,sizeof(a));
		cout<<"Do you want to add one more record\n";
		cout<<"y-Yes\nn-No\n";
		cin>>choice;
	} while(choice=='y'||choice=='Y');
	fio.close();
	break;

	case 2:
	fio.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
	a.getid();
	fio.write((char *) & a,sizeof(a));
	fio.close();
	break;

	case 3:
	fio.open("id.txt",ios::in|ios::out|ios::binary);

	fio.seekg(0);
	while(fio.read((char *) & a,sizeof(a)))
	{
	a.displayid();
	}
	fio.close();
	break;

}

}while(ch<=3);

getch();
}