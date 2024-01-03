<p align = "center">
  <img src = "https://img.shields.io/badge/Qt_Creator-5.0.2-41CD52?style=plastic&logo=Qt&labelColor=black" alt = "Qt Version">
</p>

Компьютер с N (3) процессорами должен решить M (16) заданий. Каждое i-ое (i=1..M) задание может выполняться на любом процессоре без прерывания своей работы за некоторое априори заданное время. Это время генерируется в начальном состоянии случайным образом на интервале Т1 — Т2 (2-8) с равномерным распределением вероятностей. Предварительно все задания пользователь выстраивает в очередь. После этого задачи запускаются на выполнение, т.е. Делается прогон. Первая в очереди задача становится на выполнение на первом свободном процессоре без какой-либо задержки. Работа заканчивается при выполнении последнего задания, при этом для прогона фиксируется распределение задач в исходной очереди и суммарное время их выполнения. Состояние системы при самом прогоне должно отображаться в реальном времени. Прогон можно начать заново, формируя другую очередь при сохранении времен выполнения заданий. Если время выполнения при очередном прогоне будет лучше, то его параметры (последовательность и суммарное время) заменяют лучший предыдущий результат.
Следует также предусмотреть переход в начальное состояние (без перезапуска приложения), в котором задаются новые параметры системы (не обязательно все).
