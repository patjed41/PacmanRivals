# Wymaganie niefunkcjonalne

## Dostępność

Aplikacja jest uruchamiana na jednym komputerze i nie wymaga dostępu do Inernetu, więc jest zawsze dostępna.

## Niezowodność

Aplikacja z prawdopodobieństwem 99,99% działa bezawaryjnie podczas jednej rozgrywki.

## Wydajność

Aplikacja systematycznie wyświetla przynajmniej 60 klatek na sekundę. Jest testowana na komputerze z:
- systemem Linux Mint 19.3
- procesorem Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz
- kartą graficzną Iris Plus Graphics G7

## Przenośność

Aplikacja wspiera następujące dystrybucje systemu Linux:
- Ubuntu 18.04+
- Mint 19.3+
- Manjaro 21.2.5+

## Wymagania techniczne
- rozdzielczość ekranu przynajmniej 1920x1080
- klawiatura
  - potrzebna do obsługi interfejsu
  - umożliwia sterowanie maksymalnie dwu graczom
- kontrolery
  - umożliwiają sterowanie nawet czterem graczom
  - konieczne, gdy graczy jest więcej niż dwóch
- biblioteki i narzędzia zainstalowane na komputerze użytkownika:
  - SFML 2.4.2+
  - xboxdrv - biblioteka potrzebna do obsługi kontrolerów
  - CMake 3.10.2+
