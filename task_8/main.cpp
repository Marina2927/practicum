#include <iostream>
#include <string>
#include <fstream>
#include "assert.h"
#include "tests.h"

using namespace std;

string shorten(string sin);
string unshorten(string str);

string shorten(string sin){
    string sout;
    sout.clear();
    int i = 0, cnt;
    char sym;
    while (i < sin.size()){
        sym = sin[i];
        cnt = 1;
        i++;
        while (sin[i] == sym){
            cnt++;
            i++;
        }
        sout.push_back(sym);
        sout.push_back(cnt + '0');
    }
    return sout;
}

string unshorten(string sin){
    string sout;
    sout.clear();
    int i = 0, j;
    while (i < sin.size()){
        sout.push_back(sin[i]);
        j = sin[i+1] - '0';
        while (j > 1){
            sout.push_back(sin[i]);
            j--;
        }
        i++; i++;
    }
    return sout;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string sin, sout;
    fin >> sin;
    sout = shorten(sin);
    assert(test_1(sout));
    fout << sout << endl;
    sout = unshorten(sout);
    assert(test_2(sout));
    fout << sout;
    return 0;
}
