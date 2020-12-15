#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<bits/stdc++.h>
#include<cmath>
#include<windows.h>
using namespace std;
class password
{
  private:
      char username [30];
      char pass [12];
  public:
    void get_fix();

};
void password::get_fix()
{
    cout<<"\n\n";
        cout<<"\t|----------------------------------------------|\n";
        cout<<"\t|                  Login Admin                 |\n";
        cout<<"\t|----------------------------------------------|\n";
    cout<<"\tInput User name: ";
    cin>>username;
    cout<<endl;
    cout<<"\tEnter User Password: ";
    char ch;
    int i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            pass[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else if(ch==32||ch==9)
        {
            continue;
        }
        else
        {
            pass[i]=ch;
            i++;
            cout<<"*";
        }
    }
    pass[i]='\0';
    cout<<"\n";
    if((strcmp(username,"tanjina")==0)&&(strcmp(pass,"tanjina2508")==0))
    {
        cout<<"";
    }
    else
    {
        cout<<"\n\n !!Sorry Try Again.....\n"<<endl;
        getch();
        system("cls");
        get_fix();
    }
}
class user
{
    int idno;//id
    int bill;
	char name[50];
	char fname[40];//us name/father name
public:
	void create_user();	//function to get data from user
	void show_user() const;	//function to show data on screen
	int retidno() const;
};
void user::create_user()
{
	cout<<"\n\tEnter The user ID No. :";
	cin>>idno;
	cout<<"\n\tEnter The User Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tEnter The User Father Name : ";
	cin.ignore();
	cin.getline(fname,40);
	cout<<"\n\tEnter The Bill : ";
	cin>>bill;
	cout<<"\n\tFile complete!";
}

void user::show_user() const
{
	cout<<"\n\tUser ID No. : "<<idno;
	cout<<"\n\tUser Name : "<<name;
	cout<<"\n\tUser Father Name : "<<fname;
	cout<<"\n\tBalance amount : "<<bill;
}
int user::retidno() const
{
	return idno;
}
class admin
{
public:
    int unit,bill,ID;

    void Admin();
    void Bill_No();
    void search_file_();
};

void admin::Bill_No()
{
    system("cls");
    int rt,unit,nmr,omr;
    float tbill,lastpayment;
    cout<<"\n\n\t\tENTER YOUR OLD METER READING:\n";
    cin>>omr;
    cout<<"\n\n\t\tENTER YOUR NEW METER READING:\n";
    cin>>nmr;
    unit=nmr-omr;
   // cout<<"Enter units between 1-900";
    //cin>>unit;
    cout<<" UNIT = "<<unit<<endl;
    if (unit<=100)
        bill=unit*4;
    else if (unit<=200)
        bill=100*4+(unit-100)*6;
    else if (unit<=400)
        bill=100*4+200*6+(unit-200)*8;
    else if (unit<=900)
        bill=100*4+200*6+400*8+(unit-400)*10;
        cout<<"\nyour bill is:"<<bill<<endl;
        cout<<"\t\t\t\t\t\t ===================\n";
        cout<<"\t\t\t\t\t\t       Payment      \n";
        cout<<"\t\t\t\t\t\t ===================\n\n\n";
    //system("cls");
    int ldp,c,num,amnt,n;
    cout<<"\tLast Date OF Payment = "<<endl;
    cin>>ldp;
    if(ldp>10)
    {
        cout<<"\tFine is 50 TAKA"<<endl;
    }
    cout<<"\tDue Payment of any month"<<endl;
    cout<<"\t[1] Yes\n\t[2] No\n";
    cout<<"\tSelect Your Option(1/2)= "<<endl;
    cin>>num;
    if(num==1 && ldp>10)
    {
        cout<<"\tEnter Your Amount = ";
        cin>>amnt;
        c=bill+50+amnt;
        cout<<"\tYour Current Payment is = "<<c<<endl;
    }
    if(ldp<=10 && num==1)
    {
        cout<<"\tEnter Your Amount = ";
        cin>>amnt;
        c=bill+amnt;
        cout<<"\tYour Current Payment is = "<<c<<endl;
    }
    if(ldp>10 && num==2)
        cout<<"\tYour Current Payment is = "<<bill+50<<endl;
    if(ldp<=10 && num==2)
     cout<<"\tYour Current Payment is = "<<bill<<endl;
}

