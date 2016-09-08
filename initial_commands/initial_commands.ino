// MD03A_Motor_basic
// Test MD03a / Pololu motor

#include <ros.h>
#include <std_msgs/Int8.h>

ros::NodeHandle  nh;



#define InA1            11                 // INA motor pin
#define InB1            10                 // INB motor pin
#define PWM1            5                  // PWM motor pin

#define InA2            8                  // INA motor pin
#define InB2            9                  // INB motor pin
#define PWM2            6                  // PWM motor pin

#define ENC11            2                  // Encoder
#define ENC12            3                  // Encoder
#define ENC21            12                  // Encoder
#define ENC22            13                  // Encoder


void messageCb( const std_msgs::Int16& pwm_msg){
  moveForward(pwm_msg.data);
}

ros::Subscriber<std_msgs::Int8> sub("pwm", messageCb );

std_msgs::String str_msg;
ros::Publisher chatter("encoder1", &str_msg);

void setup() {
 pinMode(InA1, OUTPUT);
 pinMode(InB1, OUTPUT);
 pinMode(PWM1, OUTPUT);
 pinMode(InA2, OUTPUT);
 pinMode(InB2, OUTPUT);
 pinMode(PWM2, OUTPUT);
 
 nh.initNode();
 nh.subscribe(sub);
}


void loop() {
 nh.spinOnce();
 delay(100);
}

void moveForward(int PWM_val)  {
 resetCommands();
 analogWrite(PWM1, PWM_val);
 analogWrite(PWM2, PWM_val);
 digitalWrite(InA1, LOW);
 digitalWrite(InB1, HIGH);
 digitalWrite(InA2, LOW);
 digitalWrite(InB2, HIGH);
}

void moveBackward(int PWM_val)  {
 resetCommands();
 analogWrite(PWM1, PWM_val);
 analogWrite(PWM2, PWM_val);
 digitalWrite(InA1, HIGH);
 digitalWrite(InB1, LOW);
 digitalWrite(InA2, HIGH);
 digitalWrite(InB2, LOW);
}

void moveLeft(int PWM_val)  {
 resetCommands();
 analogWrite(PWM1, PWM_val);
 analogWrite(PWM2, PWM_val);
 digitalWrite(InA1, HIGH);
 digitalWrite(InB1, LOW);
 digitalWrite(InA2, LOW);
 digitalWrite(InB2, HIGH);
}

void moveRight(int PWM_val)  {
 resetCommands();
 analogWrite(PWM1, PWM_val);
 analogWrite(PWM2, PWM_val);
 digitalWrite(InA1, LOW);
 digitalWrite(InB1, HIGH);
 digitalWrite(InA2, HIGH);
 digitalWrite(InB2, LOW);
}


void resetCommands()  {
 analogWrite(PWM1, 0);
 analogWrite(PWM2, 0);
 digitalWrite(InA1, LOW);
 digitalWrite(InB1, LOW);
 delay(10);
}

