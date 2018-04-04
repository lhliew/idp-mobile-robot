#include <iostream>
using namespace std;
#include "header.h"
#include <iostream>

void S_P2_pass(){
	forward();
	return;
}

void S_P2(){
	//assume pointing at P2
	forward();
	cout << "reached P2" << endl;
	return;
}
/*
 
void P2_D4(){
	turn_left();
    forward();
	//forward_wall, raise_fork, drop_off
	//small_reverse
	turn_around();
	return;
}
	
void D4_P2(){
	forward();
	forward();
	return;
}

void S_P1_pass(){
	//assume dont need to turn to direction of P1
	forward();
	return;
}

void S_P1(){
	//assume dont need to turn to direction of P1
	forward();
	//pickup. discriminate
	return;
}

void P1_D1(){
	turn_right();
	forward();
	//forward_wall, raise_fork, drop_off
	//small_reverse
	turn_around();
	return;
}
	
void D1_P1(){
	forward();
	forward();
	return;
}
 
*/

void P2_S(){
    turn_around();
    forward();
    forward();
    return;
}

void P2_S_turn(){
    turn_right();
    forward();
    forward();
    turn_around();
    return;
}




