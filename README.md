# sleepyhead
*experimental interface for emotional connection between newborns and parents*

![logo sleepyhead]
(https://raw.githubusercontent.com/ecodallaluna/sleepyhead/master/img/sleepyhead_intro.jpg)

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


