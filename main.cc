#include <iostream>
using namespace std;
#include <delay.h>
#include <stopwatch.h>
#include "header.h"
#include "navigation.cc"


int main()
{
	stopwatch overall_timer;
	overall_timer.start();
	int total_stack = 0;
	while (overall_timer.read < 4000 || total_stack < 6) {				///change timing to (5 seconds - time needed to run 1 drop off) OR after deleivering 5 boxes
		forward_no_delay();
		forward();
		place_box();
		alignment_pick();
		int box = analyse();
		//if analysing fails
		if (box == 6){
			int box = analyse();
		}

		//to make sure we identify box 3 and open circuit correctly
		if (box == 4 || box == 3) {
			int box2 = analyse();

			if (box2 == box) {
				break;
			}
			else {
				box = analyse();
			}
			
		}
		turn_around();
		forward_no_delay();
		forward_no_delay();
		jerk_right();
		jerk_right();
		ramp_forward(20000);

		//if Box S/C or O/C
		if (box == 5 || 4) {
			diagonal_cut_r_up();
			forward_no_delay();
			turn_90_l();
			alignment_drop_v2();
			stack_4 += 1;
			pick_up();
			turn_90_l();
			forward_some_time(2800);
			diagonal_cut_r();
			forward_no_delay();
		}

		//if Box 1
		if (box == 1) {
			if (stack_1 == 0) {
				diagonal_cut_l();
				forward_no_delay();
				alignment_drop();
				stack_1 += 1
				turn_around();
				//forward some time
				diagonal_cut_r();
				forward_no_delay();
			}
			if (stack_1 == 1) {
				diagonal_cut_r();
				forward_no_delay();
				alignment_drop();
				stack_1 += 1
				turn_around();
				//forward some time
				diagonal_cut_l();
				forward_no_delay();
			}
			else () {}				///run stacking or throw away
			
		}
		//if Box 2
		if (box == 2) {
			diagonal_cut_r_up();
			forward_no_delay();
			turn_90_r();
			alignment_drop_v2();
			stack_2 += 1;
			pick_up();
			turn_90_r();
			forward_some_time(2800);
			diagonal_cut_l();
		}
		//if Box 3
		if (box == 3) {
			if (stack_3 == 0) {
				diagonal_cut_l();
				forward_no_delay();
				turn_90_r();
				alignment_drop();
				stack_3 += 1
				turn_around();
				//forward some time
				diagonal_cut_r();
				forward_no_delay();
			}
			if (stack_3 == 1) {
				diagonal_cut_r();
				forward_no_delay();
				turn_90_l();
				alignment_drop();
				stack_3 += 1
				turn_around();
				//forward some time
				diagonal_cut_l();
				forward_no_delay();
			}
			else () {}				///run stacking or throw away
		}
		forward();
		forward();
		turn_left(); ///does is reach outer box line or misses?
		///forward();  use this if it misses
		//should end with robot pointing at P2
		total_stack = stack_1 + stack_2 + stack_3 + stack_4;
	}
}
