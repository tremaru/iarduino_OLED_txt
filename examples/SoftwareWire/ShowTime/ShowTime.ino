// ПРИМЕР ВЫВОДА ВРЕМЕНИ С МОМЕНТА СТАРТА СКЕТЧА:                      //
// Требуется установить библиотеку <iarduino_I2C_Software.h>           // https://iarduino.ru/file/627.html
                                                                       //
// OLED экран 128×64 / 0,96" (Trema-модуль):                           // https://iarduino.ru/shop/displays/ekran-0-96-128x64-oled-i2c-belyy.html
// Информация о подключении модулей к шине I2C:                        // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                          // https://wiki.iarduino.ru/page/OLED_trema/
// Библиотека   iarduino_OLED_txt (текстовая  ) экономит ОЗУ:          // https://iarduino.ru/file/341.html
// Библиотека   iarduino_OLED     (графическая):                       // https://iarduino.ru/file/340.html
                                                                       //
#include <iarduino_I2C_Software.h>                                     // Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_OLED_txt.
SoftTwoWire sWire(3,4);                                                // Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
                                                                       //
#include <iarduino_OLED_txt.h>                                         // Подключаем библиотеку iarduino_OLED_txt.
iarduino_OLED_txt myOLED(0x3C);                                        // Объявляем объект myOLED, указывая адрес дисплея на шине I2C: 0x3C или 0x3D.
                                                                       //
uint32_t i;                                                            // Объявляем переменную для хранения времени прошедшего с момента старта скетча.
int h, m, s;                                                           // Объявляем переменную для хранения времени в часах, минутах и секундах.
                                                                       //
void setup(){                                                          //
     myOLED.begin(&sWire);                                             // Инициируем работу с дисплеем, указав ссылку на объект для работы с шиной I2C на которой находится дисплей (по умолчанию &Wire).
     myOLED.setFont(MediumFont);                                       // Указываем шрифт который требуется использовать для вывода цифр и текста.
}                                                                      //
                                                                       //
void loop(){                                                           //
     i=millis();                                                       // Получаем количество миллисекунд прошедшее с момента старта скетча.
     if(i%1000==0){ delay(1);                                          // Выполняем скетч 1 раз в секунду. Так как условие истинно в течении 1 миллисекунды, то устанавливаем задержку в 1 миллисекунду.
         i/=1000; h=i/60/60%24; m=i/60%60; s=i%60;                     // Рассчитываем часы, минуты и секунды.
                                    myOLED.setCursor(16,4);            // Устанавливаем курсор в 16 столбец 4 строки.
         if(h<10){myOLED.print(0);} myOLED.print(h);                   // Выводим часы прошедшие с момента старта скетча, в формате ЧЧ.
                                    myOLED.print(":");                 // Выводим текст состоящий из одного символа «:»
         if(m<10){myOLED.print(0);} myOLED.print(m);                   // Выводим минуты прошедшие с момента старта скетча, в формате ММ.
                                    myOLED.print(":");                 // Выводим текст состоящий из одного символа «:»
         if(s<10){myOLED.print(0);} myOLED.print(s);                   // Выводим секунды прошедшие с момента старта скетча, в формате СС.
     }                                                                 //
}                                                                      //
                                                                       //
/*   ДОСТУПНЫЕ ШРИФТЫ:                                                 // Шрифты можно менять и добавлять в файле: src/DefaultFonts.h
 *   SmallFont                                                         // Маленький шрифт  6x8  ( 95 символов) только латиница
 *   SmallFontRus                                                      // Маленький шрифт  6x8  (176 символов) латиница и кириллица
 *   MediumFont                                                        // Средний   шрифт 12x16 ( 95 символов) только латиница
 *   MediumFontRus                                                     // Средний   шрифт 12x16 (176 символов) латиница и кириллица
 *   MediumNumbers                                                     // Средние   цифры 12x16 ( 13 символов) 0123456789./-
 *   BigNumbers                                                        // Большие   цифры 14x24 ( 13 символов) 0123456789./-
 *   MegaNumbers                                                       // Большие   цифры 24x40 ( 13 символов) 0123456789./-
 */