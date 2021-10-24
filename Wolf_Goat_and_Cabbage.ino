/*Правила игры "Волк, Коза, Капуста":
 * Необходимо с левого берега реки переправить на правый волка, козу и капусту, причем одновременно на одном 
 * берегу не могут оставаться без крестьянина следующие объекты: Волк - Коза, Коза - Капуста, Волк - Коза - Капуста.  
 * Чтобы  переместить персонажей, воспользуйтесь кнопками, где кнопка 1 - Крестьянин, 2 - Волк, 3 - Коза, 4 - Капуста
 * При нажатии кнопки перемещения объекта(Волка, Козы, Капусты), он перемещается вместе с крестьянином.
 * Чтобы начать игру заново, нажмите кнопку RESET на ардуино.
 * Желаем удачи!
*/

#define ledPeasantL 5       // пин светодиода, обозначающего крестьянина на левом берегу
#define ledWolfL 4          // пин светодиода, обозначающего волка на левом берегу
#define ledGoatL 3          // пин светодиода, обозначающего козу на левом берегу
#define ledCabbageL 2       // пин светодиода, обозначающего капусту на левом берегу
#define ledPeasantR 6       // пин светодиода, обозначающего крестьянина на правом берегу
#define ledWolfR 7          // пин светодиода, обозначающего волка на правом берегу
#define ledGoatR 8          // пин светодиода, обозначающего козу на правом берегу
#define ledCabbageR 9       // пин светодиода, обозначающего капусту на правом берегу
#define ledWin 11           // пин светодиода, обозначающего выигрыш
#define ledLoss 10          // пин светодиода, обозначающего проигрыш
bool statePeasant;          // переменная состояния объекта "Крестьянин", где - 0 это левый берег, 1 - правый
bool stateWolf;             // переменная состояния объекта "Волк", где - 0 это левый берег, 1 - правый
bool stateGoat;             // переменная состояния объекта "Коза", где - 0 это левый берег, 1 - правый
bool stateCabbage;          // переменная состояния объекта "Капуста", где - 0 это левый берег, 1 - правый
bool win;                   // переменная выигрыша
bool loss;                  // переменная проигрыша
int buttonPeasant;          // переменная состояния кнопки "Крестьянин"
int buttonWolf;             // переменная состояния кнопки "Волк"
int buttonGoat;             // переменная состояния кнопки "Коза"
int buttonCabbage;          // переменная состояния кнопки "Капуста"
void setup() {
  pinMode(ledPeasantL, OUTPUT);     // назначаем цифровой пин 5 как выход (output)
  pinMode(ledPeasantR, OUTPUT);     // назначаем цифровой пин 6 как выход (output)
  pinMode(ledWolfL, OUTPUT);        // назначаем цифровой пин 4 как выход (output)
  pinMode(ledWolfR, OUTPUT);        // назначаем цифровой пин 7 как выход (output)
  pinMode(ledGoatL, OUTPUT);        // назначаем цифровой пин 3 как выход (output)
  pinMode(ledGoatR, OUTPUT);        // назначаем цифровой пин 8 как выход (output)
  pinMode(ledCabbageL, OUTPUT);     // назначаем цифровой пин 2 как выход (output)
  pinMode(ledCabbageR, OUTPUT);     // назначаем цифровой пин 9 как выход (output)
  pinMode(ledWin, OUTPUT);          // назначаем цифровой пин 11 как выход (output)
  pinMode(ledLoss, OUTPUT);         // назначаем цифровой пин 10 как выход (output)
  digitalWrite(ledPeasantL, HIGH);  // задаем начальную индикацию светодиода крестьянина на левом берегу
  digitalWrite(ledPeasantR, LOW);   // задаем начальную индикацию светодиода крестьянина на правом берегу
  digitalWrite(ledWolfL, HIGH);     // задаем начальную индикацию светодиода волка на левом берегу
  digitalWrite(ledWolfR, LOW);      // задаем начальную индикацию светодиода волка на правом берегу
  digitalWrite(ledGoatL, HIGH);     // задаем начальную индикацию светодиода козы на левом берегу
  digitalWrite(ledGoatR, LOW);      // задаем начальную индикацию светодиода козы на правом берегу
  digitalWrite(ledCabbageL, HIGH);  // задаем начальную индикацию светодиода капусты на левом берегу
  digitalWrite(ledCabbageR, LOW);   // задаем начальную индикацию светодиода капсуты на правом берегу
  digitalWrite(ledWin, LOW);        // задаем начальную индикацию светодиода выигрыша
  digitalWrite(ledLoss, LOW);       // задаем начальную индикацию светодиода проигрыша
}

