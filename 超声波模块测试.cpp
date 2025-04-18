// ���峬����ģ���Trig���ź�Echo����
#define Trig 2
#define Echo 3

// ��ȡ����ĺ���
float getDistance() {
    // ȷ��Trig���ų�ʼΪ�͵�ƽ�������󴥷�������
    digitalWrite(Trig, LOW);  
    delayMicroseconds(2);     // �ȴ�2΢�룬ȷ���ȶ�

    // ��Trig���ŷ���һ��10΢��ĸߵ�ƽ���壬��������������
    digitalWrite(Trig, HIGH); 
    delayMicroseconds(10);    // ����10΢��
    digitalWrite(Trig, LOW);  // �����ߵ�ƽ����

    // ʹ��pulseIn��������Echo���ŵĸߵ�ƽ����ʱ�䣨��λ��΢�룩
    // ��ͨ����ʽ��ʱ��ת��Ϊ���루��λ�����ף�
    float distance = pulseIn(Echo, HIGH) / 58.00; 

    delay(10); // ��ʱ10���룬����������������
    return distance; // ���ز����ľ���ֵ
}

// ��ʼ��������������һ��
void setup() {
    Serial.begin(9600); // ��ʼ������ͨ�ţ�������Ϊ9600
    pinMode(Trig, OUTPUT); // ����Trig����Ϊ���ģʽ
    pinMode(Echo, INPUT);  // ����Echo����Ϊ����ģʽ
}

// ��ѭ����������������
void loop() {
    // ����getDistance������ȡ���벢ͨ�����ڴ�ӡ
    Serial.print(getDistance()); // ��ӡ�����ľ���ֵ
    Serial.println(" cm");       // ��ӡ��λ��cm��
}