int led = 2;  //定义开发板上的引脚2控制LED灯
int flag = 0; //定义一个变量，记录LED灯是亮起还是熄灭
int shengyin = 3; //定义声音传感器的控制引脚

void setup()
{
    pinMode(led, OUTPUT);  //定义LED灯为输出模式
    pinMode(shengyin, INPUT);  //定义声音控制引脚为输入模式
}

void loop()
{
    if (digitalRead(shengyin) == HIGH)  //判断是否检测到声音信号
    {
        if (flag == 0)
        {
            flag = 1;  //标志LED灯亮起
            digitalWrite(led, HIGH);  //对应的LED灯亮起
        }
        else
        {
            flag = 0;  //标志LED灯熄灭
            digitalWrite(led, LOW);  //对应的LED灯熄灭
        }
        delay(1000);  //延时
    }
}