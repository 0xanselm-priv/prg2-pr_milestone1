# prg2-pr
## Ausführung
Es wird ein mindestens C++11-Compiler sowie `make` benötigt, um dieses Projekt zu kompilieren. Hierzu führen Sie auf einem Unix-System
```
make
./out.x
```
im Ordner GoL für das Game of Life in einer Konsolenfassung, copy_arrays für das Kopieren der Arrays, im Ordner Krypto für die visuelle Kryptographie und in `pwd` für die GUI-Anwendung, aus. Auf Windows-Systemen ist die zweite Zeile entsprechend angepasst.

##Krypto
To usex^

## Projektteam
Andreas Haupt (hat an GoL und Copy Arrays gearbeitet, Arbeitszeit 13 Stunden). Robert hat für die Integration der beiden Programmteile in Qt und der damit verbundenen Anpassungen ungefähr 40-45 Stunde Arbeitszeit verbracht.
## Bekannte Fehler
 - Random doesn't work on every system. https://github.com/skeeto/fantasyname/issues/11
 - GoL: Eingabe von `n` > `s` und einer illegalen Eingabe wie `"a"` führt in eine Endlosschleife.

- GUI
- How to Start: Projekt Datei Laden. Build Project -> Run. 
- 1) Game of Life kann lediglich ein Spielfeld einlesen und visualisieren. Ausserdem können Zellen angeclickt und mit "Next round" invertiert werden. QTimer wurde aufgrund von Probleme mit der Speicherung des Automaten als Attribut in der Klasse nicht realisiert. 
- 2) Crypto: Die Buttons sind für den User nach intendierter Reihenfolge enabled und so zu bedienen. Es gibt die Möglichkeit eine Random Matrix zu erzeugen. Aber erst nachdem eine Matrix geladen wurde, da die Random Matrix die selbe Dimesion hat. 
