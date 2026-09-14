#ifndef TIME_H
#include<string>
#include<iostream>

#define TIME_H
class Time
{
    public:
    //Time();
    Time(std::string time_string);
    Time(unsigned int H = 0, unsigned int M = 0, unsigned int S= 0, unsigned int T = 0);
    unsigned int get_hour() const;
    unsigned int get_minute() const;
    unsigned int get_second() const;
    unsigned int get_thou() const;
    std::string to_string(bool is_12h = false) const;
    bool is_am() const;
    // Time operator++(int unused);
    bool operator<(Time const& rhs) const;
    bool operator>(Time const& rhs) const;
    bool operator<=(Time const& rhs) const;
    bool operator>=(Time const& rhs) const;
    bool operator!=(Time const& rhs) const;
    bool operator==( Time const& rhs) const;
    Time& operator++();
    Time operator++(int);
    std::ostream& operator<<(std::ostream& os);
    std::ostream& operator>>(std::ostream& os);
     
    

    private:
    void set_time(unsigned int H, unsigned int M, unsigned int S, unsigned int T);
    void rollover();
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    unsigned int thousands;
};
#endif