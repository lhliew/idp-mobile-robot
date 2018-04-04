#include <iostream>
using namespace std;
#include "header.h"


int IR, left2, middle, right2, white;


extern robot_link rlink;	/*rlink is in header.h, so this code makes 
							it so that a new rlink definition is not 
							declared, but uses the one in header.h*/
							
							
int IR_sensor(){
		//detect from IR sensor
		//0 means black, LED lights up
		IR = rlink.request (READ_PORT_0);			//read value on IR sensor
		left2 = (IR bitand bit0);
		if ((IR bitand bit1) == 2){
			middle = 1;
		}
		else {
			middle = 0;
		}
		
		if ((IR bitand bit2) == 4){
			right2 = 1;
		}
		else {
			right2 = 0;
		}
		
		white = left2 + middle*10 + right2*100;
		
		cout << "IR Decimal Value="  << white << endl;	//print value of the IR sensors
		cout << "Bit Value="  << left2 << middle << right2 << endl;	//print value of the 3 IR sensors
		return white;
}
