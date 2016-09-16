#ifndef CONSTANTS_H
#define CONSTANTS_H

//#define NUMBER_OF_USED_INPUTS 16	// Number of Used    Digital Inputs in: MODE_DIRECT

    static const int numberOfUsedDigitalInputs = 16;

    static const int samplesPerBeltRound = 2000;
    static const int numbersOfBeltRounds = 10;
    static const int numberOfElementsInList = 5;

    static const int filterDelay = 10;

    static const int productEntry = 1; //start of conveyor

    static const int productWeighingStartDistance = 430; // FIXME: was 330
    static const int productWeightingStopDistance = 770; // FIXME: was 666
    static const int productRelease = 1400; // FIXME

    static const int plotXvalueMIN = 0;
    static const int plotXvalueMAX = 150;

    static const int plotYvalueMIN = 500;
    static const int plotYvalueMAX = 1500;





#endif // CONSTANTS_H

