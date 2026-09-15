#ifndef TIME_H
#include<string>
#include<iostream>

#define TIME_H
class Time
{
    public:
    Time(unsigned int H = 0, unsigned int M = 0, unsigned int S= 0, unsigned int T = 0);
    Time(std::string time_string);
    unsigned int get_hour() const;
    unsigned int get_minute() const;
    unsigned int get_second() const;
    unsigned int get_thou() const;
    std::string to_string(bool is_12h = false) const;
    bool is_am() const;
    bool operator<(Time const& rhs) const;
    bool operator>(Time const& rhs) const;
    bool operator<=(Time const& rhs) const;
    bool operator>=(Time const& rhs) const;
    bool operator!=(Time const& rhs) const;
    bool operator==(Time const& rhs) const;
    Time& operator++();
    Time operator++(int);
    float operator-(Time const& rhs);

    private:
    void set_time(unsigned int H, unsigned int M, unsigned int S, unsigned int T);
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    unsigned int thousands;
};
std::ostream& operator<<(std::ostream& lhs, const Time& rhs);
#endif