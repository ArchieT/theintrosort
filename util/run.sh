#!/bin/bash
echo "Wybrano plik $1"
echo "o długości" `wc -l $1` "linii"
echo "Budowanie i uruchamianie na pliku" $1 "…";
echo "Odpalam 'make theintrosort'…"
make theintrosort;
echo "Skończył już 'make theintrosort'"
echo "Przypominam, nazwa pliku to $1"
echo "Usuwam plik $1.out …"
rm $1.out
echo "Usunięto $1.out"
echo "Teraz robię echo nazwy pliku, pipe'ując ją do wykonywalnego…"
time (echo $1 | ./theintrosort);
echo "Skończył."
#echo "Odpalam more na oucie…"
#more $1.out;
echo "Odpalam check: sort -c $1.out …"
sort -nc $1.out
echo "Zakończono wszystko."
