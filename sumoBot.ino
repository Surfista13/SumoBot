#include "sumoBot.h"

void setup()
{
  // Initialisation des entrées
  pinMode(BP,                INPUT_PULLUP); // On ajoute une résistance de pullup pour que la pin soit à un niveau HIGH par défaut.
  pinMode(TCRT_AVG,          INPUT);
  pinMode(TCRT_AVD,          INPUT);
  pinMode(ULTRASON_ECHO,     INPUT);

  // Initialisation des sorties
  pinMode(MOTEUR_G_PWM,      OUTPUT);
  pinMode(MOTEUR_G_DIR_1,    OUTPUT);
  pinMode(MOTEUR_G_DIR_2,    OUTPUT);
  pinMode(MOTEUR_D_PWM,      OUTPUT);
  pinMode(MOTEUR_D_DIR_1,    OUTPUT);
  pinMode(MOTEUR_D_DIR_2,    OUTPUT);
  pinMode(ULTRASON_TRIGGER,  OUTPUT);
  Serial.flush();
}

void loop(){
  // Déclaration des variables
  byte ligne;      // Cette variable servira à mémoriser l'état des capteurs de ligne blanche
  byte ligne_mem;  // Cette variable servira à mémoriser le dernier capteur de ligne activé
  long distance;   // Cette variable servira à mémoriser l'état du capteur ultrason et la distance de l'adversaire
  unsigned long debut;
  unsigned long fin;
  unsigned long duree;

  // Attente du bouton GO
  attente_go();

  // Attente des 5sec règlementaires
  delay(5000);

  // Début du combat 
  while (digitalRead(BP) == HIGH){                                          // Tant qu'on n'appuie pas sur le bouton, on est en combat
    ligne = ligne_blanche();                                                // Détection de la ligne blanche   
    distance = ultrason_distance();                                         // Détection de l'adversaire       
    if (ligne > 0){                                          
      esquive_ligne(ligne);
      moteur_stop();
      distance = ultrason_distance(); 
      if(distance > ULTRASON_SEUIL || distance == 0){
        rotation(ligne,100);
      }else{
        moteur_avance(MOTEUR_25, MOTEUR_50);   
      };
    }
    if(distance < ULTRASON_SEUIL || distance > 0){
    moteur_avance(MOTEUR_25, MOTEUR_25); 
    }
    moteur_avance(MOTEUR_25, MOTEUR_50); 
    delay(0);     
  }                                                        
  // Sortie du mode combat, on arrête les moteurs et on attend que le bouton soit relâché
  moteur_stop();
  while (digitalRead(BP) == LOW);                       // cette syntaxe permet d'attendre la condition sans exécuter de code spécifique.
  delay(100);
}

void attente_go(){
  bool led = false;              // On créer une variable pour l'état des leds
  while (digitalRead(BP) == HIGH) // Tant que le bouton poussoir est à l'état haut (grâce à la fonction PULLUP)
  {
    delay(100);                  // On répète l'opération toutes les 200ms, c'est ce qui créer le clignotement
  }

  // Quand le bouton est pressé, on quitte la boucle While et on sort de la fonction attente_go()
}

byte ligne_blanche()
{
  if (digitalRead(TCRT_AVG))                      // si le capteur de ligne blanche avant gauche est activé
  {
    return AV_GAUCHE;                             // alors on renvoie la valeur associée à ce capteur, définie dans Kit_SumoBot.h
  }
  else if (digitalRead(TCRT_AVD))                 // si le capteur de ligne blanche avant droit est activé
  {
    return AV_DROITE;                             // alors on renvoie la valeur associée à ce capteur
  }
  else                                            // Sinon, aucun capteur d'activé, pas de ligne blanche détectée
  {
    return 0;
  }
}

//Méthode d'esquive de la ligne blanche
void esquive_ligne(byte sens)
{
  long aleatoire;
  moteur_recule(MOTEUR_25, MOTEUR_25);
  delay(300);
  if (sens == AV_GAUCHE)
  {
    moteur_rotation_droite(MOTEUR_25, MOTEUR_50); 
  }
  else
  {
    moteur_rotation_gauche(MOTEUR_50, MOTEUR_25); 
  }

  aleatoire = random(200, 500);
  
  delay(aleatoire);                                
}

//Méthode pour effectuer une rotation dont le sens est définie par l'opposée de la valeur detectée par les capteurs de lignes et un temps de rotation
void rotation(byte sens,int tps){
  if (sens == AV_GAUCHE)
  {
    moteur_rotation_droite(MOTEUR_25, MOTEUR_50); // le robot tourne vers la droite
  }
  else
  {
    moteur_rotation_gauche(MOTEUR_50, MOTEUR_25); // le robot tourne vers la gauche
  }
  delay(tps); // tps pour tourner qui determine l'angle de rotation
}
