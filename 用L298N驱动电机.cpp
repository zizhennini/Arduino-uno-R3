// 假设控制电机A的引脚为in1、in2，控制电机B的引脚为in3、in4
const int in1 = 13;
const int in2 = 12;
const int in3 = 26;
const int in4 = 27;

void setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() {
    // 电机A正转，电机B正转
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(2000);  // 持续2秒

    // 电机A反转，电机B反转
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(2000);  // 持续2秒
}


// 两块L298N直接导致原地旋转，高低电平不一样，基于ESP 32 