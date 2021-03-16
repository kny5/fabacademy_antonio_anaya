# 8. Computer controlled machining

<img src="../../images/week08/hero_01.jpg" alt="Render_01" width=100%/>



## Introduction

CNC stands for Computer Controlled Machining and the modern predecessors were developed at the beginning of 1950 at the MIT servomechanism lab. Through the years this technology has became more precise and affordable, so we can have a tabletop [Roland SRM-20](http://fabacademy.org/2021/labs/agrilab/students/antonio-anaya/assignments/week05/) with a 0.01 mm precision or any [SLM 3D printer](http://fabacademy.org/2021/labs/agrilab/group/week_6_3D_printing/#description-of-ultimaker-3-extended).

The process needs a hardware capable of following a series of instructions with the encoded geometrical position in 2, 3 or more axis of the tool so as the tool type, the cut-rate, the tolerance, and the speed of any movement.

For this week our individual task is to design, encode, manufacture and assemble a large object. And our group assignment is to document our security training to use the CNC machine workshop at [AgriLab](http://agrilab.unilasalle.fr/), you can check our work [here.](http://fabacademy.org/2021/labs/agrilab/group/week_8_cnc/)



### Security assessment

[Check the group assignment to find this information here.](http://fabacademy.org/2021/labs/agrilab/group/week_8_cnc/)



## Design process

I've used [Fusion 360](https://www.autodesk.com/products/fusion-360/overview?term=1-YEAR&support=null) (under Windows) to design my project. I've been trying to run Fusion on Linux but it has some complications due to my Nvidia driver configuration.

The idea is just very simple yet useful. I got a very bad back pain everytime I solder in the ElectroLab, the reason is that there's no a right size bench. You can get one very tall bench or a very low chair. So I think a good cheap bench design will help us a little in the upcoming weeks.

This is my first sketch.

<img src="../../images/week08/sketch_00.jpg" alt="Render_01" width=50%/>


Then I started drawing it in Fusion.
<img src="../../images/week08/fusion_02.jpg" alt="Render_02" width=100%/>


This is the parametric table.
<img src="../../images/week08/fusion_01.jpg" alt="Render_01" width=100%/>

These are the three parts of the sketch. To make the second part of the body for the bench I've copy pasted the first sketch into a new one, and then modify the groove to coincide and serve as join mechanism.
<img src="../../images/week08/fusion_03_0.jpg" alt="Render_01" width=100%/>

These are the three parts extruded by 18 mm which is the width of the material.
<img src="../../images/week08/fusion_03_1.jpg" alt="Render_01" width=100%/>

On the Render environment of Fusion I've used Oak as a material for the appearance of the model.
<img src="../../images/week08/render_02.jpg" alt="Render_01" width=100%/>


This is render I've made using the basic render options of Fusion 360.
To virtually assemble the parts I've using the move/rotate tools under the design environment.
<img src="../../images/week08/render_01.jpg" alt="Render_01" width=100%/>



## CAM with Fusion 360

After the design has been completed the next steps to generate **""*.NC"** files for our CNC machine are:

**1.** Configure the tool size measuring the tool available in the lab.

- I've chose a 10 mm diameter 32 mm two flutes flat-end mill.
- For now all the other parameters of the milling tools like the shaft and holder are not very important, because the milling depth is only about 18 mm.

<img src="../../images/week08/fusion_03.jpg" alt="Render_02" width=100%/>

**2.** Then under the manufacture environment of Fusion select setup to configure the machine, orientation, models and tool for the manufacturing process.

- Select Milling.
- Selecte Z as the vertical axis for your model, be aware of you machine axis too, in this case Y is the longest axis in the machine so as in the model.

<figure class="video_container">
  <video controls="true" allowfullscreen="true" width=100%>
    <source src="../../images/week08/setup_01.mp4" type="video/mp4">
  </video>
</figure>

**3.** Under the 2D strategy I've selected **2D contour** as my milling process. The reason is because in the test I've found that as the quickest and simplest process for milling.

- Select the lower contour of your model.
- Select the right tool.
- Select the multi-height passes and use about hald the diameter of your milling bit.

<img src="../../images/week08/fusion_04.jpg" alt="Render_02" width=100%/>

**4.** Contour parameters I've selected:

- The **feedrate was too high** and during the manufacturing process [Luc](link) had to lower the travel and cutting feedrate and increased the spindle RPM to reduce vibrations in the machine. So I'll advice to use 2000 or 2200 Feedrate for 18mm OSB sheets.

<img src="../../images/week08/fusion_05.jpg" alt="Render_02" width=50%/>

**5.** I've used tabs to reduce vibration and the risk of detached parts during the process.

- Tabs are placed every 125.0 mm
- Tabs are rectangular
- Height 2.5 mm
- Width 10.0 mm

<img src="../../images/week08/fusion_06.jpg" alt="Render_02" width=100%/>

**6.** The tolerance was just enough and the parts fit perfectly in place.

- Tolerance was set as 0.125 mm

<img src="../../images/week08/fusion_07.jpg" alt="Render_02" width=50%/>

**7.** Multiple depths were configured

- Maximum roughihg stepdown was set to 5 mm
- Finishing stepdown for a clean edge is 0.1 mm

<img src="../../images/week08/fusion_08.jpg" alt="Render_02" width=50%/>

**8.** The contour operation is finished and the program shows the cut path way.

<img src="../../images/week08/fusion_09.jpg" alt="Render_02" width=100%/>

- The video shows the complete process

<figure class="video_container">
  <video controls="true" allowfullscreen="true" width=100%>
    <source src="../../images/week08/cam_02.mp4" type="video/mp4">
  </video>
</figure>


<img src="../../images/week08/fusion_10.jpg" alt="Render_02" width=100%/>

<img src="../../images/week08/fusion_11.jpg" alt="Render_02" width=100%/>

<img src="../../images/week08/fusion_12.jpg" alt="Render_02" width=50%/>


<figure class="video_container">
  <video controls="true" allowfullscreen="true" width=100%>
    <source src="../../images/week08/sim_01.mp4" type="video/mp4">
  </video>
</figure>





## Preparation

This is the material I've used OSB.
<img src="../../images/week08/preparation_01.jpg" alt="Render_01" width=100%/>

The sheet should be maximum 2.0m, so we should cut it using the saw.
<img src="../../images/week08/preparation_02.jpg" alt="Render_01" width=100%/>

Finally we need to measure in different points the thickness of the material.

- 17.6 mm
- 17.8 mm
- 17.5 mm

So I've used 17.5 mm as a medium thickness measurement.

<img src="../../images/week08/preparation_03.jpg" alt="Render_01" width=100%/>


## Milling machine check list

1. Power on the machine.
2. Start Depression.
3. Start Vacuum dust aspiration.
4. Setup the Z axis connecting the electrode and the clamps, make a small test pressing "toolset" in the remote.
  - Place the electrode at the top of the material. It's always useful to remember that the "Depression" should be activated to make this step as the height will change because a small compression caused by the vacuum.

5. Lower the brush: To lower the brush go into "inputs menu" and look for **"06"** check it to red color and press "ok".
6. Ensure that there's no obstacles in the build area.
7. Ensure that you are using ear protections.

## Milling with the CNC machine


We need to access the **"*.nc"** files we made with Fusion on the machine.
<img src="../../images/week08/outcome_02.jpg" alt="Render_01" width=100%/>

Press OK and Run to start the process.

<img src="../../images/week08/outcome_01.jpg" alt="Render_01" width=100%/>
<img src="../../images/week08/outcome_03.jpg" alt="Render_01" width=100%/>
<img src="../../images/week08/outcome_05.jpg" alt="Render_01" width=100%/>



## Assembly

<img src="../../images/week08/assembly_01.jpg" alt="Render_01" width=100%/>
<img src="../../images/week08/assembly_02.jpg" alt="Render_01" width=100%/>
<img src="../../images/week08/assembly_03.jpg" alt="Render_01" width=100%/>
<img src="../../images/week08/hero_01.jpg" alt="Render_01" width=100%/>



## Files

[Download Zip with all files from Fabcloud gitlab](https://gitlab.fabcloud.org/academany/fabacademy/2021/labs/agrilab/students/antonio-anaya/-/archive/master/antonio-anaya-master.zip?path=docs/files/week08)

- [Fusion file](../../files/week08/week08_cnc_bech.f3d)
- [NC file 1 Cross](../../files/week08/a.nc)
- [NC file 2 Seat](../../files/week08/b.nc)
- [NC file 1 Body A](../../files/week08/circle.nc)
- [NC file 1 Body B](../../files/week08/cross.nc)
