Цей варіант программи доволі простий тому я туди всунув ООП.  

##Вступ в ооп 
Загалом ООП було створенно для того,  аби программістам менше писати код і робити написані программи безпечніші.  Тобто сенс в тому аби групувати код котрий виконує подібні дії в коремі класси.  Власне класс можно розглядати як креслення,  по якому виконують якийсь обьект реального світу.  Тобто в нас є креслення машини по якій ми можемо зібрати готовий екземпляр. Класс містить конструктор і деструктор  - це методи котрі викликаються при створенні об'єкту і при його знищенні відповідно.  Окрім того в нього існують поля - змінні котрі належать классу і доуступні у всіх його елементах. Функції котрі належать классу називаються методами.  усі елементи класу мають модифікатор області видимості - публічні,  приватні та захищені.  елементи,  помічені публічним типом доступу видимі по всьому проєкту,  приватні  - доступні тільки в середині классу,  а захищені - в середині классу та классів,  котрі наслідються від ньього.  Це сторення з метою виконання принципу інкапсуляції(принципу коли скривається реалізація классу від зовнішнього середовище. Потрібно аби інші елементи не отримували надлишкової інформації про роботу классу і  він варіювати певні внутрішні алгоритми,  не викликаючи необхідності переписувати решту коду.)

Окрім того можно використати іншу метафору. Розглядати программу, написану в стилі ООП як певну організацію. В організаціях є різноманітні посади,  їх визначають посадові інструкції.  Подекуди в  конкретних посадах згадаються інші посади і способи взаємодії з ними,  подекуди посадові інструкції "наслідують" одна іншу,  наприклад старший викладач повинен робити те ж,  що і звичайни викладач,  але на додачу і ряд інших,  спецівічних речей. Власе інструкції і є класами.  А якщо брати ідеальних,  абстрактних робітників - вони являють собою обєкти - реалізації цих інструкцій в житті. В цій метафорі теж можна віднайти принцип інкапсуляції - наприклад виклад програмування вчить студентів С++,  як він вчить це вже його справа,  але викладач по матлозіці розраховує на знання програмування в студентів в своїй практиці. Тобто фактично вони взаємодіють один з одним(викладачі) але влазити в справи викладання чужого предмету ніхто не будет,  тому що викладач інкапсулює(скрива) власні методи викладання і інші можуть керуватись тільки загальним протоколом, в котрому написано що мають знати студенти.  В цій метафорі також можна розглянути абстрагування - в нас є декілька викладачів,  котрі викладають один і той же предмет,  але оскільки вони викладають його по одній і тій самій программі(інструкції) то інші викладачі можть розраховувати на знання студентів,  незалежно того,  хто читав цей предмет. Знову ж таки в ідеальній системі все))) 
 
##Аналіз того що потрібно робити
Спочатку намагаємось визначити які задаі нам слід вирішити в программі.  Перше  - нам потрібно розібрати вхідні данні,  друге - це класс предиката в котрому реалізована власне логіка предікату і третє - потрібно виконати завдання і вивести значення предикату після того як до нього примінили квантори. Для цього реалізуємо 3 різних класси.  

##Розробка классу для обробки предикату 
```C++
class Predicat {
public:
    Predicat(char *line);
    char *getPredicatSource();
    bool getvalue();

private:
    const int MAX_LINE_LENGTH = 1024;

    char *line;
    int VOWEL_LETTERS_COUNT = 40;
    char *vowelLetters;
    bool calculatePredicat(char *input);
    bool checkWord(char *input,int length);

    int cachedValue=-1;
};
```
Класс предикату буде містити логіку,  котра буде визначати предикат і данні на яких він працює.  Тобто класс в конструктор передається строка,  котра являється конкретним значенням змінної х,  вибраного з предметної області.  Метод getPredicatSource використовується для того аби вивести на консоль данні, котрі оброблює предикат.  І метод getvalue поверта власне значення предикату - результат підстановки данних,  переданих в конструктор в формулу.  
Метод calculatePredicat  обраховує значення предикату по вхідній строці.  Але його винесено в приватну область видимості. Це зроблено для того,  аби предикат сам управляв вичесленнями і міг наприклад кешувати(зберігати) значення,  котрі він вирахував раніше - такий прийом один з способів реалізовувати інкапсуляцію в реальному житті.  
Решта елементів ніби зрозуміла.  
Переходимо до коду - реалізації заголовку: 


