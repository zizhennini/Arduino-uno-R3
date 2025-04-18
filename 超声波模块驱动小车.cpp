// ================== 电机控制引脚定义 ==================
// L298N1
const int motorAIN1_1 = 13;  // 电机A 正转控制
const int motorAIN2_1 = 12;  // 电机A 反转控制
const int motorBIN3_1 = 26;  // 电机B 正转控制
const int motorBIN4_1 = 27;  // 电机B 反转控制
// L298N2
const int motorAIN1_2 = 18;  // 电机C 正转控制
const int motorAIN2_2 = 19;  // 电机C 反转控制
const int motorBIN3_2 = 25;  // 电机D 正转控制
const int motorBIN4_2 = 22;  // 电机D 反转控制

// ================== 超声波模块引脚定义 ==================
const int trigPin1 = 14;   // 超声波模块1 触发引脚
const int echoPin1 = 15;   // 超声波模块1 回波引脚
const int trigPin2 = 16;   // 超声波模块2 触发引脚
const int echoPin2 = 17;   // 超声波模块2 回波引脚

long duration1, duration2;
float distance1, distance2;  // 存储两个模块的距离（单位：cm）

void setup() {
    Serial.begin(115200);       // 初始化串口（用于打印距离）

    // 初始化电机控制引脚为输出模式
    pinMode(motorAIN1_1, OUTPUT);
    pinMode(motorAIN2_1, OUTPUT);
    pinMode(motorBIN3_1, OUTPUT);
    pinMode(motorBIN4_1, OUTPUT);
    pinMode(motorAIN1_2, OUTPUT);
    pinMode(motorAIN2_2, OUTPUT);
    pinMode(motorBIN3_2, OUTPUT);
    pinMode(motorBIN4_2, OUTPUT);

    // 初始化超声波模块引脚
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);

    // 初始状态：电机停止（所有引脚LOW）
    digitalWrite(motorAIN1_1, LOW);
    digitalWrite(motorAIN2_1, LOW);
    digitalWrite(motorBIN3_1, LOW);
    digitalWrite(motorBIN4_1, LOW);
    digitalWrite(motorAIN1_2, LOW);
    digitalWrite(motorAIN2_2, LOW);
    digitalWrite(motorBIN3_2, LOW);
    digitalWrite(motorBIN4_2, LOW);
}

void loop() {
    // ================== 测量两个超声波模块的距离 ==================
    distance1 = getDistance(trigPin1, echoPin1);
    distance2 = getDistance(trigPin2, echoPin2);

    Serial.print("Distance1: ");
    Serial.print(distance1);
    Serial.print(" cm | Distance2: ");
    Serial.print(distance2);
    Serial.println(" cm");

    // ================== 简单电机控制逻辑（示例：前进/后退/转向） ==================
    // 假设模块1测前方，模块2测后方（可根据实际安装位置调整逻辑）
    if (distance1 < 20) {        // 前方距离过近（10cm），后退并转向
        motorBackward();           // 后退
        delay(50);
        motorLeft();               // 左转（或右转，根据实际需求）
        delay(50);
    }
    else {
        motorForward();            // 正常前进
    }

    delay(100);  // 控制循环频率，避免CPU占用过高
}

// ================== 超声波测距函数 ==================
float getDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    return (duration * 0.034) / 2;  // 计算距离（单位：cm）
}

// ================== 电机控制函数（正转/反转/停止/转向） ==================
// 前进（四个电机正转）
void motorForward() {
    digitalWrite(motorAIN1_1, HIGH);
    digitalWrite(motorAIN2_1, LOW);
    digitalWrite(motorBIN3_1, HIGH);
    digitalWrite(motorBIN4_1, LOW);
    digitalWrite(motorAIN1_2, HIGH);
    digitalWrite(motorAIN2_2, LOW);
    digitalWrite(motorBIN3_2, HIGH);
    digitalWrite(motorBIN4_2, LOW);
}

// 后退（四个电机反转）
void motorBackward() {
    digitalWrite(motorAIN1_1, LOW);
    digitalWrite(motorAIN2_1, HIGH);
    digitalWrite(motorBIN3_1, LOW);
    digitalWrite(motorBIN4_1, HIGH);
    digitalWrite(motorAIN1_2, LOW);
    digitalWrite(motorAIN2_2, HIGH);
    digitalWrite(motorBIN3_2, LOW);
    digitalWrite(motorBIN4_2, HIGH);
}

// 左转（电机A和C停止，电机B和D正转）
void motorLeft() {
    digitalWrite(motorAIN1_1, LOW);
    digitalWrite(motorAIN2_1, LOW);
    digitalWrite(motorBIN3_1, HIGH);
    digitalWrite(motorBIN4_1, LOW);
    digitalWrite(motorAIN1_2, LOW);
    digitalWrite(motorAIN2_2, LOW);
    digitalWrite(motorBIN3_2, HIGH);
    digitalWrite(motorBIN4_2, LOW);
}

// 右转（电机B和D停止，电机A和C正转）
void motorRight() {
    digitalWrite(motorAIN1_1, HIGH);
    digitalWrite(motorAIN2_1, LOW);
    digitalWrite(motorBIN3_1, LOW);
    digitalWrite(motorBIN4_1, LOW);
    digitalWrite(motorAIN1_2, HIGH);
    digitalWrite(motorAIN2_2, LOW);
    digitalWrite(motorBIN3_2, LOW);
    digitalWrite(motorBIN4_2, LOW);
}

// 停止
void motorStop() {
    digitalWrite(motorAIN1_1, LOW);
    digitalWrite(motorAIN2_1, LOW);
    digitalWrite(motorBIN3_1, LOW);
    digitalWrite(motorBIN4_1, LOW);
    digitalWrite(motorAIN1_2, LOW);
    digitalWrite(motorAIN2_2, LOW);
    digitalWrite(motorBIN3_2, LOW);
    digitalWrite(motorBIN4_2, LOW);
}