#include <kipr/botball.h>
void lift(int position);
void grab(int position);
void arm(int position);
void start();
void stop();
void turnRight();
void turnLeft();
void drive(int distance);
void middle(int time);
void reverse(int dist);
void armmiddle();
void turn(int angle);
void middledrive(int distance);
void startposition();
void altturn(int angle);
void driveslow(int distance);
// lift port 0 (higher) = forward
// grab higher port 1 = close
// arm higher = port 2 = higher

const int CLAW = 1;
const int ARM = 2;
const int LIFT = 3;

int main()
{   
    //wait_for_light(0);
    //shut_down_in(119);
    create_connect();
    
   	enable_servos();
    
   
    shut_down_in(119);
    //break
    start();
    
    altturn(-18);//right turn
    drive(785);
    turn(10);// left turn
    
    
    
    
    while (analog(0) < 1800)//senses botguy  1850 before
    {
        create_drive_direct(300,300);
        if (analog(0) > 1760)//grabbing loop
        {
            
            grab(2040);//grab botguy
            msleep(500);
            altturn(-77);
            driveslow(1230);
            arm(700);
            arm(680);
            
            grab(250);
            break;
            
            
            
        }
        
    }
    
    create_disconnect(); 
    return 0;
}

void lift(int position)
{
    set_servo_position(LIFT, position);
}
void grab(int position)
{
    set_servo_position(CLAW, position);
}
void arm(int position)
{
    set_servo_position(ARM, position);
}

void start()
{
    lift(800);
    arm(1120);
    grab(100);
    msleep(750);
}

void stop()
{
	create_stop();
}

void turnRight()
{
	set_create_total_angle(0);
	while (get_create_total_angle() > -68)
	{
		create_drive_direct(300, -300);
	}
	stop();
}

void drive(int distance)
{
 	set_create_distance(0);
	while (get_create_distance() < distance)
	{
		create_drive_direct(500, 500);
	}
}

void turnLeft()
{
	set_create_total_angle(0);
	while (get_create_total_angle() < 87)
	{
		create_drive_direct(-300, 300);
	}
	stop();
}

void middle(int time)
{
    int x = 0;
    for (x = 0; x <= time; x++)
    {
		lift(950);
        msleep(250);
    }
}

void reverse(int dist)
{
    set_create_distance(0);
	while (get_create_distance() > dist)
	{
		create_drive_direct(-500, -500);
    	msleep(500);
	}
}
void armmiddle()
{
    arm(1550);
}

void turn(int angle)
{
	set_create_total_angle(0);
	while (get_create_total_angle() < angle)
	{
		create_drive_direct(-300, 300);
	}
	stop();
}

void middledrive(int distance)
{
	while (get_create_distance() < distance)
	{
		create_drive_direct(310, 310);
	}
}

void startposition()
{
    lift(438);
    arm(0);
    grab(2040);
    msleep(250);
}

void altturn(int angle)
{
	set_create_total_angle(0);
	while (get_create_total_angle() > angle)
	{
		create_drive_direct(300, -300);
	}
	stop();
}

void driveslow(int distance)
{
 	set_create_distance(0);
	while (get_create_distance() < distance)
	{
		create_drive_direct(500, 500);
	}
}