```C++
#include "Predicat.h"
#include <iostream>

using namespace std;

Predicat::Predicat(char *line) {

    vowelLetters = new char[VOWEL_LETTERS_COUNT]{'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'
            ,'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};

    this->line = line;
    cachedValue = calculatePredicat(line);
}


bool Predicat::calculatePredicat(char *input) {
    int spacesCount = 0;
    int begin = 0;
    int end = 0;
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        end++;
        if (input[i] == ' ' || input[i] == '\0') {
            spacesCount++;
            if (spacesCount % 2 == 1 && checkWord(input + begin, (end - begin)))
                return true;
            begin = end;
        }
        if (input[i] == '\0')
            break;
    }
    return false;
}

bool Predicat::checkWord(char *input, int length) {
    cout << "check word :: '";
    for (int i = 0; i < length; i++)
        cout << input[i];

    int vowelLetterCount = 0;
    for (int i = 0; i < length; i++) {
        for (int c = 0; c < VOWEL_LETTERS_COUNT; c++) {
            if (vowelLetters[c] == input[i]) {
                vowelLetterCount++;
                break;
            }
        }
    }
    cout << "' count vowel :: " << vowelLetterCount << endl;
    return vowelLetterCount > (length - vowelLetterCount);
}

char *Predicat::getPredicatSource() {
    return line;

}

bool Predicat::getvalue() {
    if(cachedValue == -1)
        cachedValue = calculatePredicat(line);
    return cachedValue!=0;
}
```

Розглянемо конструктор більш детально. В ньому відбувається ініціалізація списка приголосних(велих та маленьких)
Зберігається посилання на данні для придикату. Ключеве слово ```C++ this``` використовується для отримання посилання на єкземпляр классу,  з яким зараз відбувається робота.  
Також в конструкторі предикату вичисляється його значення,  відповідно до змінної,  яку він отримав.  Це значення записується в кеш - змінну.  Це можливо за рахунок того що клас інкапсулював метод розрахунку і може наступного разу коли потрібно буде отримати значення не вираховувати його наново а повернути те,  що знаходится в кеші. При цьому якщо виникне потреба не працювати з кешом,  а кожного раху розраховувати нове значення,  то зміни в коді будуть лише локально, в классі предикату.  
```C++
Predicat::Predicat(char *line) {

    vowelLetters = new char[VOWEL_LETTERS_COUNT]{'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'
            ,'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};

    this->line = line;
    cachedValue = calculatePredicat(line);
}
```

###Пояснення як працює предикат 
*Тоюто на початку ми заводимо 3 змінні - позиція пробілу на початку слова(а) позицію пробіла на його кінці(б) і кількість віднайдених пробілів(н). На початку всі 3 змінні рівні нулю.  Далі рухаємось почергово по кожному символу строки і збільшуємо на 1 змінну б,  лишаючи без змін а, і як тільки ми знаходимо пробіл ми збільшуємо на 1 Н. перевіряємо,  якщо Н не парне значить це потрібно нам слово і сиволи між а і б відправляємо на подальшу обробку. Незалежно від парності Н ми а присвоюємо б тому що ми вже шукаємо наступне слово і для нього початком буде кінець попереднього :

