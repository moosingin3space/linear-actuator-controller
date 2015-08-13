const int RELAY_A = 2;
const int RELAY_B = 3;

const int EXTEND = 1;
const int RETRACT = 2;
const int STOP = 3;
const int ACK = 6;

void setup()
{
    Serial.begin(115200);
    pinMode(RELAY_A, OUTPUT);
    pinMode(RELAY_B, OUTPUT);

}

void extend()
{
    digitalWrite(RELAY_A, HIGH);
    digitalWrite(RELAY_B, LOW);
}

void retract()
{
    digitalWrite(RELAY_A, LOW);
    digitalWrite(RELAY_B, HIGH);
}

void stop()
{
    digitalWrite(RELAY_A, LOW);
    digitalWrite(RELAY_B, LOW);
}

void loop()
{
    if (Serial.available() > 0)
    {
        int command = Serial.read();
        switch (command)
        {
            case EXTEND:
                extend();
                break;
            case RETRACT:
                retract();
                break;
            case STOP:
                stop();
                break;
            default:
                break;
        }
        Serial.write(ACK);
    }
}
