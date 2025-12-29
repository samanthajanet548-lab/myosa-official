/* --- Libraries --- */
#include <LightProximityAndGesture.h>
#include <oled.h>
#include <Wire.h>
#include <BarometricPressure.h>   // Added BMP180 library

/* --- Configuration --- */
const int LIGHT_THRESHOLD = 30; // Threshold for "Low Light"
const int BUZZER_PIN = 18;       // Choose a digital pin for buzzer (e.g., D8)

/* --- Object Creation --- */
LightProximityAndGesture Lpg;
oLed display(SCREEN_WIDTH, SCREEN_HEIGHT);
BarometricPressure Pr(ULTRA_HIGH_RESOLUTION); // BMP180 object

void setup() {
  /* 1. Initialize Communication */
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(100000);

  /* 2. Initialize OLED Display */
  if(!display.begin()) {
    Serial.println("OLED allocation failed");
    while(1); // Stop here if OLED fails
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.display();

  /* 3. Initialize Light Sensor */
  Serial.println("Connecting to Myosa Sensor...");
  while (true) {
    if(Lpg.begin()) {
      Serial.println("Light sensor connected!");
      break;
    }
    Serial.println("Waiting for light sensor...");
    delay(500);
  }

  if(Lpg.enableAmbientLightSensor(DISABLE)) {
    Serial.println("Light sensor enabled.");
  } else {
    Serial.println("Error enabling light sensor.");
  }

  /* 4. Initialize BMP180 Sensor */
  Serial.println("Connecting to BMP180...");
  while (true) {
    if(Pr.begin()) {
      Serial.println("Barometric Pressure Sensor connected!");
      break;
    }
    Serial.println("Waiting for BMP180...");
    delay(500);
  }

  /* 5. Initialize Buzzer */
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); // Ensure buzzer is off initially

  delay(500); // Allow sensors to stabilize
}

void loop() {
  // Check if sensors are responding
  if(Lpg.ping() && Pr.ping()) {
    
    // --- Light Sensor ---
    uint16_t currentLight = Lpg.getAmbientLight(); 
    Serial.print("Light Level: ");
    Serial.println(currentLight);

    // --- Pressure Sensor ---
    float pressure_hPa = Pr.getPressureBar() * 1000; // Convert bar → hPa
    Serial.print("Pressure (hPa): ");
    Serial.println(pressure_hPa);

    // --- Temperature Sensor ---
    float tempC = Pr.getTempC();
    Serial.print("Temperature (C): ");
    Serial.println(tempC);

    /* --- OLED Display Logic --- */
    display.clearDisplay();

    if (currentLight < LIGHT_THRESHOLD) {
      // --- WARNING MODE ---
      display.invertDisplay(true);
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(10, 20);
      display.println("LOW LIGHT");


      // --- BUZZER ALERT ---
      digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
      delay(200);                      // Short beep
      digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
    } 
    else {
      // --- NORMAL MODE ---
      display.invertDisplay(false);
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.println("System Normal");
      
      display.setCursor(0, 20);
      display.print("Light: ");
      display.println(currentLight);

      display.setCursor(0, 35);
      display.print("Pressure: ");
      display.print(pressure_hPa, 0);
      display.print(" hPa");

      display.setCursor(0, 50);
      display.print("Temp: ");
      display.print(tempC);
      display.print(" C");

      // Ensure buzzer is OFF in normal mode
      digitalWrite(BUZZER_PIN, LOW);
    }
    
    display.display(); // Push data to screen
  }
  
  delay(500); // Prevent flicker
}
