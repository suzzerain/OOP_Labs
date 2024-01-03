<p align = "center">
  <img src = "https://img.shields.io/badge/Qt_Creator-5.0.2-41CD52?style=plastic&logo=Qt&labelColor=black" alt = "Qt Version">
</p>

![image](https://github.com/suzzerain/OOP_Labs/assets/101402419/8abbd0be-9a0c-4b5a-aaf7-8554d71036b0)

<p align = "center"> Рис.3. Диаграмма классов работы №3 </p>

Создать GUI приложение, реализующее функции перечисленные в описании работы №1, но на множестве рациональных чисел. Для этого требуется разработать и реализовать класс рациональных чисел.

Рациональное число — это несократимая дробь a/b, где a и b — целые, причем b>0.

Приложение должно включать основной модуль, модуль «interface», модуль «matrix», модуль «rational» и файл number.h:
~~~
	#include «rational.h»
	typedef TRational number;
~~~
	
Основной модуль main.cpp GUI приложения может иметь вид:
~~~
		#include <QApplication>
		#include "interface.h"
		int main(int argc, char *argv[])
		{
		    QApplication a(argc, argv);
		    TInterface interface;
		    interface.show();
		    return a.exec();
		}
~~~

При необходимости расширения функциональности класса «Квадратная матрица» следует только дополнить его протокол без каких-либо изменений уже существовавшей реализации.
