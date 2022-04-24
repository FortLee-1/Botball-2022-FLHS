#include <kipr/wombat.h>

void grabRing(int armUp, int armDown, int clawOpen, int clawClose);
void driveToPole(int distanceToPole);
void dropRing(int armUp, int armDown, int clawOpen, int clawClose);
void driveBack();
void driveFromStack();

int main()
{
    wait_for_light(0);			//automatic start w/light for 119 secs
    shut_down_in(119)
    enable_servos();
    //Red and orange
    grabRing(1232, 1796, 387, 1097); 
    driveToPole(114*82);
    dropRing(1232, 1558, 387, 1038); 
    
    //grab yellow and green
    driveBack();
    grabRing(1100, 1918, 387, 1016); 
    driveFromStack();
    dropRing(1232, 1558, 387, 1038); 
    
    //grab blue
    driveBack();
    grabRing(1232, 1991, 387, 916); 
    driveFromStack();
    dropRing(1232, 1558, 387, 1038);  
    
    ao();
    return 0;
}

void grabRing(int armUp, int armDown, int clawOpen, int clawClose)
	{
    set_servo_position(3, clawOpen);
    msleep(1000);
    int y;  //slowly going down
 		for(y = armUp; y <= armDown; y++)
 		{
			set_servo_position(0, y);
			msleep(15);
 		}

    //slowly close
    int b; 
		for(b = clawOpen; b <= clawClose; b++)
		{
			set_servo_position(3, b);
 			msleep(5);
    }
    ao();
    int x;  //slowly lifting up stack
 		for(x = armDown; x >= armUp; x--)
 		{
			set_servo_position(0, x);
			msleep(7);
    }
    msleep(300);
}

void driveToPole(int distanceToPole)
{
  cmpc(0);
  while (gmpc(0) < 3.14 * 82.0 * (90.0/360.0) * 16.76) //turn 90 right
	{
		mav(0, 1500);
		mav(3, -1475);
  }
  ao();
    
  cmpc(0);
  while(gmpc(0)< 82 * 14) //move forward
  {
    mav(0, 1500);
    mav(3, 1475);
  }
    
  cmpc(3);
  while (gmpc(3) < 3.14 * 82.0 * (90.0/360.0) * 16.76) //turn 90 left, face forward
	{
		mav(0, -1500);
		mav(3, 1475);
  }
  ao();
    
  //drive up to pole
  cmpc(0);
  while(gmpc(0)< distanceToPole)
  {
    mav(0, 1500);
    mav(3, 1490);
  }  
  ao();
  cmpc(0);
  while (gmpc(0) < 3.14 * 82.0 * (47.0/360.0) * 16.76) //turn right to the pole
	{
		mav(0, 1500);
		mav(3, -1475);
  }
  ao();  
}

void dropRing(int armUp, int armDown, int clawOpen, int clawClose)
{
  //arm down
  int y;  //slowly going down
 	for(y = armUp; y <= armDown; y++)
 	{
		set_servo_position(0, y);
		msleep(15);
 	}
  ao(0);
  cmpc(3);
  while (gmpc(3) < 3.14 * 82.0 * (3.0/360.0) * 16.76) //turn left slightly to drop
	{
		mav(0, -1500);
		mav(3, 1475);
  }
  ao();
    
  int b; 
	for(b = clawClose; b >= clawOpen; b--)
	{
		set_servo_position(3, b);
 		msleep(5);
  }
  ao();
}
    
void driveBack()
{
    cmpc(0);
    while(gmpc(0) > -25*82)
    {
        mav(0, -1500);
        mav(3, -1475);
    }
    ao();
          
    cmpc(0);
    while (gmpc(0) < 3.14 * 82.0 * (74.0/360.0) * 16.76) //turn 90 right, face pole
    {
		  mav(0, 1500);
		  mav(3, -1475);
    }
    ao();
    
    cmpc(0);
    while(gmpc(0) < 32*82)
    {
        mav(0, 1500);
        mav(3, 1475);
    }
    ao();            
}
          
void driveFromStack()
{
    cmpc(0);
    while(gmpc(0) > -32*82)
    {
        mav(0, -1500);
        mav(3, -1475);
    }
    ao();
    
    cmpc(3);
    while (gmpc(3) < 3.14 * 82.0 * (74.0/360.0) * 16.76) //turn left, face pole
    {
		mav(0, -1500);
		mav(3, 1475);
    }
    ao();
    
    cmpc(0);
    while(gmpc(0) < 18*82)
    {
        mav(0, 1500);
        mav(3, 1475);
    }
    ao();     
}              
