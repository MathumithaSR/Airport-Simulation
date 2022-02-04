
#include <iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<ctype.h>
#include<windows.h>
#include<cstring>

class domestic_book
{
protected:
    long pnr;
    char f_d[10],toja[7],tojd[7];
    string doj;
    int choice,src,dest;
    int fd_no;

public:
    void d_pnr(int fl_no)
    {
        string pp;
        int y;
        stringstream geek(pp);
        geek>>y;
        pnr=rand()%100+fl_no;
        fd_no=fl_no;
    }

    int j_detail()
    {
        if(fd_no==1)
        {
            cout<<" \n\nCoimbatore  to Delhi\n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Qantas\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            strcpy(tojd,"08:00");
            strcpy(toja,"11:05");
            strcpy(f_d,"Qantas");
        }

        else if(fd_no==2)
        {
            cout<<"\n\nCoimbatore to Chennai \n \n";
            cout<< "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly Dubai\t14:00\t\t17:35\t\tRs.5500\t\tRefundable\n";
            strcpy(tojd,"14:00");
            strcpy(toja,"17:35");
            strcpy(f_d,"Fly India");
        }

        else if(fd_no==3)
        {
            cout<<"\n\nCoimbatore to Cochin \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Go Air(3)\t19:00\t\t22:05\t\tRs.6100\t\tRefundable\n";
            strcpy(tojd,"19:00");
            strcpy(toja,"22:05");
            strcpy(f_d,"Go Air");
        }

        else if(fd_no==4)
        {
            cout<<"Coimbatore to Thiruvandrum \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly Dubai(2)\t11:00\t\t16:35\t\tRs.2500\t\tRefundable\n";
            strcpy(tojd,"11:00");
            strcpy(toja,"16:35");
            strcpy(f_d,"Fly Dubai");
        }

        else if(fd_no==5)
        {
            cout<<"Coimbatore to Bombay\n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Kingfisher\t16:00\t\t20:05\t\tRs.9000\t\tRefundable\n";
            strcpy(tojd,"16:00");
            strcpy(toja,"20:05");
            strcpy(f_d,"Kingfisher");
        }
        else if(fd_no==6)
         {
            cout<<"\n\nCoimbatore to Kolkata\n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Qantas\t18:00\t\t21:15\t\tRs.5800\t\tRefundable\n";
            strcpy(tojd,"18:00");
            strcpy(toja,"21:15");
            strcpy(f_d,"Qantas");
        }
        else if(fd_no==7)
        {
            cout<<"\n\nCoimbatore to Ahmedabad \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "IndiGo\t12:00\t\t16:00\t\tRs.10000\t\tRefundable\n";
            strcpy(tojd,"12:00");
            strcpy(toja,"16:00");
            strcpy(f_d,"IndiGo");
        }
        else if(fd_no==8)
        {
            cout<<"\n\nCoimbatore to Hyderabad\n \n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "AirIndia\t19:45\t\t22:55\t\tRs.7000\t\tRefundable\n";
            strcpy(tojd,"19:45");
            strcpy(toja,"22:55");
            strcpy(f_d,"Air India");
        }
        else if(fd_no==9)
        {
            cout<<"\n\nCoimbatore to Bangalore\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Spice_Jet\t15:00\t\t21:00\t\tRs.9000\t\tRefundable\n";
            strcpy(tojd,"15:00");
            strcpy(toja,"21:00");
            strcpy(f_d,"Spice_Jet");
        }
        else if(fd_no==10)
        {
             cout<<"\n\nCoimbatore to Goa\n";
             cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
             cout << "AirIndia\t09:00\t\t16:25\t\tRs.6000\t\tRefundable\n";
             strcpy(tojd,"09:00");
            strcpy(toja,"16:25");
            strcpy(f_d,"Air India");
        }
        else if(fd_no==11)
        {
            cout<<"Coimbatore(cbe) to Delhi(dhl)\n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Qantas\t11:00\t\t14:05\t\tRs.5000\t\tRefundable\n";
            strcpy(tojd,"11:00");
            strcpy(toja,"14:05");
            strcpy(f_d,"Qantas");
        }
        else if(fd_no==12)
        {
            cout<<"\n\nCoimbatore to Chennai \n\n";
            cout<< "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly India\t17:00\t\t20:35\t\tRs.5500\t\tRefundable\n";
            strcpy(tojd,"17:00");
            strcpy(toja,"20:00");
            strcpy(f_d,"Fly India");
        }
        else if(fd_no==13)
        {
            cout<<"\n\nCoimbatore to Cochin \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Go Air\t22:00\t\t01:05\t\tRs.6100\t\tRefundable\n";
            strcpy(tojd,"22:00");
            strcpy(toja,"01:05");
            strcpy(f_d,"Go Air");
        }
        else if(fd_no==14)
        {
            cout<<"\n\nCoimbatore to Thiruvandrum \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly India\t14:00\t\t19:35\t\tRs.2500\t\tRefundable\n";
            strcpy(tojd,"14:00");
            strcpy(toja,"19:35");
            strcpy(f_d,"Fly India");
        }

        else if(fd_no==15)
        {
            cout<<"\n\nCoimbatore to Bombay\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Indian Airlines\t19:00\t\t23:05\t\tRs.10000\t\tRefundable\n";
            strcpy(tojd,"19:00");
            strcpy(toja,"23:05");
            strcpy(f_d,"Indian Airlines");
        }
        else if(fd_no==16)
         {
            cout<<"\n\nCoimbatore to Kolkata\n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Qantas\t21:00\t\t23:15\t\tRs.8800\t\tRefundable\n";
            strcpy(tojd,"21:00");
            strcpy(toja,"23:15");
            strcpy(f_d,"Qantas");
        }
        else if(fd_no==17)
        {
            cout<<"\n\nCoimbatore to Ahmedabad\n \n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "IndiGo\t15:00\t\t19:00\t\tRs.11000\t\tRefundable\n";
            strcpy(tojd,"15:00");
            strcpy(toja,"19:00");
            strcpy(f_d,"IndiGo");
        }
        else if(fd_no==18)
        {
            cout<<"Coimbatore to Hyderabad \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "AirIndia\t22:45\t\t01:55\t\tRs.6000\t\tRefundable\n";
            strcpy(tojd,"22:45");
            strcpy(toja,"01:55");
            strcpy(f_d,"Air India");
        }
        else if(fd_no==19)
        {
            cout<<"\n\nCoimbatore to Bangalore\n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Spice Jet\t16:00\t\t20:00\t\tRs.6000\t\tRefundable\n";
            strcpy(tojd,"15:00");
            strcpy(toja,"21:00");
            strcpy(f_d,"Spice Jet");
        }
        else if(fd_no==20)
        {
             cout<<"\n\nCoimbatore to Goa\n\n";
             cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
             cout << "AirIndia\t11:00\t\t17:25\t\tRs.7000\t\tRefundable\n";
            strcpy(tojd,"11:00");
            strcpy(toja,"17:25");
            strcpy(f_d,"Air India");
        }
        else
        {
            cout <<"\n*****Wrong input entered\tTry again**********\n\n\n" << endl;
            return j_detail();
        }
        char m;
        cout<<"\nDo you like to travel in this plane(y/Y)   ";
        cin>>m;
        if(m=='y' || m=='Y')
        {
            cout << "\n Enter DateOfJourney(DDMMYY)." << "Please enter a valid date.\t" ;
            cin>>doj;
        }
        else
        {
            cout<<"\n*********Try another flight no**********";
        }

    }

};