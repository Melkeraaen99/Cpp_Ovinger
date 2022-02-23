// Øving 3 Thomas Melkeraaen

#include "std_lib_facilities.h"
#include "cannonball.h" 
#include "utilities.h" 
#include "Graph.h"
#include "AnimationWindow.h" 
#include <cmath>

int main() {

	// cout<<acclY()<<endl;

	// cout<<velY(25, 2.5)<<endl;

	// cout<<posX(0,50,5)<<endl;

	// cout<<posY(0,25,5)<<endl;

	// printTime(10000.5);

	// flightTime(1023.45);

	// testDeviation(posY(0.0,50,5), 127.375, 0.0001, "posY(0.0,50,5)");

	// cout<<degToRad(30)<<endl;

	// getVelocityVector(60, 50);

	// cout<<getDistanceTraveled(20, 50)<<endl;

	// cout<<getTimeTraveled(20, 50)<<endl;

	// cout<<targetPractice(205.0, 20, 50)<<endl;

	// cout<<checkIfDistanceToTargetIsCorrect()<<endl;

	srand(unsigned(time(nullptr)));

	// randomWithLimits(1, 1000, 10);

	// playTargetPractice(10, 5);

	// Funksjonen getDistanceTraveled fungerer ikke optimalt da jeg har satt opp feilmarginen til 1.
	// Den er også dårlig dersom vinkelen blir for stor i playTargetPractice (20 som vinkel funker bra da)
	// Kunne fikset dette med å sjekke for mindre tidsintervaller slik at det varierer mer mellom hver gang 

	return 0;
}

