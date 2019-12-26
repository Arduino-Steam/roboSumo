#include"motor_setup.h"
Robot robot(4,5,6,7);

void setup() {
//  delay(5000);
  robot.set_ir_line_pin(8);
}

void loop() {
  int dist = robot.get_distance();
  if(robot.get_ir_line()=='b'){
    robot.move(0,1,0,1,1000);
    robot.move(0,0,0,0);
  }
  else{
    if(dist<40 and dist>0){
      robot.move(1,0,1,0);
    }
    if(dist>40 or dist==0){
      robot.move(1,0,0,1);
    }
  }
}
