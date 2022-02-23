double acclY();

double velY(double initVelocityY, double time);

double posX(double initPosition, double initVelocity, double time);

double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double flightTime(double initVelocityY);

double getUserInputTheta();

double getUserInputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);

double getDistanceTraveled(double velocityX, double velocityY);

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int testDeviation_int(double compareOperand, double toOperand, double maxError, string name);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

double getTimeTraveled(double velocityX, double velocityY);

// bool checkIfDistanceToTargetIsCorrect();

void playTargetPractice(int attempts, double radius_target);