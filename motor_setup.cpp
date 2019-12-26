#include"motor_setup.h"
#include"default_definations.h"
// Begin realize constructors

// Default constructor
Robot::Robot(){
  Serial.begin(9600);
  Serial.println("Default constructor");
  Serial.end();
  
  set_motor_pin(DEFAULT_LF_PIN,DEFAULT_LB_PIN,DEFAULT_RF_PIN,DEFAULT_RB_PIN);
  set_motor_speed_pin(DEFAULT_L_SPEED_PIN,DEFAULT_R_SPEED_PIN);

  set_ultrasonic_pin(DEFAULT_ULTRASONIC_TRIG_PIN,DEFAULT_ULTRASONIC_ECHO_PIN);
  set_ir_line_pin(DEFAULT_IR_LINE_PIN);

  print_info_about_pins();
}
// Constructor only for motor pins without speed pins
Robot::Robot(int LF_SET_PIN, int LB_SET_PIN,
             int RF_SET_PIN, int RB_SET_PIN)
{
  Serial.begin(9600);
  Serial.println("Constructor only for motor pins without speed pins");
  Serial.end();
  
  set_motor_pin(LF_SET_PIN, LB_SET_PIN, RF_SET_PIN, RB_SET_PIN);
  set_motor_speed_pin(DEFAULT_L_SPEED_PIN,DEFAULT_R_SPEED_PIN);
  set_ultrasonic_pin(DEFAULT_ULTRASONIC_TRIG_PIN, DEFAULT_ULTRASONIC_ECHO_PIN);
  set_ir_line_pin(DEFAULT_IR_LINE_PIN);

  print_info_about_pins();
}
// Constructor for motor and speed pins
Robot::Robot(int LF_SET_PIN,int LB_SET_PIN, 
      int RF_SET_PIN,       int RB_SET_PIN, 
      int L_SPEED_SET_PIN,  int R_SPEED_SET_PIN)
{
  Serial.begin(9600);
  Serial.println("Constructor for motor and speed pins");
  Serial.end();
  
  set_motor_pin(LF_SET_PIN, LB_SET_PIN, RF_SET_PIN, RB_SET_PIN);
  set_motor_speed_pin(L_SPEED_SET_PIN, R_SPEED_SET_PIN);
  set_ultrasonic_pin(DEFAULT_ULTRASONIC_TRIG_PIN, DEFAULT_ULTRASONIC_ECHO_PIN);
  set_ir_line_pin(DEFAULT_IR_LINE_PIN);
  
  print_info_about_pins();
}
// Constructor for motor, speed, and ultrasonic pins
Robot::Robot(int LF_SET_PIN, int LB_SET_PIN, 
             int RF_SET_PIN, int RB_SET_PIN, 
             int L_SPEED_SET_PIN, int R_SPEED_SET_PIN,
             int TRIG_SET_PIN, int ECHO_SET_PIN){
  Serial.begin(9600);
  Serial.println("Constructor for motor, speed, and ultrasonic pins");
  Serial.end();
  
  set_motor_pin(LF_SET_PIN, LB_SET_PIN, RF_SET_PIN, RB_SET_PIN);
  set_motor_speed_pin(L_SPEED_SET_PIN, R_SPEED_SET_PIN);
  set_ultrasonic_pin(TRIG_SET_PIN, ECHO_SET_PIN);
  set_ir_line_pin(DEFAULT_IR_LINE_PIN);
  
  print_info_about_pins();              
}
// Constructor for motor, speed, ultrasonic and ir-line pins
Robot::Robot(int LF_SET_PIN, int LB_SET_PIN, 
          int RF_SET_PIN, int RB_SET_PIN, 
          int L_SPEED_SET_PIN, int R_SPEED_SET_PIN,
          int TRIG_SET_PIN, int ECHO_SET_PIN,
          int IR_LINE_SET_PIN)
{
  Serial.begin(9600);
  Serial.println("Constructor for motor, speed, ultrasonic and ir-line pins");
  Serial.end();
  
  set_motor_pin(LF_SET_PIN, LB_SET_PIN, RF_SET_PIN, RB_SET_PIN);
  set_motor_speed_pin(L_SPEED_SET_PIN, R_SPEED_SET_PIN);
  set_ultrasonic_pin(TRIG_SET_PIN, ECHO_SET_PIN);
  set_ir_line_pin(IR_LINE_SET_PIN);
  
  print_info_about_pins();              
}
///////////////////////////////////////////////////////////////////
// End realize constructors


// Begin set functions

void Robot::set_motor_pin(int LF_SET_PIN, int LB_SET_PIN, 
                       int RF_SET_PIN, int RB_SET_PIN)
{
  LF_PIN = LF_SET_PIN;
  LB_PIN = LB_SET_PIN;
  RF_PIN = RF_SET_PIN;
  RB_PIN = RB_SET_PIN;
  L_SPEED_PIN = DEFAULT_L_SPEED_PIN;
  R_SPEED_PIN = DEFAULT_R_SPEED_PIN;
  set_pins_to_output();
}
             
