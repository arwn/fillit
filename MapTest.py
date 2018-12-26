import subprocess
import os

for root, dirs, files in os.walk(os.path.abspath("test_maps")):
	for file in files:
		path = os.path.join(root, file)
		proc = subprocess.Popen(["./fillit", path], stdout=subprocess.PIPE)
		out = proc.stdout.readline().strip().decode("ascii")
		if "invalid" in path:
			# Did not print error when it was an invalid map
			if "error" not in out:
				print ("Map " + path + " is failing")
				if "segmentation" in out:
					print ("Segfault")
		else:
			if "error" in out:
				# This means it prints error on a valid map
				print ("Map " + path + " is failing")