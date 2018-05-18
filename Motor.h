class Motor {
private:
  int drivePin;
  int dirPin;
  bool reversed;
public:
  Motor(int a, int b);
  void set(int a);
  void setReversed(bool set) { reversed = set; }
  bool isReversed() { return reversed; }
};

Motor::Motor(int drive, int dir) {
  drivePin = drive;
  dirPin = dir;
  pinMode(drivePin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void Motor::set(int val) {
  val = constrain(val, -255, 255);
  val = val * (isReversed()?-1:1);
  analogWrite(drivePin, (val < 0 ? 255 + val : val));
  digitalWrite(dirPin, (val < 0 ? HIGH : LOW));
}

