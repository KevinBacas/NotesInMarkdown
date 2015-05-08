# [Arduino workshop] Notes
## Abstract
### What is a Microcontroler ?
It's a **micro-computer**. It has an internal CPU which is used for **control purposes** and **data analysis**.

Famous microncontroller manufacturers :
- MicroChip
- Atmel
- Intel
- Analog devices
- ..

### What is Arduino ?
It's **a tool** that simplifies the process of **creating control systems**. The **Control system** can **sense and control the physical world**. It's an **open-source physical computing platform** based on a simple microcontroller board.

### Sensors
A resistor is something that will limit the voltage of a source. Sensors are resistors that reacts chemically to something (e.g. light).

## Arduino Software
### Arduino programming language
- Simplified C/C++
- Check and Upload
- Tools -> choose Board
- Serial Port -> Choose Port

```c
void setup() {
  // ...
}

void loop() {
  // ...
}
```

### Programming basics ([Reference](http://arduino.cc/en/Reference/HomePage))
#### Types
**Integer** 2 bytes

```c
int x = 1200;
```

**Character** 1 byte

```c
char x = 'r';
```

**Long** 4 bytes

```c
long x = 199203;
```

**Floating-point** 4 bytes

```c
float x = 1.291;
```

### Statement and operators
Exactly like **C**

### If / Switch case / Loop Statements
Exactly like **C**

### Arduino basics
- pinMode()
  - Define the mode of a pin

- digitalWrite()
  - Write on a digital pin

- digitalRead()
  - Read a digital pin
  - Returns HIGH or LOW

- analogWrite()
  - Write on an analog pin
  - value between 0 and 1023

- analogRead()
  - Read an analog pin
  - Returns value between 0 and 1023

- delay()
  - Wait for a number of milliseconds
