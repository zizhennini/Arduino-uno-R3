// 定义超声波模块的Trig引脚和Echo引脚
#define Trig 2
#define Echo 3

// 获取距离的函数
float getDistance() {
    // 确保Trig引脚初始为低电平，避免误触发超声波
    digitalWrite(Trig, LOW);  
    delayMicroseconds(2);     // 等待2微秒，确保稳定

    // 向Trig引脚发送一个10微秒的高电平脉冲，触发超声波发射
    digitalWrite(Trig, HIGH); 
    delayMicroseconds(10);    // 持续10微秒
    digitalWrite(Trig, LOW);  // 结束高电平脉冲

    // 使用pulseIn函数测量Echo引脚的高电平持续时间（单位：微秒）
    // 并通过公式将时间转换为距离（单位：厘米）
    float distance = pulseIn(Echo, HIGH) / 58.00; 

    delay(10); // 延时10毫秒，避免连续测量干扰
    return distance; // 返回测量的距离值
}

// 初始化函数，仅运行一次
void setup() {
    Serial.begin(9600); // 初始化串口通信，波特率为9600
    pinMode(Trig, OUTPUT); // 设置Trig引脚为输出模式
    pinMode(Echo, INPUT);  // 设置Echo引脚为输入模式
}

// 主循环函数，持续运行
void loop() {
    // 调用getDistance函数获取距离并通过串口打印
    Serial.print(getDistance()); // 打印测量的距离值
    Serial.println(" cm");       // 打印单位“cm”
}