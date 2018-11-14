# prg2-pr
## Ausführung von GoL

Es wird ein mindestens C++11-Compiler sowie `make` benötigt, um dieses Projekt zu kompilieren. Hierzu führen Sie auf einem Unix-System
```
make
./out.x
```
im Ordner `GoL/` für das Game of Life in einer Konsolenfassung aus.
## Ausführung von `copy_arrays`
Für das Kopieren von Arrays, führe 
```
g++ -o ./out.x copy_arrays.cpp
```
im Ordner `copy_arrays/` aus.

## Krypto
To use the krypto program, go to our folder and type 
```
"./visualcrypt *mode* *path1* *path2* *result_path*"
```
, where *mode* can stand for:
'encode' -> encryption with path1 = picture you want to encrypt; path2 = key for encryption; result_path = path of the operations result
'decode' -> decryption with path1 = picture you want to decrypt; path2 = key for decryption; result_path = path of the operations result
'overlay' -> overlaying two pictures with path1 = first picture; path2 = second picture; result_path = path of the operations result
For 'Aufgabe 2f)' just type "./visualcrypt". This will encrypt the two pictures with the same key and safe the result in the same folders, where the picture lies. This only works on my personal mac.

## Ausführen der GUI
Projekt Datei Laden. Build Project -> Run. 

## Projektteam
Andreas Haupt (hat an GoL und Copy Arrays gearbeitet, Arbeitszeit 13 Stunden). Robert hat für die Integration der beiden Programmteile in Qt und der damit verbundenen Anpassungen ungefähr 40-45 Stunden Arbeitszeit verbracht.
## Bekannte Fehler
 - Random doesn't work on every system. https://github.com/skeeto/fantasyname/issues/11
 - GoL: Eingabe von `n` > `s` und einer illegalen Eingabe wie `"a"` führt in eine Endlosschleife.
 - GUI: Game of Life kann lediglich ein Spielfeld einlesen und visualisieren. Ausserdem können Zellen angeclickt und mit "Next round" invertiert werden. QTimer wurde aufgrund von Probleme mit der Speicherung des Automaten als Attribut in der Klasse nicht realisiert. 
 - GUI: Crypto: Die Buttons sind für den User nach intendierter Reihenfolge enabled und so zu bedienen. Es gibt die Möglichkeit eine Random Matrix zu erzeugen. Aber erst nachdem eine Matrix geladen wurde, da die Random Matrix die selbe Dimesion hat. 
