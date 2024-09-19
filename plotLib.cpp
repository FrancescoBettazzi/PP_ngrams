#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "matplotlibcpp.h"  // Includi la libreria matplotlib-cpp

using namespace std;
namespace plt = matplotlibcpp;  // Alias per matplotlibcpp

// Funzione per disegnare l'istogramma
void plotHistogram(const map<string, int>& freqMap, const string& title) {
    vector<string> labels;
    vector<int> values;

    for (const auto& pair : freqMap) {
        labels.push_back(pair.first);
        values.push_back(pair.second);
    }

    plt::bar(labels, values);  // Disegna l'istogramma
    plt::title(title);         // Imposta il titolo
    plt::show();               // Mostra il grafico
}

int main() {
    // Testo di esempio
    string text = "Questo è un esempio di testo per bigrammi e trigrammi.";

    // Mappa di esempio
    map<string, int> freqMap = {
            {"ab", 5}, {"bc", 3}, {"cd", 9}, {"de", 6}
    };

    // Disegna l'istogramma
    plotHistogram(freqMap, "Istogramma di Bigrammi");

    return 0;
}