void loop() {
  
    buttonPeasant = analogRead(A6); // считываем и записываем состояние кнопки "Крестьянин". Если кнопка нажата, значение на аналоговом пине равно 1023 
    buttonWolf = analogRead(A5);    // считываем и записываем состояние кнопки "Волк". Если кнопка нажата, значение на аналоговом пине равно 1023 
    buttonGoat = analogRead(A4);    // считываем и записываем состояние кнопки "Коза". Если кнопка нажата, значение на аналоговом пине равно 1023 
    buttonCabbage = analogRead(A3); // считываем и записываем состояние кнопки "Капуста". Если кнопка нажата, значение на аналоговом пине равно 1023
    
if (win == false && loss == false){ // условие, при котором игра продолжается (не выиграли и не победили)

  if (stateWolf == 0 &&  stateGoat == 0 && stateCabbage ==0 && statePeasant == 1) {digitalWrite(ledLoss, HIGH); loss = true;}  // описываем условия проигрыша 
  if (stateWolf == 0 &&  stateGoat == 0 && stateCabbage ==1 && statePeasant == 1) {digitalWrite(ledLoss, HIGH); loss = true;}  // описываем условия проигрыша 
  if (stateWolf == 1 &&  stateGoat == 0 && stateCabbage ==0 && statePeasant == 1) {digitalWrite(ledLoss, HIGH); loss = true;}  // описываем условия проигрыша 
  if (stateWolf == 1 &&  stateGoat == 1 && stateCabbage ==1 && statePeasant == 0) {digitalWrite(ledLoss, HIGH); loss = true;}  // описываем условия проигрыша 
  if (stateWolf == 1 &&  stateGoat == 1 && stateCabbage ==0 && statePeasant == 0) {digitalWrite(ledLoss, HIGH); loss = true;}  // описываем условия проигрыша 
  if (stateWolf == 0 &&  stateGoat == 1 && stateCabbage ==1 && statePeasant == 0) {digitalWrite(ledLoss, HIGH); loss = true;}  // описываем условия проигрыша 

  if (stateWolf == 1 &&  stateGoat == 1 && stateCabbage ==1 && statePeasant == 1) {digitalWrite(ledWin, HIGH); win = true;}    // описываем условия выигрыша
  
  if (buttonPeasant == 1023) {                // если кнопка нажата, перемещаем крестьянина
    delay (300);                              // задержка для корректной обработки нажатия кнопки
    digitalWrite(ledPeasantL, statePeasant);  // управляем светодиодом крестьянина слева
    statePeasant = !statePeasant;             // инвертируем значения статуса крестьянина
    digitalWrite(ledPeasantR, statePeasant);  // управляем светодиодом крестьянина справа
  }
  
  if (buttonWolf == 1023 && stateWolf == statePeasant){                    // если кнопка нажата и крестьянин с волком находятся на одном берегу, перемещаем обоих
    delay (300);                              // задержка для корректной обработки нажатия кнопки
    digitalWrite(ledWolfL, stateWolf);        // управляем светодиодом волка слева
    digitalWrite(ledPeasantL, statePeasant);  // управляем светодиодом крестьянина слева
    stateWolf = !stateWolf;                   // инвертируем значения статуса волка
    statePeasant = !statePeasant;             // инвертируем значения статуса крестьянина
    digitalWrite(ledWolfR, stateWolf);        // управляем светодиодом волка справа
    digitalWrite(ledPeasantR, statePeasant);  // управляем светодиодом крестьянина справа
  }
  
  if (buttonGoat == 1023 && stateGoat == statePeasant){                    // если кнопка нажата и крестьянин с козой находятся на одном берегу, перемещаем обоих
    delay (300);                              // задержка для корректной обработки нажатия кнопки
    digitalWrite(ledGoatL, stateGoat);        // управляем светодиодом козы слева
    digitalWrite(ledPeasantL, statePeasant);  // управляем светодиодом крестьянина слева
    stateGoat = !stateGoat;                   // инвертируем значение статуса козы
    statePeasant = !statePeasant;             // инвертируем значение статуса крестьянина
    digitalWrite(ledGoatR, stateGoat);        // управляем светодиодом козы справа
    digitalWrite(ledPeasantR, statePeasant);  // управляем светодиодом крестьянина справа
  }
  
  if (buttonCabbage == 1023 && stateCabbage == statePeasant){               // если кнопка нажата и крестьянин с капустой находятся на одном берегу, перемещаем обоих
    delay (300);                              // задержка для корректной обработки нажатия кнопки
    digitalWrite(ledCabbageL, stateCabbage);  // управляем светодиодом капусты слева
    digitalWrite(ledPeasantL, statePeasant);  // управляем светодиодом крестьянина слева
    stateCabbage = !stateCabbage;             // инвертируем значение статуса капусты
    statePeasant = !statePeasant;             // инвертуруем значение статуса крестьянина
    digitalWrite(ledCabbageR, stateCabbage);  // управляем светодиодом капусты справа
    digitalWrite(ledPeasantR, statePeasant);  // управляем светодиодом крестьянина справа
  }
  
}}
