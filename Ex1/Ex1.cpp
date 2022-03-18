#include <fstream>
#include "DirectedGraph2.h"
#include <iostream>

int main() {
    ifstream in ("input.in.txt");
    ofstream out ("output.out.txt");

    int T,N;
    in >> T;

    for (int i = 0; i < T; i++)
    {
        in >> N;
        string Word;
        vector<string> Words;

        for (int i = 0; i < N; i++)
        {
            in >> Word;
            Words.push_back(Word);
        }

        if (canBeChained(Words))
        {
            out << 1 << endl;
        } else
        {
            out << 0 << endl;
        }
        
           
       

    }
    
    
}