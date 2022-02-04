#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "class_flight.cpp"
#include "class_queue.cpp"


enum Runway_activity {idle, land, takeoffg};
enum Error_code {success,overflow,underflow};


class Runway
{

public:
    Runway(int limit);
    Error_code can_land(const Flight &current);
    Error_code can_depart(const Flight &current);
    Runway_activity activity(int time, Flight &moving);
    void shut_down(int time);

private:
    Queue landing;
    Queue takeoff;
    int queue_limit;
    int num_land_requests;
    int num_takeoff_requests;
    int num_landings;
    int num_takeoffs;
    int num_land_accepted;
    int num_takeoff_accepted;
    int num_land_refused;
    int num_takeoff_refused;
    int land_wait;
    int takeoff_wait;
    int idle_time;
};

Runway::Runway(int limit)
{
    queue_limit = limit;
    num_land_requests = num_takeoff_requests = 0;
    num_landings = num_takeoffs = 0;
    num_land_refused = num_takeoff_refused = 0;
    num_land_accepted = num_takeoff_accepted = 0;
    land_wait = takeoff_wait = idle_time = 0;
}

Error_code Runway::can_land(const Flight &current)

{
    Error_code result;
    if (landing.size() < queue_limit)
    {
        result = landing.append(current);
    }
    else
    {
        result = overflow;
    }
    num_land_requests++;

    if (result != success)
    {
       num_land_refused++;
    }
    else
    {
       num_land_accepted++;
    }
    return result;
}

Error_code Runway::can_depart(const Flight &current)

{
    Error_code result;
    if (takeoff.size() < queue_limit)
    {
        result = takeoff.append(current);
    }
    else
    {
        result = overflow;
    }
    num_takeoff_requests++;
    if (result != success)
    {
       num_takeoff_refused++;
    }
    else
    {
       num_takeoff_accepted++;
    }
    return result;
}

Runway_activity Runway::activity(int time, Flight &moving)

{
    Runway_activity in_progress;
    if (!landing.empty())
    {
        landing.retrieve(moving);
        land_wait = land_wait + time - moving.started();
        num_landings++;
        in_progress = land;
        landing.serve();
    }
    else if (!takeoff.empty())
    {
        takeoff.retrieve(moving);
        takeoff_wait += time - moving.started();
        num_takeoffs++;
        in_progress = takeoffg;
        takeoff.serve();
    }
   else
    {
        idle_time++;
        in_progress = idle;
    }
    return in_progress;
}


void Runway::shut_down(int time)

{
    tot_flights=(num_land_requests + num_takeoff_requests);
    cout << "\n\nSimulation has concluded after              \t" << time << "      time units." << endl;
    cout << "\n\nTotal number of flights processed            \t" << (num_land_requests + num_takeoff_requests) << endl;
    cout << "\n\nTotal number of flights asking to land       \t" << num_land_requests << endl;
    cout << "\n\nTotal number of flights asking to take off   \t" << num_takeoff_requests << endl;
    cout << "\n\nTotal number of flights accepted for landing \t" << num_land_accepted << endl;
    cout << "\n\nTotal number of flights accepted for takeoff \t" << num_takeoff_accepted << endl;
    cout << "\n\nTotal number of flights refused for landing  \t" << num_land_refused << endl;
    cout << "\n\nTotal number of flights refused for takeoff  \t" << num_takeoff_refused << endl;
    cout << "\n\nTotal number of flights that landed          \t" << num_landings << endl;
    cout << "\n\nTotal number of flights that took off        \t"<< num_takeoffs << endl;
    cout << "\n\nTotal number of flights left in landing queue \t" << landing.size() << endl;
    cout << "\n\nTotal number of flights left in takeoff queue \t" << takeoff.size() << endl;

    cout << "\n\nPercentage of time runway idle               \t"
            << 100.0 * (( float ) idle_time) / (( float ) time) << "%" << endl;

    cout << "\n\nAverage wait in landing queue               "
        << (( float ) land_wait) / (( float ) num_landings) << " time units";

    cout << endl << "\n\nAverage wait in takeoff queue        "
        << (( float ) takeoff_wait) / (( float ) num_takeoffs)
        << " time units" << endl;

    cout << "\n\nAverage observed rate of flights wanting to land     "
        << (( float ) num_land_requests) / (( float ) time)
        << " per time unit" << endl;

    cout << "\n\nAverage observed rate of flights wanting to take off     "
        << (( float ) num_takeoff_requests) / (( float ) time)
        << " per time unit" << endl;
}
