# Automatically generated Makefile
tester :  tester.o robot_navigation.o robot_initialise.o ir_sensor.o forklift.o box_discriminator.o all_tests_files.o
	 g++ -L/export/teach/1BRobot -o tester  tester.o  robot_navigation.o  robot_initialise.o  ir_sensor.o  forklift.o  box_discriminator.o  all_tests_files.o  -lrobot

tester.o: tester.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c tester.cc
robot_navigation.o: robot_navigation.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c robot_navigation.cc
robot_initialise.o: robot_initialise.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c robot_initialise.cc
ir_sensor.o: ir_sensor.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c ir_sensor.cc
forklift.o: forklift.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c forklift.cc
box_discriminator.o: box_discriminator.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c box_discriminator.cc
all_tests_files.o: all_tests_files.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c all_tests_files.cc
