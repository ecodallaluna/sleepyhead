<!---
# sleepyhead
* experimental interface for emotional connection between newborns and parents *
-->

![logo sleepyhead](https://raw.githubusercontent.com/ecodallaluna/sleepyhead/master/img/sleepyhead_intro.jpg)

### 1.Introduction 
During the last years there has been a rising interest for smart systems that are able to monitor the condition of the newborns. Modern baby monitors collected several negative feedbacks. In particular, it looks that their ability to sense the breathing and the heartbeat are far away to be accurate and that generates false alarms very stressful for both parents and children. On the other hand, a more subdue and dangerous false feeling of security can lead the parents to do not check babies carefully when sensors are not triggered often.
Our team decided to analyze a real situation, a young family with a small baby. According to the information given by the family and a pediatrician, we realized that the most important information required to improve a baby’s quality of life is the humidity of the head. A baby with wet head can easily suffer from strong migraine.
We realized a prototype composed by two elements: a pillow with sensors and a sculpture to keep in the living room. The pillow analyzes children’s conditions, while the sculpture show the gathered information in the living room with a dance of water, lights and colors. This solution is elegant and shows the baby’s condition to the parents in an innovative and emotional way.

### 2.Problem analysis
During the project planning phase typical baby monitors purchasable on the market is found to be limited to relaying audio and/or video. This lead to the idea of using more advanced features such as body temperature and humidity measurements to identify comfort levels, sound recognition for separating distress (crying) from other loud noises, and other activity detection mechanisms.
Although research on the subject of the project is somewhat limited and hard to find, some studies (Hey and Katz, 1969) have found that linked increased sweating in infants to discomfort which eventually manifests as increased activity and crying. Tracking temperature and the humidity gives some advanced warning of the baby's growing discomfort. This is further corroborated by the pediatrician consulted during the project planning stage. Other products (Linti et al.) of similar nature have also employed humidity and temperature sensors to monitor the welfare of infants.
A galvanic skin response sensor was also considered, but the feedback from a representative of the target audience — a parent with a small baby — indicated that parents were likely to not be comfortable with a solution that would have sensors in direct contact with the skin of their baby.
A microphone for recognizing crying sounds was also included in early project plans, but the test showed that the precision of the microphone would not be enough to do accurate sound recognition.

### 3.Design work
The design approach followed an iterative process. The following notes show the process followed in the developing of the project.

#### 3.1 Define features
Firstly, the group defined the features required for the system and different solutions were proposed as input and output for the system. The first ideas explored the use use of microphones, galvanic skin response systems and temperature/humidity sensors as input and music or animated puppet/toy as output. Then, the necessary components were ordered by the Internet. The order was placed in China to save money, but it required a considerable long time for the delivery (2 weeks ~ 2 months).

#### 3.2 Hardware testing
In the second step of the project, the electronic components were tested and several solutions were abandoned:
* **microphone** input is too noisy and it is not possible to discriminate baby’s information such breathing, heartbeat, cry or laugh;
* **galvanic skin response** systems requires a constant contact with baby skin and sending a slow voltage electricity stream through baby’s body. The benefits of this technique are marginal and the side effects are unknown. For safety reason it has not been used;
* **puppet/toy carousel and music** outputs resulted not very attractive because they are not able to improve the quality of the experience of the baby.
For the final version of the input it was decided to use a humidity/temperature sensor as input because it has high reliability, and it does not need to be in direct contact with baby’s body. Furthermore, this sensor approach is diverse and more innovative compared to the commercial baby monitor solutions.
For the final version of the output, several scenarios were explored. In some scenarios the electronic system was designed to automatically provide relief to the baby (e.g. by changing the temperature of the cradle or by drying the baby with a fan or hot air). In some other scenarios the system was designed to inform the parents about the baby’s situation and let them to provide relief. It was decided to use this second kind of approach due the limited capability of the electronic equipment. It was decided to use an indoor water fountain as output. This artifact is able to communicate baby’s status directly to the parents with light and water patterns and improves the design of the living room.

#### 3.3 Final implementation  
The first design of the fountain/lamp was made with plastic and paper containers to experiment the best way to connect all the components. A final part of the project, a sophisticated vessel was designed with glass and stain with the help of the Aalto Design Factory.

### 4. Design Implementation 
#### 4.1 Artifact design
For the implementation of the design it was asked the help of the Aalto Design Factory (ADF). ADF personnel helped a lot the developing of the design by suggesting practical hacking of the material gathered in second hand shops.
The project consists in two elements, the pillow placed in the baby’s cradle and the lamp/fountain allocated in the living room.
**The pillow board** has a humidity/temperature sensor sewn inside the pillow, quite close to the surface. 
There is some concern about the effect of the radio waves for human body, however not clear scientific answers have been collected so far. Anyway, some precautions have been taken and the hardware elements of the the board, the battery and the wifi board are placed inside the pillow as much far away possible from the baby’s head. The pillow looks like a normal pillow because all the electronic components are sewn into the pillow and they are not visible or tangible for the baby (image 4.1.1).
**The fountain/lamp** has two elements piled one over the other (images from 4.1.2 to 4.1.4). The electronic components and the light are inserted inside the steel base. The water pump is placed inside a glass container at the top.  ADF helped to create some elements made in transparent plexiglass acrylic board and stainless steel to connect all the elements together. The fountain/lamp is designed to let the light hit the ceiling of the room and the movement of the water is changing the reflection of the light in an amusing and emotional way.

![prototype](https://raw.githubusercontent.com/ecodallaluna/sleepyhead/master/img/sleepyhead_prototype.jpg)

#### 4.2 Hardware design
Two Arduino boards are used to connect all the elements.
**The pillow board** (image 4.2.1) is powered by a 9v battery. A DHT11 humidity/temperature sensor is sewn inside the pillow and it is used for the reading and it is placed near the head of the baby. 
**The fountain/lamp** (image 4.2.2) is connected directly to a 5v USB charger. The light is provided by a RGB LED and the fountain works with a 5v submersible water pump. A photoresistor modules the power of the LED to adapt to the room luminosity. An extra power sources is needed for the water pump and a transistor is used as switcher.
Both Arduino boards communicate with a local wireless network and two ESP8266 Wifi boards are implemented to supply wireless communication. 

![connection schema](https://raw.githubusercontent.com/ecodallaluna/sleepyhead/master/img/sleepyhead_schema.jpg)

### 4.3 Software design
The implementation has been realized with standard Arduino software (based on C language). The following libraries are imported let the arduino board to communicate with the DHT11 sensor and ESP8266 Wifi board:
[Adafruit DHT11 Library](https://learn.adafruit.com/dht)
[WeeESP8266 Library](https://github.com/itead/ITEADLIB_Arduino_WeeESP8266)

#### 4.3.1 Implementation problems
Some problems were found during the implementation of the wifi network because the connection is sometimes unstable. Furthermore, a variable pause time is requested to be asked in the loop() function to read correctly the data from the sensor. This pause time change according to the temperature and the humidity which the sensor operate and it is provided by a specific function of the DHT11 library. Sometimes this waiting time is going to affect the transmission of the data through the wifi network, however our tests did not find any serious problem about that, just a little delay in the transmission of the data. Due the purpose of the prototype, this delay is not going to affect the functions of the project. 

### 5. Implementation contribution
No specific roles were assigned to different team members, and almost everyone participated in all the parts of the project construction. The table below breaks down the contributions and loosely defined project roles for each project member.

Member | Project role
------------ | -------------
Antti Alho | Programming, audio solution research, documentation
Álvaro Mompó Camarasa | Programming, hardware building, design
Lingying Jiang | Programming, wireless network setup, hardware building
Zhengwu Lu | Programming, wireless network setup, contact with parents and pediatrician
Ilario Toniello | Programming, design, concept, hardware building, documentation

### 6. Conclusion
Complications with the implementation of the various parts — such as microphone and wireless link — of the initial project plan reduced the feature scope of the project a bit more than desired.
Despite these problems we feel we were able to design a creative solution for an actual need, for which we also received positive feedback from the family that tested it.

### 7. References
E.N. Hey and G. Katz. *Evaporative water loss in the new-born baby.* The Journal of Physiology, 200(3):605-619, 1969.
Linti et al. *Sensory baby vest for the monitoring of infants.* Proceedings of the International Workshop of Wearable and Implantable Body Sensor Networks, pages 135-137, 2006.

