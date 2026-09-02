#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{
    // Variabeldefinitioner
    // int heltal{};
    // float flyttal{};
    // char tecken{};
    string ord{};

    // cout << "  ===== Del A Formaterad I/O =====\n"
    // << "  Skriv in ett heltal: ";
    // cin >> heltal;
    // cout << "  Du skrev in talet: " << heltal
    // <<"\n  Skriv in ett heltal och ett flyttal: ";
    // cin >> heltal;
    // cin >> flyttal;
    // cout << "  Du skrev in heltalet: " << heltal
    // << "\n  Du skrev in flyttalet: " << flyttal
    // << "\n  Skriv in ett flyttal och ett heltal: ";
    // cin >> flyttal;
    // cin >> heltal;
    // cout << "  Du skrev in heltalet: " << heltal
    // << "\n  Du skrev in flyttalet: " << flyttal
    // << "\n  Skriv in ett tecken: ";
    // cin >> tecken;
    // cout << "  Du skrev in tecknet: " << tecken
    //      << "\n  Skriv in ett ord: ";
    // cin >> ord;
    // cout << "  Du skrev in ordet: " << ord << endl;

    // cout << "\n  ===== Del B Escapesekvenser =====\n"
    //      << "  Skriv in ett heltal och ett ord: ";
    // cin >> heltal;
    // cin >> ord;
    // cout << "  Du skrev in talet |" << heltal << "| och ordet |" << ord << "|."
    //      << "\n  Skriv in ett tecken och ett ord: ";
    // cin >> tecken;
    // cin >> ord;
    // cout << "  Du skrev in ordet \"" << ord << "\" och tecknet '" << tecken << "'.";

    
    // struct Rad 
    // {
    //     string ord;
    //     float tal;
    // };
    // vector<Rad> tabell (5);

    // cout << "\n\n===== Del C Inmatningsbuffer och tabellutskrift =====\n"
    //      <<"Skriv in en sträng och ett decimaltal fem gånger på samma rad: \n";
    // for (int i = 0 ; i < 5; ++i)
    // {
    //     cin >> tabell.at(i).ord >> tabell.at(i).tal;
    // }
    // cout << "Här är talen i tabellform: \n" <<
    //         "==============================\n";
    // for (int i = 0 ; i < 5; ++i)
    // {
    //     cout << setw(20) << setfill('_') << left << tabell.at(i).ord 
    //     << right << setw(10) << setfill('_') << fixed << setprecision (3) << tabell.at(i).tal << '\n';
    // }

    // string mening {};
    // cout << "===== Del D Oformaterad I/O =====\nSkrev in en rad text: ";
    // getline(cin, mening);
    // cout << "Du skrev in: \"" << mening << "\"\nSkrev in en till rad text: ";
    // getline(cin, mening);
    // cout << "Du skrev in: \"" << mening << '"';

    string indata {};
    string namn1 {};
    istream used_cin;
    string namn2{};
    cout << "===== Del E Sträng som datakälla (istf cin) =====\nSkriv in liU-ID och fullständigt namn på samma rad:";
    getline(cin, indata);
    cout << "Du skrev in: \"" << indata << '"';
    cin >> namn1;
    cout << namn1;
    
}