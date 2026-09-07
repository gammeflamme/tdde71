#include<iostream>
#include<vector>
#include<fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Time 
{
    string name;
    string tid;
    int sort_tid;
};

vector<Time> read_data(string const& file_path, int const& rader)
{
    ifstream filestream(file_path);
    vector<Time> times(rader);
    // Kanske vill flytta på den här men kan vara effektivare.

    for (int i = 0 ; i < rader ; ++i) 
    {
        ostringstream numberformater{};
        string tmp{};
        filestream >> times.at(i).name;
        for (int i = 0; i < 3; ++i) 
        {
            filestream >> tmp;
            numberformater << setfill('0') << setw(2) << tmp;
        }
        //cout << number.str() << endl;
        times.at(i).sort_tid = stoi(numberformater.str());
        times.at(i).tid = numberformater.str().insert(2,1,':').insert(5,1,':');
        filestream.ignore(10000, '\n');
    }
    return times;
};

void sort_data(vector<Time> & data)
{
    sort(data.begin(),data.end(),[](Time a, Time b)
            {
                return a.sort_tid < b.sort_tid;
            }
        );
}


int main() {
    string filnamn{};
    int rader{};
    cout << "Skriv in ett filnamn: ";
    cin >> filnamn;
    cout << "ange antal rader:";
    cin >> rader;
    vector<Time> data;
    data = read_data(filnamn,rader);
    sort_data(data);
    cout << "    Namn    |    Tid    \n========================";
    for(int i = 0 ; i < data.size() ; ++i)
    {
        cout << '\n' << setw(10) << data.at(i).name << "  |  " 
             << data.at(i).tid;
    }
    cout << endl;
    return 1;
};



