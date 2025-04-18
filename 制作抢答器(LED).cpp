
// 定义开发板上的引脚 2
int redled = 2;
// 定义开发板上的引脚3用于连接黄色LED
int yellowLed = 3;
// 定义开发板上的引脚4用于连接绿色LED
int greenLed = 4;
// 定义开发板上的引脚5用于连接红色LED
int redLed = 5;
// 定义引脚6作为控制红色LED灯的按键
int yellowKey = 6;
// 定义引脚7作为控制黄色LED灯的按键
int greenKey = 7;
// 定义引脚8作为控制绿色LED灯的按键
int redKey = 8;
// 定义引脚8作为复位按键
int resetKey = 8;
// 初始化函数，在程序开始运行时执行一次
void setup() {
    // 将连接红色LED的引脚设为输出模式
    pinMode(redLed, OUTPUT);
    // 将连接黄色LED的引脚设为输出模式
    pinMode(yellowLed, OUTPUT);
    // 将连接绿色LED的引脚设为输出模式
    pinMode(greenLed, OUTPUT);
    // 将控制红色LED灯的按键引脚设为输入上拉模式
    pinMode(redKey, INPUT_PULLUP);
    // 将控制黄色LED灯的按键引脚设为输入上拉模式
    pinMode(yellowKey, INPUT_PULLUP);
    // 将控制绿色LED灯的按键引脚设为输入上拉模式
    pinMode(greenKey, INPUT_PULLUP);
    // 将复位按键引脚设为输入上拉模式
    pinMode(resetKey, INPUT_PULLUP);
}
// 主循环函数，程序会不断重复执行其中的代码
void loop() {
    // 判断控制红色LED灯的按键是否被按下，若被按下，则执行以下代码
    if (digitalRead(redKey) == LOW)
        RED();
    // 判断控制黄色LED灯的按键是否被按下，若被按下，则执行以下代码
    if (digitalRead(yellowKey) == LOW)
        YELLOW();
    // 判断控制绿色LED灯的按键是否被按下，若被按下，则执行以下代码
    if (digitalRead(greenKey) == LOW)
        GREEN();
}
// 控制红色LED相关操作的函数
void RED() {
    // 判断reset按键是否被按下，如果被按下，将跳出当前的while循环，进行clear()函数
    while (digitalRead(resetKey) == 1)
    {
        // 红色LED灯亮起
        digitalWrite(redLed, HIGH);
        // 绿色LED灯熄灭
        digitalWrite(greenLed, LOW);
        // 黄色LED灯熄灭
        digitalWrite(yellowLed, LOW);
    }
    clear();//熄灭所有小灯
}
// 控制黄色LED相关操作的函数
void YELLOW() {
    // 判断reset按键是否被按下，如果被按下，将跳出当前的while循环，进行clear()函数
    while (digitalRead(resetKey) == 1)
    {
        // 红色LED灯熄灭
        digitalWrite(redLed, LOW);
        // 绿色LED灯熄灭
        digitalWrite(greenLed, LOW);
        // 黄色LED灯亮起
        digitalWrite(yellowLed, HIGH);
    }
    clear();//熄灭所有小灯
}
// 控制绿色LED相关操作的函数
void GREEN() {
    // 判断reset按键是否被按下，如果被按下，将跳出当前的while循环，进行clear()函数
    while (digitalRead(resetKey) == 1)
    {
        // 红色LED灯熄灭
        digitalWrite(redLed, LOW);
        // 绿色LED灯亮起
        digitalWrite(greenLed, HIGH);
        // 黄色LED灯熄灭
        digitalWrite(yellowLed, LOW);
    }
    clear();//熄灭所有小灯
}
// 熄灭所有LED灯的函数
void clear() {
    // 红色LED灯熄灭
    digitalWrite(redLed, LOW);
    // 绿色LED灯熄灭
    digitalWrite(greenLed, LOW);
    // 黄色LED灯熄灭
    digitalWrite(yellowLed, LOW);
}
