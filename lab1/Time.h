#include<string>
#ifndef TIME_H
#define TIME_H
class Time
{
    public:
    Time();
    Time(std::string time_string);
    Time(unsigned int H, unsigned int M, unsigned int S);
    unsigned int get_hour();
    unsigned int get_minute();
    unsigned int get_second();

    private:
    void set_time(unsigned int H, unsigned int M, unsigned int S);
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};
#endif