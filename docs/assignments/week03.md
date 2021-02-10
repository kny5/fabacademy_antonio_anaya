# 3. Computer Aided design

## Introduction:

Description: CAD stands for Computer Aided Design, there are different software solutions for different industries, like [AutoCAD](https://www.autodesk.com/products/autocad/overview?term=1-YEAR&support=null) specialized in the mechanical and architecture industry, [CATIA](https://www.3ds.com/products-services/catia/) for the aircraft, marine and automobile industry, or [Blender](https://www.blender.org/) specialized in digital art.

There are also differences in licensing, for example proprietary, and open-source. Software like CATIA is proprietary and then you have to buy a license to use it, but there are also Open Sourced solutions like Blender, [FreeCAD](https://www.freecadweb.org/) and [OpenScad](https://www.openscad.org/), that are driven by their communities, and also are free of charge.

For this week the goal is to learn and use Raster or Vector drafting software, CAD and render or simulate.

As a personal note, it's my first time using 100% [Fedora](https://getfedora.org/) for all this process and I had some difficulties configuring my GPU drivers, something that's really common under this operative system if not used carefully. Normally my workflow needed a dual boot system on my personal computer to use Solidworks on Linux and programming under Linux. For the first time I've only used Linux thanks to XDesign and Blender.


## 2D


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


## InkScape illustration:

### Draft process

<img src="../../images/week03/inkscape_illustration_2.jpg" alt="photo_0" width="45%"/>
<img src="../../images/week03/inkscape_illustration_1.jpg" alt="photo_0" width="45%"/>




### Result

<img src="../../images/week03/inkscape_earring_fr27.png" alt="photo_0" width="90%"/>



## 3D

### Xdesign:

Review:

I've learned Xdesign and I found it very complicated at first even as a Solidworks user. My main OS is Linux and I've made this list to make Xdesign work fluid and efficiently.

Linux recommendations:
Chromium works better than Firefox.
Activate Hardware acceleration.
Force hardware GPU use.*

*For Nvidia Nouveau drivers use:
```
DRI_PRIME=1 chromium-browser
```

*For Nvidia propietary drivers, use Bumblebee:

```
optirun chromium-browser
```



### 3D modeling:

There are some basic operations for 3D modeling:

<ol>
<li>2D Drafting for sketching.</li>
<li>Linear region extrusion.</li>
<li>Linear region extraction.</li>
<li>One axis profile revolution.</li>
<li>Parametric scaling.</li>
</ol>

I've used all this to produce the model shown:

<img src="../../images/week03/xdesign_2.jpg" alt="drawing" width="90%"/>
<img src="../../images/week03/xdesign_4.jpg" alt="drawing" width="90%"/>
<img src="../../images/week03/xdesign_5.jpg" alt="drawing" width="90%"/>



### Model video:

<figure class="video_container">
  <video controls="true" allowfullscreen="true">
    <source src="../../images/week03/xdesign_video.mp4" type="video/mp4">
  </video>
</figure>



### Photo capture:

<img src="../../images/week03/xdesign_render.jpg" alt="drawing" />

This is a view of the model I've made in XDesign.

I've used this command for video compression with ffmpeg:



### Assembly video:

<figure class="video_container">
  <video controls="true" allowfullscreen="true">
    <source src="../../images/week03/xdesign_assembly.mp4" type="video/mp4">
  </video>
</figure>

<script id="asciicast-GVYKXvYN9nGQclZUruxwxH2TU" src="https://asciinema.org/a/GVYKXvYN9nGQclZUruxwxH2TU.js" data-autoplay="true" data-size="small" data-loop=1 data-t=23 data-speed=2  data-rows=10 async></script>


### Download:

[Download 3DXML](../../files_for_projects/earring_fr27.3dxml)

[Download from XDesign. Note: You need a 3dexperience account.](https://eu1-ifwe.3dexperience.3ds.com/#app:X3DDRIV_AP/content:driveId=R1132100766590&contentId=C0CC36E6092700006020334C00074EA0&contentType=file)


## AgriLabs workshops:

### 3D modeling with FreeCad:

<img src="../../images/week03/freecad_1.jpeg" alt="drawing" width="90%"/>
<img src="../../images/week03/freecad_2.jpeg" alt="drawing" width="90%"/>



### 3D modeling with Blender:

<img src="../../images/week03/blender_1.jpg" alt="drawing" width="90%"/>
<img src="../../images/week03/blender_2.jpg" alt="drawing" width="90%"/>

[Download Blender files](../../files/week03/blender_fabacademy.zip)

## Render with blender

I've exported the 3D model from xDesign as STL and imported it in Blender to make this renders.

<img src="../../images/week03/blender_render.jpg" alt="drawing" width="90%"/>
It was easy to paint the faces but it took a while.

<img src="../../images/week03/blender_render_2.jpg" alt="drawing" width="90%"/>
This is the model with a Simple deformation modifier.

The render motor used was Workbench with the basic configuration.
