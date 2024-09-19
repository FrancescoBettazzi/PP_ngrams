#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "matplotlibcpp.h"  // Includi la libreria matplotlib-cpp

using namespace std;
namespace plt = matplotlibcpp;  // Namespace per matplotlib

// Funzione per convertire una stringa in minuscolo
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Funzione per calcolare i bigrammi di caratteri
void computeCharacterBigrams(const string& text, map<string, int>& bigramFreq) {
    for (size_t i = 0; i < text.size() - 1; ++i) {
        string bigram = text.substr(i, 2);
        ++bigramFreq[bigram];
    }
}

// Funzione per calcolare i trigrammi di caratteri
void computeCharacterTrigrams(const string& text, map<string, int>& trigramFreq) {
    for (size_t i = 0; i < text.size() - 2; ++i) {
        string trigram = text.substr(i, 3);
        ++trigramFreq[trigram];
    }
}

// Funzione per calcolare i bigrammi di parole
void computeWordBigrams(const vector<string>& words, map<string, int>& bigramFreq) {
    for (size_t i = 0; i < words.size() - 1; ++i) {
        string bigram = words[i] + " " + words[i+1];
        ++bigramFreq[bigram];
    }
}

// Funzione per calcolare i trigrammi di parole
void computeWordTrigrams(const vector<string>& words, map<string, int>& trigramFreq) {
    for (size_t i = 0; i < words.size() - 2; ++i) {
        string trigram = words[i] + " " + words[i+1] + " " + words[i+2];
        ++trigramFreq[trigram];
    }
}

// Funzione per disegnare l'istogramma
void plotHistogram(const map<string, int>& freqMap, const string& title) {
    vector<string> labels;
    vector<int> values;

    for (const auto& pair : freqMap) {
        labels.push_back(pair.first);
        values.push_back(pair.second);
    }

    plt::bar(labels, values);  // Crea il grafico a barre
    plt::title(title);
    plt::show();  // Mostra il grafico
}

int main() {
    // Testo di esempio
    string text = "Questo è un esempio di testo per il calcolo di bigrammi e trigrammi.";

    // Convertiamo tutto il testo in minuscolo
    text = toLower(text);

    // Mappa per contenere la frequenza dei bigrammi e trigrammi
    map<string, int> charBigramFreq, charTrigramFreq, wordBigramFreq, wordTrigramFreq;

    // Calcolo bigrammi e trigrammi di caratteri
    computeCharacterBigrams(text, charBigramFreq);
    computeCharacterTrigrams(text, charTrigramFreq);

    // Spezzare il testo in parole
    stringstream ss(text);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    // Calcolo bigrammi e trigrammi di parole
    computeWordBigrams(words, wordBigramFreq);
    computeWordTrigrams(words, wordTrigramFreq);

    // Disegna istogrammi per i bigrammi e trigrammi di caratteri
    plotHistogram(charBigramFreq, "Bigrammi di caratteri");
    plotHistogram(charTrigramFreq, "Trigrammi di caratteri");

    // Disegna istogrammi per i bigrammi e trigrammi di parole
    plotHistogram(wordBigramFreq, "Bigrammi di parole");
    plotHistogram(wordTrigramFreq, "Trigrammi di parole");

    return 0;
}
