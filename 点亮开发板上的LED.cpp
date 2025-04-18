

// 注：输入上拉模式（高电平）接通GND就会变为低电平（该引脚）



// 定义一个全局变量，标记引脚2
int gPin = 2;
void setup() {
    // 设置串口波特率为9600
    Serial.begin(9600);
    // 设置引脚2为输入上拉模式
    pinMode(gPin, INPUT_PULLUP);
    // 设置引脚13为输出模式
    pinMode(13, OUTPUT);
}
void loop() {
    // 读取引脚2的电平状态值，返回结果存于变量r中
    int r = digitalRead(gPin);
    // 向串口输出引脚2的电平状态值，比如1或0
    Serial.println(r);
    // 表示开关没有被按下，这里的HIGH是一个宏，等价于1
    if (r == HIGH)
        // 向引脚输出低电平，LED熄灭，LOW是一个宏，等价于0
        digitalWrite(13, LOW);
    else
        // r为0，也就是引脚2由于开关被按下而和GND接通，处于低电平
        digitalWrite(13, HIGH); // 向引脚13输出高电平，LED被点亮，HIGH是一个宏，等价于1
}
