int ledMark = 2; // ��ʼLED���ű��
int num = 5; // LED����

void setup()
{
	// ��ʼ��ÿ��LED����Ϊ���ģʽ
	for (int i = ledMark; i < ledMark + num; i++) {
		pinMode(i, OUTPUT);
	}
}

void loop()
{
	// ���ε���ÿ��LED
	for (int i = ledMark; i < ledMark + num; i++) {
		digitalWrite(i, HIGH); // ������ǰLED
		delay(50); // �ӳ�50����
	}

	// ����Ϩ��ÿ��LED
	for (int i = ledMark; i < ledMark + num; i++) {
		digitalWrite(i, LOW); // Ϩ��ǰLED
		delay(50); // �ӳ�50����
	}
}