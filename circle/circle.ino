#define left_motor_dir 12
#define left_motor_pwm 11
#define right_motor_dir 10 
#define right_motor_pwm 9 


class _Motor{
  int pwm_pin, dir_pin, _pwm, _dir;
  public:
    // _Motor();
    // _Motor(int _dir_pin, int _pwm_pin){
    //     pwm_pin = _pwm_pin;
    //     dir_pin = _dir_pin;
    //     pinMode(dir_pin, OUTPUT);
    //     pinMode(pwm_pin, OUTPUT);
    // }
    void run(long _cmd){
      _dir = (_cmd>=0) ? 1:0;
      _pwm = abs(_cmd);
      digitalWrite(dir_pin, _dir);
      if(_dir==1) {
        _pwm = abs(255-_pwm%256);
        analogWrite(pwm_pin, _pwm);
      }
      else analogWrite(pwm_pin, _pwm);
    }
    void set_pin(int _dir_pin, int _pwm_pin){
      pwm_pin = _pwm_pin;
      dir_pin = _dir_pin;
      pinMode(dir_pin, OUTPUT);
      pinMode(pwm_pin, OUTPUT);
    }
};
// pwm(200) ~ speed(0.16);
class DiffDrive{
    double _vx, _w;                     //curr vel
    double _cmd_vel[2] = {0.0, 0.0};    //cmd vel
    int left_wheel_in, right_wheel_in;                         //w given to motors (0-255)
    double _joint_pos[2] = {0.0, 0.0};  //current rotaion of motor
    double _joint_vel[2] = {0.0, 0.0};  //current rotaional vel of motor
    double _posn[3] = {0.0, 0.0, 0.0};        //posn in world frame
    double wheel_radii = 0.04;
    double wheel_seprn = 0.10;
    _Motor dd_left_motor, dd_right_motor;

    public:
    DiffDrive(int l_dir_pin, int l_pwm_pin, int r_dir_pin, int r_pwm_pin){
        dd_left_motor.set_pin(l_dir_pin, l_pwm_pin);
        dd_right_motor.set_pin(r_dir_pin, r_pwm_pin);
        _vx = 0; _w = 0;
        left_wheel_in = 0; right_wheel_in = 0;
    }
    send_wheel_cmd(double lw, double rw){
        _joint_vel[0] = lw/wheel_radii;
        _joint_vel[1] = rw/wheel_radii;
        left_wheel_in  = lw*225/0.16;
        right_wheel_in = rw*225/0.16;
        dd_left_motor.run(left_wheel_in);
        dd_right_motor.run(right_wheel_in);
    }
    move(double vx, double w){
        double lw = vx - w * wheel_seprn / 2.0;
        double rw = vx + w * wheel_seprn / 2.0;
        send_wheel_cmd(lw, rw);
    }
    update_odom(int t_step){
      double b = wheel_seprn;
      double sl = wheel_radii * _joint_vel[0] * t_step/1000;
      double sr = wheel_radii * _joint_vel[1] * t_step/1000;
      double ssum = sl + sr;
      double sdiff = sr - sl;
      double dx = ( ssum ) /2.0 * cos ( _posn[2] + ( sdiff ) / ( 2.0*b ) );
      double dy = ( ssum ) /2.0 * sin ( _posn[2] + ( sdiff ) / ( 2.0*b ) );
      double dtheta = ( sdiff ) /b;
      _posn[0] += dx;
      _posn[1] += dy;
      _posn[2] += dtheta;
      Serial.print(_posn[0], 4); Serial.print(' ');
      Serial.print(_posn[1], 4); Serial.print(' ');
      Serial.print(_posn[2], 4); Serial.print('\n');
    }
};

  DiffDrive mybot(left_motor_dir, 
                 left_motor_pwm,
                 right_motor_dir, 
                 right_motor_pwm);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  // for(int i = 0; i<225; i++){
  //   mybot.update_odom(10);
  //   mybot.move(i*0.16/225, 0);
  //   delay(10);
  // }
}


void loop() {
  mybot.update_odom(10);
  //for a circular trajectory radius 0.25m
  double R = 0.25, V = 0.15, W = V/R;
  mybot.move(V, W);
  delay(8000);
  mybot.move(0, 0);
  exit(0);
}