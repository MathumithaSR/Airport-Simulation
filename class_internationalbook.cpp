#include <iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<ctype.h>
#include<windows.h>
#include<cstring>



class international_book	//class for international booking
{

protected:
    int pnri;
    char f_i[10],tojai[7],tojdi[7];
    long int doji;
    int srci,desti,choicei;
    int fi_no;

public:
    void i_pnr(int fl_no)
    {
        string pp;
        int y;
        stringstream geek(pp);
        geek>>y;
        pnri=rand()%100+fl_no;
        fi_no=fl_no;
    }
    int j_detaili()
    {

        if(fi_no==1)
        {
            cout<<"\n\nCoimbtore to Singapore \n \n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Vistara\t10:00\t\t14:05\t\tRs.25000\tRefundable\n";
            strcpy(tojai,"14:05");
            strcpy(tojdi,"10:00");
            strcpy(f_i,"Vistara");
        }

        else if(fi_no==2)
        {
            cout<<"\n\nCoimbatore to Colombo\n \n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Emirates\t18:00\t\t22:05\t\tRs.24650\t\tRefundable\n";
            strcpy(tojdi,"18:00");
            strcpy(tojai,"22:05");
            strcpy(f_i,"Emirates");
        }

        else if(fi_no==3)
        {
            cout<<"\n\nCoimbatore to Sharjah (Dubai)\n\n ";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Emirates\t18:00\t\t22:05\t\tRs.64892\tRefundable\n";
            strcpy(tojdi,"14:00");
            strcpy(tojai,"18:05");
            strcpy(f_i,"Emirates");

        }

        else if(fi_no==4)
        {
            cout<<"\n\nCoimbatore to Abu Dhabi \n ";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Vistara\t10:00\t\t14:05\t\tRs.17800\tRefundable\n";
            strcpy(tojdi,"10:00");
            strcpy(tojai,"14:05");
            strcpy(f_i,"Vistara");

        }

        else if(fi_no==5)
        {
            cout<<"\n\nCoimbatore to Muscat\n \n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly Dubai\t14:00\t\t18:05\t\tRs.38500\tRefundable\n";
            strcpy(tojdi,"14:00");
            strcpy(tojai,"18:05");
            strcpy(f_i,"Fly Dubai");

        }
        else if(fi_no==6)
        {
            cout<<"\n\nCoimbatore to Kuala Lumpur \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly Dubai\t17:00\t\t21:05\t\tRs.87550\tRefundable\n";
            strcpy(tojdi,"17:00");
            strcpy(tojai,"21:05");
            strcpy(f_i,"Fly Dubai");
        }
        else if(fi_no==7)
        {
            cout<<"Coimbatore to Paris \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly Dubai\t16:00\t\t19:05\t\tRs.90550\tRefundable\n";
            strcpy(tojdi,"16:00");
            strcpy(tojai,"19:05");
            strcpy(f_i,"Fly Dubai");
        }
        else if(fi_no==8)
        {
            cout<<"\n\nCoimbatore to Hong Kong \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly Dubai\t14:00\t\t18:05\t\tRs.90000\tRefundable\n";
            strcpy(tojdi,"14:00");
            strcpy(tojai,"18:05");
            strcpy(f_i,"Fly Dubai");
        }
        else if(fi_no==9)
        {
            cout<<"\n\nCoimbatore to Medan \n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly Dubai\t02:00\t\t08:05\t\tRs.87550\tRefundable\n";
            strcpy(tojdi,"02:00");
            strcpy(tojai,"08:05");
            strcpy(f_i,"Fly Dubai");
        }
        else if(fi_no==10)
        {
            cout<<"\n\nCoimbatore to London \n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Fly Dubai\t10:00\t\t14:05\t\tRs.87550\tRefundable\n";
            strcpy(tojdi,"10:00");
            strcpy(tojai,"14:05");
            strcpy(f_i,"Fly Dubai");
        }

        else if(fi_no==11)
        {
            cout<<"\nCoimbtore to Singapore \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Vistara\t14:00\t\t18:05\t\tRs.20000\tRefundable\n";
            strcpy(tojai,"14:00");
            strcpy(tojdi,"18:05");
            strcpy(f_i,"Vistara");
        }

        else if(fi_no==12)
        {
            cout<<"\n\nCoimbatore to Colombo \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Emirates\t22:00\t\t02:05\t\tRs.21650\t\tRefundable\n";
            strcpy(tojdi,"18:00");
            strcpy(tojai,"22:05");
            strcpy(f_i,"Emirates");
        }

        else if(fi_no==13)
        {
            cout<<"\n\nCoimbatore to Sharjah (Dubai) \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Emirates(3)\t22:00\t\t03:05\t\tRs.59892\tRefundable\n";
            strcpy(tojdi,"22:00");
            strcpy(tojai,"03:05");
            strcpy(f_i,"Emirates");

        }

        else if(fi_no==14)
        {
            cout<<"\n\nCoimbatore to Abu Dhabi \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Vistara\t14:00\t\t18:05\t\tRs.15000\tRefundable\n";
            strcpy(tojdi,"10:00");
            strcpy(tojai,"14:05");
            strcpy(f_i,"Vistara");

        }

        else if(fi_no==15)
        {
            cout<<"\n\nCoimbatore to Muscat \n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Gulf Air\t18:00\t\t22:05\t\tRs.34500\tRefundable\n";
            strcpy(tojdi,"18:00");
            strcpy(tojai,"22:05");
            strcpy(f_i,"Gulf India");

        }
        else if(fi_no==16)
        {
            cout<<"\n\nCoimbatore to Kuala Lumpur \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Gulf India\t21:00\t\t01:05\t\tRs.83550\tRefundable\n";
            strcpy(tojdi,"21:00");
            strcpy(tojai,"01:05");
            strcpy(f_i,"Gulf India");
        }
        else if(fi_no==17)
        {
            cout<<"\n\nCoimbatore to Paris \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Gulf India\t20:00\t\t01:05\t\tRs.85550\tRefundable\n";
            strcpy(tojdi,"20:00");
            strcpy(tojai,"01:05");
            strcpy(f_i,"Gulf India");
        }
        else if(fi_no==18)
        {
            cout<<"\n\nCoimbatore to Hong Kong \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Gulf India\t18:00\t\t22:05\t\tRs.85000\tRefundable\n";
            strcpy(tojdi,"18:00");
            strcpy(tojai,"22:05");
            strcpy(f_i,"Gulf India");
        }
        else if(fi_no==19)
        {
            cout<<"\n\nCoimbatore to Medan \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Gulf India\t06:00\t\t10:05\t\tRs.83550\tRefundable\n";
            strcpy(tojdi,"06:00");
            strcpy(tojai,"10:05");
            strcpy(f_i,"Gulf India");
        }
        else if(fi_no==20)
        {
            cout<<"\n\nCoimbatore to London \n\n";
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "Gulf India\t14:00\t\t18:05\t\tRs.83550\tRefundable\n";
            strcpy(tojdi,"14:00");
            strcpy(tojai,"18:05");
            strcpy(f_i,"Gulf India");
        }
        else
        {
            cout << "\n*********Wrong input entered.\tTry again*******\n\n\n";
            return j_detaili();
        }
        char m;
        cout<<"\nDo you like to travel in this flight(y/Y)      ";
        cin>>m;
        if(m=='y' || m=='Y')
        {
            cout << "\nEnter DateOfJourney(DDMMYY).   " << "Please enter a valid date.\t" ;
            cin >> doji;
        }
        else
        {
            cout<<"\n*********Try with another flight************";
        }
    }
};