```C++
bool Predicat::calculatePredicat(char *input) {
    int spacesCount = 0;
    int begin = 0;
    int end = 0;
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        end++;
        if (input[i] == ' ' || input[i] == '\0') {
            spacesCount++;
            if (spacesCount % 2 == 1 && checkWord(input + begin, (end - begin)))
                return true;
            begin = end;
        }
        if (input[i] == '\0')
            break;
    }
    return false;
}
```
*Тепер про перевірку слова.  Нам потрібно перевірити всі символи і підрахувати кількість приголосних.  Тобто потрібно пройтись по кожній літері слова і в той момент коли відбувається перевірка вказаної літери порівняти її з кожним елементом з списку приголосних.  Якщо літера,  яку перевіряють є в списку приголосних - значить вона приголосна і тому можна збільшити кількість приголосних на 1.  Після перевірки всіх літер слова,  ми матимо змінну з кількість приголосних.  Оскільки ми маємо кількістьв сіх літер то ми можемо вирахувати кількість голосних(все що не приголосне це голосне))))) ) і видати результат 
```C++
bool Predicat::checkWord(char *input, int length) {
    cout << "check word :: '";
    for (int i = 0; i < length; i++)
        cout << input[i];

    int vowelLetterCount = 0;
    for (int i = 0; i < length; i++) {
        for (int c = 0; c < VOWEL_LETTERS_COUNT; c++) {
            if (vowelLetters[c] == input[i]) {
                vowelLetterCount++;
                break;
            }
        }
    }
    cout << "' count vowel :: " << vowelLetterCount << endl;
    return vowelLetterCount > (length - vowelLetterCount);
}
```

##Розробка парсеру файлу
В нас є предикат,  але він залежить від строки,  котра буде вхідним параметром.  Нам потрібно десь брати цю строку. Для цього напишемо клас PredicatParser.  Він буде відповідати за те,  щоб розібрати файл і повернути список об'єктів типу Predicat котрі будуть являти собою вираз над значенням змінної з області значень предикату(тобто файлу).  Що нам потрібно для того аби клас роботи з файлом працював коректно. Сам файл.  А якщо бути точним - шлях до нього. Тому конструктор класу буде приймати строку,  що буде містити шлях до файлу. Приймемо на формат файлу наступний набір правил перша строка - кількість строк в ньому,  а кожна подальша - окрема строка(окреме значення предметної змінни з області значень). Окрім того що ми прочитали з файл данні,  нам потрібно надати можливість оперувати ними в зручному форматі - тобто у вигляді списка предикатів. Тобто отримаємо наступний хедер: 
```C++
class PredicatParser {
public:
    PredicatParser(char *fileName);
    virtual ~PredicatParser();
    std::vector<Predicat *> getParsedPredicat();

private:
    char **input;
    int countLine =0;
    std::vector<Predicat*> predicats;


    const int MAX_LINE_LENGTH = 1024;


};
```

Розглянемо його реалізацію: 

```C++
#include "PredicatParser.h"
#include <fstream>
#include <iostream>

using namespace std;

PredicatParser::PredicatParser(char *fileName) {

    ifstream in(fileName);
    in >> countLine;
    input = new char *[countLine];

    for (int i = 0; i < countLine; i++) {
        input[i] = new char[MAX_LINE_LENGTH];
    }

    in.getline(input[0], MAX_LINE_LENGTH);
    for (int i = 0; i < countLine; i++) {
        in.getline(input[i], MAX_LINE_LENGTH);
        cout << input[i] << endl;
    }
    in.close();
}

PredicatParser::~PredicatParser() {
    for (int i = 0; i < countLine; i++)
        delete[] input[i];
    delete[] input;

}

std::vector<Predicat*> PredicatParser::getParsedPredicat() {
    if(predicats.size() == 0)
        for(int i=0;i<countLine;i++)
            predicats.push_back(new Predicat(input[i]));
    return predicats;
}
```
Як можна помітити більшість дій відбувається в конструкторі.  Спочатку прояснемо декілька моментів.  Для зберігання предикатів використовуємо  ```C++ std::vector<Predicat*>``` тобто вектором з посилан на обьект предикату.  Вектор використаний тому що з ним зручно працювати,  а посилання на об'єкт замість власне самого обьекта використані тому,  що так простіше, якщо робити без них нам потрібно писати конструктор компіювання, а це поки що лишемо на потім.  
Тепер  ближче до коду - ми читаємо кількість строк в файлі,  далі ми "в холосту" in.getline(input[0], MAX_LINE_LENGTH); для того,  аби уникнути повторного читання.  і далі в циклі читаємо стоки з файли і зберігаємо їх.  
В методі getParsedPredicat  ми перевіряємо список предикатів,  якщо він порожній,  значить ми нічого туди ще не внесли а значить потрібно перетворити список вхідних строк на список параметрів.  Знову ж таки скриття реалізації дозволяє нам відносно просто маніпалювати кодом(прочитати і одразу перетворити його в список предикатів,  або ж прочитати і перетворити за потреби і зберегти результат для подальшого використання,  або ж ні і перетворювати список вхідних строк кожен раз)