void admin:: Admin()
{
    system("Cls");
    user us;
    password p;
    admin u;
    p.get_fix();
    system("Cls");
    cout<<"\n";
    cout<<"\t|----------------------------------------------|\n";
    cout<<"\t|                 Admin Panel                  |\n";
    cout<<"\t|----------------------------------------------|\n";
    cout<<"\n\n";
    cout<<"\t1. Open New User ID."<<endl;
    cout<<"\t1. Edit User Information."<<endl;
    cout<<"\t2. Edit Bill and payment Information."<<endl;
    //cout<<"3. Edit payment Information."<<endl;
    cout<<"\t3. search user information"<<endl;
    int n;
    cin>>n;
    switch(n)
    {
    case 1:
        //write_account();
        us.create_user();       //u.add_user_information();
       //u.write_userinfo_file();
         break;
    case 2:
        //u.Bill_No();
        break;
    /*case 3:
        u.payment();
        break;*/
    case 3:
       //u.search_file_();
        break;
    default:
        cout<<"thank you";
    }
}
void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void intro();
void des();
//void login();
int main()
{
    //system("cls")
    admin ad;
	char ch;
	int num;
	intro();
	des();
	//login();
	do
	{
		system("cls");
        system("COLOR 2E");
		cout<<"\n\n";
        cout<<"\t|----------------------------------------------|\n";
        cout<<"\t|                 MAIN SCREEN                  |\n";
        cout<<"\t|----------------------------------------------|\n";
		cout<<"\n\n\t[01]. ADMIN";
		cout<<"\n\n\t[02]. USER INFORMATION";
		cout<<"\n\n\t[03]. EXIT";
		cout<<"\n\n\tSelect Your Option (1-3) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
		    //ad.Admin();
		    system("Cls");
            //user us;
            password p;
            admin u;
            p.get_fix();
            system("Cls");
    cout<<"\n";
    cout<<"\t|----------------------------------------------|\n";
    cout<<"\t|                 Admin Panel                  |\n";
    cout<<"\t|----------------------------------------------|\n";
    cout<<"\n\n";
    //cout<<"\t1. Open New User ID."<<endl;
    cout<<"\t1. Edit User Information."<<endl;
    cout<<"\t2. Edit Bill and payment Information."<<endl;
    //cout<<"3. Edit payment Information."<<endl;
    //cout<<"\t3. search user information"<<endl;
    int n;
    cin>>n;
    switch(n)
    {
    case 1:
        write_account();
        //us.create_user();       //u.add_user_information();
       //u.write_userinfo_file();
         break;
    case 2:
        ad.Bill_No();
        //u.Bill_No();
        break;
    /*case 3:
        u.payment();
        break;*/
    case 3:
       //u.search_file_();
        break;
    default:
        cout<<"thank you";
    }

			//write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The User ID No. : "; cin>>num;
			display_sp(num);
			break;
        case '3':
			cout<<"\n\tThanks\n\tDESCO";
			break;
		default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='3');
	return 0;
}
void write_account()
{
	user us;
	ofstream outFile;
	outFile.open("user.dat",ios::binary|ios::app);
	us.create_user();
	outFile.write(reinterpret_cast<char *> (&us), sizeof(user));
	outFile.close();
}
void display_sp(int n)
{
    system("cls");
    system("COLOR F1");
    user us;
	bool flag=false;
	ifstream inFile;
	inFile.open("user.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
        while(inFile.read(reinterpret_cast<char *> (&us), sizeof(user)))
	{
		if(us.retidno()==n)
		{
		    //system("cls");
			us.show_user();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
        {
            cout<<"\n\tUSER ID number does not exist";
        }
    //system("cls");
}
void des()
{
    cout<<("\n     ____      _______     ____       ____      ___     ");
    cout<<("\n    |    *    |           *    )     *    *    *   *    ");
    cout<<("\n    |     *   |          (          |      )  (     )   ");
    cout<<("\n    |      *  |           *         |      )  |     |   ");
    cout<<("\n    |       ) | ______     *___     |         |     |   ");
    cout<<("\n    |       ) |                *    |         |     |   ");
    cout<<("\n    |      *  |                 )   |         |     |   ");
    cout<<("\n    |     *   |                 *   |         (     )   ");
    cout<<("\n    |____*    |_______    (____*     *____*    *___*    ");

     cout<<"\n\t"<<"************************* SAVE ELECTRICITY, SAVE MONEY *************************\n\n";
     cout<<"\tGazipur Polli Biddut Shomity\n";
     cout<<"\tChandona,Gazipur\n";
     cout<<"\tBoard Bazar General Ofiice\n";
     cout<<"\tElectricity Bill\n";

    cout<<endl;
    cin.get();
	system("cls");
}
void intro()
{
	system("COLOR 0C");
    cout<<"\t\t\t\t|=========================================|\n";
	cout<<"\t\t\t\t|  Electricity Billing Management System  |\n";
	cout<<"\t\t\t\t|=========================================|\n\n";
	cout<<("\n\t              ______           ");
    cout<<("\n\t             |_    _|             ");
    cout<<("\n\t!--------!     |  |     !--------!");
    cout<<("\n\t!--!  !--!  ___|  |___  !--!  !--!");
    cout<< "\n\t   !  !    |__________|    !  !       "<<"IUBAT- International University of Business Agriculture and Technology";
    cout<< "\n\t   !  !        |  |        !  !       ";
    cout<< "\n\t   !  !    B   |  |  A     !  !       ";
    cout<< "\n\t   !  !       _|  |_       !  !       "<<"Founded 1991 by Md. Alimullah Miyan";
    cout<<("\n\t   !  !      |______|      !  !       ");
    cout<<("\n\t   !  !________|  |________!  !       ");
    cout<<("\n\t   !___________|  |___________!       ");
    cout<<("\n\t              _|  |_                ");
    cout<<("\n\t             |______|                 ")<<endl;
	cout<<"\n\n\n\n\tMADE BY : Tanjina Akter";
	cout<<"\n\tID : 17203023";
	cout<<"\t\n\tProgram : BCSE";
	cin.get();
	system("cls");
}
