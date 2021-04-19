'''
This program list jpg and mp4 files and makes an html tag for each one in a md file.
The pourpose of this is to automate consuming time steps in the documentation process.

Autor: Antonio de Jesus Anaya Hernandez
Fablab: agrilab
Country: France
Week: 12
'''

import os

basepath = '.'
images = []
videos = []

week = "week12"
size = "100%"

html_img = '<img src="../../images/%w/%n" alt="%n" width=100%/>'
html_video = '''
<figure class="video_container">\n\t<video controls="true" allowfullscreen="true">\n\t\t<source src="../../images/{week}/{name}" type="video/mp4">\n\t</video>\n</figure>'''

for entry in os.listdir(basepath):
    if os.path.isfile(os.path.join(basepath, entry)):
        if str(entry)[-3:] == "jpg" :
            images.append(entry)
        elif str(entry)[-3:] == "mp4" :
            videos.append(entry)

print(images)

tags = ["## Images"]
for image in images:
    tags.append('<img src="../../images/{week}/{image}" alt="{image}" width=100%/>'.format(week=week, image=image))

print(tags)

file = open("tags.md", "a")

tags.append("\n\n\n##Videos")

for video in videos:
    tags.append(html_video.format(week=week, name=video))

for tag in tags:
    tag = tag + "\n\n"
    file.write(tag)

print(tags)

file.close()
