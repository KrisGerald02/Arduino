#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Definir el tamaño de la pantalla OLED
#define SCREEN_WIDTH 128  // Ancho de la pantalla en píxeles
#define SCREEN_HEIGHT 64  // Alto de la pantalla en píxeles

// Dirección del display OLED
#define OLED_RESET -1  // No se usa el pin de reset
#define SCREEN_ADDRESS 0x3C  // Dirección I2C del OLED

// Inicializar el objeto de la pantalla OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Datos del bitmap
static const unsigned char PROGMEM sunfounderIcon[] = {
  // Aquí iría el array de bytes del icono (lo has incluido correctamente)
};

// Definir el pin del sensor DHT y el tipo de sensor
#define DHTPIN 5  // Pin donde está conectado el sensor DHT
#define DHTTYPE DHT11  // Tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);  // Inicializar el sensor DHT11

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);
  dht.begin();

  // Inicializar la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Error al iniciar el OLED"));
    for (;;);
  }

  display.clearDisplay();  // Limpiar la pantalla

  // Configurar el texto para la pantalla OLED
  display.setTextSize(1);  // Tamaño del texto
  display.setTextColor(WHITE);  // Color del texto
  display.setCursor(0, 28);  // Establecer posición del cursor
  display.println("¡Hola Mundo!");
  display.display();  // Mostrar el texto
  delay(2000);
  display.clearDisplay();  // Limpiar la pantalla
}

void loop() {
  // Leer los datos de temperatura y humedad
  delay(2000);  // Esperar 2 segundos entre lecturas
  float h = dht.readHumidity();  // Leer humedad
  float t = dht.readTemperature();  // Leer temperatura en °C

  // Verificar si hubo un error en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer los datos del sensor DHT11");
    return;
  }

  // Mostrar los datos en el monitor serial
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");

  // Mostrar los datos en la pantalla OLED
  display.setTextSize(1);
  display.setCursor(0, 28);
  display.println("Temperatura:");
  display.display();
  display.setCursor(88, 28);
  display.println(t);
  display.display();

  display.setCursor(0, 45);
  display.println("Humedad:");
  display.display();
  display.setCursor(88, 45);
  display.println(h);
  display.display();

  delay(2000);  // Esperar 2 segundos antes de limpiar la pantalla
  display.clearDisplay();  // Limpiar la pantalla
}
