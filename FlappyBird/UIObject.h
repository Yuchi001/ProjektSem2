#pragma once
#include "Entity.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class UIObject : public Entity
{
	
public:
    UIObject(string fileName, char errorChar = '\0');
    void readUI(string fileName);
    void printEndGameBoard(int score, int highScore);
    char GetUIChar(Vector2 searchPos);

protected:
    virtual char GetConfiguredChar_override(Vector2 charPos) = 0;
    vector<string> board;

private:
    char GetConfiguredChar(Vector2 charPos);

    Vector2 offset;

    char errorChar = '\0';
};

