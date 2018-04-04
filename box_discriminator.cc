 #include <iostream>
using namespace std;
#include "header.h"
#include <iostream>


int analyse(){
	int etime;
	cout << "started" << endl;
	stopwatch watch;					//create object 'watch' with class stopwatch
	rlink.command(WRITE_PORT_0, 16);	//to initialise Port 0 Pin 4
	rlink.command(WRITE_PORT_1, 1);		//to initialise test
	delay (3000);						//allow time for initialising
	int k = rlink.request(READ_PORT_0);
	cout << k << endl;
	watch.start();						//start the stopwatch
	rlink.command(WRITE_PORT_0, 0);		//pull the voltage to low
	
    
    //open circuit detection
	if (rlink.request(READ_PORT_1) == 0){
		cout << "Box is open circuit" << endl;
		cout << watch.read() << endl;

        //LED Output
		rlink.command(WRITE_PORT_1, 16);
		return 4;
	}
	
	int c = 2;
	int b = 2;
	while (c != 0) {
		b = rlink.request(READ_PORT_1);
		c = b bitand bit0;
		cout << c << endl;
		cout << "placeholder" << endl;
		if ((etime = watch.read() ) > 3000){
		//code for short circuit
			cout << "Box is short circuit" << endl;
			
            //LED Output
            rlink.command(WRITE_PORT_1, 8);
			return 5;
		}	
	}
	etime = watch.stop();
	
	cout << etime << endl;
	cout << "Test passed" << endl;
	if (etime<80){
		cout << "Box is Type 3" << endl;
        
        //LED Output
		rlink.command(WRITE_PORT_1, 128);
		return 3;
	}
	if (80<etime && etime<500){
		cout << "Box is Type 2" << endl;
        
        //LED Output
		rlink.command(WRITE_PORT_1, 64);
		return 2;
	}
	if (etime>500 && etime<1000){
		cout << "Box is Type 1" << endl;
        
        //LED Output
		rlink.command(WRITE_PORT_1, 32);
		return 1;
	}
	//failed
	return 6;
}
