// ������Ƶ��A������Ϊin1��in2�����Ƶ��B������Ϊin3��in4
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
    // ���A��ת�����B��ת
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(2000);  // ����2��

    // ���A��ת�����B��ת
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(2000);  // ����2��
}


// ����L298Nֱ�ӵ���ԭ����ת���ߵ͵�ƽ��һ��������ESP 32 