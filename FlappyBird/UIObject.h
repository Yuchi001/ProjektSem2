#pragma once
#include "Entity.h"
#include <string>
#include <vector>

using namespace std;

class UIObject : public Entity
{
	
public:
    //UIObject();
    void readUI();
    void printEndGameBoard(int score, int highScore);

private:
    vector<std::vector<char> > boarD;
    
   

};

