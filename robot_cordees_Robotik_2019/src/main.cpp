#include "Arduino.h"

//fichiers avec les #define :
#include "pins.h"
#include "parameters.h"

//librairies (bibliotheques) :
#include <RobotFonctions.h>
#include <Motor.h>
//#include <NewPing.h>
#include <Ultrasonic.h>
#include <IRremote.h>

Motor moteurDroit(PIN_MOTEUR_D_EN, PIN_MOTEUR_D_1, PIN_MOTEUR_D_2, 1);
Motor moteurGauche(PIN_MOTEUR_G_EN, PIN_MOTEUR_G_1, PIN_MOTEUR_G_2, 1);

RobotFonctions robot(PIN_LED_CLIGNO_R, PIN_LED_CLIGNO_L, PIN_LED_PHARES, PIN_LED_RGB_R, PIN_LED_RGB_G, PIN_LED_RGB_B);
//Motor moteur()
//NewPing sonar(PIN_SONAR_TRIG, PIN_SONAR_ECHO, SONAR_MAX_DISTANCE);
Ultrasonic sonar(PIN_SONAR_TRIG, PIN_SONAR_ECHO, SONAR_MAX_DISTANCE);

//IRrecv reception_ir(PIN_IR);//pour la telecommande
//decode_results decode_ir; // stockage données reçues par la telecommande

//int etatMoteur = 0;

void setup()
{
	Serial.begin(57600);
	Serial.println("Robot OK !");
	robot.enableClignoAll();
	robot.enablePhares();
	robot.enableRGBLed();
	//reception_ir.enableIRIn(); // démarre la réception de la telecommande IR

	robot.setLumPhares(255);
	robot.setColor(CYAN);
	moteurDroit.setSpeed(255);
	moteurGauche.setSpeed(255);
}

void loop()
{
	delay(10);
	//Serial.println(sonar.Ranging(CM));//Affiche la distance du sonar
	/*if (reception_ir.decode(&decode_ir))
  {
    Serial.println(decode_ir.value, HEX); //affiche la valeur de la touche presse
    reception_ir.resume(); // reçoit le prochain code
    if (decode_ir.value == 0xFFA25D)
    {
      etatMoteur = !etatMoteur;//inverse l'etat du moteur
    }

  }*/
	if (sonar.Ranging(CM) > 15) {
		robot.setColor(CYAN);
		//moteurDroit.setSpeed(etatMoteur*255);
		//moteurGauche.setSpeed(etatMoteur*255);
		moteurDroit.setSpeed(255);
		moteurGauche.setSpeed(255);
	}
	else {
		robot.setColor(ROUGE);
		moteurDroit.setSpeed(0);
		moteurGauche.setSpeed(0);
		robot.update();
		delay(800);
		robot.setColor(BLEU);
		moteurDroit.setSpeed(-200);
		moteurGauche.setSpeed(255);
		robot.update();
		delay(400);
		robot.setColor(JAUNE);
		moteurDroit.setSpeed(200);
		moteurGauche.setSpeed(200);
		robot.update();
		delay(800);
		robot.setColor(VERT);
		moteurDroit.setSpeed(255);
		moteurGauche.setSpeed(-200);
		robot.update();
		delay(400);
	}
	robot.update();
}
