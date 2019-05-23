#ifndef ROBOT_FONCTIONS_H
#define ROBOT_FONCTIONS_H

//Code by Romain THOMAS    2019

#include "Arduino.h"

typedef enum {
  NOIR,
  BLANC,
  ROUGE,
  VERT,
  BLEU,
  JAUNE,
  MAGENTA,
  CYAN}couleur;

typedef enum {
  DISABLE,
  LEFT,
  RIGHT,
  ALL
}cligno;

class RobotFonctions
{
  private :
    //pins :
    uint8_t pin_cligno_r;
    uint8_t pin_cligno_l;
    uint8_t pin_led_phares;
    uint8_t pin_led_rgb_r;
    uint8_t pin_led_rgb_g;
    uint8_t pin_led_rgb_b;
    //vars :
    cligno clignoState = DISABLE;
    uint8_t lumPhares = 128;
    uint8_t pharesState = 0;
    uint8_t r = 128;
    uint8_t g = 128;
    uint8_t b = 128;
    uint8_t rgbLedState = 0;

    long t_cligno = 0;

  public :
    RobotFonctions(uint8_t pin_cligno_r, uint8_t pin_cligno_l, uint8_t pin_led_phares, uint8_t pin_led_rgb_r, uint8_t pin_led_rgb_g, uint8_t pin_led_rgb_b);//constructeur
    void update();//met a jour les LEDs
    void enableClignoAll();//active tout les clignotants
    void enableClignoRight();//active les clignotants droit
    void enableClignoLeft();//active les clignotants gauche
    void disableCligno();//desactive les clignotants
    void enablePhares();//active les phares
    void disablePhares();//desactive les phares
    void setLumPhares(uint8_t lum);//regle la luminosite des phares (de 0 a 255)
    void enableRGBLed();//active les LEDs RGB
    void disableRGBLed();//desactive les LEDs RGB
    void setRGBColor(uint8_t r, uint8_t g, uint8_t b);//regle la couleur des leds RGB avec trois variables (de (0,0,0) a (255,255,255))
    void setColor(couleur c);//regle la couleur des LEDs RGB avec les couleurs du type couleur (NOIR, BLANC, ROUGE...)
};

#endif //ROBOT_FONCTIONS_H