void Robot::set_motor_pin(int LF_SET_PIN, int LB_SET_PIN, 
                       int RF_SET_PIN, int RB_SET_PIN,
                       int L_SPEED_SET_PIN, int R_SPEED_SET_PIN)
{  
  LF_PIN = LF_SET_PIN;
  LB_PIN = LB_SET_PIN;
  RF_PIN = RF_SET_PIN;
  RB_PIN = RB_SET_PIN;
  L_SPEED_PIN = L_SPEED_SET_PIN;
  R_SPEED_PIN = R_SPEED_SET_PIN;
  set_pins_to_output();
}
void Robot::set_motor_speed_pin(int L_SPEED_SET_PIN, int R_SPEED_SET_PIN){
  L_SPEED_PIN = L_SPEED_SET_PIN;
  R_SPEED_PIN = R_SPEED_SET_PIN;
  set_pins_to_output();
}

void Robot::set_ultrasonic_pin(int TRIG_SET_PIN, int ECHO_SET_PIN)
{
  ULTRASONIC_PIN[0] = TRIG_SET_PIN;
  ULTRASONIC_PIN[1] = ECHO_SET_PIN;
}
void Robot::set_ir_line_pin(int IR_LINE_SET_PIN)
{
  IR_LINE_PIN = IR_LINE_SET_PIN;
}
// End set functions

// Begin get functions
int Robot::get_distance(){
  delay(50);
  NewPing sonar(ULTRASONIC_PIN[0],ULTRASONIC_PIN[1]);
  return sonar.ping_cm();
}
int Robot::get_ir_line(){
  return digitalRead(IR_LINE_PIN)?'w':'b';
}
// End get functions

// Begin move functions
void Robot::set_speed_value(int L_SPEED_VALUE, int R_SPEED_VALUE)
{
  analogWrite(L_SPEED_PIN, L_SPEED_VALUE);
  analogWrite(R_SPEED_PIN, R_SPEED_VALUE);
}
void Robot::move(bool LF_MOVE_COMMAND, bool LB_MOVE_COMMAND, bool RF_MOVE_COMMAND, bool RB_MOVE_COMMAND)
{
  set_speed_value(255,255);
  digitalWrite(LF_PIN, LF_MOVE_COMMAND);
  digitalWrite(LB_PIN, LB_MOVE_COMMAND);
  digitalWrite(RF_PIN, RF_MOVE_COMMAND);
  digitalWrite(RB_PIN, RB_MOVE_COMMAND);
}
void Robot::move(bool LF_MOVE_COMMAND, bool LB_MOVE_COMMAND, bool RF_MOVE_COMMAND, bool RB_MOVE_COMMAND, int TIME_DELAY)
{
  set_speed_value(255,255);
  digitalWrite(LF_PIN, LF_MOVE_COMMAND);
  digitalWrite(LB_PIN, LB_MOVE_COMMAND);
  digitalWrite(RF_PIN, RF_MOVE_COMMAND);
  digitalWrite(RB_PIN, RB_MOVE_COMMAND);
  delay(TIME_DELAY);
}

void Robot::move(bool LF_COMMAND, bool LB_COMMAND, 
                  bool RF_COMMAND, bool RB_COMMAND, 
                  int L_SPEED_VALUE, int R_SPEED_VALUE)
{
  set_speed_value(L_SPEED_VALUE,R_SPEED_VALUE);
  digitalWrite(LF_PIN, LF_COMMAND);
  digitalWrite(LB_PIN, LB_COMMAND);
  digitalWrite(RF_PIN, RF_COMMAND);
  digitalWrite(RB_PIN, RB_COMMAND);
}

void Robot::move( bool LF_MOVE_COMMAND, bool LB_MOVE_COMMAND,
                  bool RF_MOVE_COMMAND, bool RB_MOVE_COMMAND, 
                  int L_SPEED_VALUE, int R_SPEED_VALUE, int TIME_DELAY)
{
  set_speed_value(L_SPEED_VALUE,R_SPEED_VALUE);
  digitalWrite(LF_PIN, LF_MOVE_COMMAND);
  digitalWrite(LB_PIN, LB_MOVE_COMMAND);
  digitalWrite(RF_PIN, RF_MOVE_COMMAND);
  digitalWrite(RB_PIN, RB_MOVE_COMMAND);
  delay(TIME_DELAY);
}
// End move functions
void Robot::set_pins_to_output(){
  pinMode(LF_PIN,OUTPUT);
  pinMode(LB_PIN,OUTPUT);
  pinMode(RF_PIN,OUTPUT);
  pinMode(RB_PIN, OUTPUT);
  pinMode(L_SPEED_PIN,OUTPUT);
  pinMode(R_SPEED_PIN,OUTPUT);
}
void Robot::print_info_about_pins(){
  Serial.begin(9600);
  Serial.println("MOTOR PINS\n_________________________________________________");
  Serial.println("\tLeft  Forward  -> " +(String)LF_PIN+"pin\t| Left  Backward  -> " +(String)LB_PIN+"pin\n"+
                 "\tRight Forward  -> " +(String)RF_PIN+"pin\t| Right Backward  -> "+(String)RB_PIN+"pin\n"+
                 "\tLEFT_SPEED_PIN -> " +(String)L_SPEED_PIN+"pin\t| RIGHT_SPEED_PIN -> "+(String)R_SPEED_PIN+"pin");
  Serial.println("_________________________________________________");
  Serial.println("SENSOR PIN\n_________________________________________________");
  Serial.println("\tULTRASONIC: TRIG->"+(String)ULTRASONIC_PIN[0]+"pin  ECHO->"+(String)ULTRASONIC_PIN[1]+"pin");
  Serial.println("\tIR_LINE_PIN -> "+(String)IR_LINE_PIN+"pin");
  Serial.println("_________________________________________________");
  Serial.end();
}
