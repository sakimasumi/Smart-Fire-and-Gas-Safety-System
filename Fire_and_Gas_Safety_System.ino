/*
 * ESP8266 Fire & Gas Safety System
 * Board: NodeMCU 1.0 (ESP-12E Module)
 * * Pin Connections:
 * - Green LED: D1
 * - Red LED:   D2
 * - Buzzer:    D5
 * - Flame Sensor: D6
 * - MQ-2 Digital: D7
 * - MQ-2 Analog:  A0
 */

// --- 1. Pin Definitions ---
#define GREEN_LED D1
#define RED_LED   D2
#define BUZZER    D5
#define FLAME_PIN D6
#define GAS_DIG   D7  // Digital pin from MQ-2
#define GAS_ANA   A0  // Analog pin from MQ-2

// --- 2. Thresholds ---
// Adjust this value if the gas sensor is too sensitive
int gasAnalogThreshold = 400; 

void setup() {
  // Start Serial Monitor for debugging
  Serial.begin(115200);
  Serial.println("System Initializing...");

  // Set Pin Modes
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  pinMode(FLAME_PIN, INPUT);
  pinMode(GAS_DIG, INPUT);

  // Test sequence: Flash LEDs and Beep once to show it's working
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay(200);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);
  digitalWrite(GREEN_LED, HIGH);
  
  Serial.println("System Ready!");
}

void loop() {
  // --- 3. Read Sensors ---
  // Note: Most sensors are "Active LOW" (0 = Danger, 1 = Safe)
  int flameState = digitalRead(FLAME_PIN);
  int gasDigitalState = digitalRead(GAS_DIG);
  int gasAnalogValue = analogRead(GAS_ANA);

  // Print values to Serial Monitor (Tools > Serial Monitor) so you can see them
  Serial.print("Flame: ");
  Serial.print(flameState); // 0 usually means FIRE DETECTED
  Serial.print(" | Gas Dig: ");
  Serial.print(gasDigitalState); // 0 usually means GAS DETECTED
  Serial.print(" | Gas Ana: ");
  Serial.println(gasAnalogValue);

  // --- 4. Logic Flow ---
  // CHECK FOR DANGER (If Flame is 0 OR Gas is 0 OR Analog Gas is High)
  if (flameState == LOW  gasDigitalState == LOW  gasAnalogValue > gasAnalogThreshold) {
    
    // DANGER STATE
    digitalWrite(GREEN_LED, LOW);  // Turn off Safe LED
    digitalWrite(RED_LED, HIGH);   // Turn on Danger LED
    
    // Beep the buzzer (Pulse sound)
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    delay(100);
    
    Serial.println("!!! ALERT: DANGER DETECTED !!!");
    
  } else {
    
    // SAFE STATE
    digitalWrite(GREEN_LED, HIGH); // Turn on Safe LED
    digitalWrite(RED_LED, LOW);    // Turn off Danger LED
    digitalWrite(BUZZER, LOW);     // Silence Buzzer
  }
  
  delay(200); // Small delay to keep the loop stable