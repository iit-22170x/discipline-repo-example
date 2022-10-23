# Описание первой лабораторной работы
Суть короче в том, что надо было написать скрипт в формате:
scriptname dirpath logname
Где scriptname -- название скрипта, dirpath -- папка назначения, logname -- имя log-файла
В задании требовалось найти все txt-файлы в dirpath и записать их имена в отсортированном порядке в logname.

# bat

@echo off -- Отключения ненужного вывода
setlocal -- локальные переменные

cd. > %2 -- создание log-файла

for %%i in (%1\*.txt) do ( -- цикл по txt файлам дирректории
	echo %%~ni >> %2 -- запись короткого имени файла в дирректорию
)

sort %2 -- сортировка

echo New file has been created -- вывод сообщения

# sh

#!/bin/bash -- 

rm $2 
touch $2 -- пересоздание log-файла (если скрипт вызывается повторно)

for file in $1/*.txt -- 
do
	echo cd $(basename $file) >> $2
done

sort $2

echo New file has been created