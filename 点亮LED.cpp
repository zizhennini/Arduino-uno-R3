int ledPin = 13; // LED���ӵ���������13

void setup() {
	pinMode(ledPin, OUTPUT); // ��������Ϊ���ģʽ
}
void loop() {
	digitalWrite(ledPin, HIGH); // ����LED
	delay(10); // �ȴ�10ms
	digitalWrite(ledPin, LOW); // Ϩ��LED
	delay(10); // �ȴ�10ms
}