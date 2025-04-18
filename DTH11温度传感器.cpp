#include <DHT.h>
// 引入DHT库，这个库提供了与DHT系列温湿度传感器（包括DHT11、DHT22等）进行交互的函数和功能。
// 只有引入了这个库，我们才能使用其中定义好的类和方法来读取传感器数据。

// 定义DHT传感器的类型为DHT11
#define DHTTYPE DHT11
// 使用宏定义来指定传感器的类型是DHT11。DHT系列有不同型号的传感器，这里明确告诉程序我们使用的是DHT11。

// 定义DHT11连接的引脚，这里假设连接到数字引脚2
#define DHTPIN 2
// 同样是宏定义，用来指定DHT11传感器的数据引脚连接到Arduino UNO R3的数字引脚2。
// 实际连接时，如果连接到了其他引脚，需要修改这里的数字，同时代码中与引脚相关的操作才会对应正确的硬件引脚。

DHT dht(DHTPIN, DHTTYPE);
// 创建一个名为dht的DHT类对象，通过传入前面定义好的引脚号（DHTPIN ）和传感器类型（DHTTYPE ）进行初始化。
// 这个对象后续会用于调用库中提供的函数来读取温湿度数据。

void setup() {
    Serial.begin(9600);
    // 初始化串口通信，设置波特率为9600。波特率决定了数据在串口上传输的速率。
    // 这里设置为9600，意味着Arduino和外部设备（比如连接的电脑串口监视器）
    // 之间将以这个速率来发送和接收数据，这样两边才能正确解析传输的信息。
    dht.begin();
    // 调用dht对象的begin()函数来启动DHT传感器。
    // 这一步是让传感器准备好工作，初始化内部的一些参数和状态，以便后续能正常读取数据。
}

void loop() {
    // 等待2秒钟，让传感器稳定
    delay(2000);
    // 调用delay()函数让程序暂停执行2000毫秒（即2秒）。
    // 因为DHT11传感器在通电或刚进行一些操作后，可能需要一点时间来稳定工作，获取准确的测量值。
    // 等待一段时间可以提高数据读取的准确性和稳定性。

    // 读取湿度数据
    float humidity = dht.readHumidity();
    // 调用dht对象的readHumidity()函数来读取当前环境的湿度数据。
    // 这个函数会从传感器获取湿度信息，并将其转换为一个浮点数返回，然后赋值给humidity变量。

    // 读取温度数据
    float temperature = dht.readTemperature();
    // 调用dht对象的readTemperature()函数来读取当前环境的温度数据。
    // 同理，该函数获取温度信息并转换为浮点数返回，赋值给temperature变量。

    // 检查是否读取成功
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }
    // isnan()是一个判断是否为“非数字（Not a Number）”的函数。
    // 因为如果传感器读取数据失败，返回的可能是一个特殊的非数字值（NaN ）。
    // 这里通过判断humidity和temperature变量是否为NaN，来确定传感器是否成功读取到数据。
    // 如果是NaN，说明读取失败，通过Serial.println()在串口打印错误信息“Failed to read from DHT sensor!”，
    // 然后使用return语句直接结束本次循环，不再执行后面打印数据的代码。

    // 打印温度和湿度数据
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F(" %\tTemperature: "));
    Serial.print(temperature);
    Serial.println(F(" °C"));
    // 当传感器成功读取到数据后，通过一系列的Serial.print()函数，
    // 按照指定的格式将湿度值和温度值打印到串口监视器上。
    // Serial.print()函数用于在串口上输出内容，不换行；Serial.println()函数输出内容后会换行。
    // 这里先打印描述性文字，再打印实际的测量数值，方便在串口监视器上查看和识别数据。
}