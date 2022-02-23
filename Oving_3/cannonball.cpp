#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "cannonball.h" 
#include "utilities.h" 

double acclY(){
    double akselerasjon = -9.81;
    return akselerasjon;
}

double velY(double initVelocityY, double time){
    double fart = initVelocityY + (acclY()*time);
    return fart;
}

double posX(double initPosition, double initVelocity, double time){
    double acclX = 0;
    double posisjon = initPosition + (initVelocity*time) + ((acclX*pow(time,2))/2);
    return posisjon;
}

double posY(double initPosition, double initVelocity, double time){
    double posisjon = initPosition + (initVelocity*time) + ((acclY()*pow(time,2))/2);
    return posisjon;
}

void printTime(double time){
    int timer = time/3600;
    double rest_sec_1 = fmod(time,3600);
    int minutter = rest_sec_1/60;
    double sekunder = fmod(rest_sec_1,60);
    cout<<timer<<" time(r), "<<minutter<<" minutt(er) og "<<sekunder<<" sekund(er)"<<endl;    
}

double flightTime(double initVelocityY){
    double tid = (-2 * initVelocityY)/(acclY());
    printTime(tid);
    return tid;
}

double getUserInputTheta(){
    double theta = 0;
    cout<<"Anngi en vinkel: ";
    cin>>theta;
    return theta;
}

double getUserInputAbsVelocity(){
    double absFart = 0;
    cout<<"Anngi en fart (absoluttveri): ";
    cin>>absFart;
    return absFart;
}

double degToRad(double deg){
    double rad = (M_PI*deg)/180;
    return rad;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    string like = "De er tilnæremet like";
    string ulike = "De er ikke tilnærmet like";
	if (abs(compareOperand - toOperand) < maxError){
		cout<<like<<endl;
	}
	else{
		cout<<ulike<<endl;
	}
}

int testDeviation_int(double compareOperand, double toOperand, double maxError, string name){
    int like = 1; 
    int ulike = 0;
	if (abs(compareOperand - toOperand) < maxError){
		return like;
	}
	else{
		return ulike;
	}
}

double getVelocityX(double theta, double absVelocity){
    double fartX = absVelocity * cos(theta);
    return fartX;
}

double getVelocityY(double theta, double absVelocity){
    double fartY = absVelocity * sin(theta);
    return fartY;
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velocityVector;
    velocityVector.push_back(getVelocityX(theta, absVelocity));
    velocityVector.push_back(getVelocityY(theta, absVelocity));
    // cout<< "[";
    // for (int j=0; j<velocityVector.size(); j++){
    //     cout<<velocityVector.at(j);
    //     if (j < velocityVector.size()-1) {
    //         cout<<", ";
    //     }
    // }
    // cout<<"]"<<endl;
    return velocityVector;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double start_y = 0;
    double start_x = 0;
    double x_pos = 0;
    double time_desimal = 0;
    for (int time_heltall = 0; time_heltall<100000; time_heltall++){
        time_desimal = time_heltall/100.0;
        if (testDeviation_int(posY(start_y,velocityY,time_desimal), 0, 1, "posY(start_y,velocityY,time_desimal)")==1 
        && time_heltall>1){
            x_pos = posX(start_x, velocityX, time_desimal);
        }
    }
    return x_pos;
}

double getTimeTraveled(double velocityX, double velocityY){
    double start_y = 0;
    double start_x = 0;
    double x_pos = 0;
    double time_desimal = 0;
    double time_in_air = 0;
    for (int time_heltall = 0; time_heltall<100000; time_heltall++){
        time_desimal = time_heltall/100.0;
        if (testDeviation_int(posY(start_y,velocityY,time_desimal), 0, 1, "posY(start_y,velocityY,time_desimal)")==1 
        && time_heltall>1){
            x_pos = posX(start_x, velocityX, time_desimal);
            time_in_air = time_desimal;
        }
    }
    return time_in_air;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
    double distanceAway = distanceTraveled-distanceToTarget;
    return distanceAway; 
}

// bool checkIfDistanceToTargetIsCorrect() {
//     double error = targetPractice(0,0,0);
//     if(error == 0) return true;
// }

void playTargetPractice(int attempts, double radius_target){
    int count = 0;
    double theta = 0;
    double initVelocity = 0;
    int target = randomTarget(100,1000);
    int hit_target = 0;
    double distance_away = 0;
    double time_in_air = 0;
    while(count<attempts && hit_target<1){
        cout<<"Oppgi vinkel: ";
        cin>>theta;
        cout<<"Oppgi startfart: ";
        cin>>initVelocity;
        double xVel = getVelocityVector(theta,initVelocity).at(0);
        double yVel = getVelocityVector(theta,initVelocity).at(1);
        distance_away = targetPractice(target, xVel, yVel);
        if (abs(distance_away)<=radius_target){
            cout<<"Du traff blink! "<<endl;
            count+=1;
            hit_target=1;
            time_in_air += getTimeTraveled(xVel, yVel);
        }
        else if (distance_away>radius_target){
            cout<<"For langt! Du var "<<distance_away<<" meter fra målet."<<endl;
            count+=1;
            time_in_air += getTimeTraveled(xVel, yVel);
        }
        else{
            cout<<"For kort! Du var "<<distance_away<<" meter fra målet."<<endl;
            count+=1;
            time_in_air += getTimeTraveled(xVel, yVel);
        }
    }
    cout<<"Total tid i lufta var ";
    printTime(time_in_air);
}