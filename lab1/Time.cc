#include<string>
#include<iostream>
#include"Time.h"

Time::Time(unsigned int H, unsigned int M, unsigned int S)
    : hours {0}, minutes {0}, seconds {0}
{
    set_time(H,M,S);
}

Time::Time()
    : hours {0}, minutes {0}, seconds {0}
{}

Time::Time(std::string time_string)
    : hours {0}, minutes {0}, seconds {0}
{
    unsigned int H, M, S;
    std::istringstream intermidiate_stream {"test"};
}
void Time::set_time(unsigned int H, unsigned int M, unsigned int S)
{

    if (H > 23 || M > 59 || S > 59) 
    {
        throw "Invalid time input!";
    }
    hours = H;
    minutes = M;
    seconds = S;
}
unsigned int Time::get_hour() 
{
    return hours;
}
unsigned int Time::get_minute() 
{
    return minutes;
}
unsigned int Time::get_second() 
{
    return seconds;
}