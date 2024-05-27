#pragma once
#include <SFML/Graphics.hpp>    
#include "Area.h"

class Text : public Area {
     sf::Text          _Text                                        ;
     sf::Font          _Font                                        ;
     sf::Color         _Color                  { sf::Color::Black } ;
     sf::Color         _Color_On               { sf::Color::Black } ;
     sf::Color         _Color_Turn             { sf::Color::Black } ;
     sf::Color         _Color_Turn_On          { sf::Color::Black } ;
         _f32          _Border                 { 0 }                ;
         _ui32         _CharacterSize          { 15 }               ;
     sf::Color         _BorderColor            { sf::Color::Black } ;
     sf::Color         _BorderColor_On         { sf::Color::Black } ;
     sf::Color         _BorderColor_Turn       { sf::Color::Black } ;
     sf::Color         _BorderColor_Turn_On    { sf::Color::Black } ;
         _bool         _Turn                :1 { false }            ;
    using Area::setSize;
    using Area::Area;
public:
    using Area::scanMousePosOff;
    using Area::scanMousePosOn;
    Text        operator =         (Text txt);
                Text               ();
                Text               (sf::RenderWindow* Win);
    void        setFont            (std::string filename);
    void        setString          (std::string str);
    std::string getString          ();
    void        setSize            (_ui32 size);
    _ui32       getCharacterSize   ();
    void        setColor           (sf::Color col);
    void        setColor           (sf::Color col, sf::Color colOn);
    void        setColorTurn       (sf::Color col);
    void        setColorTurn       (sf::Color col, sf::Color colOn );
    void        setBorder          (_f32 dx);
    void        setBorderColor     (sf::Color col);
    void        setBorderColor     (sf::Color col, sf::Color colOn);
    void        setBorderColorTurn (sf::Color col);
    void        setBorderColorTurn (sf::Color col, sf::Color colOn);
    void        setTurn            (_bool _Switch = true);
    void        draw               ();
};