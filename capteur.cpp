 /*               <- 10µs ->                     <- >200µs ->
 * Trigger : ___|¯¯¯¯¯¯¯¯¯|_________________________________|¯¯¯¯¯¯¯¯¯|____
 * Echo    : ___________________|¯¯¯¯¯¯¯¯¯¯¯¯¯¯|___________________________
 *                              <-- distance -->
 */

#include "capteur.h"

long ultrason_distance()
{
  long mesure;
  
  // On envoie le trigger
  digitalWrite(ULTRASON_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASON_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASON_TRIGGER, LOW);
  
  // On mesure le temps à l'état haut de la pin echo
  // On ajoute un timeout de 25ms pour le cas où aucun objet n'est devant le capteur
  mesure = pulseIn(ULTRASON_ECHO, HIGH, 25000); 
  
  // On attend le minimum de 200µs requit par le capteur
  delayMicroseconds(200);
  
  // On effectue la conversion en centimètres
  mesure = mesure * 17/1000;
  
  return mesure;
}
