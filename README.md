# Automated RFID Attendance System (Excel-based Database)
---
This project is an automated RFID-based attendance system that connects to microcontroller hardware setup with a python-based backend to manage user logs using Excel file.

**Story:** This project was presented during my Grade 12, second semester to prove our thesis statement in the subject English for Academic and Professional Purposes.

---
## 📦 Function of the System
- ✅ ​**Contactless Identification:** Uses RFID (MFRC522) to scan card IDs without touching.
- ✅ **​Real-Time Data Processing:** Sends data from Arduino to Python in real time using serial communication (9600 baud).
- ​✅ **Automated Excel Logging:** Automatically saves student info (Name, LRN, Grade/Section) into an Excel file (attendance.xlsx).
- ✅ **Precise Timestamping:** Every attendance entry is logged with the exact Date and Time of the scan using Python’s datetime module.

---
## ⚙️ Setup Instruction

**1. Ready and Wire Electronics Components**

   - MFRC522 RFID reader
   - Red and Green LEDs
   - Buzzer
     Connect the components to your Arduino according to the pins defined in the code (SDA to Pin 10, RST to Pin 9, Buzzer to Pin 6, etc.)

**2. Arduino IDE**
   - Install and Open Arduino IDE and upload getUID.ino

**3. GetUID.ino**
   - Open the Serial Monitor (set to 9600 baud)
   - ​Tap your RFID cards
   - ​Copy the HEX strings (e.g., 5326AF2B) that appear. Save these; you will need them for your database.

**4. User Database**
   - ​Create a new Excel file named database.xlsx in the same folder where your Python script is located.
   - Rename the first sheet to "Students".
   - Create four columns: UID, Name, LRN, and Grade & Section.
   - ​Paste the UIDs you collected in Step 3 into the UID column and fill out the corresponding student info.

**5.  Main Firmware**
   - Upload main.ino to your Arduino
   - Once uploaded, the Serial Monitor should display "READY". Close the Serial Monitor before moving to the next step.

**6. Python**
   - Open Command Prompt
   - Install ``pip install pyserial openpyxl``
   - Execute ``python run.py``

**7. Run Test**
​   - Tap a registered card. Python should find the student in database.xlsx, log the entry to attendance.xlsx, and send a "VALID" signal back.
   - The Arduino will then trigger the Green LED and a short beep.
   - ​Tap an unregistered card to confirm the Red LED and long buzzer trigger correctly.

---

## 🤝 Credits

Built by Jim and his Groupmates
