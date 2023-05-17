//
// Created by dansecan on 26/03/23.
//

#include "../Headers/SfmlButton.h"

SfmlButton::SfmlButton(float x, float y, float width, float height, sf::Font * font, std::string text,
                       sf::Color idleC, sf::Color hoverC, sf::Color activeC){
    this->buttonState=BTNidle;
    this->buttonShape.setPosition(sf::Vector2(x,y));
    this->buttonShape.setSize(sf::Vector2f(width,height));
    this->font=font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    this->text.setPosition(
            this->buttonShape.getPosition().x +(this->buttonShape.getGlobalBounds().width/ 2.f) - this->text.getGlobalBounds().width / 2.f,
            this->buttonShape.getPosition().y +(this->buttonShape.getGlobalBounds().height/ 2.f) - this->text.getGlobalBounds().height / 2.f );
    this->idleC=idleC;
    this->hoverC=hoverC;
    this->activeC=activeC;

    this->buttonShape.setFillColor(this->idleC);
}
SfmlButton::~SfmlButton() {

}
/**
 * @brief returns a boolean if the button is pressed or not
 * @return true if button is pressed, false if not
 */
const bool SfmlButton::isPressed() const{
    if(this->buttonState==BTNpressed) return true;
    return false;
}

/**
 * @brief updates the status of the button
 * @param posX float
 * @param posY float
 */
void SfmlButton::update(float posX, float posY) {
    this->buttonState=BTNidle;

    if(this->buttonShape.getGlobalBounds().contains(posX,posY)){
        this->buttonState=BTNhover;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->buttonState=BTNpressed;
        }
    }
    switch(this->buttonState){
        case BTNidle:
            this->buttonShape.setFillColor(this->idleC);
            break;
        case BTNpressed:
            this->buttonShape.setFillColor(this->activeC);
            break;
        case BTNhover:
            this->buttonShape.setFillColor(this->hoverC);
            break;
        default:
            this->buttonShape.setFillColor(sf::Color::Red);
            break;
    }
}
/**
 * @brief draws the button and text in the window
 * @param target window to draw button
 */
void SfmlButton::render(sf::RenderTarget *target) {
    target->draw(this->buttonShape);
    target->draw(this->text);
}
