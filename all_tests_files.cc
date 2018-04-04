#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <bitset>
using namespace std;
extern int stop;
#include "header.h"

//Manually control and calibrate the motor. 

void motor_Control_Test(){
	rlink.command(RAMP_TIME,10); 					//Ramp response
	int man_commands = 0; 
	while(stop == 0){
		///Command controls: 
		cout<<"Enter commands"<<endl;
		cin>>man_commands;
		//1- move forward
		if	(man_commands == 8){
				rlink.command(MOTOR_2_GO, 243);
				rlink.command(MOTOR_4_GO, 120);
				cout<<"MOVING"<<endl;
		}
		// 2 - Stop the wheel
		else if(man_commands == 5){
			rlink.command(MOTOR_2_GO, 0);
			rlink.command(MOTOR_4_GO, 0);
			cout<<"STOPPING THE WHEELS"<<endl;
		}
		// 3- to turn clockwise
		else if(man_commands == 6){
			rlink.command(MOTOR_2_GO, 240);
			rlink.command(MOTOR_4_GO, 240);
			cout<<"Turn direction: CLOCKWISE"<<endl;
		}
		//4 - turn anticlockwise
		else if(man_commands == 4){
			rlink.command(MOTOR_2_GO, 113);
			rlink.command(MOTOR_4_GO, 113);
			cout<<"Turn direction: ANTI_CLOCKWISE"<<endl;
		}
		//5- Wheel debug information
		else if(man_commands == 2){
			cout<<"LEFT WHEEL Speed:"<<rlink.request(MOTOR_2)<<endl;
			cout<<"RIGHT WHEEL Speed:"<<rlink.request(MOTOR_4)<<endl;
		}
		else if (man_commands == 7){
			return;
		}
		else break;
		
		cout<<"Command executed!"<<endl;
		man_commands=0;
	}
}
