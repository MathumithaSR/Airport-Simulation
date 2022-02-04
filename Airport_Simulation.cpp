#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "book.cpp"
#include "class_flight.cpp"
#include "class_queue.cpp"
#include "class_runway.cpp"


using namespace std;
typedef double Queue_entry;
int land_flight[20]={0};
int takeoff_flight[20]={0};
int no_l[20];
int no_d[20];
int k =0;
int m=0;
int land_count =0;
int depart_count =0;
int tot_flights;
enum Error_code {success,overflow,underflow};


class Random
{

public:
	int generate(int arrival_rate)
	{
		int no = rand()%arrival_rate;
		return no;
	}
};


void initialize(int &end_time, int &queue_limit, int &arrival_rate, int &departure_rate)
{
    cout << "\n\nUp to what number of flights can be waiting to land "
            << "or take off at any time?(queue limit)    " << flush;
    cin  >> queue_limit;
    cout << "\n\nHow many units of time will the simulation run?(end time)     " << flush;
    cin  >> end_time;

    bool acceptable=false;
    do
    {
        cout << "\n\nExpected number of arrivals per unit time?(arrival rate)       " << flush;
        cin  >> arrival_rate;
        cout << "\n\nExpected number of departures per unit time?(departure rate)     " << flush;
        cin  >> departure_rate;

        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "\n\nThese rates must be nonnegative." << endl;

        else
            acceptable = true;

        if (acceptable && arrival_rate + departure_rate > 1.0)
            cerr << "\n\nSafety Warning: This airport will become saturated. " << endl;

   } while (!acceptable);
}


void run_idle(int time)

{
    cout <<"\n\n"<< time << ": Runway is idle." << endl;
}





