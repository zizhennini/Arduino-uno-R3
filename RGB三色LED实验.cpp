// �����һ�� LED ���ŵı�ţ���������Ϊ 2
int ledMark = 2;
// ���� LED ����������������Ϊ 5
int num = 5;

// setup() �����ڳ���ʼʱִֻ��һ��
// ͨ�����ڳ�ʼ������ģʽ������ͨ�ŵȲ���
void setup()
{
    // ʹ�� for ѭ�������ö�� LED ����Ϊ���ģʽ
    // �� ledMark ��ʼ���� ledMark + num ������������ ledMark + num��
    for (int i = ledMark; i < ledMark + num; i++) {
        // ������ i ����Ϊ���ģʽ���Ա���Կ��Ƹ����ŵĵ�ƽ
        pinMode(i, OUTPUT);
    }
}

// loop() ������ setup() ����ִ����Ϻ�᲻��ѭ��ִ��
// ��Ҫ����ʵ�ֳ���ĺ����߼�
void loop()
{
    // �������� LED
    // ʹ�� for ѭ�����ε���ÿ�� LED
    for (int i = ledMark; i < ledMark + num; i++) {
        // ������ i �ĵ�ƽ����Ϊ�ߵ�ƽ���������� LED
        digitalWrite(i, HIGH);
        // �ӳ� 50 ���룬�� LED ���ֵ���״̬һ��ʱ��
        delay(50);
    }

    // Ϩ������ LED
    // ʹ�� for ѭ������Ϩ��ÿ�� LED
    for (int i = ledMark; i < ledMark + num; i++) {
        // ������ i �ĵ�ƽ����Ϊ�͵�ƽ����Ϩ��� LED
        digitalWrite(i, LOW);
        // �ӳ� 50 ���룬�� LED ����Ϩ��״̬һ��ʱ��
        delay(50);
    }
}