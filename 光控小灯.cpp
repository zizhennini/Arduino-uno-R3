
// 定义一个整型变量 led，用于存储LED连接的引脚编号，这里LED连接到数字引脚 2
int led = 2;
// 定义一个整型变量 lightR，用于存储模拟传感器连接的引脚编号，这里传感器连接到模拟引脚 14
int lightR = 14;
// 定义一个整型变量 val，用于存储从模拟传感器读取到的值
int val;


// setup() 函数是Arduino程序的初始化函数，在程序开始运行时仅执行一次
void setup() {
    // 将 led 引脚设置为输出模式，意味着该引脚可以用来输出高电平或低电平以控制外部设备（如LED）
    pinMode(led, OUTPUT);
    // 将 lightR 引脚设置为输入模式，意味着该引脚用于读取外部设备（如模拟传感器）的信号
    pinMode(lightR, INPUT);
    // 初始化串口通信，设置波特率为 9600bps，用于与计算机或其他设备进行数据传输
    Serial.begin(9600);
}


// loop() 函数是Arduino程序的主循环函数，在 setup() 函数执行完毕后，该函数会不断循环执行
void loop() {
    // 从 lightR 引脚读取模拟值，并将其存储到变量 val 中。模拟值的范围通常是 0 - 1023
    val = analogRead(lightR);
    // 通过串口将读取到的模拟值以文本形式发送出去，同时换行，方便在串口监视器中查看
    Serial.println(val);
    // 程序暂停执行 1000 毫秒（即 1 秒），避免过于频繁地读取传感器值和更新LED状态
    delay(1000);
    // 判断读取到的模拟值是否大于 500
    if (val > 500) {
        // 如果模拟值大于 500，则将 led 引脚设置为高电平，点亮连接在该引脚上的 LED
        digitalWrite(led, HIGH);
    }
    else {
        // 如果模拟值小于等于 500，则将 led 引脚设置为低电平，熄灭连接在该引脚上的 LED
        digitalWrite(led, LOW);
    }
}
