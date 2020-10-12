== Bibliothèque LightEffect ==
------------------------------
Version 1.0.0 - Octobre 2020

Cette bibliothèque permet de créer facilement des animations lumineuses
à partir d'une carte Arduino ou d'un microcontrôleur ATtiny (feux tricolores, 
chenillard, enseigne de commerçant, etc.)

Les LEDs sont reliées aux sorties numériques de la carte Arduino ou du
microcontrôleur avec une résistance en série limitant le courant dans la LED. 
La valeur de la résistance dépend de la couleur de la LED et doit tenir compte 
de la limitation en courant de la sortie numérique et des possibilités de la carte.

Les LEDs peuvent être connectées aux sorties numériques par leur anode ou bien
par leur cathode, mais toutes les LEDs doivent être connectées de la même manière.
De plus, les sorties numériques utilisées doivent se suivre dans l'ordre croissant
de leur numérotation.
Attention : ne pas confondre numéro de sortie numérique et numéro de broche du
microcontrôleur (voir les documentations des cartes ou des microcontrôleurs).

La bibliothèque utilise des delay(), ce qui ne permet pas de l'utiliser dans un 
programme faisant autre chose que gérer les effets lumineux.

= Utilisation =
---------------
Inclure la bibliothèque au début du programme d'utilisation avec
#include <LightEffect.h>

Instancier un ou plusieurs effets lumineux en donnant un nom à l'objet et en précisant
la position de la première LED, le nombre de LEDs et le niveau logique pour les allumer.
LightEffect monEnseigne(4, 6, LOW);
Les 6 LEDs sont connectées par leur cathode puisqu'un niveau LOW les allume, la première
LED est sur la sortie numérique 4.

Au cas où on crée plusieurs effets lumineux, les séquences sont jouées les unes après 
les autres et doivent être astucieusement choisies pour laisser croire à l'indépendance
de chaque effet lumineux (voir l'exemple donné Electric_sign).

= Séquences proposées =
-----------------------
Les séquences s'appellent avec la syntaxe suivante : nomObjet.fonction();
avec nomObjet le nom qu'on a donné à l'objet et fonction() une des fonction de la 
bibliothèque (voir ci-dessous) avec ou sans argument. Exemple :
monEnseigne.onRight();

= Fonctions =
-------------
onAll()			allume toutes les LEDs d'un coup
offAll()		éteint toutes les LEDs d'un coup
onLeft()		allume les LEDs de la droite vers la gauche de l'enseigne
offLeft()		éteint les LEDs de la droite vers la gauche de l'enseigne
onRight()		allume les LEDs de la gauche vers la droite de l'enseigne
offRight()		éteint les LEDs de la gauche vers la droite de l'enseigne
blinkAll(N)		fait clignoter l'ensemble des LEDs N fois (N est un entier)
movingFlashLeft()	déplace un flash de la droite vers la gauche
movingFlashRight()	déplace un flash de la gauche vers la droite
roundTrip()		effet lumineux (deux LED faibles entourant une LED brillante) effectuant des 
				aller-retours (nombre de LEDs conseillé au moins égal à six)
shiftStopLeft()		les flash se déplacent de la droite vers la gauche et s'accumulent à 
			gauche
shiftStopRight()	les flash se déplacent de la gauche vers la droite et s'accumulent à 
			droite
randomLightOn()		allume les LEDs de façon aléatoire (entrée analogique A5 sert au seed
			donc ne pas l'utiliser comme sortie digitale)
randomLightOff()	éteint les LEDs de façon aléatoire (entrée analogique A5 sert au seed
			donc ne pas l'utiliser comme sortie digitale)
trafficLight()		simule deux feux tricolores de carrefour routier - Le nombre de LED est
			forcément 6 et cette animation s'emploie seule à cause de la durée des 
			séquences 
alternatingTrafficLight()	simule deux feux de circulation alternée - Le nombre de LED est
			forcément 6 et cette simulation s'emploie seule à cause de la durée des
			séquences.

= Exemples =
------------
La bibliothèque est fournie avec 6 exemples d'utilisation.

Demo_LightEffect
This example will show you the possibilities of the library.

Traffic_Light
This example simulates two traffic lights of a crossing.

Alternating_Traffic_Light
This example simulates two traffic lights of a working zone.

Electric_sign
This example manages two groups of LED, the first one for a HOTEL sign and the second one for a PARK sign.

Work_lights
This example reproduces moving flashing lights to prevent dangerous areas as work or merging lanes.

