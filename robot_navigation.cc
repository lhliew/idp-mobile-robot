 //remember to put function prototype into header.h, and include the header.h in the file you are running to use the functions

#include <iostream>
using namespace std;
#include "header.h"
#include <iostream>
int  IR_result, stop, stop2, speed, etime;


extern robot_link rlink;	/*rlink is in header.h, so this code makes 
							it so that a new rlink definition is not 
							declared, but uses the one in header.h*/
							
//forward until all white, not following the line for a while but following it after the delay. 
void forward(){
	rlink.command(MOTOR_2_GO, speed = 233);
	rlink.command(MOTOR_4_GO, speed = 110);
	
	//here's the delay
	delay(2000);
	
	stop = 0;
	stopwatch watch;
	while (stop==0){
		//detect from IR sensor
		IR_result = IR_sensor();


		//robot straight or on the line
		if (IR_result == 10) {
			rlink.command (RAMP_TIME,30);
			rlink.command(MOTOR_2_GO, speed = 233);
			rlink.command(MOTOR_4_GO, speed = 110);			
		}
		
		//robot sliding right, so go left
		if (IR_result == 110){
			rlink.command (RAMP_TIME,70);
			rlink.command(MOTOR_2_GO, speed = 147);
			rlink.command(MOTOR_4_GO, speed = 147);
		}
		
		//robot sliding right, so go left more
		if (IR_result == 100){
			rlink.command (RAMP_TIME,70);
			rlink.command(MOTOR_2_GO, speed = 157);
			rlink.command(MOTOR_4_GO, speed = 157);
		}
		
		//robot sliding left, so go right
		if (IR_result == 11){
			rlink.command (RAMP_TIME,70);
			rlink.command(MOTOR_2_GO, speed = 20);
			rlink.command(MOTOR_4_GO, speed = 20);
		}
		//robot sliding left, so go right more
		if (IR_result == 1){
			rlink.command (RAMP_TIME,70);
			rlink.command(MOTOR_2_GO, speed = 30);
			rlink.command(MOTOR_4_GO, speed = 30);
		}
		
		//if at T junction/ crossroad, stop
		if (IR_result == 111){
			//rlink.command (STOP SELECT, 7);
			rlink.command (RAMP_TIME,40);
			rlink.command(MOTOR_2_GO, speed = 0);
			rlink.command(MOTOR_4_GO, speed = 0);
			delay (200);
			return;
		}
		
		//if lost, reverse
		if (IR_result == 000){
			watch.start();
			stop2 = 0;
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 55);
			rlink.command(MOTOR_4_GO, speed = 178);
		}
	}				
}

//forward until all white
void forward_no_delay(){
	rlink.command(MOTOR_2_GO, speed = 243);
	rlink.command(MOTOR_4_GO, speed = 120);
	stop = 0;
	stopwatch watch;
	
	while (stop==0){
		//detect from IR sensor
		IR_result = IR_sensor();

		//robot straight or on the line
		if (IR_result == 10) {
			rlink.command (RAMP_TIME,30);
			rlink.command(MOTOR_2_GO, speed = 243);
			rlink.command(MOTOR_4_GO, speed = 120);			
		}
		
		//robot sliding right, so go left
		if (IR_result == 110){
			rlink.command (RAMP_TIME,70);
			rlink.command(MOTOR_2_GO, speed = 147);
			rlink.command(MOTOR_4_GO, speed = 147);
		}
		
		//robot sliding right, so go left more
		if (IR_result == 100){
			rlink.command (RAMP_TIME,70);
			rlink.command(MOTOR_2_GO, speed = 157);
			rlink.command(MOTOR_4_GO, speed = 157);
		}
		
		//robot sliding left, so go right
		if (IR_result == 11){
			rlink.command (RAMP_TIME,70);
			rlink.command(MOTOR_2_GO, speed = 20);
			rlink.command(MOTOR_4_GO, speed = 20);
		}
		//robot sliding left, so go right more
		if (IR_result == 1){
			rlink.command (RAMP_TIME,70);
			rlink.command(MOTOR_2_GO, speed = 30);
			rlink.command(MOTOR_4_GO, speed = 30);
		}
		
		//if at T junction/ crossroad, stop
		if (IR_result == 111){
			//rlink.command (STOP SELECT, 7);
			rlink.command (RAMP_TIME,40);
			rlink.command(MOTOR_2_GO, speed = 0);
			rlink.command(MOTOR_4_GO, speed = 0);
			delay (200);
			return;
		}
		
		//if lost, reverse
		if (IR_result == 000){
			watch.start();
			stop2 = 0;
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 55);
			rlink.command(MOTOR_4_GO, speed = 178);
		}
		
	}				
}


