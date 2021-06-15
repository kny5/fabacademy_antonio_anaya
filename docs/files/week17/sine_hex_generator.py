import numpy as np

import matplotlib.pyplot as plot



# Get x values of the sine wave

time        = np.arange(0, 2*np.pi, 0.2)



# Amplitude of the sine wave is sine of a variable like time

amplitude   = np.sin(time)

amplitude_np =  [(x*(1024/2)) + (1024/2)  for x in amplitude]

print(amplitude_np)
print(len(amplitude_np))

amplitude_1023_rnd = []

for elem in amplitude_np:
    amplitude_1023_rnd.append(round(elem))

hex_sine = []

for elem in amplitude_1023_rnd:
    _hex = hex(elem)
    if str(_hex).__len__() > 4:
        hex_sine.append(_hex)
    else:
        end = str(_hex).split("0x")
        _fix = "0x0" + end[1]
        hex_sine.append(_fix)
        if len(_fix) < 5:
            end = str(_hex).split("0x")
            _fix = "0x00" + end[1]
            hex_sine.append(_fix)


with open("hex_sin_1024.txt","w") as hex_file:
    for __hex in hex_sine:
        hex_file.write(__hex + ", ")
    hex_file.close()


print(amplitude_1023_rnd)

print(amplitude_1023_rnd.__len__())

print(min(amplitude_1023_rnd))

print(hex_sine)

print(hex_sine.__len__())

amplitude_hex = []

for elem in amplitude_1023_rnd:

    amplitude_hex.append(None   )

# Plot a sine wave using time and amplitude obtained for the sine wave

plot.plot(time, amplitude_1023_rnd)



# Give a title for the sine wave plot

plot.title('Sine wave')



# Give x axis label for the sine wave plot

plot.xlabel('Time')



# Give y axis label for the sine wave plot

plot.ylabel('Amplitude = sin(time)')



plot.grid(True, which='both')



plot.axhline(y=0, color='k')



plot.show()



# Display the sine wave

plot.show()
