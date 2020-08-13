from osr2mp4cv import PyFrameWriter
import numpy as np

width, height = 1000, 1000

a = PyFrameWriter(b"ok.mp4", b"libx264", 60, width, height, b"-preset ultrafast -crf 23")
nparr = np.frombuffer(a, dtype=np.uint8)
af = nparr.reshape((height, width, 3))
for i in range(6000):
	x = i % 1070
	af[x:x+10, x:x+10, :] = 255
	a.write_frame()
	af[x:x+10, x:x+10, :] = 0
a.close_video()
a.close_video()