##Процесор предикатів
Лишилось написати класс котрий буде приміняти до предикатів квантори. Тобто що нам потрібно для того аби він працював. Для того аби визначити значення висловлювання утровреного внаслідок використання кванторів нам потрібно значти значення предикату для кожного елементу з предметної області.  Тобто клас повинен приймати список об'єктів типу Predicat котрі і будуть представляти ці значення. Окрім того нам потрібні методи для отримання значення висловлювання після використання квантаров загальності і існування до предикату і його заперечення,  тобто ще чотири методи. Керуючись цим отримуємо наступний заголовочний файл: 
```C++
class PredicatProccessor {
public:
    PredicatProccessor(vector<Predicat *> predicats);
    virtual  ~PredicatProccessor();

    bool getCommonKvantor();
    bool getExistKvanotor();
    bool getCommonKvantorAnti();
    bool getExistKvantorAnti();

private:
    vector<Predicat*> predicats;
    bool *predicatCache;

};
```
Переходимо для реалізації: 
```C++
PredicatProccessor::PredicatProccessor(vector<Predicat*> predicats) {
    this->predicats = predicats;
    predicatCache = new bool[predicats.size()];
    for (int i = 0; i < predicats.size(); i++)
        predicatCache[i] = predicats[i]->getvalue();

    for (int i = 0; i < predicats.size(); i++) {
        cout << "predicat :: " << predicats[i]->getPredicatSource() << " = " << predicats[i]->getvalue() << endl;
    }
}

PredicatProccessor::~PredicatProccessor() {
    delete[] predicatCache;
}

bool PredicatProccessor::getCommonKvantor() {
    bool  result = true;
    for(int i=0;i<predicats.size();i++)
        result &= predicatCache[i];
    return result;
}

bool PredicatProccessor::getExistKvanotor() {
    bool  result = false;
    for(int i=0;i<predicats.size();i++)
        result |= predicatCache[i];
    return result;
}

bool PredicatProccessor::getCommonKvantorAnti() {
    bool  result = true;
    for(int i=0;i<predicats.size();i++)
        result &= (!predicatCache[i]);
    return result;
}

bool PredicatProccessor::getExistKvantorAnti() {
    bool  result = false;
    for(int i=0;i<predicats.size();i++)
        result |= (!predicatCache[i]);
    return result;
}
```

