/*
 Name:		ParallelBinaryPinOutput.h
 Created:	8/30/2020 10:43:37 PM
 Author:	Diego Garcia
 Editor:	http://www.visualmicro.com
*/

#include "BitOutPins.h"
#define MAXDISPLAYS 2 //Varies depending on the Arduino model used. Due to pin quantity, recommended for Uno and similar models is 2
#define DELAYTIME 100

class Driver_74LS47
{
private:
	BitOutPins<4>* displays[MAXDISPLAYS];
	unsigned char DisplayCount;
	unsigned int MaxNumber;
	bool overcount;
	void _h();
	bool verbose = false;
	unsigned int id;
	void _init(unsigned char displays, unsigned int* pins);
public:
	unsigned char DisplayedDigits[MAXDISPLAYS];
	Driver_74LS47(unsigned char display, unsigned int startpin);
	Driver_74LS47(unsigned char display, unsigned int* pins);
	void PrintAllPins();
	void CalcOutput(unsigned int value);
	void Write();
	void OutputDisplay(unsigned int value);
	bool IsOverCounting(); //Is it attempting to display a number higher than what it can
	void All0();
	void OutputAll0();
	void TestSequence(unsigned int ms = DELAYTIME);
	void LampTest();
	void FullSequence(unsigned int ms = DELAYTIME);
	bool IsVerbose();
	void Verbosity(bool v);
};
