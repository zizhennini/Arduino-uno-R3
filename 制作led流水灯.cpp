int ledMark = 2; // 起始LED引脚编号
int num = 5; // LED数量

void setup()
{
	// 初始化每个LED引脚为输出模式
	for (int i = ledMark; i < ledMark + num; i++) {
		pinMode(i, OUTPUT);
	}
}

void loop()
{
	// 依次点亮每个LED
	for (int i = ledMark; i < ledMark + num; i++) {
		digitalWrite(i, HIGH); // 点亮当前LED
		delay(50); // 延迟50毫秒
	}

	// 依次熄灭每个LED
	for (int i = ledMark; i < ledMark + num; i++) {
		digitalWrite(i, LOW); // 熄灭当前LED
		delay(50); // 延迟50毫秒
	}
}