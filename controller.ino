// Pinos correspondentes para cada botao
enum Buttons
{
    Left = 2,
    Up,
    Down,
    Right,
    Select,
    Start,
    B,
    A,
    Count
};

// Array de strings com os nomes dos botoes (apenas para depuracao)
const String BUTTON_NAMES[] = {
    "Left",
    "Up",
    "Down",
    "Right",
    "Select",
    "Start",
    "B",
    "A"
};

void setup()
{
    Serial.begin(9600);
    
    // Configura todos os pinos de entrada
    for(int i = Buttons::Left;i < Buttons::Count;i++){
        pinMode(i, INPUT_PULLUP);
    }
}

void loop()
{ 
    // Envia pela saida serial o nome de cada botao e 1 caso esteja pressionado ou 0 caso contrario
    for(int i = Buttons::Left;i < Buttons::Count;i++){ 
        Serial.println(BUTTON_NAMES[i - Buttons::Left] + " " + !digitalRead(i));
    }

    // Espera 1s para realizar a proxima leitura (apenas para depuracao)
    // delay(1000);
}
