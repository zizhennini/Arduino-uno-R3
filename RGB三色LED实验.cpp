// 定义第一个 LED 引脚的编号，这里设置为 2
int ledMark = 2;
// 定义 LED 的数量，这里设置为 5
int num = 5;

// setup() 函数在程序开始时只执行一次
// 通常用于初始化引脚模式、串口通信等操作
void setup()
{
    // 使用 for 循环来设置多个 LED 引脚为输出模式
    // 从 ledMark 开始，到 ledMark + num 结束（不包含 ledMark + num）
    for (int i = ledMark; i < ledMark + num; i++) {
        // 将引脚 i 设置为输出模式，以便可以控制该引脚的电平
        pinMode(i, OUTPUT);
    }
}

// loop() 函数在 setup() 函数执行完毕后会不断循环执行
// 主要用于实现程序的核心逻辑
void loop()
{
    // 点亮所有 LED
    // 使用 for 循环依次点亮每个 LED
    for (int i = ledMark; i < ledMark + num; i++) {
        // 将引脚 i 的电平设置为高电平，即点亮该 LED
        digitalWrite(i, HIGH);
        // 延迟 50 毫秒，让 LED 保持点亮状态一段时间
        delay(50);
    }

    // 熄灭所有 LED
    // 使用 for 循环依次熄灭每个 LED
    for (int i = ledMark; i < ledMark + num; i++) {
        // 将引脚 i 的电平设置为低电平，即熄灭该 LED
        digitalWrite(i, LOW);
        // 延迟 50 毫秒，让 LED 保持熄灭状态一段时间
        delay(50);
    }
}