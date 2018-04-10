
import numpy as np
import cv2
import steering.configs as configs
import steering.models as models
import steering.visualization.visualization as vis

class SteeringPredictor:

    def __init__(self):

        self.cnn = models.commaai_model()
        self.cnn.load_weights(configs.model_path)
        print("---------------------")
        print("steering model loaded")

    def predict_steering(self, image):

        input = cv2.resize(image, (320, 160))
        predicted_angle = self.cnn.predict(np.array([input]))[0][0]
        overlay_img = vis.visualize_steering_wheel(image, predicted_angle)

        return predicted_angle, overlay_img

