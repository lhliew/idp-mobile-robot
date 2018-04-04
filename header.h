#ifndef HEADER_H
#define HEADER_H

#include <robot_link.h>
#include <robot_instr.h>
#include <robot_delay.h>
#include <stopwatch.h>

extern robot_link rlink;
const int bit0 = 0x01; // ’0000 0001’ individual bits
const int bit1 = 0x02;
const int bit2 = 0x04;
const int bit3 = 0x08;
const int bit4 = 0x10;
const int bit5 = 0x20;
const int bit6 = 0x40;
const int bit7 = 0x80;
/*int stack_1 = 0;
int stack_2 = 0;
int stack_3 = 0;
int stack_4 = 0;
*/

//Initialisation 
int initialise();

//sensor
int IR_sensor();

//Locomotion
void forward();
void jerk_forward();
void reverse();
void turn_right();
void turn_left();
void turn_around();
void instant_stop();
void junction();
void lost();
bool curving_forward();
void forward_no_delay();
void forward_some_time( int delay_time);
void ramp_forward();

//Forklift & Box detect
void test_switch_pickup();
void pick_up();
int analyse();
void place_box();
void alignment_pick();
void alignment_drop();
void alignment_drop_v2();
void test_lift();
void one_box_lift();
void slow_forward( int delay_time);
void turn_90_r();
void turn_90_l();
void diagonal_cut_r();
void diagonal_cut_l();

//Destinations
void S_P2();
void P2_S();
void D2_move();
void D3_move();
void D4_move();
void D5_move();
void D6_move();

//Test and calibration files 
void motor_Control_Test();
void sensor_test();

//Fail safe
void lost();

#endif
