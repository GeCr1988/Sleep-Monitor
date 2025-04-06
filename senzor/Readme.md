# Sleep Monitor Sensor

## Configurare Fișier Secret.h

Pentru a configura conexiunea Wi-Fi, trebuie să creați un fișier `Secret.h` în directorul proiectului **senzor**. Acest fișier trebuie să conțină următoarele definiții:

```cpp
#define WIFI_SSID "WIFI SSID"
#define WIFI_PASSWORD "WIFI PASS"
```

### Instrucțiuni:
1. Înlocuiți `WIFI SSID` cu numele rețelei Wi-Fi la care doriți să vă conectați.
2. Înlocuiți `WIFI PASS` cu parola rețelei Wi-Fi.

> **Notă:** Fișierul `Secret.h` nu trebuie să fie inclus în controlul versiunilor (de exemplu, Git) pentru a proteja informațiile sensibile. Adăugați `Secret.h` în fișierul `.gitignore` al proiectului.