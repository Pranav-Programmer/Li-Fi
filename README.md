# Li-Fi
Li-Fi, which is light fidelity, is one of the future technologies in the wireless
communication sector. It is bidirectional, with a very high speed and is a
fully networked communication which is wireless technology similar to
Wi-Fi. In the present era, Wi-Fi is the most trending domain. As internet
users almost double every year, there is an enormous load on the radio
spectrum that leads to congestion. To get better bandwidth, efficiency and
speed, a new technology Li-Fi has evolved.. Li-Fi can be simply put to be
Wi-Fi but instead of radio waves light is used as a medium. Here, data is
transmitted using light whose intensity varies faster than the human eye
can capture. Instead of using modems, Li-Fi uses LED bulbs with
transceivers. Data transmission in Li-Fi is about 100 times faster than
Wi-Fi. Here, in this paper we explore the need for Li-Fi. Li-Fi technology,
proposed by the German Scientist — Harald Haas, Harald Haas proposed
the technology that transmits the data through illumination .Li-Fi is ideal for
high speed wireless data transmission in confined areas. Li-Fi provides
higher bandwidth, efficiency, availability and security than Wi-Fi and has
already achieved high speed in the lab. We can implement this system for
public internet access through street lamps to auto -piloted cars that
communicate through their headlights. As the speed of light is higher hence
the data transmission speed is so much faster that the existing system. In
the future we can implement this technology for fast data access for the
laptops, smart phones, and tablets that will be transmitted through the light
in a room.

## Images of Models

![Second](https://user-images.githubusercontent.com/79044490/193364552-f4e4cb45-57be-4db7-9c9c-cb8414c5e614.png)

We transferred the image after burning the code in the transmitter and receiver which are Arduino nano. After burning the code in the transmitter, we used cool term software and take the required file type and the command is passed into the LED which will blink accordingly on the solar panel and pass the data into the receiver which processes the data and display the image onto the LCD.  
![image](https://user-images.githubusercontent.com/79044490/193364725-263b25d5-e23a-430a-ba79-49e07fd7ed88.png)

![First](https://user-images.githubusercontent.com/79044490/193364532-0b73167f-a09e-46f2-800d-aa34b62b5c27.png)

In this model, we transferred messages from our mobile phones to LCD using light as a data transmitter. We used the frequency and duration of the flashlight to transmit the message through a solar panel. We made an application that take the message as an input and gives the flashlight as output which is reflected on the LDR sensor and the corresponding message is displayed on the LCD. We used Arduino Uno as the microcontroller board.  
![image](https://user-images.githubusercontent.com/79044490/193364708-5fadba1e-1f5c-4f81-9709-ac0b98227a06.png)

## LiFiVerse App

[![LiFiVerseAPP](https://user-images.githubusercontent.com/79044490/193363073-5270517b-30c8-429f-a5f0-ffee11825375.png)](https://github.com/Pranav-Programmer/LiFiVerse)

## Transmitter Cricuit
![image](https://user-images.githubusercontent.com/79044490/193365737-8e983780-4020-4c5e-9a21-3d3e49a31fa2.png)

## Receiver Cricuit
![image](https://user-images.githubusercontent.com/79044490/193365834-2f856dac-74c4-4374-b82d-1e50d7c5b4c9.png)
## Flow Chart

![image](https://user-images.githubusercontent.com/79044490/193367944-00b1ce6a-43ea-49a4-88c2-2c74276aa450.png)
## Model Design

![D1](https://user-images.githubusercontent.com/79044490/193365401-4d28c356-742d-408f-b8c6-115e5f2f74dd.png)
![D2](https://user-images.githubusercontent.com/79044490/193365421-0c2d486b-50db-4de9-a3c8-65b15f242162.png)
![D3](https://user-images.githubusercontent.com/79044490/193365438-478a14a5-fd7c-4252-aad5-20bd48a30ac0.png)

## Farbricated Model with step by step process to send and recive text and image

![WhatsApp Image 2022-10-01 at 11 02 30 AM (2)](https://user-images.githubusercontent.com/76249823/193394894-d2fd77d0-4980-4624-a9f1-2a7993f52a3a.jpeg)

### 1. Prepare the Transmitter Device:
- Set up an Arduino Nano or a similar microcontroller-based device as the transmitter.
- Burn the required code onto the transmitter device. This code should enable data transmission via Li-Fi using the LED bulb.

![WhatsApp Image 2022-10-01 at 11 02 30 AM (1)](https://user-images.githubusercontent.com/76249823/193394923-d7849ef9-11f7-4342-a19c-40e8c4f8d51f.jpeg)

### 2. Prepare the Receiver Device:
- Set up another Arduino Nano or a similar microcontroller-based device as the receiver.
- Burn the necessary code onto the receiver device. This code should enable data reception and processing from the Li-Fi signals received by the receiver's photodiode.

![WhatsApp Image 2022-10-01 at 11 02 31 AM](https://user-images.githubusercontent.com/76249823/193394919-056484b6-ddcf-4091-a5de-42ba9ccef393.jpeg)

### 3. Connect the Devices:
- Connect the LED bulb to the transmitter device. Ensure the LED is properly powered and connected to the appropriate pin on the Arduino Nano.
- Connect the photodiode to the receiver device. Make sure it is connected to the correct pin on the Arduino Nano.

![WhatsApp Image 2022-10-01 at 11 02 31 AM (1)](https://user-images.githubusercontent.com/76249823/193394928-d6566b74-7990-40e3-bb28-e6d0ad7b3f2f.jpeg)
![WhatsApp Image 2022-10-01 at 11 02 29 AM (2)](https://user-images.githubusercontent.com/76249823/193394934-cc554c1b-bb46-4763-815f-9382e41cc425.jpeg)

### 4. Prepare the Text:
- Decide on the text you want to send from the transmitter device to the receiver device.
- Encode the text into a suitable format that can be transmitted as data.

![WhatsApp Image 2022-10-01 at 11 02 29 AM (1)](https://user-images.githubusercontent.com/76249823/193394945-3ae7e7bc-08ea-406e-895f-c7496810501b.jpeg)

### 5. Transmit the Text:

- Use CoolTerm or a similar software to send the encoded text from the transmitter device.
- Send the command to the LED bulb, instructing it to blink in a specific pattern corresponding to the encoded text.
-
![WhatsApp Image 2022-10-01 at 11 02 29 AM](https://user-images.githubusercontent.com/76249823/193394947-b9bc2211-741e-4b4f-a6eb-34a7bc597a7e.jpeg)

### 6. Receive and Process the Text:

- The photodiode on the receiver device will receive the blinking light signals from the LED bulb.
- The receiver device's code should process these signals and convert them back into the original encoded text.
- Display the received text on an LCD or any other suitable output medium connected to the receiver device.
-
![WhatsApp Image 2022-10-01 at 11 02 54 AM (1)](https://user-images.githubusercontent.com/76249823/193395112-8c0ab749-1e05-417d-9b2a-53acde5b4de4.jpeg)

By following these steps, you can send text as well as image (after converting it to .h format) from the transmitter device using Li-Fi through blinking light signals, receive the signals on the receiver device, and display the text on an output medium.







https://user-images.githubusercontent.com/79044490/208243028-75432759-f541-44ab-9fb6-bbe628de19c4.mp4








**Contributers:  Pranav Dharme,Aryaka Choudhary, Shalu, PV Jayanth, Atharva Vidhulkar, and Yashwant Singariya**




