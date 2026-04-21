#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void CheckAnswer(string word, string solution, map<char, int> myMap) {
    for (int i = 0; i < 5; i++) {
        if (solution.find(word[i]) != string::npos && myMap.at(word[i]) != 0) {
            if (solution[i] == word[i]) {
                cout << "\033[32m" << word[i] << "\033[0m";
            }
            else {
                cout << "\033[33m" << word[i] << "\033[0m";
            }
            myMap[word[i]]--;
        }
        else {
            cout << "\033[31m" << word[i] << "\033[0m";
        }
    }
    cout << endl;
}

vector<string> WordList(string filename) {
    ifstream file(filename);
    string word;
    vector<string> result;
    while (getline(file, word)) {
        word.erase(remove(word.begin(), word.end(), '\r'), word.end());
        result.push_back(word);
    }

    return result;
}
int main() {
    srand(time(0));
    string word;
    vector<string> list = WordList("words.txt");
    int randNum = rand() % list.size();
    string randWord = list.at(randNum);

    //Collect occurences of letters in solution word
    map<char, int> myMap;
    for (int i = 0; i < randWord.size(); i++) {
     myMap[randWord[i]]++;
    }

    while (word != randWord) {
        cout << "Enter 5 letter word or q to quit: ";
        getline(cin, word);
        if (word == "q") {
            cout << "Word was " << randWord << endl;
            return 0;
        }
        CheckAnswer(word, randWord, myMap);
    }
    cout << "You Win!" << endl;
    
    return 0;
}