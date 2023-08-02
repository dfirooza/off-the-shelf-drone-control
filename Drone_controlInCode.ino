//
// Code to control the drone by setting the values within the loop
//
// Daniel Firoozabadi
// July 2023

const int midVoltageInt = 82;  // equivalent to controller_voltage/2 = 1.675 --> 1.675/5.20*255= 82

// calibration:
int throttle_cal = 0.8*midVoltageInt;
int yaw_cal      = 1*midVoltageInt; 
int pitch_cal    = 0.78*midVoltageInt;
int roll_cal     = 1.2*midVoltageInt; 

int throttle = throttle_cal;  
int yaw      = yaw_cal;  
int pitch    = pitch_cal;  
int roll     = roll_cal;  

// PWM outputs
int PWMpin_throttle = 5;      // Output to digital pin 5 - Throttle
int PWMpin_yaw      = 6;      // Output to digital pin 6 - Yaw
int PWMpin_pitch    = 9;      // Output to digital pin 3 - Pitch
int PWMpin_roll     = 3;      // Output to digital pin 9 - Roll
int PWMpin_launch   = 10;     // Output to digital pin 10 - Launch/Land


void setup() {
  pinMode(PWMpin_throttle, OUTPUT); // sets the pin as output
  pinMode(PWMpin_yaw, OUTPUT);      // sets the pin as output
  pinMode(PWMpin_pitch, OUTPUT);    // sets the pin as output
  pinMode(PWMpin_roll, OUTPUT);     // sets the pin as output

  writeToPWM(throttle, yaw, pitch, roll); // initialize signals

  analogWrite(PWMpin_launch, 164);  // initialize launch/land button to max V=3.35
}

void loop() {

  // Launch
  throttle = throttle_cal;
  yaw      = yaw_cal;
  pitch    = pitch_cal;
  roll     = roll_cal;
  writeToPWM(throttle, yaw, pitch, roll);
  analogWrite(PWMpin_launch, 0);  
  delay(200);
  analogWrite(PWMpin_launch, 164);  
  delay(3000); 
  
  //Pause
  throttle = throttle_cal;
  yaw      = yaw_cal;
  pitch    = pitch_cal;
  roll     = roll_cal;
  writeToPWM(throttle, yaw, pitch, roll);
  delay(3000); 

  // Orbit
  throttle = throttle_cal*1.3;
  yaw      = yaw_cal*4; 
  pitch    = pitch_cal*1;
  roll     = roll_cal*1.7;
  writeToPWM(throttle, yaw, pitch, roll);
  delay(10000); 

  // Pause
  throttle = throttle_cal;
  yaw      = yaw_cal;
  pitch    = pitch_cal;
  roll     = roll_cal;
  writeToPWM(throttle, yaw, pitch, roll);
  delay(1000)

  // Land
  analogWrite(PWMpin_land, 0);  
  delay(200);
  analogWrite(PWMpin_land, 164);  

  // Stay inactive
  while(true)
  {
    //dummy infinite loop
  }
}


void writeToPWM(int throttle, int yaw, int pitch, int roll)
{
  // limit boundaries to [0, 255]
  throttle = setBounds(throttle);
  yaw = setBounds(yaw);
  pitch = setBounds(pitch);
  roll = setBounds(roll);
  
  // Write the new values to PWM outputs:
  analogWrite(PWMpin_throttle, throttle); 
  analogWrite(PWMpin_yaw, yaw);  
  analogWrite(PWMpin_pitch, pitch);
  analogWrite(PWMpin_roll, roll);  

  return;
}


int setBounds(int val)
{
  // Keep the val between in [0,255]
  if(val>255)
    val = 255;
  else if(val<0)
    val = 0;

  return(val);
}

