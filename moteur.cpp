#include "moteur.h"  //inclusion du header

void moteur_avance(byte val_gauche, byte val_droite)
{
  digitalWrite(MOTEUR_G_DIR_1, 0);
  digitalWrite(MOTEUR_G_DIR_2, 1);
  digitalWrite(MOTEUR_D_DIR_1, 0);
  digitalWrite(MOTEUR_D_DIR_2, 1);
  analogWrite(MOTEUR_G_PWM, val_gauche);
  analogWrite(MOTEUR_D_PWM, val_droite);
}

void moteur_recule(byte val_gauche, byte val_droite)
{
  digitalWrite(MOTEUR_G_DIR_1, 1);
  digitalWrite(MOTEUR_G_DIR_2, 0);
  digitalWrite(MOTEUR_D_DIR_1, 1);
  digitalWrite(MOTEUR_D_DIR_2, 0);
  analogWrite(MOTEUR_G_PWM, val_gauche);
  analogWrite(MOTEUR_D_PWM, val_droite);
}

void moteur_rotation_droite(byte val_gauche, byte val_droite)
{
  digitalWrite(MOTEUR_G_DIR_1, 1);
  digitalWrite(MOTEUR_G_DIR_2, 0);
  digitalWrite(MOTEUR_D_DIR_1, 0);
  digitalWrite(MOTEUR_D_DIR_2, 1);
  analogWrite(MOTEUR_G_PWM, val_gauche);
  analogWrite(MOTEUR_D_PWM, val_droite);
}

void moteur_rotation_gauche(byte val_gauche, byte val_droite)
{
  digitalWrite(MOTEUR_G_DIR_1, 0);
  digitalWrite(MOTEUR_G_DIR_2, 1);
  digitalWrite(MOTEUR_D_DIR_1, 1);
  digitalWrite(MOTEUR_D_DIR_2, 0);
  analogWrite(MOTEUR_G_PWM, val_gauche);
  analogWrite(MOTEUR_D_PWM, val_droite);
}

void moteur_bloque()
{
  digitalWrite(MOTEUR_G_DIR_1, 0);
  digitalWrite(MOTEUR_G_DIR_2, 0);
  digitalWrite(MOTEUR_D_DIR_1, 0);
  digitalWrite(MOTEUR_D_DIR_2, 0);
  analogWrite(MOTEUR_G_PWM, MOTEUR_100);
  analogWrite(MOTEUR_D_PWM, MOTEUR_100);
}

void moteur_stop()
{
  digitalWrite(MOTEUR_G_DIR_1, 0);
  digitalWrite(MOTEUR_G_DIR_2, 0);
  digitalWrite(MOTEUR_D_DIR_1, 0);
  digitalWrite(MOTEUR_D_DIR_2, 0);
  analogWrite(MOTEUR_G_PWM, MOTEUR_0);
  analogWrite(MOTEUR_D_PWM, MOTEUR_0);
}
