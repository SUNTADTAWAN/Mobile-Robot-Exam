import cv2
import cv2.aruco

aruco_dict = cv2.aruco.Dictionary_get(cv2.aruco.DICT_4X4_50)
marker_img = cv2.aruco.drawMarker(aruco_dict, 0, 200)  # Marker ID 0, size 200x200
cv2.imwrite("aruco_marker0.png", marker_img)
