#IPK proect

## Popis
Byl udelan podle zadani Http server poskytuje informace o zarizeni na krem bejzi: nazev, nazev proceru,
zatez procesoru.


## Preklad
Pro preklad spustite make file prikazem:
``
make
``
## Spusteni
```
$ ./hinfosvc <port>
```
**Port** je nutnym argumentem a muze byt v rozhrani od 1 do 65535

## Vyuzite 
Pro komunikace s serverom je mozne vyzit prohlížeč nebo konsolne aplikace ktera pro zasylane Get zaprosu napriklad 
- wget 
- curl

Server podporuje **GET** a **HEAD** zaprosy. Pro přijímání dat z serveru je nutno zaslat **GET** zapros na url adres.

### Priklady vyziti
Pro priklady bude vyzen nastroj curl, IP adresem je local host a port nastavlen na 12345

####Zyskani jmena serveru
```
$ curl http://localhost:12345/hosname 
```
####Zyskani modelu cpu servera
```
$ curl http://localhost:12345/cpu-name
```
####Zyskani zatížení CPU
```
$ curl http://localhost:12345/load 
```

Kdyz server je spusten pro komunicace s nim lze vyuzit prohlížeč nebo konsolne aplicace 
дописать команды и смпособ ужития да  