//do the line following code for a while, with no delay. 
void forward_some_time( int delay_time){
	rlink.command (RAMP_TIME,80);
    rlink.command(MOTOR_2_GO, speed = 233);
    rlink.command(MOTOR_4_GO, speed = 110);
    stop = 0;
    
    stopwatch watch;
    watch.start();
    while (watch.read() < delay_time){
		cout << watch.read() << endl;
        //detect from IR sensor
        IR_result = IR_sensor();
        
        //robot straight or on the line
        if (IR_result == 10) {
            rlink.command (RAMP_TIME,30);
            rlink.command(MOTOR_2_GO, speed = 233);
            rlink.command(MOTOR_4_GO, speed = 110);
        }
        
        //robot sliding right, so go left
        if (IR_result == 110){
            rlink.command (RAMP_TIME,71);
            rlink.command(MOTOR_2_GO, speed = 147);
            rlink.command(MOTOR_4_GO, speed = 147);
        }
        
        //robot sliding right, so go left more
        if (IR_result == 100){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 157);
            rlink.command(MOTOR_4_GO, speed = 157);
        }
        
        //robot sliding left, so go right
        if (IR_result == 11){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 20);
            rlink.command(MOTOR_4_GO, speed = 20);
        }
        //robot sliding left, so go right more
        if (IR_result == 1){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 30);
            rlink.command(MOTOR_4_GO, speed = 30);
        }
        
        //if lost, reverse
        if (IR_result == 000){
            watch.start();
            stop2 = 0;
            rlink.command (RAMP_TIME,100);
            rlink.command(MOTOR_2_GO, speed = 55);
            rlink.command(MOTOR_4_GO, speed = 178);
        }
    }
    return;
}



//short jerk forward from juction
void jerk_forward(){
	rlink.command(MOTOR_2_GO, speed = 233);
	rlink.command(MOTOR_4_GO, speed = 110);
	delay(500);
	return;
}
//reverse
void reverse(){
	rlink.command(MOTOR_2_GO, speed = 60);
	rlink.command(MOTOR_4_GO, speed = 183);
	delay(1000);
	return;
}
// turn_left
void turn_left(){
	rlink.command (RAMP_TIME,20);
	rlink.command(MOTOR_2_GO, speed = 0);
	rlink.command(MOTOR_4_GO, speed = 120);
	delay(800);						//to let robot turn sufficiently away from junction to prevent false reading
	while (true){
		IR_result = IR_sensor();
		if (IR_result == 10){
				return;
			}
		 
		}
}
//turn right
void turn_right(){
	rlink.command (RAMP_TIME,20);
	rlink.command(MOTOR_2_GO, speed = 248);
	rlink.command(MOTOR_4_GO, speed = 0);
	delay(800);						//to let robot turn sufficiently away from junction to prevent false reading
	while (true){
		IR_result = IR_sensor();
		if (IR_result == 10){
				return;
			}
		 
		}
}
//turn around left
void turn_around(){
	rlink.command (RAMP_TIME,100);
	rlink.command(MOTOR_2_GO, speed = 120);
	rlink.command(MOTOR_4_GO, speed = 120);
	delay(1500);						//to let robot turn sufficiently away from junction to prevent false reading
	rlink.command (RAMP_TIME,50);
	rlink.command(MOTOR_2_GO, speed = 50);
	rlink.command(MOTOR_4_GO, speed = 50);
	while (true){
		IR_result = IR_sensor();
		if (IR_result == 10){
				return;
			}
		 
		}
}
//slow stop
//instant stop
void instant_stop(){
	return;
}

