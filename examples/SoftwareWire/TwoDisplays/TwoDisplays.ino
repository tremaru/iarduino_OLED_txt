// ПРИМЕР РАБОТЫ С ДВУМЯ ДИСПЛЕЯМИ НА ОДНОЙ ШИНЕ I2C:                  //
// Требуется установить библиотеку <iarduino_I2C_Software.h>           // https://iarduino.ru/file/627.html
                                                                       //
// Адреса дисплеев должны быть разными (меняются переключателем).      //
                                                                       //
// Если ваш дисплей не умеет менять адрес, то создайте несколько       //
// программных шин I2C и подключите каждый дисплей к своей шине:       //
// #include <iarduino_I2C_Software.h>                                  // Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_OLED.
// SoftTwoWire sWire_1(3,4);                                           // Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
// SoftTwoWire sWire_2(5,6);                                           // Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
// iarduino_OLED myOLED_1(0x3C); // Нужно указать адрес вашего дисплея // Объявляем объект myOLED_1, указывая адрес дисплея на первой программной шине I2C.
// iarduino_OLED myOLED_2(0x3C); // Нужно указать адрес вашего дисплея // Объявляем объект myOLED_2, указывая адрес дисплея на второй программной шине I2C.
// myOLED_1.begin(&sWire_1);                                           // Инициируем работу с первым дисплеем, указав ссылку на объект для работы с шиной I2C на которой находится дисплей (по умолчанию &Wire).
// myOLED_2.begin(&sWire_2);                                           // Инициируем работу с вторым дисплеем, указав ссылку на объект для работы с шиной I2C на которой находится дисплей (по умолчанию &Wire).
                                                                       //
// Можно использовать несколько аппаратных шин I2C, см. примеры        //
// iarduino_OLED/HardwareWire/...                                      //
// Допускается комбинировать программные и аппаратные шины I2C.        //
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
iarduino_OLED_txt myOLED_1(0x3C);                                      // Объявляем объект myOLED_1, указывая адрес первого дисплея на шине I2C: 0x3C.
iarduino_OLED_txt myOLED_2(0x3D);                                      // Объявляем объект myOLED_2, указывая адрес второго дисплея на шине I2C: 0x3D.
                                                                       // 
void setup(){                                                          //
     myOLED_1.begin  (&sWire);                                         // Инициируем работу с первым дисплеем, указав ссылку на объект для работы с шиной I2C на которой находится дисплей (по умолчанию &Wire).
     myOLED_2.begin  (&sWire);                                         // Инициируем работу с вторым дисплеем, указав ссылку на объект для работы с шиной I2C на которой находится дисплей (по умолчанию &Wire).
     myOLED_1.setFont(MediumFontRus);                                  // Указываем шрифт который требуется использовать для вывода цифр и текста на первом дисплее.
     myOLED_2.setFont(MediumFontRus);                                  // Указываем шрифт который требуется использовать для вывода цифр и текста на втором дисплее.
     myOLED_1.print  ("1 дисплей", OLED_C, 3);                         // Выводим текст на первый дисплей по центру 3 строки (высота шрифта 2 строки, он займёт строки 2 и 3).
     myOLED_2.print  ("2 дисплей", OLED_C, 3);                         // Выводим текст на второй дисплей по центру 3 строки (высота шрифта 2 строки, он займёт строки 2 и 3).
     myOLED_1.setFont(SmallFontRus);                                   // Указываем шрифт который требуется использовать для вывода цифр и текста на первом дисплее.
     myOLED_2.setFont(SmallFontRus);                                   // Указываем шрифт который требуется использовать для вывода цифр и текста на втором дисплее.
     myOLED_1.print  ("Адрес дисплея 0x3C", OLED_C, 5);                // Выводим текст на первый дисплей по центру 5 строки (высота шрифта 1 строка).
     myOLED_2.print  ("Адрес дисплея 0x3D", OLED_C, 5);                // Выводим текст на второй дисплей по центру 5 строки (высота шрифта 1 строка).
}                                                                      //
                                                                       //
void loop(){}                                                          //
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