from test1 import PyFrameWriter
import numpy as np
a = PyFrameWriter(b"ok.mp4", b"libx264", 60, 1920, 1080, b"-preset ultrafast -crf 23")
nparr = np.frombuffer(a, dtype=np.uint8)
af = nparr.reshape((1080, 1920, 3))
for i in range(6000):
	x = i % 1070
	af[x:x+10, x:x+10, :] = 255
	a.write_frame()
	af[x:x+10, x:x+10, :] = 0
a.close_video()
a.close_video()