В конструкторі ми отримуємо значення пердикатів і зберігаємо в клокальному масиві, аби надалі працювати з внутрішним форматом данних,  який нам повинен бути зручнішим.  
*Для того аби образувати значення квантору загальністі нам потрібно щоб всі значення предикату бли правдиві. Це реалізовано в методі getCommonKvantor. Що для цього потрібно зробити? Фактично ми повинні повернути значення виразу в якому значення предикатів за кожної змінної поєднанні логічним і. Тобто щось на кштал ```C++ predicatCache[0]&&predicatCache[1]&&predicatCache[2] ...``` Проте це можна зробити лише у випадку,  коли кількість значень фіксовані.  Оскільки ми маємо справу з довільною кількість потрібно той же вираз розписати через цикл.  Ми без проблем це можемо представити у вигляді ```C++ result = predicatCache[0]&&predicatCache[1] result = result&&predicatCache[2]... ``` Отож кінцевий варіант матиме наступний вигляд: 
```C++
bool  result = true;
    for(int i=0;i<predicats.size();i++)
        result &= predicatCache[i];
    return result;
```
result має значення  true на початку з тієї причини, що нам потрібно присвоїти змінній котресь значення і таке,  щоб не вплинуло на розрахунки.  Данне значення жодним чином не вплива,  оскільки якщо серед значень предикатів я хибні то і результуюча змінна прийме хибне значення. 
*Для того аби арганізувати метод для квантора існування нам потрібно віднайти серед значень хоча б одне правдиве. Тобто ми можимо використати прийом з попереднього завдання,  але замість логічного і використаємо логічне або.  І врешті решт отримаємо наступний код: 
```C++
bool  result = true;
    for(int i=0;i<predicats.size();i++)
        result &= (!predicatCache[i]);
    return result;
```
*Для квантора загальності заперечення предикату нам потрібно аби всі значення предикату були хибними,  тому модифікуємо код метода для віднайдення квантору загальності так аби логічне і поєднувало не самі значення, а їх заперечення.  Отримаємо наступний код:
```C++
 bool  result = true;
    for(int i=0;i<predicats.size();i++)
        result &= (!predicatCache[i]);
    return result;
```
*Квантор існування заперечення предикату дасть істене висловлювання в випадку коли знайдеться хоч одна змінна,  котра перетворює предикат на хибне висловлювання.  Тобто ми можемо модифікувати код для віднайдення предикату існування так, щоб логічне або поєднувало не самі значення предикату,  а їх заперечення.  Отримаємо наступне: 
```C++
bool  result = false;
    for(int i=0;i<predicats.size();i++)
        result |= (!predicatCache[i]);
    return result;
```
##Збирання все докупи 
В нас є набір інструментів,  котрий містить і інкапсуляцію значення предикату з змінної, і інструмет для отриамння множини значень з файл, і власне операції над предикатом.  Лишилось зібрати це докупи.  Це зробимо в функції main:
```C++
 	char *fileName = "/Users/yurabraiko/dev/temp/c++/matLogic5_Ann/test.txt";
    PredicatParser parser(fileName);
    vector<Predicat *> predicatList = parser.getParsedPredicat();
    PredicatProccessor proccessor(predicatList);
    cout << "______________________________________________________________" << endl;
    cout << "common kvantor result :: " << proccessor.getCommonKvantor() << endl;
    cout << "exist kvantor result :: " << proccessor.getExistKvanotor() << endl;
    cout << "common kvantor with negativ result :: " << proccessor.getCommonKvantorAnti() << endl;
    cout << "exist kvantor with negativ result :: " << proccessor.getExistKvantorAnti() << endl;
    cout << "______________________________________________________________";
    return 0;
```
Ми спочатку створюємо об'єкт парсера, передаючи в конструктор шлях до файлу з данними.  Далі отримуємо список з значень предикату при кожній з змінних предметної області і записуємо в змінну predicatList. Після того ініціалізуємо процесор предикатів цим списком.  І Нарешті виводимо значення,  відповідно до завдання.  

##Приклад виводу: 

```C++
csdacsd asddm aod
csdacsd asddm aodsd
rtrtrtrtrttrtraaa ssasaaaaaaaa ooooososooooo
check word :: 'csdacsd ' count vowel :: 6
check word :: 'csdacsd ' count vowel :: 6
check word :: 'rtrtrtrtrttrtraaa ' count vowel :: 14
predicat :: csdacsd asddm aod = 1
predicat :: csdacsd asddm aodsd = 1
predicat :: rtrtrtrtrttrtraaa ssasaaaaaaaa ooooososooooo = 1
______________________________________________________________
common kvantor result :: 1
exist kvantor result :: 1
common kvantor with negativ result :: 0
exist kvantor with negativ result :: 0
______________________________________________________________
```
