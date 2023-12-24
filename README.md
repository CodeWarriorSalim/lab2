"RPSLS Game" (Rock-Paper-Scissors-Lizard-Spock Game).
### Компиляция и запуск

1. Убедитесь, что у вас установлен компилятор C++ (например, g++ для Linux или MinGW для Windows).
2. Откройте терминал и перейдите в директорию проекта.
3. Скомпилируйте исходные файлы с помощью следующей команды:
   g++ -o Game main.cpp GameCore.cpp DynamicChoice.cpp Rock.cpp Paper.cpp Scissors.cpp Lizard.cpp Spock.cpp ComputerPlayer.cpp -std=c++11
