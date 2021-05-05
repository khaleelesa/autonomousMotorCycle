#pragma config(Sensor, S2,     sensor2,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     Gyro,           sensorEV3_Gyro)
#pragma config(Motor,  motorA,          motorLeft,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          steering,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          degree,        tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorD,          motorRight,    tmotorEV3_Large, PIDControl, encoder)
#pragma DebuggerWindows("Sensors")

/*name: khaleel esa , id: 208982728
name: dror ben yakov , id: 316048750
name: Reuven shemkin ,id:305405953
name: itai natan ,id:316046705          */


task main()
{

	int angle=0;     // integer for storing the angle from the gyro sensor
	int destince =0; // integer for storing the destince from an opject using the urltrasonic sensor
	int direction=30; // integer that we use to tell the steering motor(B) how much degree to set
	//	int random_num;  // random interger so we can give the motorsycle to choose left or right

	// this loop is continuous
	while(true)
	{

		destince=SensorValue[sensor2]; // we store the destince value from the ultrasonic sensor
		angle=getGyroDegrees(Gyro); // we store the angle value from the gyro sensor
		//random_num=rand()%1; // we uses the function rand() to generate anumber random from 0-3

		// the switch function gets the generated number and depends on the random_number it sets the value
		// for the direction 30(right) or (-30) left we did 4 numbres for it to be more random

		// we checks if the moto is farther than 50cm than the opject it sees
		// and we tell the moto to go straight
		while(destince>50)
		{
			/*angle=getGyroDegrees(Gyro);
			if(angle >=10)
			{
			setMotorTarget(steering,20 , 30);
			sleep(500);
			setMotorTarget(steering,-20 , 30);

			}
			if(angle <=-10)
			{
			setMotorTarget(steering,-20 , 30);
			sleep(500);
			setMotorTarget(steering,20 , 30);

			}*/

			destince=SensorValue[sensor2]; // gets the sensor value
			motor[motorLeft]=-25;  // sets the speed of the rear motor
			motor[motorRight]=-25; // // sets the speed of the rear motor
			resetGyro(Gyro);
		}

		// we check if we are below 50cm from the ioject so we start to turn
		if(destince<=50 && destince>20)
		{
			//checks if the moto gone left (-) or right (+) and depends on that tells the wight to go along with it so
			// the moto will not fall
			motor[motorLeft]=0;  // sets the speed of the rear motor
			motor[motorRight]=0;
			sleep(500);
			//setMotorTarget(degree,-1*direction,15);
			//setMotorTarget(steering,0.5*direction , 11); // change the angle of the steering using the dircetion data
			setMotorTarget(degree,-2*direction,15);
			setMotorTarget(steering,direction , 11); // change the angle of the steering using the dircetion data

		}

		// wee loop the time the destince between the moto and the opject is below 50cm
		// and set the moto to go stright while turning
		while(destince<=50 && destince>20)
		{

			destince=SensorValue[sensor2];
			motor[motorLeft]=-15;
			motor[motorRight]=-15;


		}

		// if the opject is 20cm close to the robot that means its very close to the robot
		// we set the steering direction in the opposet of what it was that means we set it back to the orignal
		// and we do the same thing to the weight
		if( destince<=20)
		{
			//direction=-17;
			motor[motorLeft]=0;
			motor[motorRight]=0;
			sleep(1000);
      setMotorTarget(degree,0,15);
			setMotorTarget(steering,0 ,15);
			sleep(1000);
			//setMotorTarget(degree,-2*direction,7);
			//setMotorTarget(steering,direction ,9);

			//setMotorTarget(degree,2*direction,10);
			//setMotorTarget(steering,-1*direction ,10);


			motor[motorLeft]=10;
			motor[motorRight]=10;
			sleep(8000);
			direction=28;


		}

		// inside a loop we check if we in the destince of the 20cm
		/*if so :
		1. we set the moving-motors to 0
		2. we set the steering to turn left or right
		3. we check depends on the steering and set the wight to turn
		4. we set the motor speed of the back wheel on low speed so it can reverse
		5. we set bakc the steering and the wight to the origanle postion
		*/
		/*while(destince<=20)
		{

		destince=SensorValue[sensor2];
		motor[motorLeft]=0;
		motor[motorRight]=0;
		sleep(1000);
		setMotorTarget(steering,direction , 10);
		if(direction>0)
		setMotorTarget(degree,-25,10);
		else
		setMotorTarget(degree,25,10);

		motor[motorLeft]=10;
		motor[motorRight]=10;
		sleep(6000);
		motor[motorLeft]=0;
		motor[motorRight]=0;
		sleep(1000);
		setMotorTarget(steering,-1*(direction) , 10);
		setMotorTarget(degree,0 , 10);



		}*/
	}
}
