#define qtdColors 3

#define buttonRed 2
#define buttonYellow 3
#define buttonBlue 4

#define ledRed 5
#define ledYellow 6
#define ledBlue 7

void setup()
{
    Serial.begin(9600);
    randomSeed(analogRead(0));
    pinMode(buttonRed, INPUT);
    pinMode(buttonYellow, INPUT);
    pinMode(buttonBlue, INPUT);

    pinMode(ledRed, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledBlue, OUTPUT);
}

int sequence[qtdColors];
int playerSequence[qtdColors];
int lightVelocity = 500;

void generateSequence(int (&sequence)[qtdColors])
{
    for (int i = 0; i < qtdColors; i++)
    {
        sequence[i] = random(ledRed, ledBlue + 1);
    }
}
int getPress()
{
    if (digitalRead(buttonRed))
    {
        return buttonRed;
    }
    if (digitalRead(buttonYellow))
    {
        return buttonYellow;
    }
    if (digitalRead(buttonBlue))
    {
        return buttonBlue;
    }
    return 0;
}

void sequencePressed(int (&sequence)[qtdColors])
{
    int pressedButton = 0;
    int cont = 0;
    while (cont < qtdColors)
    {
        pressedButton = getPress();
        if (pressedButton != 0)
        {
            Serial.print("Pressed button: ");
            Serial.println(pressedButton);
            sequence[cont] = pressedButton;
            cont++;
            delay(100);
          	pressedButton = 0;
        }
    }
}

bool compareSequences(int (&sequence)[qtdColors], int (&playerSequence)[qtdColors])
{
    for (int i = 0; i < qtdColors; i++)
    {
        if (sequence[i]-qtdColors != playerSequence[i])
        {
            return false;
        }
    }
    return true;
}

void showSequence(int (&sequence)[qtdColors])
{
    for (int i = 0; i < qtdColors; i++)
    {
        digitalWrite(sequence[i], HIGH);
        delay(lightVelocity);
        digitalWrite(sequence[i], LOW);
        delay(lightVelocity);
    }
}
void flashLed()
{
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledBlue, HIGH);
    delay(500);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledBlue, LOW);
    delay(1000);
}
void loop()
{
    Serial.println("Initializing sequence...");
    generateSequence(sequence);
    showSequence(sequence);
    sequencePressed(playerSequence);
    if (!compareSequences(sequence, playerSequence))
    {
        flashLed();
        lightVelocity = 500;
    }
    else
    {
        lightVelocity -= 25;
    }
}
