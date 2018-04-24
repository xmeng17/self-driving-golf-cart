#!/usr/bin/python
#
# ROS node for steering controller
# publishes /dbw/steering_angle as Float64
#
# Developed & maintained by Neil Nie
# (c) Yongyang Nie, 2018, All rights Reserved
#

import numpy as np
import cv2
import configs as configs
import models as models

import rospy
from std_msgs.msg import Image
from std_msgs.msg import Float64
from cv_bridge import CvBridge, CvBridgeError


class SteeringPredictor:

    def __init__(self):

        self.current_frame = None

        self.cnn = models.commaai_model()
        self.cnn.load_weights(configs.model_path)
        rospy.loginfo('steering deep learning model loaded')

        rospy.init_node('steering_controller')
        rospy.Subscribe('/cv_camera/image_raw', Image, callback=self.image_update_callback, queue_size=5)

        steering_pub = rospy.Publisher('/dbw/steering_angle/', Float64, queue_size=5)
        rate = rospy.Rate(10)


        while not rospy.is_shutdown():
            angle = self.predict(self.current_frame)
            steering_pub.publish(angle)
            rate.sleep()

    def image_update_callback(self, data):

        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            print(e)

        self.current_frame = cv_image

    def predict(self, image):

        input = cv2.resize(image, (320, 160))
        predicted_angle = self.cnn.predict(np.array([input]))[0][0]

        return predicted_angle


if __name__ == "__main__":

    try:
        SteeringPredictor()
    except rospy.ROSInterruptException:
        pass