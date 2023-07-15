#define left_motor_dir 12
#define left_motor_pwm 11
#define right_motor_dir 10 
#define right_motor_pwm 9 


class _Motor{
  public:
    int pwm_pin, dir_pin, _pwm, _dir;
  _Motor(int _dir_pin, int _pwm_pin){
    pwm_pin = _pwm_pin;
    dir_pin = _dir_pin;
    pinMode(dir_pin, OUTPUT);
    pinMode(pwm_pin, OUTPUT);
  }
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
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  _Motor left_motor(left_motor_dir, left_motor_pwm), right_motor(right_motor_dir, right_motor_pwm);
  left_motor.run(0);
  right_motor.run(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  // left_motor.run(200);
  // right_motor.run(200);
  if (Serial.available() > 0) {
    // read the incoming byte:
    int vel = Serial.parseInt();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(vel);
  }
  delay(10);
}