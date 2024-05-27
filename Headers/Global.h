#pragma once
#include <SFML/Graphics.hpp>    
#include <fstream>
#include <iostream>

typedef bool              _bool;    //bool													 

typedef __int8            _i8;      //char													 
typedef __int16           _i16;     //short													 
typedef __int32           _i32;     //int												 
typedef __int64           _i64;     //long long												 
typedef unsigned __int8   _ui8;     //unsigned char									 
typedef unsigned __int16  _ui16;    //unsigned short											 
typedef unsigned __int32  _ui32;    //unsigned int										 
typedef unsigned __int64  _ui64;    //unsigned long long										 

typedef float             _f32;     //float										 
typedef double            _f64;     //double													 
typedef long double       _lf64;    //long double		

typedef signed char       _sc8;     //signed char
typedef char8_t           _uc8;     //char8_t												 
typedef char16_t          _uc16;    //char16_t												 
typedef char32_t          _uc32;    //char32_t												 
typedef __wchar_t         _wc;      //__wchar_t	

struct _Set {

	static inline std::string ffmpeg { "Files\\ffmpeg.exe" };
	static inline std::string cycle_ { "for %a in (\"" };
	static inline std::string _cycle { "*.mp4\") do " };
	static inline std::string name { "\"%a\"" };
	static inline std::string nname { "\"%~na.mp4\"" };

	static inline std::string pathOut { "..\\Save\\" };
	static inline std::string pathOutff { "Save/" };
	static inline std::string pathIn { "..\\Videos\\" };

	static inline std::string STpathOut { "..\\Save\\" };
	static inline std::string STpathOutff { "Save/" };
	static inline std::string STpathIn { "..\\Videos\\" };


};

// Colors
// But: RGB(234, 122, 8) , RGB(20, 201, 20)
// TurnBut: RGB(5, 129, 193), RGB(23, 160, 110)
// Bord: RGB(217, 65, 25), RGB(31, 110, 21)
// TurnBord: RGB(23, 103, 139), RGB(19, 98, 69)
sf::Color RGB(_ui8 red, _ui8 green, _ui8 blue, _ui8 alpha = 255U);

_f32 _centering(_f32 x, _f32 y);

void saveSet();

void loadSet();