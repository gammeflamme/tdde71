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
    // Tid string för utskrift, int för sortering
};

vector<Time> read_data()
// Ber om filnamn, laddar in och tolkar datan.
{
    string filnamn{};
    vector<Time> times{};
    
    cout << "Skriv in ett filnamn: ";
    cin >> filnamn;
    cin.ignore(1000, '\n');
    ifstream filestream(filnamn);
    while (!(filestream.is_open()))
    {
        cout << "FEL: Filen gick inte att oppna!" << endl;
        cout << "Skriv in ett filnamn: ";
        cin >> filnamn;
        filestream.open(filnamn);
        cin.ignore(1000, '\n');
    }
    

    Time iteration {}; // Temporär instans för varje rad.
    // Gå igenom hela filen
    while (!filestream.eof()) 
    {
        string stream_string_intermidiate{}; // Mellansteg mellan filestream och stringstream
        ostringstream numberformater{}; // Hjälpsträngström för formatering av siffror
        if(!(filestream >> iteration.name))
        {
            //rad följer inte formateringen
            cout << "En rad i filen är fel formaterad, hela filen kanske inte är läst" << endl;
            return times;
        }
        for (int j = 0; j < 3; ++j)
        // Loop över H:M:S
        {
            filestream >> stream_string_intermidiate;
            //Formatera siffror                    1 siffra på H
            numberformater << setfill('0') << setw(2 - (j == 0)) << stream_string_intermidiate;
        }
        // Int för sortering
        iteration.sort_tid = stoi(numberformater.str());
        // Sätt in : för formatering
        iteration.tid = numberformater.str().insert(1,1,':').insert(4,1,':');
        filestream.ignore(10000, '\n');
        times.push_back(iteration);
    }
    return times;
};

void sort_data(vector<Time> & data)
// Sorterar med innbyggt Bilbotek
{
    sort(data.begin(),data.end(),[](Time a, Time b)
            {
                return a.sort_tid < b.sort_tid;
            }
        );
}


int get_rows(int rader_i_fil) {
    // Rekrusift se till att input av mängden rader är ok.
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
        cin.ignore(1000, '\n');
        return get_rows(rader_i_fil);
    }
    cin.ignore(1000, '\n');
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



