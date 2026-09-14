#ifndef TIME_H
#include<string>
#include <iomanip>

#define TIME_H
class Time
{
    public:
    Time();
    Time(std::string time_string);
    Time(unsigned int H, unsigned int M, unsigned int S);
    unsigned int get_hour() const;
    unsigned int get_minute() const;
    unsigned int get_second() const;
    std::string to_string(bool is_12h = false) const;
    bool is_am() const;
    // Time operator++(int unused);
    bool operator<(Time const& rhs) const;
    bool operator>(Time const& rhs) const;
    bool operator<=(Time const& lhs) const;
    bool operator>=(Time const& lhs) const;
    bool operator!=(Time const& rhs) const;
    bool operator==( Time const& rhs) const;
    Time& operator++();
    Time operator++(int);
    

    private:
    void set_time(unsigned int H, unsigned int M, unsigned int S);
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};
#endif