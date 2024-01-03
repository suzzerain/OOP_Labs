<p align = "center">
  <img src = "https://img.shields.io/badge/Qt_Creator-5.0.2-41CD52?style=plastic&logo=Qt&labelColor=black" alt = "Qt Version">
</p>

![image](https://github.com/suzzerain/OOP_Labs/assets/101402419/17000705-2bd3-4bbc-b189-c153e1628691)
Рис.1. Диаграмма классов работы №1

## Создать консольное приложение согласно представленной на рис.1 диаграмме классов, предназначенное для заданных вычислений над квадратной матрицей, заданной на **множестве вещественных чисел**. Для этого необходимо специфицировать пользовательские классы "Консольное приложение" и "Квадратная матрица", т.е. задать атрибуты и методы указанных классов, а также распределить их по существующим областям видимости.  Спецификация классов и реализация их методов должна обеспечивать реализацию отношений, указанных на диаграмме классов.
## Приложение должно включать основной модуль (функция main), модуль «application» и модуль «matrix».
### В **основном модуле** консольного приложения (для языка С++ - это модуль с функцией main) должен создаваться объект класса "Консольное приложение" и вызываться его метод, который предоставляет пользователю **меню команд** приложения.
### Модуль **«application»** должен содержать спецификацию класса "Консольное приложение" и реализацию его методов. Один из его методов должен выводить в консоль меню команд приложения, включающее:
- команду, инициирующую ввод с консоли значений, задающих объект матрицы (до ввода в программе должна быть задана матрица по умолчанию);
- команду, инициирующую расчет определителя матрицы и вывод результатов расчета;
- команду, инициирующую формирования транспонированной матрицы и ее вывода в консоль;
- команду, инициирующую расчет ранга матрицы и вывод результатов расчета;
- команду, инициирующую представление в консоль текущего объекта матрицы;
- команду выхода из приложения.
## Модуль **«matrix»** должен содержать спецификацию класса "Квадратная матрица" и реализацию его методов, необходимых для достижения цели разрабатываемого приложения. Описание класса должно использовать вместо типа double (вещественное число, заданное в условии) абстрактный тип **number**, описание которого должно задаваться в отдельном заголовочном файле number.h с помощью оператора **typedef double number** (для С++).
### _ВАЖНО_. Основное требование к реализации класса **«matrix»** заключается в том, что она должна быть инвариантна (одна и та же для различных вариантов использования) ко множеству применимых объектов. Здесь задано множество определения элементов матрицы как вещественное, а может быть и множества целых, комплексных, рациональных и т.д. Для различных множеств при сохранении функциональности реализация класса должна быть одна и та же. Если для различных множеств менять реализацию, то теряется смысл ООП как парадигмы.
