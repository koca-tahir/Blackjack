\# 🃏 Arduino Blackjack Project



This project is a simple Blackjack game built using Arduino.

The system follows the basic logic of Blackjack by comparing the player's score with the dealer's score.



!\[Blackjack Project](IMG\_20260720\_205802.jpg)



\## 🎮 How It Works



The project uses two buttons to control the game:



\- 🔵 \*\*Blue Button:\*\* Draw a card

\- 🔴 \*\*Red Button:\*\* Stop drawing cards and compare scores



When the game starts:



\- Arduino generates a random score between \*\*17 and 21\*\* for the dealer.

\- The player receives an initial random score between \*\*1 and 10\*\*.

\- The player can press the blue button to draw additional cards.

\- The goal is to get as close as possible to 21 without exceeding it.



\## 🃏 Blackjack Rules



\- If the player's score goes above 21, the player loses.

\- When the player stops, the scores are compared.

\- If the player's score is higher than the dealer's score, the player wins.

\- If the dealer's score is higher, the dealer wins.

\- If both scores are equal, the result is a draw.



\## 🔧 Components Used



The project includes:



\- Arduino board

\- One single-digit 7-segment display

\- Two push buttons

\- Two LEDs

&#x20; - Green LED → Win indicator

&#x20; - Red LED → Lose indicator

\- Breadboard

\- Power supply

\- Jumper wires



\## 🔢 7-Segment Display System



A single-digit 7-segment display is used in this project.



Since the display can only show one digit at a time, two-digit scores are displayed using a special method.



For example, if the player's score is \*\*18\*\*:



1\. The display shows the tens digit (\*\*1\*\*)

2\. Then it shows the ones digit (\*\*8\*\*)



The digits are switched continuously using the `millis()` function to create a smooth display effect.



\## ⚡ Display Working Principle



The 7-segment display is configured as a \*\*common anode display\*\*.



Because of this, the segments are activated by setting the corresponding pins to \*\*LOW (0)\*\*.



\## 💻 Software Features



The Arduino code includes:



\- Random number generation using `random()`

\- Button input control

\- LED control

\- 7-segment display programming

\- Non-blocking timing with `millis()`

\- Custom functions for displaying numbers



\## 🚀 Possible Improvements



Future improvements could include:



\- Card graphics

\- Buzzer sound effects

\- Larger displays

\- Real card drawing system

\- Betting system

\- Score history



\## 👨‍💻 Project Information



\*\*Project Name:\*\* Arduino Blackjack Game



\*\*Platform:\*\* Arduino IDE



\*\*Language:\*\* C/C++ (Arduino)



