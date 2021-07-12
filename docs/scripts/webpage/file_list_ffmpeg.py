import os

basepath = '.'
images = []
videos = []

for entry in os.listdir(basepath):
    if os.path.isfile(os.path.join(basepath, entry)):
        if str(entry)[-3:] == "jpg" :
            images.append(entry)
        elif str(entry)[-3:] == "mp4" :
            videos.append(entry)

img_txt = open("imgs.txt", "w")
for img in images:
    img_txt.write("file " + img)
img_txt.close()


vid_txt = open("vids.txt", "w")
for vid in videos:
    vid_txt.write("file " + vid)
vid_txt.close()

# os.system('ffmpeg -f concat -i imgs.txt -vcodec libx264 -b:v 1000k -filter:v "setpts=0.5*PTS -vf scale=-2:1080 -an presentation_imgs.mp4')

os.system('ffmpeg -r 1/5 -start_number 0 -f concat -i imgs.txt -c:v libx264 -vf "fps=25,format=yuv420p" presentation_imgs.mp4')

os.system('ffmpeg -f concat -i vids.txt -vcodec libx264 -b:v 1000k -filter:v "setpts=0.5*PTS" -vf scale=-2:1080 -an presentation_vids.mp4')
