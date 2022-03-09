from mujoco_py import load_model_from_path, MjSim
from mujoco_py.mjviewer import MjViewer
import numpy as np

pi = np.pi

robot = load_model_from_path("iiwa.xml")
jnames = ["lbr_iiwa_joint_%d"%i for i in range(1,8)]

sim = MjSim(robot)
viewer = MjViewer(sim)

angle4 = 0

while 1:
    angle4 = angle4-0.0001
    if angle4<-pi/2:
        angle4=-pi/2

    pose = np.array([0,0,0,angle4,0,0,0])
    for j in range(7):
        sim.data.set_joint_qpos(jnames[j], pose[j])

    sim.forward()
    sim.step()
    viewer.render()

