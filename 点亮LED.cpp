int ledPin = 13; // LED连接到数字引脚13

void setup() {
	pinMode(ledPin, OUTPUT); // 设置引脚为输出模式
}
void loop() {
	digitalWrite(ledPin, HIGH); // 点亮LED
	delay(10); // 等待10ms
	digitalWrite(ledPin, LOW); // 熄灭LED
	delay(10); // 等待10ms
}