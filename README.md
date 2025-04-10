# Sleep-Monitor
Aceasta este pagina pentru proiectul pentru concursul Mihai Konteschweller.

**Treci direct la ce te intereseaza**

+ Introducere - [Ce este proiectul?](#ce-este-proiectul) ----- [De ce am ales aceasta idee?](#de-ce-am-ales-aceasta-idee)
+ Despre somn - [Sleep research and heartrate research](#sleep-research-and-heartrate-research)
+ Schema - [Cum va arata mai exact?](#cum-va-arata-mai-exact)
+ Specificatii - [Care sunt componentele sale?](#care-sunt-componentele-utilizate) ---- [Specificatii componente](#specificatii-componente)
+ Codul pe care se bazeaza proiectul - [Cum functioneaza codul?](#cum-functioneaza-codul)

# Ce este proiectul?

Proiectul este crearea unui aparat neinvaziv care să poată monitoriza somnul, să preia date despre acesta și să le proceseze și să formeze "diagnostice" cât mai folositoare ale acestuia. De asemenea, poate fi folosit și pentru a estima stadiile de somn și pentru a trezi purtătorul în stadiul cel mai benefic, pentru ca acesta să se trezească odihnit. Dispozitivul poate detecta inconsistențe ale somnului, dar și ale pulsului și ale nivelului de oxigen din sânge și le poate semnala. În cazuri extreme, pot fi alertate rudele sau, în cazuri și mai extreme, chiar și serviciile de urgență.

# De ce am ales aceasta idee?

Motivul principal pentru această alegere a fost insatisfacția produsă de către opțiunile prezente pe piață și raporturile calitate-preț. Un alt motiv a fost faptul că doream o modalitate de a mă trezi în stadiul propice pentru a mă simți odihnit, întrucât știm cu toții momentele când dormim și 12 ore, de exemplu, dar tot obosiți ne trezim. Așa, te poți simți mai energic, fără să fie nevoie să dormi extrem de mult. Un ultim motiv a fost posibilitatea de a fi utilizat de către persoanele vârstnice sau cu diferite probleme, care nu pot fi monitorizate tot timpul, ca un fel de alertă pentru familiile lor sau chiar de salvare.

# Sleep research and heartrate research


# Cum va arata mai exact?

-imagine schema-  vs  -imagine finala-


# Care sunt componentele utilizate?

+ Microcontroller - ESP32
+ Pulsoximetru - MAX301020
+ Accelerometru - MPU6050
+ Microfon - MAX9814
+ baterie Li-Po, posibil nevoie modul BMS

adaugam si alte componente in functie de cum evolueaza treaba


# Specificatii componente

### Microcontroller - ESP32 ---- [datasheet](esp32_datasheet_en.pdf)

<details>
<summary>Despre ESP32</summary>
ESP32 este un sistem pe cip (SoC) de putere joasa, dezvoltat de Espressif Systems, care integrează atât Wi-Fi, cât și Bluetooth. Acest cip este utilizat pe scară largă în aplicații IoT (Internet of Things), dispozitive inteligente și sisteme embedded. Datorită arhitecturii sale avansate, care include mai multe nuclee de procesare, periferice versatile și un sistem eficient de gestionare a energiei, ESP32 este o soluție excelentă.

Unul dintre cele mai importante aspecte ale ESP32 este procesorul său Tensilica Xtensa LX6 cu două nuclee, care poate funcționa la o frecvență de până la 240 MHz. Acesta dispune de 520 KB de SRAM (Static RAM) și 8 KB de memorie RTC (Real Time Clock RAM) pentru gestionarea operațiunilor de joasă putere. De asemenea, suportă memorie externă flash și PSRAM (Pseudostatic RAM) de până la 16MB, oferind flexibilitate în dezvoltarea de aplicații complexe.

În ceea ce privește conectivitatea wireless, ESP32 integrează Wi-Fi 802.11 b/g/n pe banda de 2.4 GHz, permițând utilizatorilor să-l configureze atât în mod stație (client Wi-Fi), cât și punct de acces (AP mode) sau Wi-Fi Direct. Suportul pentru Bluetooth 4.2 și Bluetooth Low Energy (BLE) îl face ideal pentru aplicații care necesită consum redus de energie și comunicare rapidă între dispozitive.

Pe partea de periferice, ESP32 este echipat cu o gamă variată de interfețe care facilitează interacțiunea cu alte dispozitive. Dispune de 34 de pini GPIO[^1], ce pot fi configurați pentru PWM[^2], SPI[^3], I2C[^4], UART[^5] și alte funcționalități. De asemenea, include un ADC[^6] SAR[^7] de 12 biți, două canale DAC[^8] de 8 biți, senzori tactili capacitivi și un senzor de efect Hall. Aceste caracteristici îl fac extrem de versatil pentru aplicații variind de la controlul motoarelor și iluminatului inteligent la interfețe tactile avansate.

Un alt avantaj major al ESP32 este gestionarea inteligentă a consumului de energie, ceea ce îl face potrivit pentru dispozitive alimentate pe baterie. Cipul suportă mai multe moduri de operare cu consum redus de energie, inclusiv:

+ Mod activ, unde toate funcțiile sunt complet operaționale;
+ Modul de somn al modemului (Modem Sleep), unde conexiunile Wi-Fi și Bluetooth sunt menținute, dar consumul este redus;
+ Somn ușor (Light Sleep), unde procesorul este oprit, dar poate fi reactivat rapid;
+ Somn profund (Deep Sleep), în care consumul scade sub 10 µA, făcând ESP32 extrem de eficient energetic.

Din punct de vedere al securității, ESP32 oferă protecție avansată împotriva atacurilor informatice. Acesta include boot securizat, care împiedică rularea firmware-ului neautorizat, și criptare a memoriei flash, pentru protejarea datelor sensibile. De asemenea, dispune de acceleratoare criptografice hardware, compatibile cu AES[^9], SHA[^10] și RSA[^11], ceea ce îmbunătățește securitatea comunicațiilor și protejează împotriva atacurilor cibernetice.

În ceea ce privește caracteristicile electrice, ESP32 poate funcționa într-un interval de tensiune cuprins între 2.2V și 3.6V, iar consumul său variază în funcție de sarcină, de la 80 mA în modul activ până la sub 10 µA în modul Deep Sleep. Această eficiență energetică îl face ideal pentru dispozitive IoT care trebuie să funcționeze pe termen lung, fără reîncărcare frecventă a bateriei.

Din punct de vedere fizic, ESP32 este disponibil în mai multe formate, inclusiv module QFN[^12] și module WROOM. Dimensiunile sale variază în funcție de model. De asemenea, este capabil să funcționeze într-un interval larg de temperaturi, între -40°C și 85°C, ceea ce îl face potrivit pentru medii industriale sau condiții extreme.

Datorită acestor caracteristici, ESP32 este utilizat într-o gamă largă de aplicații, inclusiv automatizări inteligente pentru locuințe, ceasuri inteligente și dispozitive purtabile, electrocasnice inteligente, automatizări industriale și roboți. Versatilitatea sa îl face o alegere ideală pentru dezvoltatori care caută o soluție compactă, puternică și eficientă din punct de vedere energetic.

[^1]: general-purpose input output
[^2]: pulse-width modulation
[^3]: Serial Peripheral Interface
[^4]: Inter-Integrated Circuit
[^5]: Universasl asynchronous receiver-transmitter
[^6]: analog-to-digital converter
[^7]: successive-approximation-register
[^8]: digital-to-analog converter
[^9]: Advanced Encryption Standard
[^10]: Secure Hash Algorithms
[^11]: Rivest-Shamir-Adleman
[^12]: quad-flat no-leads

</details>

### Pulsoximetru - MAX301020 ---- [datasheet](max30102.pdf)

lorem ipsum

### Accelerometru - MPU6050 ---- [datasheet](MPU-6000-Datasheet1.pdf)

lorem ipsum

### Microfon - MAX9814 ---- [datasheet](max9814.pdf)

lorem  ipsum


# Cum functioneaza codul?

Gandirea din spatele unor chestii idk

## Footnotes
