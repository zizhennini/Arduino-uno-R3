
// ���忪�����ϵ����� 2
int redled = 2;
// ���忪�����ϵ�����3�������ӻ�ɫLED
int yellowLed = 3;
// ���忪�����ϵ�����4����������ɫLED
int greenLed = 4;
// ���忪�����ϵ�����5�������Ӻ�ɫLED
int redLed = 5;
// ��������6��Ϊ���ƺ�ɫLED�Ƶİ���
int yellowKey = 6;
// ��������7��Ϊ���ƻ�ɫLED�Ƶİ���
int greenKey = 7;
// ��������8��Ϊ������ɫLED�Ƶİ���
int redKey = 8;
// ��������8��Ϊ��λ����
int resetKey = 8;
// ��ʼ���������ڳ���ʼ����ʱִ��һ��
void setup() {
    // �����Ӻ�ɫLED��������Ϊ���ģʽ
    pinMode(redLed, OUTPUT);
    // �����ӻ�ɫLED��������Ϊ���ģʽ
    pinMode(yellowLed, OUTPUT);
    // ��������ɫLED��������Ϊ���ģʽ
    pinMode(greenLed, OUTPUT);
    // �����ƺ�ɫLED�Ƶİ���������Ϊ��������ģʽ
    pinMode(redKey, INPUT_PULLUP);
    // �����ƻ�ɫLED�Ƶİ���������Ϊ��������ģʽ
    pinMode(yellowKey, INPUT_PULLUP);
    // ��������ɫLED�Ƶİ���������Ϊ��������ģʽ
    pinMode(greenKey, INPUT_PULLUP);
    // ����λ����������Ϊ��������ģʽ
    pinMode(resetKey, INPUT_PULLUP);
}
// ��ѭ������������᲻���ظ�ִ�����еĴ���
void loop() {
    // �жϿ��ƺ�ɫLED�Ƶİ����Ƿ񱻰��£��������£���ִ�����´���
    if (digitalRead(redKey) == LOW)
        RED();
    // �жϿ��ƻ�ɫLED�Ƶİ����Ƿ񱻰��£��������£���ִ�����´���
    if (digitalRead(yellowKey) == LOW)
        YELLOW();
    // �жϿ�����ɫLED�Ƶİ����Ƿ񱻰��£��������£���ִ�����´���
    if (digitalRead(greenKey) == LOW)
        GREEN();
}
// ���ƺ�ɫLED��ز����ĺ���
void RED() {
    // �ж�reset�����Ƿ񱻰��£���������£���������ǰ��whileѭ��������clear()����
    while (digitalRead(resetKey) == 1)
    {
        // ��ɫLED������
        digitalWrite(redLed, HIGH);
        // ��ɫLED��Ϩ��
        digitalWrite(greenLed, LOW);
        // ��ɫLED��Ϩ��
        digitalWrite(yellowLed, LOW);
    }
    clear();//Ϩ������С��
}
// ���ƻ�ɫLED��ز����ĺ���
void YELLOW() {
    // �ж�reset�����Ƿ񱻰��£���������£���������ǰ��whileѭ��������clear()����
    while (digitalRead(resetKey) == 1)
    {
        // ��ɫLED��Ϩ��
        digitalWrite(redLed, LOW);
        // ��ɫLED��Ϩ��
        digitalWrite(greenLed, LOW);
        // ��ɫLED������
        digitalWrite(yellowLed, HIGH);
    }
    clear();//Ϩ������С��
}
// ������ɫLED��ز����ĺ���
void GREEN() {
    // �ж�reset�����Ƿ񱻰��£���������£���������ǰ��whileѭ��������clear()����
    while (digitalRead(resetKey) == 1)
    {
        // ��ɫLED��Ϩ��
        digitalWrite(redLed, LOW);
        // ��ɫLED������
        digitalWrite(greenLed, HIGH);
        // ��ɫLED��Ϩ��
        digitalWrite(yellowLed, LOW);
    }
    clear();//Ϩ������С��
}
// Ϩ������LED�Ƶĺ���
void clear() {
    // ��ɫLED��Ϩ��
    digitalWrite(redLed, LOW);
    // ��ɫLED��Ϩ��
    digitalWrite(greenLed, LOW);
    // ��ɫLED��Ϩ��
    digitalWrite(yellowLed, LOW);
}
