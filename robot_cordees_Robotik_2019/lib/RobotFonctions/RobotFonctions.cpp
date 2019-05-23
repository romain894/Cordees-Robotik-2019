#include "RobotFonctions.h"

RobotFonctions::RobotFonctions(uint8_t pin_cligno_r, uint8_t pin_cligno_l, uint8_t pin_led_phares, uint8_t pin_led_rgb_r, uint8_t pin_led_rgb_g, uint8_t pin_led_rgb_b)
{
  this->pin_cligno_r = pin_cligno_r;
  this->pin_cligno_l = pin_cligno_l;
  this->pin_led_phares = pin_led_phares;
  this->pin_led_rgb_r = pin_led_rgb_r;
  this->pin_led_rgb_g = pin_led_rgb_g;
  this->pin_led_rgb_b = pin_led_rgb_b;
  pinMode(pin_cligno_r, OUTPUT);
  pinMode(pin_cligno_l, OUTPUT);
  pinMode(pin_led_phares, OUTPUT);
  pinMode(pin_led_rgb_r, OUTPUT);
  pinMode(pin_led_rgb_g, OUTPUT);
  pinMode(pin_led_rgb_b, OUTPUT);
}

void RobotFonctions::update()
{
  if (rgbLedState == 1) {
    digitalWrite(pin_led_rgb_r, r);
    digitalWrite(pin_led_rgb_g, g);
    digitalWrite(pin_led_rgb_b, b);
  }
  else {
    digitalWrite(pin_led_rgb_r, 0);
    digitalWrite(pin_led_rgb_g, 0);
    digitalWrite(pin_led_rgb_b, 0);
  }
  if (pharesState == 1) {
    analogWrite(pin_led_phares, lumPhares);
  }
  else {
    analogWrite(pin_led_phares, 0);
  }
  if (millis()-t_cligno >= 1000) {
    t_cligno = millis();
  }
  uint8_t cligno_droit = 0;
  uint8_t cligno_gauche = 0;
  if (millis()-t_cligno < 500) {
    switch (clignoState) {
      case ALL:{
        cligno_droit = 1;
        cligno_gauche = 1;
        break;
      }
      case RIGHT:{
        cligno_droit = 1;
        break;
      }
      case LEFT:{
        cligno_gauche = 1;
        break;
      }
    }
  }
  digitalWrite(pin_cligno_r, cligno_droit);
  digitalWrite(pin_cligno_l, cligno_gauche);
}

void RobotFonctions::enableClignoAll()
{
  clignoState = ALL;
  t_cligno = 0;
}

void RobotFonctions::enableClignoRight()
{
  clignoState = RIGHT;
  t_cligno = 0;
}

void RobotFonctions::enableClignoLeft()
{
  clignoState = LEFT;
  t_cligno = 0;
}

void RobotFonctions::disableCligno()
{
  clignoState = DISABLE;
}

void RobotFonctions::enablePhares()
{
  pharesState = 1;
}

void RobotFonctions::disablePhares()
{
  pharesState = 0;
}

void RobotFonctions::setLumPhares(uint8_t lum)
{
  lumPhares = lum;
}

void RobotFonctions::enableRGBLed()
{
  rgbLedState = 1;
}

void RobotFonctions::disableRGBLed()
{
  rgbLedState = 0;
}

void RobotFonctions::setRGBColor(uint8_t r, uint8_t g, uint8_t b)
{

}

void RobotFonctions::setColor(couleur c)
{
  switch (c) {
    case NOIR:{
      r = 0;
      g = 0;
      b = 0;
      break;
    }
    case BLANC:{
      r = 255;
      g = 255;
      b = 255;
      break;
    }
    case ROUGE:{
      r = 255;
      g = 0;
      b = 0;
      break;
    }
    case VERT:{
      r = 0;
      g = 255;
      b = 0;
      break;
    }
    case BLEU:{
      r = 0;
      g = 0;
      b = 255;
      break;
    }
    case JAUNE:{
      r = 255;
      g = 255;
      b = 0;
      break;
    }
    case MAGENTA:{
      r = 255;
      g = 0;
      b = 255;
      break;
    }
    case CYAN:{
      r = 0;
      g = 255;
      b = 255;
      break;
    }
  }
}
