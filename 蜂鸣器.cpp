int buzzer = 2;//设置控制蜂鸣器的数字引脚对应开发板上的引脚2
void setup()
{
    pinMode(buzzer, OUTPUT);//设置对应的输出模式
}
void loop()
{
    unsigned char i, j;//定义变量
    while (1)
    {
        for (i = 0; i < 50; i++)//输出一个频率的声音
        {
            digitalWrite(buzzer, HIGH);//高电平打开蜂鸣器，使其发声
            delay(1);//延时1ms，通过这个延时可以改变声音的频率
            digitalWrite(buzzer, LOW);//低电平关闭蜂鸣器，使其不发声音
            delay(1);//延时1ms，通过这个延时可以改变声音的频率
        }
        for (i = 0; i < 50; i++)//输出另一个频率的声音
        {
            digitalWrite(buzzer, HIGH);//高电平打开蜂鸣器，使其发声
            delay(5);//延时5ms，通过这个延时可以改变声音的频率
            digitalWrite(buzzer, LOW);//低电平关闭蜂鸣器，使其不发声音
            delay(5);//延时5ms，通过这个延时可以改变声音的频率
        }
    }
}