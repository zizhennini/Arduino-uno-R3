int buzzer = 2;//���ÿ��Ʒ��������������Ŷ�Ӧ�������ϵ�����2
void setup()
{
    pinMode(buzzer, OUTPUT);//���ö�Ӧ�����ģʽ
}
void loop()
{
    unsigned char i, j;//�������
    while (1)
    {
        for (i = 0; i < 50; i++)//���һ��Ƶ�ʵ�����
        {
            digitalWrite(buzzer, HIGH);//�ߵ�ƽ�򿪷�������ʹ�䷢��
            delay(1);//��ʱ1ms��ͨ�������ʱ���Ըı�������Ƶ��
            digitalWrite(buzzer, LOW);//�͵�ƽ�رշ�������ʹ�䲻������
            delay(1);//��ʱ1ms��ͨ�������ʱ���Ըı�������Ƶ��
        }
        for (i = 0; i < 50; i++)//�����һ��Ƶ�ʵ�����
        {
            digitalWrite(buzzer, HIGH);//�ߵ�ƽ�򿪷�������ʹ�䷢��
            delay(5);//��ʱ5ms��ͨ�������ʱ���Ըı�������Ƶ��
            digitalWrite(buzzer, LOW);//�͵�ƽ�رշ�������ʹ�䲻������
            delay(5);//��ʱ5ms��ͨ�������ʱ���Ըı�������Ƶ��
        }
    }
}