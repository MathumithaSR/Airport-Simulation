#include <iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<ctype.h>
#include<windows.h>
#include<cstring>
#include"class_passenger.cpp"


using namespace std;

int g_d;
int g_i;

class payment
{
protected:
    int choice1,bank,card,date,cvv,user_id;
    char password[10];
public:
    void pay_detail()
    {
        cout << "\n\n\nHow would you like to pay?:\n";
        cout << "\n\t1.Debit Card(1) \n\t2.Credit Card(2) \n\t3.Net Banking(3)";
        cout << "\n\nEnter your choice";
        cin >> choice1;
        switch(choice1)
        {
            case 1:
                cout << "\nEnter card no.:      ";
                cin >> card;
                cout << "\nEnter expiry date:   ";
                cin >> date;
                cout << "\nEnter CVV no.:       ";
                cin >> cvv;
                cout << "\nTransaction Successful\n";
                break;

            case 2:
                cout << "\nEnter card no.:      ";
                cin >> card;
                cout << "\nEnter expiry date:   ";
                cin >> date;
                cout << "\nEnter password:      ";
                cin >> password;
                cout << "\nTransaction Successful\n";
                break;

            case 3:
                cout << "Banks Available: \n\n1.Indian Overseas Bank(1) \n2.Canara Bank(2) \n3.State Bank of India(3) \n4.Bank of Baroda Bank(4) \n5.Others(5)";
                cout << "\nSelect your bank:    ";
                cin >> bank;
                cout << "\nYou have selected:   " << bank;
                cout << "\nEnter user id:(int)  ";
                cin >> user_id;
                cout << "\nEnter password:      ";
                cin >> password;
                cout << "\nTransaction Successful\n";
                break;
            default:
                cout << "\n*******Wrong input entered.\tTry again**********\n\n";
                return pay_detail();
        }
    }

};

void createfile(passenger p)
{
    ofstream fin("domestic.txt",ios::app);
    fin.write((char*)&p,sizeof(p));
    fin.close();
}

void cancelticket(int x,int y)//function to cancel ticket
{
    passenger p;
    int f=0;
    ifstream fout("domestic.txt",ios::app);
    ofstream fin("domestic1.txt",ios::app);
    fout.read((char *)&p,sizeof(p));
    while(fout)
    {
        if(p.getpnr()!=x && p.getfno()!=y)
            fin.write((char *)&p,sizeof(p));
        else
        {
            p.disp();
            cout<<"\nYour Above ticket is being canceled:\n" << "Amount refunded: Rs 1000\n";
            f++;
        }
        fout.read((char *)&p,sizeof(p));
    }
   if(f==0)
        cout<<"*********Ticket not found************\n";
    fout.close();
    fin.close();
    remove("domestic.txt");//deleting old file
    rename("domestic1.txt","domestic.txt");//renaming new file

}

void checkticket(int x,int y)//function to check pnr or ticket
{
    passenger p;
    int f=0;
    ifstream fout("domestic.txt");
    fout.read((char *)&p,sizeof(p));
    while(!fout.eof())
    {
        if(p.getpnr()==x && p.getfno()==y )
        {
                p.disp();
                cout<<"\nYour ticket"<<endl;
                f++;
                break;
        }
        fout.read((char *)&p,sizeof(p));
    }
    fout.close();
    if(f==0)
        cout<<"\n*************Ticket not found***********"<<endl;

}

void createfilei(passenger p)
{
    ofstream fin("international.txt",ios::app);
    fin.write((char*)&p,sizeof(p));
    fin.close();
}

void cancelticketi(int x,int y)
{
    passenger p;
    int f=0;
    ifstream fout("international.txt",ios::app);
    ofstream fin("international1.txt",ios::app);
    fout.read((char *)&p,sizeof(p));
    while(fout)
    {
        if(p.getpnri()!=x && p.getfnoi()!=y)
            fin.write((char *)&p,sizeof(p));

        else
        {
            p.dispi();
            cout<<"Your Above ticket is being deleted:\n"<<"Amount refunded: Rs 1000\n";
            f++;
        }
        fout.read((char *)&p,sizeof(p));
    }
    if(f==0)
        cout<<"\n************Ticket not found************\n";
    fout.close();
    fin.close();
    remove("international.txt");//deleting old file
    rename("international1.txt","international.txt");//renaming new file
}

void checkticketi(int x,int y)
{
    passenger p;
    int f=0;
    ifstream fout("international.txt");
    fout.read((char *)&p,sizeof(p));
    while(!fout.eof())
    {
        if(p.getpnri()==x && p.getfnoi() ==y)
        {
                p.dispi();
                cout<<"\nYour ticket"<<endl;
                f++;
                break;
        }
        fout.read((char *)&p,sizeof(p));
   }
   fout.close();
   if(f==0)
        cout<<"************Ticket not found**************"<<endl;

}
