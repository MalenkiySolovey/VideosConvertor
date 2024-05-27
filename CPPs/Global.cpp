#include "../Headers\Global.h" 

sf::Color RGB(_ui8 red, _ui8 green, _ui8 blue, _ui8 alpha) { return sf::Color(red, green, blue, alpha); }

_f32 _centering(_f32 x, _f32 y) { return (x - y) / 2.f; }

void saveSet() {
	std::fstream File("Files/Settings.txt", std::ios::out);
	File << _Set::pathIn << '\n';
	File << _Set::pathOut << '\n';
	File << _Set::pathOutff;
	File.close();
}

void loadSet() {
	std::fstream File("Files/Settings.txt");
	File >> _Set::pathIn;
	File >> _Set::pathOut;
	File >> _Set::pathOutff;
	File.close();
}