int main()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
      run, the expected number of flights arriving, the expected number
      of flights departing per time interval, and the
      maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
      the status of the runway at each time interval, and prints out a
      summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/
{
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tWelcome to Airport Stimulator";
    cout<<"\n\t\t\t\t\t\t\t\t\t---------------------------------------------";
    cout<<"\n\n\t\t\t\t\t\t\t\t\tThis program just implements the Airport stimulation";
    cout<<"\n\n\t\t\tThe program is to simulate the operation of one day's activity at an airport,and output the times waiting to land and take off for each BWIA flight.";
    cout<<"\n\n\t\t\t\t\tThe program also performs a random simulation of the airport, showing the status of the runway at each time interval";
    cout << "\n\n\t\t\t\t\t\t\t\t\tThis program simulates an airport with only one runway.\n" << endl
            << "\n\n\t\t\t\t\t\t\t\t\tOne plane can land or depart in each unit of time." << endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDONE BY:\n\t\t\t\t\t\t\t\t\t\t\t\t\t---------\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tNikhita Binu(19pw18)\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tMathumitha S R(19pw14)"<<endl;
    Sleep(8000);
    system("CLS");
    
	
	//  time to run simulation
	int end_time=0;  
	//  size of Runway queues	
    int queue_limit=0;         
    int flight_number = 1;
    int arrival_rate=0, departure_rate=0;
	
    initialize(end_time, queue_limit, arrival_rate, departure_rate);
	
	//object of class Random
    Random variable;
	
	//object of class Runway
    Runway airport(queue_limit);
	
    for (int current_time = 1; current_time <= end_time; current_time++)
    {
        int number_arrivals = variable.generate(arrival_rate);
        for (int i = 0; i < number_arrivals; i++)
        {
			//object current_flight of Flight class
            Flight current_flight(flight_number++, current_time, arriving);

            no_l[land_count]=rand()%2;

            if(no_l[land_count]==0)
                cout<<"\tDomestic flight";
            else
                cout<<"\tInternational flight";
			
            land_count++;
			
            if (airport.can_land(current_flight) != success)
                current_flight.refuse();
        }
		//random no of depature within a limit
        int number_departures= variable.generate(departure_rate);
		
        for (int j = 0; j < number_departures; j++)
        {
            Flight current_flight(flight_number++, current_time, departing);
            no_d[depart_count]=rand()%2;

            if(no_d[depart_count]==0)
               cout<<"\tDomestic flight";
            else
                cout<<"\tInternational flight";

            depart_count++;

            if (airport.can_depart(current_flight) != success)
                current_flight.refuse();
        }
		
        //cout<<"\n\n";
        Flight moving_flight;
        switch (airport.activity(current_time, moving_flight))
        {
            case land:
                    moving_flight.land(current_time);
                    break;
            case takeoffg:
                    moving_flight.fly(current_time);
                    break;
            case idle:
                    run_idle(current_time);
        }
        cout<"\n\n";
   }
    airport.shut_down(end_time);
    cout<<"\n\t\t\t------------------------------------------------------------------------------------";
    cout<<"\n\t\t\tInstructions:\n\t\t\t\tFor booking tickets please dont try to enter the flights that is being takeoff\n\t\t\t And only book tickets that are to be landed or landing ";
    cout<<"\n\n\t\t\t\tPlease  note your PNR no and don't share with anyone";
    cout<<"\n\t\t\t------------------------------------------------------------------------------------";
    
	
	
	//TICKET BOOKING FOR FLIGHTS CURRENTLY ON AIRPORT
	
	
	class domestic_book D;
    class international_book I;
    class passenger p1;
    class payment p2;
	
	
    int ch,ch1,n,n1;
    char input;
    int f=0;
    do
    {
        cout << "\n\n\t\t\t\t  Here you can Reserve your Flight tickets " << endl << endl;
        cout <<"\t\t\t\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
        cout << "\t\t\t\t  Book your Flight tickets at affordable prices!!" << endl;
        cout <<"\t\t\t\t   <><><><><><><><><><><><><><><><><><><><><><><>";
        cout<<"\n\n\t\t\t\t\tFlights you can book tickets.:      ";
        for(int i=0;i<k;i++)
        {
            if(land_flight[i]!=0)
                 cout<<land_flight[i]<<"   ";
        }
		
		
        cout<<"\n";
        cout << "\n\n\t\t\t\t1.Book Flight(1) \n\t\t\t\t2.Cancel Fight(2) \n\t\t\t\t3.Check Ticket(3) \n\t\t\t\t4.Exit(4)" << endl;
        cout << "\n\t\t Please enter your choice:  ";
        cin >> ch;
		
        switch(ch)
        {
            case 1:
                    system("CLS");
                    cout << "\nPlease enter the flight no       " ;
                    cin >> ch1;
                    int u;
                    for(int i=0;i<a;i++)
                    {
                        if(land_flight[i]==ch1)
                        {
                            u=no_l[i];
                            f=1;
                        }
                    }
                    if(f==0)
                    {
                        cout<<"***********Enter a valid flight no**************";
                    }
                    cout<<"\n\n";
                    switch(u)
                    {
                        case 0:
                                p1.d_pnr(ch1);
                                p1.p_detail(1);
                                p1.gender_check();
                                p1.more_details();
                                p2.pay_detail();
                                p1.disp();
                                createfile(p1);
                                break;
                        case 1:
                                p1.i_pnr(ch1);
                                p1.p_detail(2);
                                p1.gender_check();
                                p1.more_details();
                                p2.pay_detail();
                                p1.dispi();
                                createfilei(p1);
                                break;
                        default:
                                cout << "************Wrong input entered.Try again********\n\n\n" << endl;
                    }
                    break;

            case 2:

                    cout << "\n1.Domestic Fights(1) \n2.International Flights(2)" << endl;
                    cout << "\nPlease enter your option         "   ;
                    cin >> ch1;
                    if(ch1==1)
                    {
                        cout << "Please enter your PNR no.:     " ;
                        cin>>n;
                        cout << "Please enter your Flight no.:  " ;
                        cin>>n1;
                        cancelticket(n,n1);
                    }
                    else if(ch1==2)
                    {
                        cout << "Please enter your PNR no.:     " ;
                        cin>>n;
                        cout << "Please enter your Flight no.:  " ;
                        cin>>n1;
                        cancelticketi(n,n1);
                    }
                    else
                    {
                        cout << "*******Wrong input entered.Try again*********\n\n\n";
                    }
                    break;

            case 3:
                    cout << "\n1.Domestic Fights(1) \n2.International Flights(2)" << endl;
                    cout << "\nPlease enter your option         " ;
                    cin >> ch1;
                    if(ch1==1)
                    {
                        cout << "Please enter your PNR no.:     " ;
                        cin>>n;
                        cout << "Please enter your Flight no.:  " ;
                        cin>>n1;
                        checkticket(n,n1);
                    }
                    else if(ch1==2)
                    {
                        cout << "Please enter your PNR no.:     " ;
                        cin>>n;
                        cout << "Please enter your Flight no.:  " ;
                        cin>>n1;
                        checkticketi(n,n1);
                    }
                   else
                    {
                        cout << "*************Wrong input entered.Try again**************\n\n\n";
                    }
                    break;
            case 4:
                cout<<"\n\n\n\n\t\t\t\t\t\t------------------------------------------THANK YOU!!-----------------------------------------\t\t\t\t\n\n\n\n";
                exit(1);
                break;

            default:
                    cout << "\n***********Wrong input entered.Try again.**********\n\n\n\n" << endl;
        }

        cout<<"\n\n\nDo you wish to continue:(y/Y)" << endl;
        cin >> input;

    }while(input=='Y' || input=='y');

    cout<<"\n\n\t\t\t\t\t\t------------------------------------------THANK YOU!!-----------------------------------------\t\t\t\t\n\n";
    return 0;
}
