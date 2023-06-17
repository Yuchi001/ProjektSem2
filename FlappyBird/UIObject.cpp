#include "UIObject.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "GameSettings.h"

using namespace std;

UIObject::UIObject(string fileName, char errorChar) {
    readUI(GameSettings::filePath_UI + fileName);
    entityType = EEntityType::eUI;
    this->errorChar = errorChar;
}

void UIObject::readUI(string fileName)
{
    string line;
    bool offset_red = false;
    string offset_x_str;
    string offset_y_str;
    int maxLineLength = 0;
    int lines = 0;
    
    ifstream file(fileName);
    while (getline(file, line)) {
        if (offset_red) {
            board.push_back(line);
            lines++;
            maxLineLength = maxLineLength < 
                line.length() ? 
                line.length() : maxLineLength;
            continue;
        }

        auto comma_index = line.find_first_of(',');
        offset_x_str = line.substr(0, comma_index);
        offset_y_str = line.substr(comma_index + 1);
        offset_red = true;
    }

    try {
        auto offset_x = stoi(offset_x_str);
        auto offset_y = stoi(offset_y_str);
        offset_x = offset_x == 0 ? offset_x : GameSettings::boardSize_x / offset_x - (maxLineLength / 2);
        offset_y = offset_y == 0 ? offset_y : GameSettings::boardSize_y / offset_y - (lines / 2);
        offset = Vector2(offset_x, offset_y);
    }
    catch (exception e) {
        throw new exception("Parse error");
        exit(1);
    }
}

char UIObject::GetUIChar(Vector2 searchedPos) {
    for (auto y = 0; y < board.size(); y++) {
        for (auto x = 0; x < board[y].length(); x++) {
            auto currentPos = 
                Vector2(x + offset.getX(), y + offset.getY());
            if (currentPos == searchedPos) 
                return GetConfiguredChar({y, x});
        }
    }
    return '\0'; 
}

char UIObject::GetConfiguredChar(Vector2 charPos) {
    auto currentCharacter = board[charPos.getX()][charPos.getY()];
    if (currentCharacter == '@') return ' ';

    auto childClassConfigChar = GetConfiguredChar_override(charPos);
    if (childClassConfigChar != errorChar) return childClassConfigChar;

    return currentCharacter;
}


void UIObject::printEndGameBoard(int score, int highScore)
{
    /*for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '_')
            {
                cout << " ";
                continue;
            }

            if (board[i][j] == 'X')
            {
                cout << score;
                continue;
            }

            if (board[i][j] == '+')
            {
                cout << highScore;
                continue;
            }

            cout << board[i][j];
        }
        cout << '\n';
    }*/
}