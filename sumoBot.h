
#include "Arduino.h"                // bibliothèque pour la gestion de projet Arduino
#include <Wire.h>                   // Cette bibliothèque fournie par Arduino permet d'utiliser la liaison série et d'envoyer des messages à l'ordinateur
#include <SoftwareSerial.h>         //Bibliothèque de dialogue avec le bluetooth
#include "moteur.h"
#include "capteur.h"

#define VERSION "1.0"

//#define NUCLEO

#define ULTRASON_SEUIL 70

#define AV_GAUCHE  1
#define AV_DROITE  2
#define AV_CENTRE  3
#define AR_GAUCHE  4
#define AR_DROITE  5
#define AR_CENTRE  6

// Entrées
const int BP                  = 2;  // bouton poussoir
const int TCRT_AVG            = A0;  // TCRT avant gauche
const int TCRT_AVD            = A1; // TCRT avant droit


const int ULTRASON_ECHO    = 3; // Pin ECHO du module ultrason HC-SR04

// Sorties
/*#ifdef NUCLEO
const int LED_1            = A4;  // LED verte 1
const int LED_2            = A5; // LED verte 2
#else
const int LED_1            = 7;  // LED verte 1
const int LED_2            = 8; // LED verte 2
#endif
*/
const int MOTEUR_G_PWM     = 5;  // PWM moteur gauche
const int MOTEUR_G_DIR_1   = 9;  // Direction 1 moteur gauche
const int MOTEUR_G_DIR_2   = 10;  // Direction 2 moteur gauche
const int MOTEUR_D_PWM     = 6;  // PWM moteur droit
const int MOTEUR_D_DIR_1   = A3;  // Direction 1 moteur droit
const int MOTEUR_D_DIR_2   = A2; // Direction 2 moteur droit
const int ULTRASON_TRIGGER = 4; // Pin TRIGGER du module ultrason HC-SR04

//Méthodes
void attente_go();
byte ligne_blanche();
void esquive_ligne(byte sens);
