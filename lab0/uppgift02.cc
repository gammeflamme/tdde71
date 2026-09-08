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

vector<Time> read_data()
{
    string filnamn{};
    vector<Time> times{};
    
    cout << "Skriv in ett filnamn: ";
    cin >> filnamn;
    ifstream filestream(filnamn);
    while (!(filestream.is_open()))
    {
        cout << "FEL: Filen gick inte att oppna!" << endl;
        cout << "Skriv in ett filnamn: ";
        cin >> filnamn;
        filestream.open(filnamn);
        cin.ignore(1000, '\n');
    }
    

    Time iteration {};
    while (!filestream.eof()) 
    {
        ostringstream numberformater{};
        string tmp{};
        if(!(filestream >> iteration.name))
        {
            //slut på rader
            cout << "varning: sista raden i filen ar ej en lopar tid " << endl;
            return times;
        }
        for (int j = 0; j < 3; ++j)
        {
            filestream >> tmp;
            numberformater << setfill('0') << setw(2 - (j == 0)) << tmp;
        }
        iteration.sort_tid = stoi(numberformater.str());
        iteration.tid = numberformater.str().insert(1,1,':').insert(4,1,':');
        filestream.ignore(10000, '\n');
        times.push_back(iteration);
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


int get_rows(int rader_i_fil) {
    int rader{};
    string input{};
    
    cout << "ange antal rader:";
    if(!(cin >> rader))
    {
        cout << "FEL: Inmatningen maste vara ett positivt heltal!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return get_rows(rader_i_fil);
    }
    if ( (rader > rader_i_fil) || (rader <= 0)) 
    {
        cout << "FEL: Det finns inte " << rader << " rader i filen." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return get_rows(rader_i_fil);
    }
    return rader;
}

int main() 
{

    unsigned int rader{};
    // Kolla om det går att dra in i rader så om man skriver negativt
    vector<Time> data;
    data = read_data();
    sort_data(data);

    rader = get_rows(data.size());
    cout << "    Namn    |    Tid    \n========================";
    for(int i = 0 ; i < rader ; ++i)
    {
        cout << '\n' << setw(10) << data.at(i).name << "  |  " 
             << data.at(i).tid;
    }
    cout << endl;
    return 1;
};



