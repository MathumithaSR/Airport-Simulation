#include <iostream>
#include <iomanip>
#include <stdlib.h>



enum Flight_status {null, arriving, departing};
enum Error_code {success,overflow,underflow};

class Flight
{
   int flt_num;
   int clock_start;
   Flight_status state;

public:
   Flight();
   Flight(int flt, int time, Flight_status status);
   void refuse() ;
   void land(int time) ;
   void fly(int time) ;
   int started();
};

Flight::Flight(int flt, int time, Flight_status status)

{
   flt_num = flt;
   clock_start = time;
   state = status;
   cout << "\n\nFlight number " << flt << " ready to ";
   if (status == arriving)
   {
       cout << "land." << endl;
       land_flight[k]=flt;
       k++;
       cout<<"\n"<<flt;
   }
   else if (status == departing)
   {
        cout << "take off." << endl;
        takeoff_flight[m]=flt;
        m++;
        cout<<"\n"<<flt;
   }
}

Flight::Flight()
{
    flt_num = 0;
    clock_start = 0;
    state = null;
}

void Flight::refuse()
{
    cout << "\n\nFlight number " << flt_num;
    if (state == arriving)
        cout << " directed to another airport    " << endl;
    else
        cout << " told to try to takeoff again later" << endl;
}

void Flight::land(int time)
{
    int wait = time - clock_start;
    cout <<"\n\n "<< time << "   : Flight " << flt_num << " landed after "
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << " in the takeoff queue." << endl;
    for(int i=0;i<20;i++)
    {
        if(land_flight[i]==flt_num)
        {
            land_flight[i]=0;
        }
    }
}

void Flight::fly(int time)
{
    int wait = time - clock_start;
    cout <<"\n\n  "<< time << "  : Flight number " << flt_num << " took off after "
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << " in the takeoff queue." << endl;
    for(int i=0;i<20;i++)
    {
        if(takeoff_flight[i]==flt_num)
        {
            takeoff_flight[i]=0;
        }
    }
}
int Flight::started()
{
    return clock_start;
}
struct Node
{
    Flight entry;
    Node *next;
    Node(){next = NULL;};
    Node(Flight item, Node *add_on = NULL)
    {   entry = item;
        next = add_on;
    };
};