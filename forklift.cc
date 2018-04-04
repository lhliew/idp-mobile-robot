#include <iostream>
using namespace std;
#include "header.h"

extern int speed;
extern robot_link rlink;


void test_switch_pickup(){
	cout<< (rlink.request(READ_PORT_0) bitand bit6) << endl;
	return;
}

void pick_up(){
	cout<<"running pickup" << endl;
    stopwatch lifttime;
    lifttime.start();
    
	//raise forks until; microswitch hits
	while ((rlink.request(READ_PORT_0) bitand bit6) != 64 && (lifttime.read() < 4000)){		//change bit5 to correct bit
		cout<< (rlink.request(READ_PORT_0) bitand bit6) << endl;
		rlink.command(MOTOR_3_GO, speed = 255);		//change motor to correct one
		cout<<"running pickup" << endl;
	}
	delay (500);
	cout<<"end" << endl;
	return;
}

void place_box(){
	cout << "dropping off" << endl;
    stopwatch droptime;
    droptime.start();
    
	//lower box until microswitch hits
	while ((rlink.request(READ_PORT_0) bitand bit7) != 128 && (droptime.read() < 10000)){
		rlink.command(MOTOR_3_GO, speed = 35);
	}
	cout << "dropped" << endl;
	return;
}


void alignment_pick(){
	
	
	while (true){
		cout << (rlink.request(READ_PORT_0) bitand bit5) << endl;
		slow_forward(300);
		//if microswitch hits, stop
		if ((rlink.request(READ_PORT_0) bitand bit5) == 32){
			rlink.command (RAMP_TIME,20);
			rlink.command(MOTOR_2_GO, speed = 0);
			rlink.command(MOTOR_4_GO, speed = 0);
			break;
		}
	}
	pick_up();
	cout << "picking up"<< endl;
}

void alignment_drop(){
	//lower forks
	place_box();
    
	//IR sensor
	while ((rlink.request (READ_PORT_0) bitand bit3) != 8){
		cout << (rlink.request (READ_PORT_0) bitand bit3) << endl;
		slow_forward(300);
	}
	reverse();

	
}

void alignment_drop_v2(){
    place_box();
    slow_forward(300);
    //time the delay to push the box until half of it is in the red box
    reverse();
}
        
        
void test_lift(){ 
	//raising the fork and dropping the fork 
	rlink.command(MOTOR_3_GO, speed = 250);
	delay(1900);
	
	rlink.command(MOTOR_3_GO, speed = 250-128);
	delay(1900);
}

void one_box_lift(){
	//raising the fork from the bottom-most, leaving the bottom-most box on the floor and lift up the ones on top
	reverse();
	delay(500);
	
	rlink.command(MOTOR_3_GO, speed = 250);
	delay(500);
	
	forward();
	delay(500);
	
	rlink.command(MOTOR_3_GO, speed = 250);
	delay(300);
}


	
