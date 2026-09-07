#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

struct Time {
    string name;
    string tid;
    int sort_tid;
};

vector<Time> read_data(string const& file_path){
    ifstream filestream(file_path);
    vector<Time> times{};
    string number{};
    string ofortid{};
    // Kanske vill flytta på den här men kan vara effektivare.
    Time line{};
    cout << "passed" << endl;
    while (!filestream.eof()) {
        filestream >> line.name;
        for (int i = 0; i < 3; ++i) {
            filestream >> number;
            line.tid += number;
            line.tid += ':';
            ofortid += number;
        }
        cout << ofortid << flush;
        line.sort_tid = stoi(ofortid);
        filestream.ignore(10000, '\n');
        times.push_back(line);
    }
    return times;
};

int main() {
    string filnamn{};
    cout << "Skriv in ett filnamn: ";
    cin >> filnamn;
    vector<Time> data;
    data = read_data(filnamn);

    return 1;
};



