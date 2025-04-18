// ================== ����������Ŷ��� ==================
// L298N1
const int motorAIN1_1 = 13;  // ���A ��ת����
const int motorAIN2_1 = 12;  // ���A ��ת����
const int motorBIN3_1 = 26;  // ���B ��ת����
const int motorBIN4_1 = 27;  // ���B ��ת����
// L298N2
const int motorAIN1_2 = 18;  // ���C ��ת����
const int motorAIN2_2 = 19;  // ���C ��ת����
const int motorBIN3_2 = 25;  // ���D ��ת����
const int motorBIN4_2 = 22;  // ���D ��ת����

// ================== ������ģ�����Ŷ��� ==================
const int trigPin1 = 14;   // ������ģ��1 ��������
const int echoPin1 = 15;   // ������ģ��1 �ز�����
const int trigPin2 = 16;   // ������ģ��2 ��������
const int echoPin2 = 17;   // ������ģ��2 �ز�����

long duration1, duration2;
float distance1, distance2;  // �洢����ģ��ľ��루��λ��cm��

void setup() {
    Serial.begin(115200);       // ��ʼ�����ڣ����ڴ�ӡ���룩

    // ��ʼ�������������Ϊ���ģʽ
    pinMode(motorAIN1_1, OUTPUT);
    pinMode(motorAIN2_1, OUTPUT);
    pinMode(motorBIN3_1, OUTPUT);
    pinMode(motorBIN4_1, OUTPUT);
    pinMode(motorAIN1_2, OUTPUT);
    pinMode(motorAIN2_2, OUTPUT);
    pinMode(motorBIN3_2, OUTPUT);
    pinMode(motorBIN4_2, OUTPUT);

    // ��ʼ��������ģ������
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);

    // ��ʼ״̬�����ֹͣ����������LOW��
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
    // ================== ��������������ģ��ľ��� ==================
    distance1 = getDistance(trigPin1, echoPin1);
    distance2 = getDistance(trigPin2, echoPin2);

    Serial.print("Distance1: ");
    Serial.print(distance1);
    Serial.print(" cm | Distance2: ");
    Serial.print(distance2);
    Serial.println(" cm");

    // ================== �򵥵�������߼���ʾ����ǰ��/����/ת�� ==================
    // ����ģ��1��ǰ����ģ��2��󷽣��ɸ���ʵ�ʰ�װλ�õ����߼���
    if (distance1 < 20) {        // ǰ�����������10cm�������˲�ת��
        motorBackward();           // ����
        delay(50);
        motorLeft();               // ��ת������ת������ʵ������
        delay(50);
    }
    else {
        motorForward();            // ����ǰ��
    }

    delay(100);  // ����ѭ��Ƶ�ʣ�����CPUռ�ù���
}

// ================== ��������ຯ�� ==================
float getDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    return (duration * 0.034) / 2;  // ������루��λ��cm��
}

// ================== ������ƺ�������ת/��ת/ֹͣ/ת�� ==================
// ǰ�����ĸ������ת��
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

// ���ˣ��ĸ������ת��
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

// ��ת�����A��Cֹͣ�����B��D��ת��
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

// ��ת�����B��Dֹͣ�����A��C��ת��
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

// ֹͣ
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