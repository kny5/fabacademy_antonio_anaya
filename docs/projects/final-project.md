# Final Project

## On site Milk QC and animal identification system:

While working in Mexico, I discovered the need for an affordable data acquisition system.

Project board:

<img src="../../images/week03/postit.jpg" alt="idea_1" width="90%"/>


## Research

![](./images/cows_infield.jpeg)


Currently RFID is the preferred technology for farm animals identification, in Mexico this is something that
has been unsuccessfully deployed due to multiple factors, but the most important one is supply chain and distribution.

[RFID stands for Radio Frequency Identification](https://www.wikiwand.com/en/Radio-frequency_identification), in animal identification it can be found as a earring, a collar or skin implant.

In Mexico the standard RFID earring is imported and then distributed, making it not accessible to small producers in rural areas, and they are the bast majority of producers making almost 60% of the country total production. Worldwide we can find the same situation in underdeveloped countries.

![](./images/cow_earings.jpeg)

My idea is to design a RFID system that can be made on FabLabs and also an Milk Quality control sensor to measure protein/fat content and also somatic cells. Somatic cells are present as part of animals immune system, and some diseases can be prevented by counting somatic cells in the dairy production.

My approach for a sustainable farm is the one that makes decisions based on data captured in the working field, to make a better use of natural resources and also all sort of different supplies. The indiscriminate use of hormones and antibiotics in animals is a problem that affects current disease control systems, producers financial viability and the consumer. One of the objectives is to identify diseases while in the dairy production and apply the antibiotics on the affected animal. Currently most farmers apply vaccines periodically without any analysis and this makes vaccination an expensive activity that most producers avoid because of their current financial status.

To indirectly measure fat/protein in milk I've found spectroscopy as a viable solution. Currently they're cheaper CHIPS like the [AS7265x](https://www.sparkfun.com/products/15050) that can be used to classify previously measured fat/protein samples of milk based in their measured spectrum.

So one of the steps in this research will be to measure a variety of milk samples using the AS7265x and a laboratory standard spectrometer to correlate the results.

The other important aspect I'm considering for this project is the interaction design. User-centered design for agriculture is an important topic, since most tools need an specialized trained professional to be used. In some places this will not be a problem, but in Mexico, in my region the technicians/animals is 3000 animals for each technician.

### A comparison of current methods in Mexico and a Experimental farm in France:

<iframe frameborder="0" scrolling="no" marginheight="0" marginwidth="0"width="788.54" height="443" type="text/html" src="https://www.youtube.com/embed/CrMBq_2zi3U?autoplay=0&fs=0&iv_load_policy=3&showinfo=0&rel=0&cc_load_policy=0&start=0&end=0&origin=https://youtubeembedcode.com"><div><small><a href="https://youtubeembedcode.com/es/">https://youtubeembedcode.com/es/</a></small></div><div><small><a href="https://mibew.org/">afforadablle targeted web traffic</a></small></div><div><small><a href="https://youtubeembedcode.com/es/">https://youtubeembedcode.com/es/</a></small></div><div><small><a href="https://mibew.org/">afforadablle targeted web traffic</a></small></div></iframe>

<iframe frameborder="0" scrolling="no" marginheight="0" marginwidth="0"width="788.54" height="443" type="text/html" src="https://www.youtube.com/embed/UNGkzNqBQVc?autoplay=0&fs=0&iv_load_policy=3&showinfo=0&rel=0&cc_load_policy=0&start=0&end=0&origin=https://youtubeembedcode.com"><div><small><a href="https://youtubeembedcode.com/en/">https://youtubeembedcode.com/en/</a></small></div><div><small><a href="https://mibew.org/">increase visitors in your website</a></small></div></iframe>



### Project description:

Challenge:

To develop an affordable device for cow milk production measurement and quality checking.

Characteristics:

- Supply-chain reduced components.
- Food-safe components for the parts in contact with the milk.
- Adaptable to different countries and their local regulations or tech level.

Functions:

- Read RFID current existing earrings
- Meassure automatically ammount of milk produced for each animal on a production.
- Meassure a sample for milk quality control.

Parts:

- 4 Milk flow meter on for each cow's udder.
- RFID earring reader.
- Spectral sensor for substance identification
- Dielectric spectroscopy sensor.

User:

- Field veterinary technicians.
- Dairy production managers.
- Researchers.
- Quality control technicians.



### Sketches

- Hall effect circuit board sketch:

<img src="../../projects/images/sketch_01.jpg" alt="Render_01" width=70%/>

- Pipe milk conduct to fluid sensor connector:

<img src="../../projects/images/sketch_02.jpg" alt="Render_01" width=70%/>

- Flow sensor sketch 01:

<img src="../../projects/images/sketch_05.jpg" alt="Render_01" width=70%/>

- Flow sensor sketch 02:

<img src="../../projects/images/sketch_03.jpg" alt="Render_01" width=70%/>

- Microfluids sketch:

<img src="../../projects/images/sketch_04.jpg" alt="Render_01" width=70%/>

- Electrode design sketch:

<img src="../../projects/images/sketch_06.jpg" alt="Render_01" width=70%/>



### Tests

- Testing SLA 3D printing, I would like to cast this pieces in food-safe silicone.

![Hero.](../../images/week06/hero.jpg)

- This is my first attempt to make a circuit board with a hall effect sensor that I'll use later for the flow sensor.

<img src="../../images/week11/hero_00.jpg" alt="hero_01" width=100%/>

- This is a test of the ISO11784 RFID module that will be used to read Cow earrings.

<figure class="video_container">
  <video controls="true" allowfullscreen="true" poster="path/to/poster_image.png" width=100% loop>
    <source src="../../images/week11/demo_01.mp4" type="video/mp4">
  </video>
</figure>
