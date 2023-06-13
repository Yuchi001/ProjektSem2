#include "UIObject.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

void UIObject::readUI()
{
    string line;
    char value;
    
    ifstream file("FlappyBirdEndGameUI.txt");
    while (getline(file, line)) {
        vector<char> row;
        istringstream iss(line);
        while (iss >> value) {
            row.push_back(value);
        }
        boarD.push_back(row);
    }
}


void UIObject::printEndGameBoard(int score, int highScore)
{
    for (int i = 0; i < boarD.size(); i++)
    {
        for (int j = 0; j < boarD[i].size(); j++)
        {
            if (boarD[i][j] == '_')
            {
                cout << " ";
                continue;
            }

            if (boarD[i][j] == 'X')
            {
                cout << score;
                continue;
            }

            if (boarD[i][j] == '+')
            {
                cout << highScore;
                continue;
            }

            cout << boarD[i][j];
        }
        cout << '\n';
    }
}