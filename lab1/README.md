# Описание первой лабораторной работы
Суть короче в том, что надо было написать скрипт в формате:
`scriptname dirpath logname`
Где `scriptname`  название скрипта, `dirpath` папка назначения, `logname` имя log-файла
В задании требовалось найти все txt-файлы в `dirpath` и записать их имена в отсортированном порядке в `logname`.

## bat
```
@echo off
setlocal

cd. > %2 

for %%i in (%1\*.txt) do (
    echo %%~ni >> %2
)
sort %2

echo New file has been created
```
С помощью `@echo off` отключаем ненужный вывод. `setlocal` делает все новые переменные по умолчанию  локальными. Далее идёт запуск цикл по всем txt-файлам, и запись их короткого имени в log-файл. Командой `sort` сортируем строки в файле. Выводим сообщение *New file has been created*

## sh

```
#!/bin/bash

rm $2 
touch $2

for file in $1/*.txt
do
	echo cd $(basename $file) >> $2
done

sort $2

echo New file has been created
```

Получаем доступ к интерпретатору bash (для Unix-систем) строкой `#!/bin/bash`. С `rm` и `touch` пересоздаём файл, на случай, если используем скрипт повторно. Аналогично с bat цикл по txt файлам указанной дирректории.