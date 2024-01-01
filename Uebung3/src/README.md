# PostfixInterpreter

Postfix Interpreter mit Templates und Concepts

## Vorgehensweise

- Attribute der Klasse IntegerInterpreter in IntegerInterpreter.h ergänzen.
- Instanzmethode von IntegerInterpreter direkt in IntegerInterpreter.h implementieren.
- Unit-Tests aus UnitTest1.cpp ausführen.
- Klasse PostfixInterpreter in GenericInterpreter.hpp ausprogrammieren.
- Unit-Tests aus UnitTest2.cpp und UnitTest3.cpp ausführen.
optional:
- Klasse PostfixInterpreter in VariadicInterpreter.hpp ausprogrammieren.
- Unit-Tests aus UnitTest4.cpp ausführen.

### Verwendung von Visual Studio

- Alle Projekteinstellungen sind schon vorgenommen. Einfach PostfixInterpreter.sln öffnen.
- Führen Sie wiederholt ```Rebuild All``` aus, um sicherzustellen, dass alles fehlerfrei kompiliert und keine Warnungen mehr erscheinen.
- Unit-Tests ausführen: Öffnen Sie den Test-Explorer und führen Sie die Unit-Tests aus UnitTest und UnitTest2 aus.
- Performance-Applikation starten: Mit der rechten Maustaste auf Performance klicken und "Set as Startup Project" auswählen. Anschliessend ausführen. 
- Für die Laufzeitmessungen müssen Sie die optimierte Release-Konfiguration verwenden.

### Verwendung von CMake

CMakeLists.txt ist so aufgebaut, dass das Google-Test-Framework heruntergeladen und installiert wird und dass eine Applikation (UnitTest2) erstellt wird.
Führen Sie im Projektverzeichnis folgende Befehle aus:
```
cmake .
cmake --build .
./UnitTest2/UnitTest2
```

