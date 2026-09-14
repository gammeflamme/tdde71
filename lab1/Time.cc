#include<string>
#include<sstream>
#include"Time.h"
#include <iomanip>

/*TODO:

- lägga till const där det går
- kommentarer vid behov
*/ 

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
    std::istringstream intermidiate_stream {time_string};
    char seperator{};
    intermidiate_stream >> H >> seperator >> M >> seperator >> S;
    set_time(H, M, S);
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
std::string Time::to_string(bool is_12h) const
{

    std::ostringstream intermidiate_stream {""};
    intermidiate_stream.fill('0');
    unsigned int formated_hours{hours};
    if (is_12h)
    {
        formated_hours = hours % 12;
        if (formated_hours == 0){ formated_hours = 12; }
    }

    intermidiate_stream << std::setw(2) << formated_hours << ':' 
                        << std::setw(2) << minutes << ':' 
                        << std::setw(2) << seconds;
    if (is_12h)
    {
        if (is_am())
        {
            intermidiate_stream << "am";
        }
        else
        {
            intermidiate_stream << "pm";
        }
    }
    return intermidiate_stream.str();
}
bool Time::is_am() const
{
    return hours > 0 && hours < 13;
}

unsigned int Time::get_hour() const
{
    return hours;
}
unsigned int Time::get_minute() const
{
    return minutes;
}
unsigned int Time::get_second() const
{
    return seconds;
}

// Operatorer
bool Time::operator==(Time const& rhs) const
{
    return hours == rhs.get_hour() &&
           minutes == rhs.get_minute() &&
           seconds == rhs.get_second();
}
bool Time::operator!=(Time const& rhs) const
{
   return !(*this == rhs);
}

bool Time::operator<(Time const& rhs) const
{
    if (rhs.get_hour() > hours) {return true;}
    if (rhs.get_hour() == hours) {
        if (rhs.get_minute() > minutes) {return true;}
        if (rhs.get_minute() == minutes && rhs.get_second() > seconds) {return true;}
    }
    return false;
}
bool Time::operator<=(Time const& rhs) const
{
    return (*this == rhs || *this < rhs);
}
bool Time::operator>(Time const& rhs) const
{
    return !(*this <= rhs);
}
Time& Time::operator++() {
    int overflow{};
    seconds ++;
    overflow = seconds / 60;
    seconds = seconds % 60;

    minutes += overflow;
    overflow = minutes / 60;
    hours = (hours + overflow) % 24;
    return *this;
}
Time Time::operator++(int) {
    Time old {*this};
    operator++();
    return old;
}
bool Time::operator>=(Time const& rhs) const
{
    return !(*this < rhs);
}