//error recovery
void lost(){
	stop = 1;
	
	while (stop != 0){
		stopwatch lost_time;
		lost_time.start();
		etime = lost_time.read();
		while(etime < 7500){
			cout << etime << endl;
			//detect from IR sensor
			IR_result = IR_sensor();
			if (IR_result == 000){
				rlink.command (RAMP_TIME,40);
				rlink.command(MOTOR_2_GO, speed = 75);
				rlink.command(MOTOR_4_GO, speed = 75);
			}
			//if (IR_result == 10 || IR_result == 100 || IR_result == 001){
			else {
				return;
			}
			etime = lost_time.read();
			
		}
		lost_time.start();
		etime = lost_time.read();
		while(etime<2000){
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 60);
			rlink.command(MOTOR_4_GO, speed = 183);
			etime = lost_time.read();
		}
		while(etime < 7500){
			cout << etime << endl;
			//detect from IR sensor
			IR_result = IR_sensor();
			if (IR_result == 000){
				rlink.command (RAMP_TIME,40);
				rlink.command(MOTOR_2_GO, speed = 75);
				rlink.command(MOTOR_4_GO, speed = 75);
			}
			//if (IR_result == 10 || IR_result == 100 || IR_result == 001){
			else {
				return;
			}
			etime = lost_time.read();
			
		}
		stop -= 1;
	}
}

//forward at curve
bool curving_forward(){							//should not be void, just a placeholder
	rlink.command(MOTOR_2_GO, speed = 183);
	rlink.command(MOTOR_4_GO, speed = 60);
	stop = 0;
	int left_curve = 0;							//counter to determine which direction the white line is curving
	int right_curve = 0;
	while (stop==0){
		//detect from IR sensor
		IR_result = IR_sensor();

		//robot straight or on the line
		if (IR_result == 10) {
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 183);
			rlink.command(MOTOR_4_GO, speed = 60);
			
		}
		
		//robot sliding right, so go left
		if (IR_result == 110){
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 177);
			rlink.command(MOTOR_4_GO, speed = 0);
			left_curve += 1;							//if wrong direction of curve is sensed switch it and corresp[ndiong ones
		}
		
		//robot sliding right, so go left more
		if (IR_result == 100){
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 187);
			rlink.command(MOTOR_4_GO, speed = 0);
			left_curve += 1;
		}
		
		//robot sliding left, so go right
		if (IR_result == 11){
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 0);
			rlink.command(MOTOR_4_GO, speed = 50);
			right_curve += 1;
		}
		//robot sliding left, so go right more
		if (IR_result == 001){
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 0);
			rlink.command(MOTOR_4_GO, speed = 60);
			right_curve += 1;
		}
		
		//if at T junction/ crossroad, stop
		if (IR_result == 111){
			//rlink.command (STOP SELECT, 7);
			rlink.command (RAMP_TIME,10);
			rlink.command(MOTOR_2_GO, speed = 0);
			rlink.command(MOTOR_4_GO, speed = 0);
			delay (200);
			break;
		}
		
		//if lost, reverse
		if (IR_result == 000){
			rlink.command (RAMP_TIME,100);
			rlink.command(MOTOR_2_GO, speed = 60);
			rlink.command(MOTOR_4_GO, speed = 183);
		}
	}				
	return	right_curve > left_curve;                            // all OK, finish
}

//moving up ramp, two parts, first part to sense the line and make it reasonably straight, second part just move forward, follwed by a 45 degree turn.
void ramp_forward(){

    stop = 0;
    stopwatch watch;
    stopwatch while_timer;
    
    while_timer.start();
    
    while (stop==0 && (while_timer.read() < 10000) ){
        //detect from IR sensor
        IR_result = IR_sensor();
        
        //robot straight or on the line
        if (IR_result == 10) {
            rlink.command (RAMP_TIME,30);
            rlink.command(MOTOR_2_GO, speed = 233);
            rlink.command(MOTOR_4_GO, speed = 110);
        }
        
        //robot sliding right, so go left
        if (IR_result == 110){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 147);
            rlink.command(MOTOR_4_GO, speed = 147);
        }
        
        //robot sliding right, so go left more
        if (IR_result == 100){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 157);
            rlink.command(MOTOR_4_GO, speed = 157);
        }
        
        //robot sliding left, so go right
        if (IR_result == 11){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 20);
            rlink.command(MOTOR_4_GO, speed = 20);
        }
        //robot sliding left, so go right more
        if (IR_result == 1){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 30);
            rlink.command(MOTOR_4_GO, speed = 30);
        }
        
        //if at T junction/ crossroad, stop
        if (IR_result == 111){
            //rlink.command (STOP SELECT, 7);
            rlink.command (RAMP_TIME,40);
            rlink.command(MOTOR_2_GO, speed = 0);
            rlink.command(MOTOR_4_GO, speed = 0);
            delay (200);
            return;
        }
        
        //if lost, reverse
        if (IR_result == 000){
            watch.start();
            stop2 = 0;
            //while (stop == 0){
            rlink.command (RAMP_TIME,100);
            rlink.command(MOTOR_2_GO, speed = 55);
            rlink.command(MOTOR_4_GO, speed = 178);
            //if ( watch.read() > 2500){
            //lost();
            //}
            //if (IR_result != 000){
            //stop2 = 1;
            //}
            //}
        }
        
    rlink.command(MOTOR_2_GO, speed = 233);
    rlink.command(MOTOR_4_GO, speed = 110);
    delay(6500);    
    }
    return;
    
}

