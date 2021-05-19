# 3. Computer Aided Design

## Introduction:

Description: CAD stands for Computer Aided Design, there are different software solutions for different industries, like [AutoCAD](https://www.autodesk.com/products/autocad/overview?term=1-YEAR&support=null) specialized in the mechanical and architecture industry, [CATIA](https://www.3ds.com/products-services/catia/) for the aircraft, marine and automobile industry, or [Blender](https://www.blender.org/) specialized in digital art.

There are also differences in licensing, for example proprietary, and open-source. Software like CATIA is proprietary and then you have to buy a license to use it, but there are also Open Sourced solutions like Blender, [FreeCAD](https://www.freecadweb.org/) and [OpenScad](https://www.openscad.org/), that are driven by their communities, and also are free of charge.

For this week the goal is to learn and use Raster or Vector drafting software, CAD and render or simulate.

As a personal note, it's my first time using 100% [Fedora](https://getfedora.org/) for all this process and I had some difficulties configuring my GPU drivers, something that's really common under this operative system if not used carefully. Normally my workflow needed a dual boot system on my personal computer to use Solidworks on Linux and programming under Linux. For the first time I've only used Linux thanks to XDesign and Blender.

The first thing I've made was this sort of ideation process to define the parts of my final project an this is the result:

<img src="../../images/week03/sketch_1.jpg" alt="idea_1" width="90%"/>

 As my Photo is a bit Pixelated, I've used InkScape to make a vectorized version and then compressed it again as a JPG image:

<img src="../../images/week03/postit.jpg" alt="idea_1" width="90%"/>





### Measuring objects:

I gave myself the challenge to draw one of the earrings used for Cow identification in the experimental farm of [unilasalle](https://www.unilasalle.fr/):

<img src="../../images/week03/photo_0.jpg" alt="photo_0" width="45%"/>
<img src="../../images/week03/photo_1.jpg" alt="photo_1" width="45%"/>



### Image compression and improvement with Gimp:

I took some photos and screen captures for this and sometimes I had too use [Gimp](https://www.gimp.org/) to crop, scale and compress all images shown for this assignment page.

To crop the images I used the Selection tool and then the crop to selection tool under the Image menu in the toolbar.

<img src="../../images/week03/inkscape_1.jpg" alt="photo_0" width="45%"/>
<img src="../../images/week03/inkscape_2.jpg" alt="photo_0" width="45%"/>

To improve contrast and color of images, you just need to use options under the Filters menu in the toolbar.

<img src="../../images/week03/inkscape_3.jpg" alt="photo_0" width="45%"/>
<img src="../../images/week03/inkscape_4.jpg" alt="photo_0" width="45%"/>



## 2D

### InkScape Draft process

Shape sketching with simple forms.

Using difference and union path tools I got the shape, next added the text, codebar and color.

- First create this simple shapes with the circle and rectangle tools. The rounded corners were made with the bezier editor.

<img src="../../images/week03/inkscape_01.jpg" alt="photo_0" width="100%"/>

- Then look for the "**Align and distribute**" palette in the **Object** menu"  

<img src="../../images/week03/inkscape_02.jpg" alt="photo_0" width="100%"/>

- Select all the shapes and use "**Center on vertical axis**"

<img src="../../images/week03/inkscape_03.jpg" alt="photo_0" width="100%"/>

- Then manually adjust the shapes to make the shape as is shown here.

<img src="../../images/week03/inkscape_05.jpg" alt="photo_0" width="100%"/>

- Select all the shapes again and use the "**Union**" boolean operation on the "**Path**" Menu.

<img src="../../images/week03/inkscape_06.jpg" alt="photo_0" width="100%"/>

- This is the result and the first part of the body for the cow earring.

<img src="../../images/week03/inkscape_07.jpg" alt="photo_0" width="100%"/>

- Then make a rectangle an a Oval using the rectangle and circle tools. Try to make the Oval tangent to the first body of the earring as is shown.

<img src="../../images/week03/inkscape_10.jpg" alt="photo_0" width="100%"/>

- Select the rectangle first and then the oval, go to the "**Path**" menu in the toolbar and use the "**Difference**" boolean operation.

<img src="../../images/week03/inkscape_11.jpg" alt="photo_0" width="100%"/>

- Make the same process por the right side.

<img src="../../images/week03/inkscape_12.jpg" alt="photo_0" width="100%"/>

- Now we have two shapes that resemble the earring.

<img src="../../images/week03/inkscape_13.jpg" alt="photo_0" width="100%"/>

- To complete the shape of the earring merge both shapes using the "**Union**" operation again.

<img src="../../images/week03/inkscape_14.jpg" alt="photo_0" width="100%"/>

- This is the basic shape of the earring.

<img src="../../images/week03/inkscape_15.jpg" alt="photo_0" width="100%"/>

- Next use the circle tool and the line bezier tool to match the image shown bellow.

<img src="../../images/week03/inkscape_18.jpg" alt="photo_0" width="100%"/>

- Then select the earring shape first and the lines right after. Use the "**Cut Path**" tool to divide the shape in 3 parts. This is needed to have 3 different colors in the next step and try to make a 3D effect.

<img src="../../images/week03/inkscape_19.jpg" alt="photo_0" width="100%"/>

- Then select the parts to paint it.

<img src="../../images/week03/inkscape_20.jpg" alt="photo_0" width="100%"/>

I've used this colors:

  - <p style="background-color:#ffcc00ff"">Top: #ffcc00ff</p>
  - <p style="background-color:#d4aa00ff"">Middle: #d4aa00ff</p>
  - <p style="background-color:#ffcc00ff"">Bottom: #ffcc00ff</p>

<img src="../../images/week03/inkscape_21.jpg" alt="photo_0" width="100%"/>

- Using the "**Text box tool**" I've wrote the numbers and codes as shown those are similar to the earring, but I didn't found the same font.

<img src="../../images/week03/inkscape_22.jpg" alt="photo_0" width="100%"/>

Then I've painted the "plug" circles in the top:

  - <p style="color:white; background-color:#918a6fff"">Outer: #918a6fff</p>
  - <p style="color:white; background-color:#24221cff"">Inner: #24221cff</p>


### Result:

<img src="../../images/week03/inkscape_23.jpg" alt="photo_0" width="100%"/>


## 3D

### Xdesign:

Review:

I've learned Xdesign and I found it very complicated at first even as a Solidworks user. My main OS is Fedora Linux.



#### Linux configuration:

I've tried to use XDeisgn under Linux using Firefox, and Chromium web navigators.

- Chromium works better than Firefox.
- Activate Hardware acceleration.
- Force hardware GPU use.*

*For Nvidia Nouveau drivers use:

```
DRI_PRIME=1 chromium-browser
```

*For Nvidia propietary drivers, use Bumblebee:

```
optirun chromium-browser
```
<!--
#### Building an ElectronJS application to ensure hardware acceleration

Install node version manager:

```
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.38.0/install.sh | bash
```

Load configuration to ZSH:

```
source ~/.zshrc
```

-->

#### Introduction

There are some basic operations for 3D modeling:

- 2D Drafting for sketching.
- Linear region extrusion.
- Linear region extraction.
- One axis profile revolution.
- Parametric scaling.

The whole process can be divided into three important steps:

- Sketching
- 3D solids modeling
- Part Modeling
- Assembling

The sketch is the 2D representation of a section or projection and its the base of a 3D model.

The modeling process starts when we transform a 2D shape from a sketch into a 3D entity, there are multiple operations like extrusion, revolution, subtraction and other boolean operations to shape a 3D entity.

An ensemble it's the combination of multiple 3D entities or parts, like in the real life process it requires constrains, joining mechanisms, but here you can restrict the displacement, rotation and collision with a "restriction or relationship" indicator.


#### Start a new XDesign File

We received an account as part of our Fab Academy course to access Xdesign:

This is the URL to access:
[https://eu1-ds-iam.3dexperience.3ds.com/cas/login?service=https%3A//eu1-ifwe.3dexperience.3ds.com/%3FserverId%3DFRONT_2](https://eu1-ds-iam.3dexperience.3ds.com/cas/login?service=https%3A//eu1-ifwe.3dexperience.3ds.com/%3FserverId%3DFRONT_2)

- This is the first screen after login, but I've already made a week03 Dashboard:

<img src="../../images/week03/x_01.jpg" alt="x_01.jpg" width=100%/>

- Then I've created a new component:

<img src="../../images/week03/x_02.jpg" alt="x_02.jpg" width=100%/>

- I've named the component rfid_tag:

<img src="../../images/week03/x_03.jpg" alt="x_03.jpg" width=100%/>

- This is the XDesign workspace:

<img src="../../images/week03/x_04.jpg" alt="x_04.jpg" width=100%/>

This is the sketch toolbar, and I'm going to use:

- Sketch.
- Lines.
- Square.
- Circle.
- Dimension.
- Convert entities.
- Offset.

<img src="../../images/week03/x_05.jpg" alt="x_05.jpg" width=100%/>



#### Sketching:

This is a 2D process where I've made the section of a RFID TAG used for cows and it's based on this model that I've available at FabLab Agrilab.

<img src="../../images/week03/photo_1.jpg" alt="x_05.jpg" width=50%/>

The process its as follows:

- Create a new sketch, select the plane XY and draw a rectangle:

<img src="../../images/week03/x_06.jpg" alt="x_06.jpg" width=30%/>
<img src="../../images/week03/x_07.jpg" alt="x_07.jpg" width=30%/>
<img src="../../images/week03/x_08.jpg" alt="x_08.jpg" width=30%/>
<img src="../../images/week03/x_09.jpg" alt="x_09.jpg" width=30%/>
<img src="../../images/week03/x_10.jpg" alt="x_10.jpg" width=30%/>
<img src="../../images/week03/x_11.jpg" alt="x_11.jpg" width=30%/>

- Redefine the dimensions of each side of the rectangle by using the dimension tool:
- I've measured the tag using the caliper the results are: 79 mm height and 57 mm width.

<img src="../../images/week03/x_12.jpg" alt="x_12.jpg" width=30%/>
<img src="../../images/week03/x_13.jpg" alt="x_13.jpg" width=30%/>
<img src="../../images/week03/x_14.jpg" alt="x_14.jpg" width=30%/>

- The I've converted the lines to contruction lines using right click and selecting the option in the menu:

<img src="../../images/week03/x_15.jpg" alt="x_15.jpg" width=30%/>
<img src="../../images/week03/x_16.jpg" alt="x_16.jpg" width=30%/>

- Then I've made two construction middle lines.

<img src="../../images/week03/x_17.jpg" alt="x_17.jpg" width=30%/>
<img src="../../images/week03/x_18.jpg" alt="x_18.jpg" width=30%/>

- The circle is the holder of the RFID it has a diameter of 20 mm, I've made it tangent to the top line. And I've made a new bottom tangent line for the lower part.

<img src="../../images/week03/x_19.jpg" alt="x_19.jpg" width=30%/>
<img src="../../images/week03/x_20.jpg" alt="x_20.jpg" width=30%/>
<img src="../../images/week03/x_21.jpg" alt="x_21.jpg" width=30%/>
<img src="../../images/week03/x_22.jpg" alt="x_22.jpg" width=30%/>

- Results so far:

<img src="../../images/week03/x_23.jpg" alt="x_23.jpg" width=100%/>

- The 3 points arc tool, works by selecting first the center, start and end.

<img src="../../images/week03/x_24.jpg" alt="x_24.jpg" width=100%/>

- Then I've joined the arc and the circle with tangent lines.

<img src="../../images/week03/x_25.jpg" alt="x_25.jpg" width=100%/>
<img src="../../images/week03/x_26.jpg" alt="x_26.jpg" width=100%/>

- I've used the rounding tool to make round corners with a 4 mm radius.

<img src="../../images/week03/x_27.jpg" alt="x_27.jpg" width=100%/>

- Then I've trimmed the lines to left the sillouete that I'm goint to extrude:

<img src="../../images/week03/x_28.jpg" alt="x_28.jpg" width=100%/>
<img src="../../images/week03/x_29.jpg" alt="x_29.jpg" width=100%/>
<img src="../../images/week03/x_30.jpg" alt="x_30.jpg" width=100%/>

- So far I've been finish a half of the tag and used the Mirror tool, selecting the vertical middle line and selecting the half siloutte:

<img src="../../images/week03/x_31.jpg" alt="x_31.jpg" width=100%/>
<img src="../../images/week03/x_32.jpg" alt="x_32.jpg" width=100%/>
<img src="../../images/week03/x_33.jpg" alt="x_33.jpg" width=100%/>

- This is the final sketch:

<img src="../../images/week03/x_34.jpg" alt="x_34.jpg" width=100%/>

- The final step its to add a inner circle of 14 mm diameter, concentric to the top curve.

<img src="../../images/week03/x_35.jpg" alt="x_35.jpg" width=100%/>
<img src="../../images/week03/x_36.jpg" alt="x_36.jpg" width=100%/>



#### Modeling:

- I've used the extrusion tool and used it on my latest sketch. Left click  on the sketch and on the extrude contextual menu select the thickness 3mm. This is the measurement I got from the RFID Tag using the caliper.

<img src="../../images/week03/x_37.jpg" alt="x_37.jpg" width=100%/>
<img src="../../images/week03/x_38.jpg" alt="" width=100%/>
<img src="../../images/week03/x_39.jpg" alt="" width=100%/>
<img src="../../images/week03/x_40.jpg" alt="" width=100%/>

- Resulting 3D shape:

<img src="../../images/week03/x_41.jpg" alt="" width=100%/>
<img src="../../images/week03/x_42.jpg" alt="" width=100%/>

- Then I've to make a cut through the material using the sketch tool in the thickness or lateral face of the 3D model.

<img src="../../images/week03/x_43.jpg" alt="" width=100%/>

- I've used the convert entity tool to make a projection square on the current sketch:

<img src="../../images/week03/x_44.jpg" alt="" width=100%/>
<img src="../../images/week03/x_45.jpg" alt="" width=100%/>
<img src="../../images/week03/x_46.jpg" alt="" width=100%/>

- Then I've draft the lines based on the measurements of the RFID Tag:

<img src="../../images/week03/x_47.jpg" alt="" width=100%/>
<img src="../../images/week03/x_48.jpg" alt="" width=100%/>
<img src="../../images/week03/x_49.jpg" alt="" width=100%/>
<img src="../../images/week03/x_50.jpg" alt="" width=100%/>

- Then I've created areas to use the extrude cut tool:

<img src="../../images/week03/x_51.jpg" alt="" width=100%/>
<img src="../../images/week03/x_52.jpg" alt="" width=100%/>
<img src="../../images/week03/x_53.jpg" alt="" width=100%/>

- Final sketch so far:

<img src="../../images/week03/x_54.jpg" alt="" width=100%/>

- To extrude the cut, use the extrude tool and select cut:

<img src="../../images/week03/x_55.jpg" alt="" width=100%/>

- I've choose the "up to next" option:

<img src="../../images/week03/x_56.jpg" alt="" width=100%/>

- First result of the cut: And I've missed to define the ramp dimension:

<img src="../../images/week03/x_57.jpg" alt="" width=100%/>
<img src="../../images/week03/x_58.jpg" alt="" width=100%/>

- Defining the ramp dimension:

<img src="../../images/week03/x_59.jpg" alt="" width=100%/>
<img src="../../images/week03/x_60.jpg" alt="" width=100%/>

- Then I've extruded over the shown surface to create a ring using, sketch and extrusion tool:

<img src="../../images/week03/x_61.jpg" alt="" width=100%/>
<img src="../../images/week03/x_62.jpg" alt="" width=100%/>
<img src="../../images/week03/x_63.jpg" alt="" width=100%/>
<img src="../../images/week03/x_64.jpg" alt="" width=100%/>
<img src="../../images/week03/x_65.jpg" alt="" width=100%/>

- Then on the bottom of the tag I've made another ring shape, following again, sketch, extrude process:

<img src="../../images/week03/x_66.jpg" alt="" width=100%/>
<img src="../../images/week03/x_67.jpg" alt="" width=100%/>
<img src="../../images/week03/x_68.jpg" alt="" width=100%/>
<img src="../../images/week03/x_69.jpg" alt="" width=100%/>

- The RFIG TAG has two visible components, so I've made an assembly with the assembly tools.

<img src="../../images/week03/x_70.jpg" alt="" width=100%/>

- I've named the assembly "Physical Product 2":

<img src="../../images/week03/x_71.jpg" alt="" width=100%/>

- Then I've created a new component named "Rfid inner":

<img src="../../images/week03/x_72.jpg" alt="" width=100%/>
<img src="../../images/week03/x_73.jpg" alt="" width=100%/>

- I've used the top face of the ring shown as base for the inner tag component:

<img src="../../images/week03/x_74.jpg" alt="" width=100%/>

- Using the sketch, extrude tool I've made the 3 parts of the body:
- First part:

<img src="../../images/week03/x_75.jpg" alt="" width=100%/>
<img src="../../images/week03/x_76.jpg" alt="" width=100%/>
<img src="../../images/week03/x_77.jpg" alt="" width=100%/>
<img src="../../images/week03/x_78.jpg" alt="" width=100%/>
<img src="../../images/week03/x_79.jpg" alt="" width=100%/>
<img src="../../images/week03/x_80.jpg" alt="" width=100%/>

- Second part:

<img src="../../images/week03/x_81.jpg" alt="" width=100%/>
<img src="../../images/week03/x_82.jpg" alt="" width=100%/>

- Third part:

<img src="../../images/week03/x_83.jpg" alt="" width=100%/>
<img src="../../images/week03/x_84.jpg" alt="" width=100%/>


<img src="../../images/week03/x_85.jpg" alt="" width=100%/>

- Final shape:

<img src="../../images/week03/x_86.jpg" alt="" width=100%/>
<img src="../../images/week03/x_87.jpg" alt="" width=100%/>

- Then I've used the apply material tool:

<img src="../../images/week03/x_88.jpg" alt="" width=100%/>

- Selected "Black low gloss plastic":

<img src="../../images/week03/x_89.jpg" alt="" width=100%/>
<img src="../../images/week03/x_90.jpg" alt="" width=100%/>

- Then I've selected the first component I've modeled and applied using the "Apply material tool":

<img src="../../images/week03/x_91.jpg" alt="" width=100%/>

- And selected "Plastic, low glow, yellow":

<img src="../../images/week03/x_92.jpg" alt="" width=100%/>



#### Assembly:

- To make this assembly video I've captured the screen on my computer using [simple screen recorder](https://www.maartenbaert.be/simplescreenrecorder/)

<img src="../../images/week03/as_01.jpg" alt="" width=100%/>

- Selecting a rectangular region of my screen framing my model under [XDesign](https://www.solidworks.com/es/media/solidworks-xdesign-design-go) and then pulsing the relationship constrain "coincident surface".

<img src="../../images/week03/as_02.jpg" alt="" width=100%/>

- [XDesign](https://www.solidworks.com/es/media/solidworks-xdesign-design-go) then makes and animation where the two selected surfaces move until fund each other.

- This is the configuration I've used on simplescreenrecorder.

<img src="../../images/week03/as_03.jpg" alt="" width=45%/>
<img src="../../images/week03/as_04.jpg" alt="" width=45%/>
<img src="../../images/week03/as_05.jpg" alt="" width45%/>


- This is the video result:

<figure class="video_container">
  <video controls="true" allowfullscreen="true">
    <source src="../../images/week03/xdesign_assembly.mp4" type="video/mp4">
  </video>
</figure>


- And then this is a the ffmpeg command I've used. More info in my [project management page.](../../assignments/week02/#video)

<script id="asciicast-GVYKXvYN9nGQclZUruxwxH2TU" src="https://asciinema.org/a/GVYKXvYN9nGQclZUruxwxH2TU.js" data-autoplay="true" data-size="small" data-loop=1 data-t=23 data-speed=2  data-rows=10 async></script>



#### Model video:

<figure class="video_container">
  <video controls="true" allowfullscreen="true">
    <source src="../../images/week03/xdesign_video.mp4" type="video/mp4">
  </video>
</figure>



#### Photo capture:

<img src="../../images/week03/xdesign_render.jpg" alt="drawing" />

This is a view of the model I've made in XDesign.

I've used this command for video compression with ffmpeg:


<!--
## AgriLabs workshops:

### 3D modeling with FreeCad:

FreeCAD is a very interesting software, I had some issues on my Linux system but we practiced during our short workshop.

<img src="../../images/week03/freecad_1.jpeg" alt="drawing" width="90%"/>
<img src="../../images/week03/freecad_2.jpeg" alt="drawing" width="90%"/>



### 3D modeling with Blender:

The last time I've used blender was in 2010 and nowadays it looks incredible amazing, the interface and the workflow have improved. At that time we only learn very basic stuff for modeling. But it gave me a very good idea of the possibilities for rendering. So I explored rendering for my self later.

<img src="../../images/week03/blender_1.jpg" alt="drawing" width="90%"/>
<img src="../../images/week03/blender_2.jpg" alt="drawing" width="90%"/>


## Render with blender

I've exported the 3D model from xDesign as STL and imported it in Blender to make this renders.

<img src="../../images/week03/blender_render.jpg" alt="drawing" width="90%"/>

It was easy to paint the faces but it took a while.

<img src="../../images/week03/blender_render_2.jpg" alt="drawing" width="90%"/>

This is the model with a Simple deformation modifier.

The render motor used was Workbench with the basic configuration.

-->


## Files


[Download 3DXML Xdesign files.](../../files_for_projects/earring_fr27.3dxml)

[Download InksCape SVG files](../../files_for_projects/inkscape_earring_fr27.zip)

[Download from XDesign. Note: You need a 3dexperience account.](https://eu1-ifwe.3dexperience.3ds.com/#app:X3DDRIV_AP/content:driveId=R1132100766590&contentId=C0CC36E6092700006020334C00074EA0&contentType=file)
[Download Blender files](../../files_for_projects/blender_fabacademy.zip)
[Download Render files](../../files_for_projects/TAG_RF27.zip)
