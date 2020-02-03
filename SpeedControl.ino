//Code for PID based Liner Follower  Version 1
// Date:03-02-2020
//Main theme  Speed control and error based decision making related to speed
int MotorSpeed = 0;
int initialSpeed = 100;
int kp = 1;
int kd = 1;
int previous_error = 0;
void setup() {
  pinMode(motor_left, OUTPUT);
  pinMode(motor_right, OUTPUT);
  pinMode(sensor_left_2, INPUT);
  pinMode(sensor_left_1, INPUT);
  pinMode(sensor_center, INPUT);
  pinMode(sensor_right_1, INPUT);
  pinMode(sensor_right_2, INPUT);

  int sensor[5] = {0, 0, 0, 0, 0};
  
  

}

void loop() {
  int error = 0;
  while(true)
  {
  Read_sensor();
  error = Error();
  PID(error);
  }

}
int Error(){
 sensor[0]=digitalRead(A0);
  sensor[1]=digitalRead(A1);
  sensor[2]=digitalRead(A2);
  sensor[3]=digitalRead(A3);
  sensor[4]=digitalRead(A4);
  
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1))
  error=4;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))
  error=3;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==0))
  error=2;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0))
  error=1;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
  error=0;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
  error=-1;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  error=-2;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  error=-3;
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
  error=-4;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
    if(error==-4) error=-5;
    else error=5;
  return error;
  }
void Read_sensor(){
    sensor[0] = digitalRead(sensor_left_2);
    sensor[1] = digitalRead(sensor_left_1);
    sensor[2] = digitalRead(sensor_center);
    sensor[3] = digitalRead(sensor_right_1);
    sensor[4] = digitalRead(sensor_right_2);
  }
void PID(int error){
  D = error-previous_error;
  MotorSpeed = intialSpeed + (kp*error) + (kd*D) ;
  analogWrite(motor_left, MotorSpeed);
  analogWrite(motor_right, initialSpeed);
  previous_error = error;
  MotorSpeed = initialSpeed;
  }
