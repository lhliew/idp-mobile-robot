#include <iostream>
using namespace std;
#include <delay.h>
#include <stopwatch.h>
#include "header.h"
extern robot_link rlink;
extern int speed;


int main()
{
	initialise();
	//pick_up();
	//analyse();

	//alignment_drop();
    //ramp_forward();
    //diagonal_cut_r();
    /*jerk_forward();
    analyse();
    forward_no_delay();
    jerk_forward();
    turn_90_l();
    turn_90_l();
    */
    
    //forward_some_time(5000);
    
    //diagonal_cut_r();
    //forward_some_time(2000);
    
    //just go forward for an amount of time until it reaches the flat ground.
    //rlink.command(MOTOR_2_GO, speed = 233);
	//rlink.command(MOTOR_4_GO, speed = 110);
	//delay(2500);
    
    /*cout<< "jerk" << endl;
    jerk_forward();
	jerk_forward();
	jerk_forward();
	*/
	
	
	//forward_no_delay();
    
    ramp_forward();
    cout<< "enter diagonal cut" << endl;
    diagonal_cut_r();
    forward_some_time(2000);
    
    
	//diagonal_cut_l();
	//alignment_drop_v2();
	//forward_some_time(2000);
	//
    //time: 1. up ramp 2. turning 45 degree with box 3. delivering a box 4.place box 
    //test: motor parameter and ramp time
    //got time then do: sensor placement
    //must ask: mech team solve the fork problem 

	return 0;
}
