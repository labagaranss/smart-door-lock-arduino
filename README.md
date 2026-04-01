=>  Smart Door Lock System (Arduino Mega 2560)

This is a simple smart door lock system I built using Arduino Mega 2560.  
The main idea behind this project is to improve basic home security using a password-based locking mechanism.

Instead of a traditional lock, this system allows access only when the correct password is entered through a keypad.

---

=>  What this project does

- Takes password input from a 4x4 keypad  
- Displays messages on a 16x2 LCD  
- Unlocks the door using a servo motor when the password is correct  
- Gives a buzzer alert for wrong attempts  
- Locks the system temporarily after multiple wrong tries  

---

=>  Components I used

- Arduino Mega 2560  
- 4x4 Keypad  
- 16x2 LCD (I2C)  
- Servo Motor  
- Buzzer  
- Jumper wires and breadboard  

---

=>  How it works

When the system starts, it asks the user to enter a password.

- As you type, the input is shown on the LCD  
- Press **'A'** to confirm the password  
- If the password is correct:
  - The LCD shows *Access Granted*  
  - The servo rotates and unlocks the door  
  - A short indication (LED/Buzzer) is given  
  - Then it shows *Welcome Home*  

- If the password is wrong:
  - The LCD shows *Wrong Password*  
  - The buzzer beeps  

- If the wrong password is entered 3 times:
  - The system gets locked for a few seconds  
  - A longer buzzer alert is triggered  

- Press **'*'** anytime to clear the input  

---

=>  Pin connections (used in my setup)

- Keypad → Pins 22 to 29  
- Servo Motor → Pin 9  
- Buzzer → Pin 8  
- LED → Pin 10  
- LCD → I2C (SDA, SCL)  

---

=>  Project structure

smart-door-lock/
│
├── smart_door_lock.ino  
├── circuit.jpg  
├── demo.mp4  
└── README.md  

---

=> What I learned

While building this project, I learned:

- How to interface a keypad with Arduino  
- Using I2C LCD for display  
- Controlling a servo motor  
- Handling user input and conditions in embedded systems  
- Improving system security with logic  

---

=>  Future Improvements

I’m planning to upgrade this project by adding a few advanced features:

- Implementing timer functions and interrupts to replace delay-based logic and improve system responsiveness  
- Adding fingerprint authentication for enhanced security  
- Enabling mobile control using WiFi for remote access  

These improvements will help me build a more efficient, secure, and real-world applicable smart door lock system.

---

=>  Final note

This is one of my beginner level embedded projects.  
It helped me understand how hardware and software work together in real-time systems.

Thanks for checking it out!
