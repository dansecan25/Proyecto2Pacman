//
// Created by dansecan on 26/03/23.
//

#ifndef PROYECTDATOS2_SFMLBUTTON_H
#define PROYECTDATOS2_SFMLBUTTON_H
#include <SFML/Graphics.hpp>
enum buttonStates{BTNidle=0,BTNhover,BTNpressed};
class SfmlButton {

private:
    short unsigned buttonState;
    bool pressedButton;
    bool hover;
    sf::RectangleShape buttonShape;
    sf::Font* font;
    sf::Text text;
    sf::Color idleC;
    sf::Color hoverC;
    sf::Color activeC;

public:
    SfmlButton(float x, float y, float width, float height, sf::Font * font, std::string text,
               sf::Color idleC, sf::Color hoverC, sf::Color activeC);
    ~SfmlButton();
    const bool isPressed() const;
    void update(float posX, float posY);
    void render(sf::RenderTarget* target);


};


#endif //PROYECTDATOS2_SFMLBUTTON_H
