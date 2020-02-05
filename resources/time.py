import matplotlib.pyplot as plt

x = ['151x176', '391x391', '960x970']
y = [7, 48, 281]

plt.xlabel('Image Size')
plt.ylabel('Time (ms)')

plt.title('Sequential algorithm')

plt.plot(x,y)

plt.savefig('TimeGraph.png')