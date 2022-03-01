#IPK project

## Popis
Podle zadání byl udělán Http server který poskytuje informace o zařízení na krém bejzi: název, název proceru,
zátěž procesoru.

Projekt implementován v jazyce C++ a byl vyzkušen objektno orentirovany přístup,

Server je spuštěn na zadanom portě a běží v nekonečném cyklu, a čeká na request a v závislosti od zaprosa odpoví.



## Překlad
Pro překlad spustíte make filé příkazem:
``
make
``
## Spuštění
```
$ ./hinfosvc 
```
**Port** je nutným argumentem a může být v rozhraní od 1 do 65535

## Využité
Pro komunikace s serverom je možné vyžít prohlížeč nebo konsolne aplikace pro zasylane Get zaprosu, například
- wget
- curl

Server podporuje **GET** a **HEAD** zaprosy. Pro přijímání dat z serveru je nutno zaslat **GET** zapros na url adres.

### Příklady vyžití
Pro příklady bude vyžeň nástroj curl, IP adresem je local host a port nastavlen na 12345

#### Zyskani jména serveru
```
$ curl http://localhost:12345/hosname 
```
#### Zyskani modelu cpu servera
```
$ curl http://localhost:12345/cpu-name
```
#### Zyskani zatížení CPU
```
$ curl http://localhost:12345/load 
```