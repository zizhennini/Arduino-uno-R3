int led = 2;  //���忪�����ϵ�����2����LED��
int flag = 0; //����һ����������¼LED����������Ϩ��
int shengyin = 3; //���������������Ŀ�������

void setup()
{
    pinMode(led, OUTPUT);  //����LED��Ϊ���ģʽ
    pinMode(shengyin, INPUT);  //����������������Ϊ����ģʽ
}

void loop()
{
    if (digitalRead(shengyin) == HIGH)  //�ж��Ƿ��⵽�����ź�
    {
        if (flag == 0)
        {
            flag = 1;  //��־LED������
            digitalWrite(led, HIGH);  //��Ӧ��LED������
        }
        else
        {
            flag = 0;  //��־LED��Ϩ��
            digitalWrite(led, LOW);  //��Ӧ��LED��Ϩ��
        }
        delay(1000);  //��ʱ
    }
}