//cut diagonally on the ramp, and move until detect line, followed by the normal line following.

void diagonal_cut_r(){
    //turn right 45 degree, need to insert the correct motor speed and delay for the turn.
    rlink.command(MOTOR_2_GO, speed = 233);
    rlink.command(MOTOR_4_GO, speed = 233);
    delay(650);
    
    //move forward until sense something
    //while (IR_result == 000 ){
        rlink.command(MOTOR_2_GO, speed = 223);
        rlink.command(MOTOR_4_GO, speed = 90);
        cout << "move" << endl;
        delay(4000);
        //IR_result = IR_sensor();
    //}
    return;
}

void diagonal_cut_l(){
    //turn left 45 degree, need to insert the correct motor speed and delay for the turn.
    rlink.command(MOTOR_2_GO, speed = 110);
    rlink.command(MOTOR_4_GO, speed = 110);
    delay(650);
    
    //move forward until sense something.
    
    //while (IR_result == 000){
        rlink.command(MOTOR_2_GO, speed = 223);
        rlink.command(MOTOR_4_GO, speed = 90);
        cout << "move" << endl;
        delay (3100);
        IR_result = IR_sensor();
    //}
    return;
}


//turn around left or right at the delivery point
void turn_90_l(){
    rlink.command (RAMP_TIME,100);
    rlink.command(MOTOR_2_GO, speed = 120);
    rlink.command(MOTOR_4_GO, speed = 120);
    delay(600);                        //to let robot turn sufficiently away from junction to prevent false reading
    
    rlink.command (RAMP_TIME,50);
    rlink.command(MOTOR_2_GO, speed = 50);
    rlink.command(MOTOR_4_GO, speed = 50);
    
    //turn slowly until it senses something
    while (true){
        IR_result = IR_sensor();
        if (IR_result == 10){
            return;
        }
        
    }
}

void turn_90_r(){
    rlink.command (RAMP_TIME,100);
    rlink.command(MOTOR_2_GO, speed = 120+127);
    rlink.command(MOTOR_4_GO, speed = 120+127);
    delay(600);                        //to let robot turn sufficiently away from junction to prevent false reading
    
    rlink.command (RAMP_TIME,50);
    rlink.command(MOTOR_2_GO, speed = 50+127);
    rlink.command(MOTOR_4_GO, speed = 50+127);
    
    //turn slowly until it senses something
    while (true){
        IR_result = IR_sensor();
        if (IR_result == 10){
            return;
        }
        
    }
}

//for picking up at P2
void slow_forward( int delay_time){
    rlink.command(MOTOR_2_GO, speed = 158);
    rlink.command(MOTOR_4_GO, speed = 30);
    stop = 0;
    stopwatch watch;
    watch.start();
    while (watch.read() < delay_time){
        //detect from IR sensor
        IR_result = IR_sensor();
        
        //robot straight or on the line
        if (IR_result == 10) {
            rlink.command (RAMP_TIME,30);
            rlink.command(MOTOR_2_GO, speed = 158);
            rlink.command(MOTOR_4_GO, speed = 30);
        }
        
        //robot sliding right, so go left
        if (IR_result == 110){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 147);
            rlink.command(MOTOR_4_GO, speed = 147);
        }
        
        //robot sliding right, so go left more
        if (IR_result == 100){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 157);
            rlink.command(MOTOR_4_GO, speed = 157);
        }
        
        //robot sliding left, so go right
        if (IR_result == 11){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 20);
            rlink.command(MOTOR_4_GO, speed = 20);
        }
        //robot sliding left, so go right more
        if (IR_result == 1){
            rlink.command (RAMP_TIME,70);
            rlink.command(MOTOR_2_GO, speed = 30);
            rlink.command(MOTOR_4_GO, speed = 30);
        }
        
        //if lost, reverse
        if (IR_result == 000){
            watch.start();
            stop2 = 0;
            rlink.command (RAMP_TIME,100);
            rlink.command(MOTOR_2_GO, speed = 55);
            rlink.command(MOTOR_4_GO, speed = 178);
        }
    }
}
