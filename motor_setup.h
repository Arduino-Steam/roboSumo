#include<NewPing.h>

class Robot{
  public:
    Robot();//
    Robot(int LF_SET, int LB_SET, 
          int RF_SET, int RB_SET);//
          
    Robot(int LF_SET, int LB_SET, 
          int RF_SET, int RB_SET, 
          int L_SPEED, int R_SPEED);
          
    Robot(int LF_SET, int LB_SET, 
          int RF_SET, int RB_SET, 
          int L_SPEED, int R_SPEED,
          int TRIG, int ECHO);
          
    Robot(int LF_SET_PIN, int LB_SET_PIN, 
          int RF_SET_PIN, int RB_SET_PIN, 
          int L_SPEED_SET_PIN, int R_SPEED_SET_PIN,
          int TRIG_PIN, int ECHO_PIN,
          int IR_LINE_PIN);
          
    void set_motor_pin(int LF_SET_PIN, int LB_SET_PIN, 
                       int RF_SET_PIN, int RB_SET_PIN);
                       
    void set_motor_pin(int LF_SET_PIN, int LB_SET_PIN, 
                       int RF_SET_PIN, int RB_SET_PIN,
                       int L_SPEED_PIN, int R_SPEED_PIN);
                       
    void set_motor_speed_pin(int L_SPEED, int R_SPEED);
    void set_speed_value(int L_SPEED, int R_SPEED);
    void set_ultrasonic_pin(int TRIG_SET_PIN, int ECHO_SET_PIN);
    void set_ir_line_pin(int IR_LINE_SET_PIN);
    
    void move(bool LF_MOVE, bool LB_MOVE, 
                  bool RF_MOVE, bool RB_MOVE);
                  
    void move(bool LF_MOVE, bool LB_MOVE,
              bool RF_MOVE, bool RB_MOVE, int TIME_DELAY);              
    
    void move(bool LF_MOVE, bool LB_MOVE, 
                  bool RF_MOVE, bool RB_MOVE, 
                  int L_SPEED, int R_SPEED);
    
    void move(bool LF_MOVE, bool LB_MOVE,
                  bool RF_MOVE, bool RB_MOVE, 
                  int L_SPEED, int R_SPEED, int TIME_DELAY);
    
    int get_distance();
    int get_ir_line();
    
  private:
    int LF_PIN = 0;
    int LB_PIN = 0;
    int RF_PIN = 0;
    int RB_PIN = 0;
    int L_SPEED_PIN=0;
    int R_SPEED_PIN=0;
    int IR_LINE_PIN=0;
    int ULTRASONIC_PIN[2]={0,0};
    void print_info_about_pins();
    void set_pins_to_output();
};
