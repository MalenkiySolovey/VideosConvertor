#pragma once
#include "Global.h"

class Area {
	void     _isOnArea     (sf::Vector2f pos);
protected:
	sf::RenderWindow* _Window                   ;
	sf::Vector2f      _Position       {0, 0}    ;
	sf::Vector2f      _Size           {0, 0}    ;
		_bool         _Centre_Flag :1 { false } ;
	sf::Vector2f      _d              { 0, 0 }  ;
		_bool         _Central     :1 { false } ;
	sf::Vector2f      _Pos_Other      { 0, 0 }  ;
	sf::Vector2f      _Size_Other     { 0, 0 }  ;
	    _bool         _On_Flag     :1 { false } ;
	    _bool         _On          :1 { false } ;
	void     scanMousePosOn  ();
	void     scanMousePosOff ();
	_bool    isMouseOnArea   ();
	void     _setPosCentre   ();
	void     _setCentral     ();
public:
	         Area          ();
	         Area          (sf::RenderWindow* win);
	_bool    isOnArea      (sf::Vector2f pos);
	_bool    isOnArea      (_f32 x, _f32 y);
	_bool    isOnArea      ();
	void     setOn         (_bool ptr = true);
	void     setWindow     (sf::RenderWindow* win);
	void     setSize       (sf::Vector2f size);
	void     setSize       (_f32 x, _f32 y);
	sf::Vector2f getSize       ();
	void     setPosition   (sf::Vector2f pos);
	void     setPosition   (_f32 x, _f32 y);
	void     setPosCentre  (_f32 dx, _f32 dy);
	void     setPosCentre  (sf::Vector2f dPos);
	void     setPosCentreOn  ();
	void     setPosCentreOff  ();
	void     setCentral(sf::Vector2f Pos, sf::Vector2f Size);
	void     setCentralOn();
	void     setCentralOff();
	sf::Vector2f getPosition   ();
};