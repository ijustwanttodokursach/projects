Проект на C, эмулятор Shell для ос Linux, реализовано выполнение команд, запуск исполняемых файлов, перенаправление потоков 
из стандартного вывода одного процесса на стандартный ввод другого процесса (можно создавать цепочки из неограниченного
числа перенаправлений с помощью |, программно реализовано с помощью pipe и функции dup2) 
Реализован вывод результата программы на файл, смена рабочей директории.
Программа разбивает входную команду на подкоманды, разделённые вертикальной чертой. Если встречается знак > происходит
запись в файл и продолжается исполнение других подкоманд. Для каждой подкоманды создаётся pipe, в который перенаправляется
вывод предыдущей команды.
Выход осуществляется по команде exit.