#include "UIObject.h"
#include <string>
#include <vector>

UIObject::UIObject(std::string fileName, Vector2 offset) {
	entityType = EEntityType::eUI;
	this->offset = offset;

	// ladowanie pliku <fileName>
	// otwieranie i odczyt pliku
	// zapis pliku do tablicy <characters>
}

char UIObject::GetUIChar(Vector2 currentPos) {
	// odczyt tabeli <characters> 
	// zwracanie znaku w przypadku znalezienia pozycji <currentPos>
	// w przypadku nieznalezienia pozycji <currentPos> zwraca "" badz '\0'
	return '\0'; // tymczasowo zeby kompilator sie nie czepial
}